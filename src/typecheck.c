#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include "typecheck.h"
#include "type.h"
#include "symtab.h"
#include "semantic.h"
#include "rules.h"
#include "go.tab.h"
#include "utils.h"

static void get_func_type(char *func_name, type_ptr *func_type)
{
    type_ptr type = NULL;
    sym_table_ptr temp;
    for (temp = current; temp != NULL; temp = temp->parent)
    {
        stack_ptr children = temp->children;
        while (!is_stack_empty(children))
        {
            type = peek_stack(children);
            if (!type)
                return;
            if (type->basetype == FUNC_TYPE)
            {
                if (strcmp(type->u.f.name, func_name) == 0)
                {
                    printf("FUNCTION TYPE: %s\n", typename(type->u.f.returntype));
                    *func_type = type;
                    return;
                }
            }
            pop_stack(children);
        }
    }
}

static void type_error_msg(tree_ptr n, type_ptr t)
{
    if (n->type->basetype == FUNC_TYPE)
    {
        type_ptr func_type = NULL;
        get_func_type(n->leaf->text, &func_type);
        if (func_type == NULL)
            return;
        // printf("FOUND FUNCTION TYPE WHEN CHECKING: %s and %s | %s | %d %d\n", typename(n->type), typename(func_type->u.f.returntype), typename(t), func_type->u.f.returntype->basetype, t->basetype);
        if (func_type->u.f.returntype->basetype != t->basetype)
        {
            fprintf(stderr, "ERROR: unexpected `%s` of incompatible return type `%s` at line %d, in file %s\n", n->leaf->text, typename(func_type->u.f.returntype), n->leaf->lineno, n->leaf->filename);
            fprintf(stderr, "Expected type `%s`\n", typename(t));
            exit(3);
        }
        else
        {
            return;
        }
    }
    else if (n->type->basetype == STRUCT_TYPE)
    {
        printf("STRUCT TYPE WHEN CHECKING: %s and %s | %s %s\n", typename(n->type), typename(t), n->leaf->text, n->type->u.s.name);

        if (strcmp(n->leaf->text, n->type->u.s.name) == 0)
            return;
    }
    else if (n->type->basetype == UNKNOW_TYPE)
    {
        type_ptr type = kid_type(n);
        n->type = type;
        printf("UNKNOWN WHEN CHECKING: %s and %s | %s | %d %d\n", typename(n->type), typename(type), n->leaf->text, n->type->basetype, type->basetype);
        if (n->type->basetype == t->basetype)
            return;
        // type_error_msg(n, t);
    }
    fprintf(stderr, "ERROR: unexpected `%s` of incompatible type `%s` at line %d, in file %s\n", n->leaf->text, typename(n->type), n->leaf->lineno, n->leaf->filename);
    fprintf(stderr, "Expected type `%s`\n", typename(t));
    exit(3);
}

static void get_has_func_call(tree_ptr n, int *has_func_call)
{

    if (n == NULL)
        return;
    int i;
    for (i = 0; i < n->nkids; i++)
    {
        if (n->prodrule == (R_PSEUDOCALL + 1))
        {
            *has_func_call = 1;
            return;
        }
        *has_func_call = 0;
        get_has_func_call(n->kids[i], has_func_call);
    }
}

static void type_error(tree_ptr n, type_ptr t, int has_func_call)
{
    if (n == NULL)
        return;

    int i;
    for (i = 0; i < n->nkids; i++)
    {
        // if (n->prodrule == (R_PSEUDOCALL + 1))
        //     continue;
        type_error(n->kids[i], t, has_func_call);
    }
    switch (n->prodrule)
    {

    case R_PSEUDOCALL + 1:
        return;

    case R_OTHERTYPE:
        type_error(n->kids[1], n->kids[3]->type, has_func_call);
        break;

    case R_DOTNAME + 1:
        type_error(n->kids[2], t, has_func_call);
        break;

    case LLITERAL:
        if (has_func_call)
            break;
        if (n->leaf->basetype != t->basetype)
        {
            type_error_msg(n, t);
        }
        break;

    case LNAME:
        if (n->type->basetype == STRUCT_TYPE)
            break;
        if (n->type->basetype != t->basetype)
        {
            type_error_msg(n, t);
        }
        break;

    default:
        // printf("DEFAULT: %s\n", n->prodname);
        break;
    }
}

static void incompatible_types_error_msg(tree_ptr n, type_ptr type)
{
    if (!type)
        return;
    printf("CHECKING TYPES: %s %s | %d %d\n", typename(n->type), typename(type), n->type->basetype, type->basetype);
    if (n->type->basetype != type->basetype)
    {
        type_error_msg(n, type);
    }
}

static void check_incompatible_types_error_msg(tree_ptr n, type_ptr type)
{
    if (n == NULL)
        return;
    int i;
    for (i = 0; i < n->nkids; i++)
    {
        check_incompatible_types_error_msg(n->kids[i], type);
    }

    type_ptr leaf_type;

    switch (n->prodrule)
    {
    case LNAME:
        leaf_type = kid_type(n);
        n->basetype = leaf_type->basetype;
        n->type = leaf_type;
        printf("FOUND LNAME: %s | type: %s | leaf type: %s\n", n->leaf->text, typename(n->type), typename(leaf_type));

        incompatible_types_error_msg(n, type);
        break;
    case LLITERAL:
        n->basetype = n->leaf->basetype;
        n->type = alctype(n->basetype);
        printf("FOUND LLITERAL: %s | type: %s | leaf type: %s\n", n->leaf->text, typename(type), typename(n->type));
        incompatible_types_error_msg(n, type);

        break;
    default:
        break;
    }
}

static void check_ntype(tree_ptr n)
{

    if (n == NULL)
        return;
    int i;
    for (i = 0; i < n->nkids; i++)
    {
        check_ntype(n->kids[i]);
    }

    // printf("N TYPE DEFAULT: %s\n", n->prodname);
    type_ptr type;

    switch (n->prodrule)
    {
    // case R_PSEUDOCALL:
    //     return; // early exit to prevent over exploration
    case R_OTHERTYPE:
        type = kid_type(n->kids[3]);
        printf("OTHERTYPE FOUND %s\n", typename(type));
        check_incompatible_types_error_msg(n->kids[1], type);
        break;
    default:
        break;
    }
}

static void check_declaration(tree_ptr n)
{
    if (n == NULL)
        return;
    int i;
    for (i = 0; i < n->nkids; i++)
    {
        if (n->prodrule == (R_PSEUDOCALL + 1))
            return;
        check_declaration(n->kids[i]);
    }

    // printf("DEFAULT: %s\n", n->prodname);

    int has_func_call = 0;

    switch (n->prodrule)
    {
    case R_PSEUDOCALL + 1:
        return; // early exit to prevent over exploration
    case R_VARDCL + 1:
    case R_CONSTDCL:
        check_ntype(n->kids[1]);
        // type = kid_type(n->kids[1]);
        // n->type = type;
        // n->type = n->kids[1]->type;
        get_has_func_call(n, &has_func_call);
        type_error(n->kids[3], n->type, has_func_call);
        break;

    case R_VARDCL + 2:
    case R_CONSTDCL + 2:
        // n->type = type;
        // n->type = n->kids[0]->type;
        get_has_func_call(n, &has_func_call);
        type_error(n->kids[2], n->type, has_func_call);
        break;

    case R_START_COMPLIT:
        break;

    case R_TYPEDCL:
        break;

    case LLITERAL:
        n->type = alctype(n->leaf->basetype);
        printf("TYPE: %s for %s | sval: %s | dval: %f | ival: %d\n", typename(n->type), n->leaf->text, n->leaf->sval, n->leaf->dval, n->leaf->ival);
        // insert_sym(current, n->leaf->text, n->type);
        break;

    default:
        break;
    }
}

static void check_common_dcl(tree_ptr n)
{
    if (n == NULL)
        return;

    int i;
    for (i = 0; i < n->nkids; i++)
    {
        check_common_dcl(n->kids[i]);
    }

    if (strcmp(n->prodname, "common_dcl") == 0)
    {
        check_declaration(n);
    }
}

static void check_expr(tree_ptr n, tree_ptr other)
{
    if (!n)
        return;
    int i;
    for (i = 0; i < n->nkids; i++)
    {
        if (n->prodrule == (R_PSEUDOCALL + 1))
            return;
        check_expr(n->kids[i], other);
    }

    type_ptr type = NULL;

    switch (n->prodrule)
    {                          // early exit to prevent over exploration
    case R_PEXPR_NO_PAREN + 2: // pexpr . sym
        // get type of expr{0} and check other type
        type = kid_type(n->kids[2]);
        printf("BASE TYPES: %d %s\n", n->prodrule, typename(type));
        check_incompatible_types_error_msg(other, type);
        break;
    case R_PEXPR_NO_PAREN + 5: // pexpr [ expr ]
        // get type of expr{0} and check other type
        type = kid_type(n->kids[2]);
        printf("OTHER TYPES: %s\n", typename(type));
        check_incompatible_types_error_msg(other, type);
        break;

    default:
        break;
    }
}

static void check_return_type(tree_ptr n, type_ptr return_type)
{
    if (!n)
        return;
    int i;
    for (i = 0; i < n->nkids; i++)
    {
        check_return_type(n->kids[i], return_type);
    }

    // printf("DEFAULT: %s %s\n", n->prodname, typename(return_type));

    switch (n->prodrule)
    {
    case R_PSEUDOCALL + 1:
        return; // early exit to prevent over exploration
    case R_SIMPLE_STMT + 1:
    case R_SIMPLE_STMT + 2:
    case R_SIMPLE_STMT + 3:
        // type = kid_type(n->kids[0]);
        // printf("CHECK TYPES: %d %s\n", n->prodrule, typename(type));
        check_incompatible_types_error_msg(n->kids[2], return_type);
        // check_expr(n->kids[0], n->kids[2]);
        break;

    case R_EXPR + 1:
    case R_EXPR + 2:
    case R_EXPR + 3:
    case R_EXPR + 4:
    case R_EXPR + 5:
    case R_EXPR + 6:
    case R_EXPR + 7:
    case R_EXPR + 8:
    case R_EXPR + 9:
    case R_EXPR + 10:
    case R_EXPR + 11:
    case R_EXPR + 12:
    case R_EXPR + 13:
    case R_EXPR + 14:
    case R_EXPR + 15:
    case R_EXPR + 16:
    case R_EXPR + 17:
    case R_EXPR + 18:
    case R_EXPR + 19:
        check_incompatible_types_error_msg(n->kids[2], return_type);

        break;

    case LLITERAL:
    case LNAME:
        check_incompatible_types_error_msg(n, return_type);

        break;

    default:
        break;
    }
}

static void check_params_error(tree_ptr n, type_ptr func_type)
{
    paramlist params = func_type->u.f.parameters;
    while (params != NULL)
    {
        if (strcmp(n->leaf->text, params->name) == 0)
        {
            incompatible_types_error_msg(n, params->type);
        }
        params = params->next;
    }
}

static void check_in_params(tree_ptr n, type_ptr func_type)
{
    if (n == NULL)
        return;
    int i;
    for (i = 0; i < n->nkids; i++)
    {
        check_in_params(n->kids[i], func_type);
    }
    switch (n->prodrule)
    {
    case LNAME:
        check_params_error(n, func_type);
        break;
    default:
        break;
    }
}

static void check_func_type(tree_ptr n)
{
    type_ptr type = NULL;
    sym_table_ptr temp;
    for (temp = current; temp != NULL; temp = temp->parent)
    {
        stack_ptr children = temp->children;
        while (!is_stack_empty(children))
        {
            type = peek_stack(children);
            if (!type)
                break;
            if (type->basetype == FUNC_TYPE)
            {
                printf("RETURN TYPE: %s\n", typename(type->u.f.returntype));
                check_return_type(n, type->u.f.returntype);
                check_in_params(n, type);
            }
            pop_stack(children);
        }
    }
}

static void check_expression(tree_ptr n)
{
    if (n == NULL)
        return;
    int i;
    for (i = 0; i < n->nkids; i++)
    {
        if (n->prodrule == (R_PSEUDOCALL + 1))
            return;
        check_expression(n->kids[i]);
    }

    // printf("DEFAULT: %s\n", n->prodname);

    switch (n->prodrule)
    {
        // case R_PSEUDOCALL + 1:
        //     return; // early exit to prevent over exploration

    case R_SIMPLE_STMT + 1:
    case R_SIMPLE_STMT + 2:
    case R_SIMPLE_STMT + 3:
        // type = kid_type(n->kids[0]);
        // printf("CHECK TYPES: %d %s\n", n->prodrule, typename(type));
        // check_incompatible_types_error_msg(n->kids[2], type);
        check_expr(n->kids[0], n->kids[2]);
        break;

    case R_EXPR + 1:
    case R_EXPR + 2:
    case R_EXPR + 3:
    case R_EXPR + 4:
    case R_EXPR + 5:
    case R_EXPR + 6:
    case R_EXPR + 7:
    case R_EXPR + 8:
    case R_EXPR + 9:
    case R_EXPR + 10:
    case R_EXPR + 11:
    case R_EXPR + 12:
    case R_EXPR + 13:
    case R_EXPR + 14:
    case R_EXPR + 15:
    case R_EXPR + 16:
    case R_EXPR + 17:
    case R_EXPR + 18:
    case R_EXPR + 19:
        check_expr(n->kids[0], n->kids[2]);

        break;

    case R_NON_DCL_STMT + 3:
        check_func_type(n->kids[1]);

        break;

    case LNAME:

        break;

    case LLITERAL:

        break;

    default:
        break;
    }
}

static void get_name(tree_ptr n, char **name)
{
    if (n == NULL)
        return;
    int i;
    for (i = 0; i < n->nkids; i++)
    {
        get_name(n->kids[i], name);
    }

    switch (n->prodrule)
    {
    case LNAME:
        *name = n->leaf->text;
        break;
    default:
        break;
    }
}

static void print_params(paramlist params)
{
    paramlist temp = params;
    while (temp != NULL)
    {
        printf("PARAM: %s of type %s\n", temp->name, typename(temp->type));
        temp = temp->next;
    }
}

static void add_param(paramlist *params, type_ptr type, char *name)
{
    paramlist temp = safe_malloc(sizeof(*temp));
    temp->name = strdup(name);
    temp->type = type;
    temp->next = *params;
    *params = temp;
}

static void collect_params(tree_ptr n, paramlist *params)
{
    int i;
    for (i = 0; i < n->nkids; i++)
    {
        collect_params(n->kids[i], params);
    }

    type_ptr type = NULL;

    switch (n->prodrule)
    {
    case LNAME:
    case LLITERAL:
        type = kid_type(n);
        printf("FOUND TYPE: %s\n", typename(type));
        add_param(params, type, n->leaf->text);
        break;

    default:
        break;
    }
}

static void func_error_msg(token_ptr leaf, type_ptr expected_type, type_ptr found_type)
{
    if (expected_type == NULL || found_type == NULL)
        return;
    fprintf(stderr, "ERROR: wrong argument of type `%s` for function `%s` at line %d, in file %s\n", typename(found_type), leaf->text, leaf->lineno, leaf->filename);
    fprintf(stderr, "Expected type `%s`\n", typename(expected_type));
    exit(3);
}

static void check_func_call_arg_type(token_ptr leaf, paramlist func_param, paramlist params)
{
    printf("CHECKING PARAM: %s:%s %s:%s\n", func_param->name, typename(func_param->type), params->name, typename(params->type));

    if (func_param->type->basetype != params->type->basetype)
    {
        func_error_msg(leaf, func_param->type, params->type);
    }
}

static void check_func_call(token_ptr leaf, type_ptr func_type, paramlist params)
{
    paramlist func_param = func_type->u.f.parameters;
    int i;
    for (i = 0; i < func_type->u.f.nparams && (func_param != NULL && params != NULL); i++)
    {
        // printf("CHECKING PARAM: %s:%s %s:%s\n", func_param->name, typename(func_param->type), params->name, typename(params->type));
        check_func_call_arg_type(leaf, func_param, params);
        params = params->next;
        func_param = func_param->next;
    }
    if (func_param != NULL && params != NULL)
        if (func_param->next != NULL || params->next != NULL)
        {
            check_func_call_arg_type(leaf, func_param, params);
        }
}

static void get_leaf(tree_ptr n, token_ptr *t)
{
    if (n == NULL)
        return;
    int i;
    for (i = 0; i < n->nkids; i++)
    {
        get_leaf(n->kids[i], t);
    }

    switch (n->prodrule)
    {
    case LNAME:
        *t = n->leaf;
        break;
    default:
        break;
    }
}

static void check_function_call(tree_ptr n)
{
    int i;
    for (i = 0; i < n->nkids; i++)
    {
        check_function_call(n->kids[i]);
    }

    char *func_name;
    type_ptr func_type;
    paramlist params = NULL;
    token_ptr leaf;

    switch (n->prodrule)
    {

    case R_PSEUDOCALL + 1:
        get_name(n, &func_name);
        get_func_type(func_name, &func_type);
        collect_params(n->kids[2], &params);
        print_params(params);
        get_leaf(n, &leaf);
        check_func_call(leaf, func_type, params);
        check_in_params(n->kids[2], func_type);
        printf("FUNCTION: %s of type: %s\n", func_name, typename(func_type));
        break;

    case LLITERAL:
        printf("LLITERAL: %s\n", n->leaf->text);
        break;
    case LNAME:
        printf("LNAME: %s\n", n->leaf->text);
        break;

    default:
        // printf("DEFAULT: %s\n", n->prodname);
        break;
    }
}

void typecheck(tree_ptr n)
{
    printf("TYPE CHECk: %s\n", n->prodname);
    // check_function_call(n);
    check_common_dcl(n);
    // check_expression(n);
}