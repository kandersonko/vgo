/*
 * Code adapted from lecture notes
 * by Dr. J
 * http://www2.cs.uidaho.edu/~jeffery/courses/445/lecture.html
 */
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
#include "utils.h"

static void print_params(paramlist params, int nparams)
{
    paramlist current = params;
    printf("\tnumber of params: %d\n", nparams);
    while (current != NULL)
    {
        printf("\tparam %s: %s\n", current->name, typename(current->type));
        current = current->next;
    }
}

void enter_newscope(char *s, int basetype)
{
    sym_table_ptr new = new_st(30);
    type_ptr t = NULL;
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
    case PACKAGE_TYPE:
        t = alctype(PACKAGE_TYPE);
        t->u.f.st = new;
        t->u.f.name = strdup(s);
        break;
    default:
        t = alctype(basetype);
        break;
    }
    new->scope = t;

    // push_stack(current->children, t);
    push_stack(new->children, current->scope);
    // printf("CHILDREN: %d | %s\n", current->children->current_size, typename(peek_stack(current->children)));

    insert_sym(current, s, t);
    pushscope(new);
}

static void enter_func_scope(char *s, type_ptr returntype, paramlist params, int nparams)
{
    sym_table_ptr new = new_st(30);
    type_ptr t = alctype(FUNC_TYPE);
    t->u.f.st = new;
    t->u.f.returntype = returntype;
    t->u.f.name = strdup(s);
    t->u.f.parameters = params;
    t->u.f.nparams = nparams;
    new->scope = t;

    // push_stack(current->children, t);
    push_stack(new->children, current->scope);
    // printf("CHILDREN: %d | %s | %d\n", current->children->current_size, typename(peek_stack(current->children)), t->basetype);

    insert_sym(current, s, t);
    pushscope(new);
}

int is_keyword_type(char *s)
{
    char *keywords[] = {"int", "float64", "string", "bool", "if", "else", "true", "false"};
    int size = (int)ARRAY_SIZE(keywords);
    int i;
    for (i = 0; i < size; i++)
    {
        if (strcmp(s, keywords[i]) == 0)
        {
            return 1;
        }
    }
    return 0;
}

static void undeclared_error(tree_ptr n)
{
    if (!n)
        return;

    int i;
    for (i = 0; i < n->nkids; i++)
    {
        undeclared_error(n->kids[i]);
    }

    if (n->prodrule == LNAME)
    {
        if (is_keyword_type(n->leaf->text))
            return;
        sym_entry_ptr entry;
        // for (temp = current; temp != NULL; temp = temp->parent)
        // {
        //     entry = lookup_st(temp, n->leaf->text);

        //     if (entry != NULL)
        //         return;
        // }

        sym_table_ptr temp;
        for (temp = current; temp != NULL; temp = temp->parent)
        {
            entry = lookup_in_type(temp->scope, n->leaf->text);
            if (entry != NULL)
                return;

            entry = lookup_st(temp, n->leaf->text);
            if (entry != NULL)
                return;
        }

        if (entry == NULL)
        {
            fprintf(stderr, "ERROR: use of undeclared variable `%s` at line %d, in file %s\n", n->leaf->text, n->leaf->lineno, n->leaf->filename);
            exit(3);
        }
    }
}

static void check_package_main(tree_ptr n)
{
    switch (n->prodrule)
    {
    case R_SYM:
        if (strcmp(n->kids[0]->leaf->text, "main") != 0)
        {
            fprintf(stderr, "ERROR: found `%s` at line %d in file %s\n", n->kids[0]->leaf->text, n->kids[0]->leaf->lineno, n->kids[0]->leaf->filename);
            fprintf(stderr, "ERROR: package name should be `main`\n");
            exit(3);
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

static void check_undeclared(tree_ptr n)
{
    if (!n)
        return;

    int i;
    for (i = 0; i < n->nkids; i++)
    {
        check_undeclared(n->kids[i]);
    }

    char *names[] = {"pseudocall", "non_dcl_stmt", "non_dcl_stmt", "if_stmt", "else", "loop_body", "elseif_list", "stmt_list", "for_stmt", "for_body", "stmt"};
    int size = (int)ARRAY_SIZE(names);
    int j;
    for (j = 0; j < size; j++)
    {
        if (strcmp(n->prodname, names[j]) == 0)
        {
            undeclared_error(n);
            break;
        }
    }
}

static void get_kid_type(tree_ptr n, type_ptr *t)
{
    if (!n)
        return;
    int i;
    for (i = 0; i < n->nkids; i++)
    {
        get_kid_type(n->kids[i], t);
    }

    sym_entry_ptr entry;

    switch (n->prodrule)
    {
    case LNAME:
        if (is_keyword_type(n->leaf->text))
        {
            *t = alctype(get_basetype(n->leaf->text));
            break;
        }
        entry = lookup_st(current, n->leaf->text);
        if (entry != NULL)
        {
            *t = entry->type;
            break;
        }
        entry = lookup(current, n->leaf->text);
        if (entry != NULL)
        {
            *t = entry->type;

            break;
        }
        entry = lookup_in_type(current->scope, n->leaf->text);
        if (entry != NULL)
        {
            *t = entry->type;
        }
        else
        {
            *t = alctype(UNKNOW_TYPE);
        }

        break;

    case LLITERAL:
        *t = alctype(n->leaf->basetype);

        break;

    default:
        break;
    }
}

type_ptr kid_type(tree_ptr kid)
{
    type_ptr type;
    get_kid_type(kid, &type);
    return type;
}

static void get_varname(tree_ptr n, char **name)
{
    int i;
    for (i = 0; i < n->nkids; i++)
    {
        get_varname(n->kids[i], name);
    }

    switch (n->prodrule)
    {
    case LNAME:
        *name = n->leaf->text;
        check_vardcl(n);
        break;

    default:
        break;
    }
}

static void vardcl(tree_ptr n, char *varname)
{
    int i;
    for (i = 0; i < n->nkids; i++)
    {
        vardcl(n->kids[i], varname);
    }

    sym_entry_ptr entry;

    char *typedclname;

    type_ptr type;

    switch (n->prodrule)
    {
    case R_VARDCL:
    case R_VARDCL + 1:
    case R_CONSTDCL:
    case R_CONSTDCL1 + 1:
        type = kid_type(n->kids[1]);
        if (type != NULL)
        {
            if (type->basetype != UNKNOW_TYPE)
                n->type = type;
            else
                n->type = n->kids[1]->type; // synthesize
        }
        else
        {
            n->type = n->kids[1]->type; // synthesize
        }
        n->kids[0]->type = n->type; // inherit
        insert_w_typeinfo(n->kids[0], current);
        break;
    case R_TYPEDCL:
        // TODO: CHECK
        typedclname = n->kids[0]->kids[0]->leaf->text;
        check_vardcl(n->kids[0]->kids[0]);
        populate_typedcl(n, typedclname);
        printf("FOUND STRUCT: %s\n", typedclname);
        popscope();
        break;
    case R_OTHERTYPE: // array
        n->type = alctype(ARRAY_TYPE);
        n->type->u.a.elemtype = n->kids[3]->type;
        int size = get_array_size(n);
        n->type->u.a.size = size;
        printf("FOUND ARRAY: %s\n", varname);
        insert_sym(current, varname, n->type);
        break;
    case R_OTHERTYPE + 2: // map
        n->type = alctype(MAP_TYPE);
        n->type->u.m.indextype = n->kids[2]->type;
        n->type->u.m.elemtype = n->kids[4]->type;
        printf("FOUND MAP: %s\n", varname);
        insert_sym(current, varname, n->type);
        break;
    case R_NTYPE:
        n->type = n->kids[0]->type;
        break;
    case R_DOTNAME + 1:
        n->type = n->kids[0]->type;
        n->kids[2]->type = n->type;
        insert_w_typeinfo(n->kids[2], current);
        break;
    case R_SYM:
        n->type = n->kids[0]->type;

        break;
    case LNAME:
        // case LLITERAL:
        entry = lookup_st(current, n->leaf->text);
        if (entry != NULL)
        {
            n->type = entry->type;
            break;
        }
        entry = lookup_in_type(current->scope, n->leaf->text);
        if (entry != NULL)
        {
            n->type = entry->type;
            break;
        }
        else if (is_keyword_type(n->leaf->text))
        {
            n->basetype = get_basetype(n->leaf->text);
            n->type = alctype(n->basetype);
        }
        else
        {
            n->type = alctype(UNKNOW_TYPE);
        }
        break;
    case LLITERAL:
        n->basetype = get_basetype(n->leaf->text);
        n->type = alctype(n->basetype);
        break;
    default:
        break;
    }
    // if (strcmp(n->prodname, "expr") == 0)
    //     check_undeclared(n);
}

static void populate_vardcl(tree_ptr n)
{
    if (!n)
        return;

    int i;
    for (i = 0; i < n->nkids; i++)
    {
        populate_vardcl(n->kids[i]);
    }

    // type_ptr type;

    static char *varname;

    printf("DEFAULT: %s\n", n->prodname);

    char *typedclname;

    switch (n->prodrule)
    {
    case R_VARDCL:
    case R_VARDCL + 1:
    case R_CONSTDCL:
    case R_CONSTDCL1 + 1:
        get_varname(n->kids[0], &varname);
        vardcl(n, varname);
        break;
    case R_TYPEDCL:
        // TODO: CHECK
        typedclname = n->kids[0]->kids[0]->leaf->text;
        check_vardcl(n->kids[0]->kids[0]);
        populate_typedcl(n, typedclname);
        printf("FOUND STRUCT: %s\n", typedclname);
        popscope();
        break;
    default:
        break;
    }
}

static void check_arg_undeclared(tree_ptr n)
{
    if (!n)
        return;

    int i;
    for (i = 0; i < n->nkids; i++)
    {
        check_arg_undeclared(n->kids[i]);
    }

    switch (n->prodrule)
    {
    case LNAME:
        undeclared_error(n);
        break;

    default:
        break;
    }
}

static paramlist create_param(tree_ptr n)
{
    paramlist temp;
    temp = safe_malloc(sizeof(*temp));
    memset(temp, 0, sizeof(*temp));
    temp->name = strdup(n->leaf->text);
    temp->type = n->type;
    temp->next = NULL;
    return temp;
}

static paramlist add_param(paramlist root, tree_ptr n)
{
    paramlist temp = create_param(n);
    if (root == NULL)
    {
        root = temp;
    }
    else
    {
        paramlist current = root;
        while (current->next != NULL)
            current = current->next;
        current->next = temp;
    }
    return root;
}

static void insert_parameters(tree_ptr n, paramlist *params, int *nparams)
{
    if (n == NULL)
        return;
    int i;
    for (i = 0; i < n->nkids; i++)
    {
        n->kids[i]->type = n->type;
        insert_parameters(n->kids[i], params, nparams);
    }

    switch (n->prodrule)
    {
    case LNAME:
        check_vardcl(n);
        *nparams = *nparams + 1;
        *params = add_param(*params, n);
        break;
    }
}

void populate_params(tree_ptr n, paramlist *params, int *nparams)
{

    if (!n)
        return;
    int i;
    for (i = 0; i < n->nkids; i++)
    {
        populate_params(n->kids[i], params, nparams);
    }

    sym_entry_ptr entry = NULL;

    switch (n->prodrule)
    {
    case R_ARG_TYPE + 1:
        n->kids[0]->type = n->kids[1]->type;
        insert_parameters(n->kids[0], params, nparams);
        check_arg_undeclared(n->kids[1]);
        break;
    case R_ARG_TYPE_LIST + 1:
        n->kids[0]->type = n->kids[2]->type;
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
    case R_NTYPE:
        n->type = n->kids[0]->type;
        break;
    case R_DOTNAME + 1:
        n->type = n->kids[0]->type;
        n->kids[2]->type = n->type;
        insert_parameters(n->kids[2], params, nparams);

        break;
    case R_TYPEDCL:
        n->type = n->kids[1]->type;
        n->kids[0]->type = n->type;
        insert_parameters(n->kids[1], params, nparams);
        break;
    case R_SYM:
        n->type = n->kids[0]->type;
        // insert_w_typeinfo(n->kids[0], current);

        break;
    case LLITERAL:
        n->basetype = get_basetype(n->leaf->text);
        n->type = alctype(n->basetype);
        // printf("LLITERAL: %s %s\n", n->leaf->text, typename(n->type));
        break;
    case LNAME:
        // printf("LNAME: %s %s\n", n->leaf->text, typename(n->type));
        entry = lookup_st(current->parent, n->leaf->text);
        if (entry != NULL)
        {
            n->type = entry->type;
        }
        else
        {
            n->basetype = get_basetype(n->leaf->text);
            n->type = alctype(n->basetype);
        }
        break;
    default:
        break;
    }
    // if (strcmp(n->prodname, "arg_type_list") == 0)
    //     check_undeclared(n);
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
        // check_undeclared(n);
    }

    // char *names[] = {"pseudocall", "non_dcl_stmt", "non_dcl_stmt", "if_stmt", "else", "loop_body", "elseif_list", "stmt_list", "for_stmt", "for_body", "stmt"};
    // int size = (int)ARRAY_SIZE(names);
    // int j;
    // for (j = 0; j < size; j++)
    // {
    //     if (strcmp(n->prodname, names[j]) == 0)
    //     {
    //         undeclared_error(n);
    //         break;
    //     }
    // }
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
    paramlist params = NULL;
    int nparams = 0;
    int i;
    for (i = 0; i < n->nkids; i++)
        populate_function(n->kids[i]);
    switch (n->prodrule)
    {
    case R_XFNDCL:
        functname = get_functname(n->kids[1]);
        get_functrettype(n->kids[1]->kids[4], &returntype);
        n->type->u.f.returntype = returntype;
        populate_params(n->kids[1], &params, &nparams);
        enter_func_scope(functname, returntype, params, nparams);
        populate_body(n->kids[2]);
        // check_undeclared(n->kids[2]);
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
        if (strcmp(n->kids[1]->prodname, "xfndcl") == 0)
        {
            populate_function(n->kids[1]);
        }
        else if (strcmp(n->kids[1]->prodname, "common_dcl") == 0)
        {
            populate_vardcl(n->kids[1]);
        }
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
        // insert_sym(current, n->leaf->text, n->type);
        break;
    default:
        break;
    }
}

static void populate_imports(tree_ptr n)
{
    char *importname;
    if (!n)
        return;
    int i;
    for (i = 0; i < n->nkids; i++)
        populate_imports(n->kids[i]);

    switch (n->prodrule)
    {
    case LLITERAL:
    case LNAME:
        importname = strip_chars(n->leaf->text);
        n->type = alctype(IMPORT_TYPE);
        insert_sym(current, importname, n->type);
        break;
    default:
        break;
    }
}

void populate(tree_ptr n)
{
    if (n == NULL)
        return;

    // TODO: fmt has a scope and builtins function (e.g. Println)
    // math/rand, time, fmt, check vgo specs
    insert_sym(current, "fmt", alctype(IMPORT_TYPE));

    // TODO: add builtins function args types and return types

    insert_sym(current, "Println", alctype(IMPORT_TYPE));
    insert_sym(current, "println", alctype(IMPORT_TYPE));
    insert_sym(current, "print", alctype(IMPORT_TYPE));

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
        // check_vardcl(n);
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
                printf("\tfunction\n");
                printf("\treturntype: %s\n", typename(ste->type->u.f.returntype));
                print_params(ste->type->u.f.parameters, ste->type->u.f.nparams);
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
