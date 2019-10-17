#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include "tree.h"
#include "symtab.h"
#include "semantic.h"
#include "go.tab.h"
#include "type.h"
#include "rules.h"

int errors, nerrors;
void yyerror(char *);
/*
 * what-all should be done automatically when a new scope is entered?
 * mainly we are creating a new empty local symbol table.
 * but if we are entering this function/method/class type into the global
 * symbol table, someone has to extract its signature
 */

// TODO: have global scope

void enter_newscope(char *s, int basetype)
{
    sym_table_ptr new = new_st(30);
    type_ptr t = NULL;
    // t = (type == STRUCT_TYPE) ? alc(s, new) : alcmethodtype(NULL, NULL, new);
    switch (basetype)
    {
    case STRUCT_TYPE:
        t = alctype(STRUCT_TYPE);
        t->u.s.st = new;
        t->u.s.name = strdup(s);
        break;
    case FUNC_TYPE:
        t = alctype(FUNC_TYPE);
        t->u.f.st = new;
        t->u.f.name = strdup(s);
        break;
    default:
        t = alctype(basetype);
        break;
    }
    new->scope = t;

    // TODO: handle current scope when missing
    insert_sym(current, s, t);
    pushscope(new);
}

static void enter_func_scope(char *s, type_ptr returntype)
{
    sym_table_ptr new = new_st(30);
    type_ptr t = alctype(FUNC_TYPE);
    t->u.f.st = new;
    t->u.f.returntype = returntype;
    t->u.f.name = strdup(s);
    new->scope = t;
    insert_sym(current, s, t);
    pushscope(new);
}

static void check_package_main(tree_ptr n)
{
    switch (n->prodrule)
    {
    case R_SYM:
        if (strcmp(n->kids[0]->leaf->text, "main") != 0)
        {
            fprintf(stderr, "ERROR: found `%s` at line %d in file %s\n", n->kids[0]->leaf->text, n->kids[0]->leaf->lineno, n->kids[0]->leaf->filename);
            yyerror("ERROR: package name should be `main`\n");
        }
        break;

    default:
        break;
    }
}

static void check_vardcl(tree_ptr n)
{
    sym_entry_ptr entry = lookup_st(current, n->leaf->text);
    if (entry != NULL)
    {
        if (strcmp(entry->text, n->leaf->text) == 0)
        {
            fprintf(stderr, "ERROR: redeclaration of `%s` at line %d, in file %s\n", n->leaf->text, n->leaf->lineno, n->leaf->filename);
            exit(3);
        }
    }
}

static char *get_functname(tree_ptr n)
{
    return n->kids[0]->kids[0]->leaf->text;
}

static void populate_struct(tree_ptr n)
{
    if (!n)
        return;
    int i;
    for (i = 0; i < n->nkids; i++)
        populate_struct(n->kids[i]);
    switch (n->prodrule)
    {
    case R_STRUCTDCL:
        n->type = n->kids[1]->type; // synthesize
        n->kids[0]->type = n->type; // inherit
        insert_w_typeinfo(n->kids[0], current);
        break;
    case R_SYM:
        n->type = n->kids[0]->type;
        break;
    case LNAME:
        n->basetype = get_basetype(n->leaf->text);
        n->type = alctype(n->basetype);
        break;
    default:
        break;
    }
}

static void populate_typedcl(tree_ptr n, char *typedclname)
{
    if (!n)
        return;
    int i;
    for (i = 0; i < n->nkids; i++)
        populate_typedcl(n->kids[i], typedclname);

    if (strcmp(n->prodname, "structtype") == 0)
    {
        if (n->nkids == 5)
        {
            enter_newscope(typedclname, STRUCT_TYPE);
            populate_struct(n->kids[2]);
        }
    }

    // switch (n->prodrule)
    // {
    // case R_VARDCL:
    //     break;
    // default:
    //     break;
    // }
}

static int get_array_size(tree_ptr n)
{
    static int size = 0;
    if (!n)
        return 0;
    int i;
    for (i = 0; i < n->nkids; i++)
    {
        size = get_array_size(n->kids[i]);
    }
    if ((n->nkids == 0) && strcmp(n->prodname, "pexpr_no_paren") == 0)
    {
        int size = atoi(n->leaf->text);
        return size;
    }
    return size;
}

static void populate_vardcl(tree_ptr n)
{
    if (!n)
        return;

    char *typedclname;
    int i;
    for (i = 0; i < n->nkids; i++)
        populate_vardcl(n->kids[i]);

    switch (n->prodrule)
    {
    case R_VARDCL:
    case R_VARDCL + 1:
    case R_CONSTDCL:
    case R_CONSTDCL1 + 1:
        n->type = n->kids[1]->type; // synthesize
        n->kids[0]->type = n->type; // inherit
        insert_w_typeinfo(n->kids[0], current);
        break;
    case R_TYPEDCL:
        typedclname = n->kids[0]->kids[0]->leaf->text;
        check_vardcl(n->kids[0]->kids[0]);
        populate_typedcl(n, typedclname);
        popscope();
        break;
    case R_OTHERTYPE:
        n->type = alctype(ARRAY_TYPE);
        n->type->u.a.elemtype = n->kids[3]->type;
        int size = get_array_size(n);
        n->type->u.a.size = size;
        break;
    case R_OTHERTYPE + 2:
        n->type = alctype(MAP_TYPE);
        n->type->u.m.indextype = n->kids[2]->type;
        n->type->u.m.elemtype = n->kids[4]->type;
        break;
    case R_SYM:
        n->type = n->kids[0]->type;
        break;
    case LNAME:
        n->basetype = get_basetype(n->leaf->text);
        n->type = alctype(n->basetype);
        break;
    default:
        break;
    }
}

void populate_params(tree_ptr n)
{

    if (!n)
        return;
    int i;
    for (i = 0; i < n->nkids; i++)
    {
        populate_params(n->kids[i]);
    }

    switch (n->prodrule)
    {
    case R_ARG_TYPE + 1:
        n->kids[0]->type = n->kids[1]->type;
        insert_w_typeinfo(n->kids[0], current);
        break;
    case R_NTYPE:
        n->type = n->kids[0]->type;
        break;
    case R_SYM:
        n->type = n->kids[0]->type;
        break;
    case LNAME:
        n->basetype = get_basetype(n->leaf->text);
        n->type = alctype(n->basetype);
        break;
    default:
        break;
    }
}

static void populate_body(tree_ptr n)
{
    if (!n)
        return;
    int i;
    for (i = 0; i < n->nkids; i++)
        populate_body(n->kids[i]);
    if (strcmp(n->prodname, "common_dcl") == 0)
    {
        populate_vardcl(n);
    }
}

static void get_functrettype(tree_ptr n, type_ptr *type)
{
    int basetype;
    int i;
    for (i = 0; i < n->nkids; i++)
        get_functrettype(n->kids[i], type);
    switch (n->prodrule)
    {
    case LNAME:
        basetype = get_basetype(n->leaf->text);
        *type = alctype(basetype);
        break;

    default:
        break;
    }
}

static void populate_function(tree_ptr n)
{

    if (!n)
        return;
    char *functname;
    type_ptr returntype = NULL;
    int i;
    for (i = 0; i < n->nkids; i++)
        populate_function(n->kids[i]);
    switch (n->prodrule)
    {
    case R_XFNDCL:
        functname = get_functname(n->kids[1]);

        get_functrettype(n->kids[1]->kids[4], &returntype);
        n->type->u.f.returntype = returntype;
        enter_func_scope(functname, returntype);
        populate_params(n->kids[1]);
        populate_body(n->kids[2]);
        popscope();
        break;
    default:
        break;
    }
}

static void populate_xdcl(tree_ptr n)
{
    int i;
    for (i = 0; i < n->nkids; i++)
        populate_xdcl(n->kids[i]);
    switch (n->prodrule)
    {
    case R_XDCL_LIST + 1:
        // printf("XDCL_LIST: %s | %d | %d | %d - %s\n", n->prodname, n->nkids, n->kids[0]->nkids, n->kids[1]->nkids, n->kids[1]->prodname);
        if (strcmp(n->kids[1]->prodname, "xfndcl") == 0)
        {
            populate_function(n->kids[1]);
        }
        else if (strcmp(n->kids[1]->prodname, "common_dcl") == 0)
        {
            populate_vardcl(n->kids[1]);
        }
        break;
    default:
        break;
    }
}

static void populate_package(tree_ptr n)
{
    int i;
    for (i = 0; i < n->nkids; i++)
        populate_package(n->kids[i]);
    switch (n->prodrule)
    {
    case R_PACKAGE + 1:
        check_package_main(n->kids[1]);
        n->type = alctype(PACKAGE_TYPE);
        enter_newscope("main", PACKAGE_TYPE);
        // insert_w_typeinfo(n->kids[1], current);
        break;
    case LNAME:
        n->type = alctype(PACKAGE_TYPE);
        insert_sym(current, n->leaf->text, n->type);
        break;
    default:
        break;
    }
}

static void populate_imports(tree_ptr n)
{
    if (!n)
        return;
    int i;
    for (i = 0; i < n->nkids; i++)
        populate_imports(n->kids[i]);

    switch (n->prodrule)
    {
    case LLITERAL:
    case LNAME:
        n->type = alctype(IMPORT_TYPE);
        insert_sym(current, n->leaf->text, n->type);
        break;
    default:
        break;
    }
}

// TODO: check with another tree traversal variable declaration
void populate(tree_ptr n)
{
    // TODO: check that type is not defined first
    // TODO: show scope information (for local & global declartion)
    // TODO: preorder to popscope/pushscope (2 switches)
    // char *functname;
    if (n == NULL)
        return;
    populate_package(n->kids[0]);
    populate_imports(n->kids[1]);
    populate_xdcl(n->kids[2]);
}

/*
 * "inherited attribute" for type could go down by copying from
 * parent node to child nodes, or by passing a parameter. Which is better?
 */
void insert_w_typeinfo(tree_ptr n, sym_table_ptr st)
{
    if (n == NULL)
        return;
    int i;
    for (i = 0; i < n->nkids; i++)
    {
        n->kids[i]->type = n->type;
        insert_w_typeinfo(n->kids[i], st);
    }
    switch (n->prodrule)
    {
    case LNAME:
        // st_insert(st, n->leaf->text, n->type);
        check_vardcl(n);
        insert_sym(st, n->leaf->text, n->type);
        break;
    }
}

void printsymbols(sym_table_ptr st, int level)
{
    int i, j;
    sym_entry_ptr ste;
    if (st == NULL)
        return;
    for (i = 0; i < st->nbuckets; i++)
    {
        for (ste = st->buckets[i]; ste; ste = ste->next)
        {
            for (j = 0; j < level; j++)
                printf("  ");
            printf("%s", ste->text);
            if (!ste->type)
            {
                continue;
            }
            switch (ste->type->basetype)
            {
            case INT_TYPE:
            case BOOL_TYPE:
            case FLOAT64_TYPE:
            case STRING_TYPE:
            case IMPORT_TYPE:
            case PACKAGE_TYPE:
            case UNKNOW_TYPE:
                printf("\t%s\n", typename(ste->type));
                break;
            case FUNC_TYPE:
                printf("\tfunction -> %s\n", typename(ste->type->u.f.returntype));
                printsymbols(ste->type->u.f.st, level + 1);
                break;
            case STRUCT_TYPE:
                printf("\tstruct\n");
                printsymbols(ste->type->u.s.st, level + 1);
                break;
            case ARRAY_TYPE:
                printf("\tarray\n");
                printf("\tsize: %d\n", ste->type->u.a.size);
                printf("\telement type: %s\n", typename(ste->type->u.a.elemtype));
                break;
            case MAP_TYPE:
                printf("\tmap\n");
                printf("\tindex type: %s\n", typename(ste->type->u.m.indextype));
                printf("\telement type: %s\n", typename(ste->type->u.m.elemtype));
                break;
            }
        }
    }
}

void semanticerror(char *s, tree_ptr n)
{
    while (n)
        n = n->kids[0];
    if (n)
    {
        fprintf(stderr, "%s:%d: %s", n->leaf->filename, n->leaf->lineno, n->leaf->text);
    }
    fprintf(stderr, "%s", s);
    // if (n && n->id == IDENT)
    //     fprintf(stderr, " %s", n->u.leaf.text);
    // fprintf(stderr, "\n");
    errors++;
}
