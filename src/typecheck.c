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

// static void check_function_call(tree_ptr n)
// {
//     int i;
//     for (i = 0; i < n->nkids; i++)
//     {
//         check_function_call(n->kids[i]);
//     }

//     switch (n->prodrule)
//     {
//     case R_EXPR_OR_TYPE_LIST + 1:
//         break;

//     case LLITERAL:
//         printf("LLITERAL: %s\n", n->leaf->text);
//         break;

//     default:
//         printf("DEFAULT: %s\n", n->prodname);
//         break;
//     }
// }

static void type_error_msg(tree_ptr n, type_ptr t)
{
    fprintf(stderr, "ERROR: unexpected `%s` of incompatible type `%s` at line %d, in file %s\n", n->leaf->text, typename(n->type), n->leaf->lineno, n->leaf->filename);
    fprintf(stderr, "Expected type `%s`\n", typename(t));
    exit(3);
}

static void type_error(tree_ptr n, type_ptr t)
{
    if (n == NULL)
        return;

    int i;
    for (i = 0; i < n->nkids; i++)
    {
        type_error(n->kids[i], t);
    }
    switch (n->prodrule)
    {
    case R_OTHERTYPE:
        type_error(n->kids[1], n->kids[3]->type);
        break;

    case LLITERAL:
        // if (n->leaf->basetype != t->basetype)
        // {
        //     type_error_msg(n, t);
        // }
        break;

    case LNAME:
        // if (n->type->basetype != t->basetype)
        // {
        //     type_error_msg(n, t);
        // }
        break;

    default:
        // printf("DEFAULT: %s\n", n->prodname);
        break;
    }
}

static void incompatible_types_error_msg(tree_ptr n, type_ptr type)
{
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

    printf("N TYPE DEFAULT: %s\n", n->prodname);
    type_ptr type;

    switch (n->prodrule)
    {
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
        check_declaration(n->kids[i]);
    }

    printf("DEFAULT: %s\n", n->prodname);

    char *typedclname;

    // type_ptr type;

    switch (n->prodrule)
    {
    case R_VARDCL + 1:
    case R_CONSTDCL:
        check_ntype(n->kids[1]);
        // type = kid_type(n->kids[1]);
        // n->type = type;
        n->type = n->kids[1]->type;
        type_error(n->kids[3], n->type);
        break;

    case R_VARDCL + 2:
    case R_CONSTDCL + 2:
        // type = kid_type(n->kids[0]);
        // n->type = type;
        n->type = n->kids[0]->type;
        type_error(n->kids[2], n->type);
        break;

    case R_START_COMPLIT:
        break;

    case R_TYPEDCL:
        typedclname = n->kids[0]->kids[0]->leaf->text;
        printf("FOUND OTHERTYPE: %s\n", typedclname);
        break;
        // case R_PEXPR_NO_PAREN + 5:
        //     printf("FOUND ITEM: %s\n", n->prodname);
        //     break;

    case LNAME:
        printf("LNAME: %s %s\n", n->leaf->text, typename(n->type));
        // insert_sym(current, n->leaf->text, n->type);
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

static void check_expression(tree_ptr n)
{
    if (n == NULL)
        return;
    int i;
    for (i = 0; i < n->nkids; i++)
    {
        check_expression(n->kids[i]);
    }

    // printf("DEFAULT: %s\n", n->prodname);

    type_ptr type;

    sym_entry_ptr entry;

    switch (n->prodrule)
    {
    case R_SIMPLE_STMT + 1:
    case R_SIMPLE_STMT + 2:
    case R_SIMPLE_STMT + 3:
        type = kid_type(n->kids[0]);
        printf("CHECK TYPES: %d %s\n", n->prodrule, typename(type));
        check_incompatible_types_error_msg(n->kids[2], type);
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
        type = kid_type(n->kids[0]);
        printf("BASE TYPES: %d %s\n", n->prodrule, typename(type));
        check_incompatible_types_error_msg(n->kids[2], type);

        break;

    case LNAME:
        // printf("LNAME: %s | type: %s\n", n->leaf->text, typename(alctype(n->leaf->basetype)));
        // n->type = alctype(n->leaf->basetype);
        entry = lookup_st(current, n->leaf->text);
        if (entry != NULL)
        {
            n->type = entry->type;
        }
        printf("NAME TYPE: %s for %s | sval: %s | dval: %f | ival: %d\n", typename(n->type), n->leaf->text, n->leaf->sval, n->leaf->dval, n->leaf->ival);

        break;

    case LLITERAL:
        n->type = alctype(n->leaf->basetype);
        n->basetype = n->leaf->basetype;
        printf("LITERAL TYPE: %s for %s | sval: %s | dval: %f | ival: %d\n", typename(n->type), n->leaf->text, n->leaf->sval, n->leaf->dval, n->leaf->ival);
        break;

    default:
        break;
    }
}

void typecheck(tree_ptr n)
{
    printf("TYPE CHECk: %s\n", n->prodname);
    // check_function_call(n);
    check_common_dcl(n);
    check_expression(n);
}