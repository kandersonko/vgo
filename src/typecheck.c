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
    else if (n->type->basetype == MAP_TYPE)
    {
        if (strcmp(n->leaf->text, n->type->u.s.name) == 0)
            return;
    }
    else if (t->basetype == MAP_TYPE)
    {
        if (t->u.m.elemtype->basetype != n->type->basetype || t->u.m.indextype->basetype != n->type->basetype)
            return;
        fprintf(stderr, "ERROR: unexpected `%s` of incompatible map element type `%s` at line %d, in file %s\n", n->leaf->text, typename(n->type), n->leaf->lineno, n->leaf->filename);
        fprintf(stderr, "Expected type `%s`\n", typename(t->u.m.elemtype));
        exit(3);
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
        n->type = kid_type(n);

        if (n->type->basetype != t->basetype)
        {
            type_error_msg(n, t, has_func_call);
        }
        break;

    case LNAME:
        n->type = kid_type(n);

        if (n->type->basetype == STRUCT_TYPE)
            break;

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
        insert_sym(globals, n->leaf->text, n->type);
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

static void check_expr(tree_ptr n, tree_ptr other, int has_func_call)
{
    if (!n)
        return;

    type_ptr type = NULL;

    switch (n->prodrule)
    {
    case R_PEXPR_NO_PAREN + 2: // pexpr . sym
        // get type of expr{0} and check other type
        type = kid_type(n->kids[2]);
        check_incompatible_types_error_msg(other, type, has_func_call);
        break;
    case R_PEXPR_NO_PAREN + 5: // pexpr [ expr ]
        // get type of expr{0} and check other type
        type = kid_type(n->kids[0]);
        check_incompatible_types_error_msg(other, type, has_func_call);
        return;

        break;
    case R_PEXPR_NO_PAREN + 7: // pexpr [ expr ]
        // get type of expr{0} and check other type
        type = kid_type(n->kids[2]);
        check_incompatible_types_error_msg(other, type, has_func_call);

        break;

    case R_PEXPR_NO_PAREN:
    case R_SYM:
        n->type = kid_type(n);
        other->type = kid_type(other);
        if (n->type->basetype == STRUCT_TYPE)
            break;

        check_incompatible_types_error_msg(other, n->type, has_func_call);
        break;

    default:

        break;
    }

    int i;
    for (i = 0; i < n->nkids; i++)
    {
        // if (n->prodrule == (R_PSEUDOCALL + 1))
        // return;
        check_expr(n->kids[i], other, has_func_call);
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
        // check_incompatible_types_error_msg(n, return_type, 1);

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

        check_expr(n->kids[0], n->kids[2], has_func_call);
        break;

    case R_NON_DCL_STMT + 3:

        check_func_type(n->kids[1]);

        break;

    case LLITERAL:
        n->type = alctype(n->leaf->basetype);
        insert_sym(globals, n->leaf->text, n->type);
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

static void add_param(paramlist *params, type_ptr type, char *name)
{
    // paramlist temp = safe_malloc(sizeof(*temp));
    // temp->name = strdup(name);
    // temp->type = type;
    // temp->next = *params;
    // *params = temp;

    paramlist temp = safe_malloc(sizeof(*temp));
    paramlist last = *params;

    temp->name = strdup(name);
    temp->type = type;
    temp->next = NULL;

    if (*params == NULL)
    {
        *params = temp;
        return;
    }
    while (last->next != NULL)
        last = last->next;

    last->next = temp;
}

static void collect_params(tree_ptr n, paramlist *params)
{
    if (!n)
        return;
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
    if (expected->type->basetype == MAP_TYPE)
    {
        // if (!expected->type->u.m.elemtype)
        //     return;
        // if (expected->type->u.m.elemtype->basetype == found->type->basetype)
        //     return;
        return;
    }
    if (found->type->basetype == expected->type->basetype)
        return;
    fprintf(stderr, "ERROR: unexpected function call with `%s` of incompatible type `%s` at line %d, in file %s\n", found->name, typename(found->type), leaf->lineno, leaf->filename);
    fprintf(stderr, "Expected type `%s`\n", typename(expected->type));
    exit(3);
}

static void check_func_call_error(token_ptr leaf, paramlist params, type_ptr func_type)
{
    paramlist temp = params;
    paramlist func_params = func_type->u.f.parameters;
    while (func_params != NULL)
    {
        if (temp == NULL)
        {
            fprintf(stderr, "ERROR: unexpected function call with no argument at line %d, in file %s\n", leaf->lineno, leaf->filename);
            fprintf(stderr, "Expected type `%s`\n", typename(func_params->type));
            exit(3);
        }
        func_call_error_msg(leaf, temp, func_params);

        func_params = func_params->next;
        temp = temp->next;
    }
}

static void check_function_call(tree_ptr n)
{
    if (!n)
        return;
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
        func_type = kid_type(n->kids[0]);
        get_leaf(n, &leaf);

        if (func_type != NULL && leaf != NULL)
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
    check_common_dcl(n);
    check_expression(n);
}