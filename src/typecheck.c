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
    for (temp = current; temp != NULL; temp = temp->child)
    {
        type = temp->scope;
        if (type->basetype == FUNC_TYPE)
        {
            if (strcmp(type->u.f.name, func_name) == 0)
            {
                *func_type = type;
                return;
            }
        }
    }
}

static void type_error_msg(tree_ptr n, type_ptr t, int has_func_call)
{
    if (n->type->basetype == FUNC_TYPE)
    {
        type_ptr func_type = NULL;
        get_func_type(n->leaf->text, &func_type);
        if (func_type == NULL)
            return;

        printf("TYPE ERROR: %d\n", has_func_call);
        if (has_func_call == 0)
        {
            fprintf(stderr, "ERROR: unexpected `%s` of incompatible type `%s` at line %d, in file %s\n", n->leaf->text, typename(func_type), n->leaf->lineno, n->leaf->filename);
            fprintf(stderr, "Expected type `%s`\n", typename(t));
            exit(3);
        }
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

        if (strcmp(n->leaf->text, n->type->u.s.name) == 0)
            return;
    }
    else if (n->type->basetype == UNKNOW_TYPE)
    {
        type_ptr type = kid_type(n);
        n->type = type;
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
        if (strcmp(n->prodname, "pseudocall") == 0)
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
        // if (!has_func_call)
        //     break;
        n->type = kid_type(n);
        printf("COMPARING LLITERAL TYPES: %s %s | %s | func call: %d\n", typename(n->type), typename(t), n->leaf->text, has_func_call);

        if (n->type->basetype != t->basetype)
        {
            type_error_msg(n, t, has_func_call);
        }
        break;

    case LNAME:
        n->type = kid_type(n);

        if (n->type->basetype == STRUCT_TYPE)
            break;

        printf("COMPARING TYPES: %s %s | %d %d\n", typename(n->type), typename(t), n->type->basetype, t->basetype);
        if (n->type->basetype != t->basetype)
        {
            type_error_msg(n, t, has_func_call);
        }
        break;

    default:
        break;
    }
}

static void incompatible_types_error_msg(tree_ptr n, type_ptr type, int has_func_call)
{
    if (type == NULL)
        return;
    if (n->type->basetype != type->basetype)
    {
        type_error_msg(n, type, has_func_call);
    }
}

static void check_incompatible_types_error_msg(tree_ptr n, type_ptr type, int has_func_call)
{
    if (n == NULL)
        return;
    int i;
    for (i = 0; i < n->nkids; i++)
    {
        check_incompatible_types_error_msg(n->kids[i], type, has_func_call);
    }

    type_ptr leaf_type;

    switch (n->prodrule)
    {
    case LNAME:
        leaf_type = kid_type(n);
        n->basetype = leaf_type->basetype;
        n->type = leaf_type;

        printf("FOUND TYPE: %s | %s | %s\n", typename(type), typename(n->type), n->leaf->text);

        incompatible_types_error_msg(n, type, has_func_call);
        break;
    case LLITERAL:
        n->basetype = n->leaf->basetype;
        n->type = alctype(n->basetype);
        incompatible_types_error_msg(n, type, has_func_call);

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

    type_ptr type;

    switch (n->prodrule)
    {
    case R_OTHERTYPE:
        type = kid_type(n->kids[3]);
        check_incompatible_types_error_msg(n->kids[1], type, 0);
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

static void print_scope(sym_table_ptr st)
{
    stack_ptr children = st->children;
    while (!is_stack_empty(children))
    {
        type_ptr type = peek_stack(children);
        pop_stack(children);
    }
}

static void check_expr(tree_ptr n, tree_ptr other, int has_func_call)
{
    if (!n)
        return;
    int i;
    for (i = 0; i < n->nkids; i++)
    {
        // if (n->prodrule == (R_PSEUDOCALL + 1))
        // return;
        check_expr(n->kids[i], other, has_func_call);
    }

    type_ptr type = NULL;

    static int correct_func_call = 0;

    switch (n->prodrule)
    {
    case R_PEXPR_NO_PAREN + 2: // pexpr . sym
        // get type of expr{0} and check other type
        type = kid_type(n->kids[2]);
        printf("TYPE: %s\n", typename(type));
        check_incompatible_types_error_msg(other, type, has_func_call);
        break;
    case R_PEXPR_NO_PAREN + 5: // pexpr [ expr ]
        // get type of expr{0} and check other type
        type = kid_type(n->kids[2]);
        printf("TYPE: %s\n", typename(type));
        break;
    case LNAME:
    case LLITERAL:
        n->type = kid_type(n);
        other->type = kid_type(other);
        printf("CURRENT SCOPE: %s | %s\n", current->name, n->symtab->name);
        printf("TYPE: %s for %s | %s\n", typename(n->type), n->leaf->text, typename(other->type));
        printf("OTHER TYPE: %s | %d\n", typename(other->type), has_func_call);
        // if (has_func_call == 0)
        //     type_error(other, n->type, 1);
        // else
        // {
        check_incompatible_types_error_msg(other, n->type, has_func_call);
        // }

        break;

    default:
        // type = kid_type(n->kids[2]);
        printf("DEFAULT: %s | %d\n", n->prodname, n->prodrule);

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

    switch (n->prodrule)
    {
    case R_PSEUDOCALL + 1:
        return; // early exit to prevent over exploration
    case R_SIMPLE_STMT + 1:
    case R_SIMPLE_STMT + 2:
    case R_SIMPLE_STMT + 3:
        check_incompatible_types_error_msg(n->kids[2], return_type, 1);
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
        check_incompatible_types_error_msg(n->kids[2], return_type, 1);

        break;

    case LLITERAL:
    case LNAME:
        check_incompatible_types_error_msg(n, return_type, 1);

        break;

    default:
        break;
    }
}

static void check_params_error(tree_ptr n, type_ptr func_type)
{
    paramlist params = func_type->u.f.parameters;
    printf("FUNC PARAM: %s\n", typename(func_type));
    while (params != NULL)
    {
        printf("CHECKING PARAM: %s %s\n", params->name, n->leaf->text);
        if (strcmp(n->leaf->text, params->name) == 0)
        {
            incompatible_types_error_msg(n, params->type, 0);
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
    case LLITERAL:
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
    for (temp = current; temp != NULL; temp = temp->child)
    {
        type = temp->scope;
        if (type->basetype == FUNC_TYPE)
        {
            check_return_type(n, type->u.f.returntype);
            check_in_params(n, type);
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
        check_expression(n->kids[i]);
    }

    int has_func_call = 0;

    switch (n->prodrule)
    {
    case R_SIMPLE_STMT + 1:
    case R_SIMPLE_STMT + 2:
    case R_SIMPLE_STMT + 3:
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

        get_has_func_call(n->kids[0], &has_func_call);

        if (has_func_call == 0)
            get_has_func_call(n->kids[2], &has_func_call);

        printf("HAS FUNC CALL: %d\n", has_func_call);

        check_expr(n->kids[0], n->kids[2], has_func_call);
        // check_expr(n->kids[2], n->kids[0]);
        break;

    case R_NON_DCL_STMT + 3:

        check_func_type(n->kids[1]);

        break;

    case LNAME:

        break;

    case LLITERAL:
        n->type = alctype(n->leaf->basetype);
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
        printf("\tPARAM -> %s: %s\n", temp->name, typename(temp->type));
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
        add_param(params, type, n->leaf->text);
        break;

    default:
        break;
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

static void func_call_error_msg(token_ptr leaf, paramlist found, paramlist expected)
{
    if (found->type->basetype != expected->type->basetype)
    {
        fprintf(stderr, "ERROR: unexpected function call with `%s` of incompatible type `%s` at line %d, in file %s\n", found->name, typename(found->type), leaf->lineno, leaf->filename);
        fprintf(stderr, "Expected type `%s`\n", typename(expected->type));
        exit(3);
    }
}

static void check_func_call_error(token_ptr leaf, paramlist params, type_ptr func_type)
{
    paramlist temp = params;
    paramlist func_params = func_type->u.f.parameters;
    // if ((temp != NULL) && (func_params != NULL))
    // printf("CHECKING ERROR IN PARAMS: %s %s\n", func_params->name, temp->name);
    print_params(func_params);
    while (func_params != NULL)
    {
        // print_params(func_params);
        printf("FOUND PARAM: %s\n", func_params->name);

        if(temp == NULL) {
            fprintf(stderr, "ERROR: unexpected function call with no argument at line %d, in file %s\n", leaf->lineno, leaf->filename);
            fprintf(stderr, "Expected type `%s`\n", typename(func_params->type));
            exit(3);
        }
        printf("NULL CHECK: %p %p\n", temp, func_params);
        func_call_error_msg(leaf, temp, func_params);

        func_params = func_params->next;
        temp = temp->next;
    }
}

static void check_function_call(tree_ptr n)
{
    int i;
    for (i = 0; i < n->nkids; i++)
    {
        check_function_call(n->kids[i]);
    }

    char *func_name = NULL;
    type_ptr func_type = NULL;
    paramlist params = NULL;
    token_ptr leaf = NULL;

    switch (n->prodrule)
    {

    case R_PSEUDOCALL + 1:
        get_name(n, &func_name);
        collect_params(n->kids[2], &params);
        // print_params(params);
        // get_func_type(func_name, &func_type);
        func_type = kid_type(n->kids[0]);
        get_leaf(n, &leaf);

        if(func_type != NULL && leaf != NULL)
        {
            check_func_call_error(leaf, params, func_type);
        }
       
        // check_in_params(n->kids[2], func_type);
        break;

    default:
        break;
    }
}

void typecheck(tree_ptr n)
{
    check_function_call(n);
    // check_common_dcl(n);
    // check_expression(n);
}