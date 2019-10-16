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
        break;
    case FUNC_TYPE:
        t = alctype(FUNC_TYPE);
        t->u.f.st = new;
        t->u.f.name = strdup(s);
        break;
    default:
        break;
    }
    new->scope = t;

    // TODO: handle current scope when missing
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

/*
*Build Type From Prototype(syntax tree) Example
*/
void btfp(tree_ptr n)
{
    if (!n)
        return;
    for (int i = 0; i < n->nkids; i++)
        btfp(n->kids[i]);
    switch (n->prodrule)
    {
    // case LLITERAL:
    //     // n->type = get_type(CHAR_TYPE);
    //     printf("literal: %s\n", n->leaf->text);
    //     break;
    // case LNAME:
    //     n->basetype = get_basetype(n->leaf->text);
    //     n->type = alctype(n->basetype);
    //     printf("identifier: %s | %d | production: %s | rule %d | basetype: %d | typename: %s\n", n->leaf->text, n->leaf->category, n->prodname, n->prodrule, n->basetype, typename(n->type));
    //     break;
    case (R_PACKAGE + 1):
        printf("var decl\n");
        printf("production: %s | rule %d | nkids: %d | kids[0]: %s\n", n->prodname, n->prodrule, n->nkids, n->kids[1]->kids[0]->leaf->text);
        check_package_main(n->kids[1]);
        break;

    // case PARAMDECL_1:
    //     n->type = n->kids[0]->type;
    //     break;
    // case THINGY:
    //     n->type = n->kids[0]->type;
    //     break;
    // case PARAMDECL_2:
    //     n->type = clone_type(n->kids[1]->type);
    //     n->type->u.p.elemtype = n->kids[0]->type;
    //     break;
    // case PARAMDECLLIST_2:
    //     n->type = get_type(TUPLE);
    //     n->type->u.t.nelems = 1;
    //     n->type->u.t.elems = calloc(1, sizeof(struct typeinfo *));
    //     n->type->u.t.elems[0] = n->kids[0]->type;
    //     break;
    // case PARAMDECLLIST_1:
    //     n->type = get_type(TUPLE)

    //               /* consider whether left kids, guaranteed to be a PARAMDECLLIST,
    //      is guaranteed to be a tuple.  Maybe its not. */
    //               n->type->u.t.nelems = n->kids[0]->type->u.t.nelems + 1;
    //     n->type->u.t.elems = calloc(n->type->u.t.nelems,
    //                                 sizeof(struct typeinfo *));
    //     for (i = 0; i < n->kids[0]->type->u.t.nelems; i++)
    //         n->type->u.t.elems[i] = n->kids[0]->type->u.t.elems[i];
    //     n->type->u.t.elems[i] = n->kids[1]->type;

    //     break;
    // case INITIALIZER_DECL:
    //     n->type = get_type(FUNC)
    //                   n->type->u.f.returntype = get_type(DONT_KNOW);
    //     n->type->u.f.params = n->kids[1].type;
    //     break;
    // case SIMPLE_DECLARATION_1:
    //     n->type = clone_type(n->kids[1]->type);
    //     n->type->u.f.returntype = n->kids[0]->type;
    default:
        break;
    }
}

/*
 * Semantic analysis from syntax tree, VGo Edition
 */
// void semantic_anal(struct symtab *current_st, tree_ptr n)
// {
//     if (n == NULL)
//         return;
//     for (int i = 0; i < n->nkids; i++)
//         semantic_anal(current_st, n->kids[i]);
//     switch (n->prodrule)
//     {
//     case R_XFNDCL: /* whole function */
//         n->symtab = n->kids[1]->symtab;
//         populate_locals(n->symtab, n->kids[2]);
//         /*
//        * visit body to check for undeclared/redeclared
//        */
//         check_variable_uses(n->kids[2]);
//         break;
//     case R_FNDCL: /* function header */
//         char *name = get_func_name(n->kids[0]);
//         n->symtab = mk_symtab();

//         n->type = get_type(LFUNC);
//         n->type->u.f.returntype = n->kids[4]->type;
//         n->type->u.f.params = n->kids[2]->type;
//         n->type->u.f.symtab = n->symtab;
//         st_insert(current_st, name, n->type);

//         populate_params(n->symtab, n->kids[2]);
//         break;
//     }
// }

static char *get_functname(tree_ptr n)
{
    return n->kids[0]->kids[0]->leaf->text;
}

static void populate_vardcl(tree_ptr n)
{
    if (!n)
        return;
    int i;
    for (i = 0; i < n->nkids; i++)
        populate_vardcl(n->kids[i]);
    switch (n->prodrule)
    {
    case R_VARDCL:
        n->type = n->kids[1]->type; // synthesize
        n->kids[0]->type = n->type; // inherit
        insert_w_typeinfo(n->kids[0], current);

        break;
    // case R_NTYPE:
    //     n->type = n->kids[0]->type;
    //     break;
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
    int i;
    for (i = 0; i < n->nkids; i++)
        populate_body(n->kids[i]);
    switch (n->prodrule)
    {
    case R_COMMON_DCL:
        populate_vardcl(n->kids[1]);
        break;
    default:
        break;
    }
}

static void populate_function(tree_ptr n)
{
    char *functname;
    int i;
    for (i = 0; i < n->nkids; i++)
        populate_function(n->kids[i]);
    switch (n->prodrule)
    {
    case R_XFNDCL:
        functname = get_functname(n->kids[1]);
        printf("function %s\n", functname);
        enter_newscope(functname, FUNC_TYPE);
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
    char *functname;
    int i;
    for (i = 0; i < n->nkids; i++)
        populate_xdcl(n->kids[i]);
    switch (n->prodrule)
    {
    case R_XDCL_LIST + 1:
        printf("XDCL_LIST: %s | %d | %d | %d - %s\n", n->prodname, n->nkids, n->kids[0]->nkids, n->kids[1]->nkids, n->kids[1]->prodname);
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
        // enter_newscope("package main", UNKNOW_TYPE);
        // insert_w_typeinfo(n->kids[1], current);
        break;
    case LNAME:
        n->type = alctype(PACKAGE_TYPE);
        insert_sym(current, n->leaf->text, n->type);
        printf("PACKAGE: %s\n", n->leaf->text);
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
        printf("FOUND: %s %s\n", n->leaf->text, n->prodname);
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
    printf("ast tree: %s | %d | %s | %s | %s\n", n->prodname, n->nkids, n->kids[0]->prodname, n->kids[1]->prodname, n->kids[2]->prodname);
    populate_package(n->kids[0]);
    populate_imports(n->kids[1]);
    populate_xdcl(n->kids[2]);
    // int i;
    // for (i = 0; i < n->nkids; i++)
    //     populate(n->kids[i]);
    // switch (n->prodrule)
    // {
    // // case R_FILE:
    // //     // enter_newscope("globals", UNKNOW_TYPE);
    // //     break;
    // case R_PACKAGE + 1:
    //     check_package_main(n->kids[1]);
    //     enter_newscope("package main", UNKNOW_TYPE);
    //     // insert_w_typeinfo(n->kids[1], current);
    //     break;
    // case R_XFNDCL:
    //     functname = get_functname(n->kids[1]);
    //     printf("function %s\n", functname);
    //     enter_newscope(functname, FUNC_TYPE);
    //     populate_params(n->kids[1]);
    //     populate_body(n->kids[2]);
    //     popscope();
    //     break;
    // case R_COMMON_DCL:
    //     populate_vardcl(n->kids[1]);
    //     break;
    // // case R_VARDCL:
    // //     n->type = n->kids[1]->type; // synthesize
    // //     n->kids[0]->type = n->type; // inherit
    // //     insert_w_typeinfo(n->kids[0], current);
    // //     break;
    // // case R_NTYPE:
    // //     n->type = n->kids[0]->type;
    // //     break;
    // // case R_SYM:
    // //     n->type = n->kids[0]->type;
    // //     break;
    // // case LNAME:
    // //     n->basetype = get_basetype(n->leaf->text);
    // //     // TODO: lookup
    // //     printf("basetype: %d\n", n->basetype);
    // //     n->type = alctype(n->basetype);
    // //     break;
    // default:
    //     // printf("default: %d %p %p %s\n", n->type->basetype, n->type, n, n->prodname);
    //     break;
    //     // case ARG_TYPE_LIST_1: /* ATL: arg_type */
    //     //     break;
    //     // case ARG_TYPE_LIST_2: /* ATL: ATL ',' arg_type */
    //     //     break;
    //     // case ARG_TYPE_1: /* AT: name_or_type */
    //     //     break;
    //     // case ARG_TYPE_2: /* AT: sym name_or_type */
    //     //     break;
    //     // case ARG_TYPE_3: /* AT: sym dotdotdot */
    //     //     break;
    //     // case ARG_TYPE_4: /* AT: dotdotdot */
    //     //     break
    //     // }
    // }
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
        if (n->kids[i])
        {
            n->kids[i]->type = n->type;
            insert_w_typeinfo(n->kids[i], st);
        }
    }
    switch (n->prodrule)
    {
    case LNAME:
        // st_insert(st, n->leaf->text, n->type);
        insert_sym(st, n->leaf->text, n->type);
        // printf("tree: %s %s\n", n->leaf->text, typename(n->type));
        break;
    }
}

void dovariabledeclarator(tree_ptr n, type_ptr t)
{
    n = n->kids[0]; /* get variabledeclaratorid */
    if (n->prodrule == R_NAME)
    {
        yyerror("arrays unimplemented");
        exit(0);
    }
    insert_sym(current, n->kids[0]->leaf->text, t);
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
                printsymbols(ste->type->u.f.st, level + 1);
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
        fprintf(stderr, "%s:%d: ", n->leaf->filename, n->leaf->lineno);
    }
    fprintf(stderr, "%s", s);
    // if (n && n->id == IDENT)
    //     fprintf(stderr, " %s", n->u.leaf.text);
    // fprintf(stderr, "\n");
    errors++;
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
    case R_FNRES:
        n->type->u.f.returntype = alctype(UNKNOW_TYPE);
        break;
    case R_FNRES + 2:
        n->type->u.f.returntype = n->kids[1]->type->u.f.returntype;
        break;
    case R_ARG_TYPE_LIST + 1:
        // n->kids[0]->type = n->kids[2]->type;
        populate_params(n->kids[2]);
        break;
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
        // printf("ARG default: %s\n", n->prodname);
        break;
    }
}

/*
 * Find local declarations in a compound statement.
 * Illustrates a more general tree traversal that calls a
 * more specific (helper) tree traversal when it finds an
 * subtree type of interest (DECLARATION triggers populatesymbols).
 */
// void populatelocals(tree_ptr t)
// {
//     int i;
//     while (1)
//     {
//         switch (t->label)
//         {
//         case COMPOUND_STATEMENT:
//             return;
//         case COMPOUND_STATEMENT - 1:
//         case COMPOUND_STATEMENT - 3:
//             t = t->u.n.kids[0];
//             break;
//         case COMPOUND_STATEMENT - 2:
//             return;
//         case DECLARATION:
//         {
//             populatesymbols(t);
//             return;
//         }
//         default:
//      if (is_nonterminal(t) {
//                 for (i = 0; i < t->u.n.nkids; i++)
//                     populatelocals(t->u.n.kids[i]);
// 	    }
// 	 return;
//         }
//     }
// }

/*
 * Having defined a struct or class for type representation, someone
 * has to constuct those types from information given in parse tree nodes.
 */
// ctypeptr synthesize_type(tree_ptr t)
// {
//     int i;
//     ctypeptr t1;

//     if (t == NULL)
//         return error_type;

//     if (is_nonterminal(t))
//     {
//         for (i = 0; i < t->u.n.nkids; i++)
//         {
//             t1 = synthesize_type(t->u.n.kids[i]);
//             /*
// 	  * Need to check grammar: are there any points where type
// 	  * information is combined from multiple children??
// 	  */
//             if (t1 != error_type)
//             {
//                 t->type = t1;
//                 return t1;
//             }
//         }
//     }

//     switch (t->label)
//     {
//     case INT:
//     case INT_LITERAL:
//         t->type = integer_type;
//         return integer_type;
//     default:
//         return error_type;
//     }
// }

/*
 * A more specialized tree traversal, only called in a known subset of
 * the tree, it is still written to recurse on children so it can skip
 * over enclosing non-terminal nodes and trigger on two production rules
 * for function definition, and one production rule for declarations.
 * In these cases, it will call helper functions like get_funcname(),
 * and perform symbol table insertions. Since functions have local
 * scopes, they must be traversed and their symbols inserted into new
 * symbol tables.  Global variable "current" tracks the current scope.
 */
// void populatesymbols(tree_ptr t)
// {
//     int i, typ;
//     char *s;
//     if (t == NULL)
//         return;
//     switch (t->label)
//     {
//     case FUNCTION_DEFINITION:
//         if (s = get_funcname(t->u.n.kids[0]))
//         {
//             struct st_entry *ste;
//             ctypeptr typ = mktype(FUNCTION_T);
//             ste = insert(current, s, typ);
//             if (ste == NULL)
//             {
//                 printf("redeclared function %s\n", s);
//                 return;
//             }
//             current = mksym(current);
//             ste->type->u.f.sym = current;
//             populateparams(t->u.n.kids[0]);
//             populatelocals(t->u.n.kids[1]);
//             current = current->parent;
//         }
//         return;
//     case FUNCTION_DEFINITION - 1:
//         if (s = get_funcname(t->u.n.kids[1]))
//         {
//             struct st_entry *ste;
//             ctypeptr typ = mktype(FUNCTION_T);
//             ste = insert(current, s, typ);
//             if (ste == NULL)
//             {
//                 printf("redeclared function %s\n", s);
//             }
//             current = mksym(current);
//             ste->type->u.f.sym = current;
//             populateparams(t->u.n.kids[1]);
//             populatelocals(t->u.n.kids[2]);
//             current = current->parent;
//         }
//         return;
//     case DECLARATION:
//         /* child 0 is a declaration specifiers containing a base type */
//         t->type = synthesize_type(t->u.n.kids[0]);

//         /* child 1 is an init_declarator_list, with symbols to insert */
//         populate_init_declarators(t->u.n.kids[1], t->type);
//         break;
//     }

//     if (t->label > 0)
//     {
//     }
//     else
//     {
//         for (i = 0; i < t->u.n.nkids; i++)
//             populatesymbols(t->u.n.kids[i]);
//     }
// }

// void populate_init_declarators(tree_ptr t, ctypeptr typ)
// {
//     switch (t->label)
//     {
//     case INIT_DECLARATOR_LIST:
//         populate_init_declarators(t->u.n.kids[0], typ);
//         populate_init_declarators(t->u.n.kids[1], typ);
//         break;
//     case INIT_DECLARATOR:
//         warn("initializer ignored in C370!", t);
//         populate_init_declarators(t->u.n.kids[0], typ);
//         break;
//     case DECLARATOR: /* it is a pointer and a direct_declarator */
//         warn("pointers not supported in C370!", t);
//         populate_init_declarators(t->u.n.kids[1], typ);
//         break;
//     case IDENTIFIER:
//         if (insert(current, t->u.t->text, typ) == NULL)
//         {
//             error("illegal redeclaration", t);
//         }
//         break;
//     case DIRECT_DECLARATOR: /* parenthesized direct_declarator */
//         populate_init_declarators(t->u.n.kids[0], typ);
//         break;
//     case DIRECT_DECLARATOR - 1: /* direct_declarator [] */
//         warn("empty arraytypes not supported!", t);
//         populate_init_declarators(t->u.n.kids[0], typ);
//         break;
//     case DIRECT_DECLARATOR - 2: /* direct_declarator [siz] */
//         warn("arrays not yet implemented!", t);
//         typ = mkarraytype(1, typ);
//         populate_init_declarators(t->u.n.kids[0], typ);
//         break;
//     case DIRECT_DECLARATOR - 3: /* [ siz ] */
//         warn("anonymous array not supported", t);
//         break;
//     case DIRECT_DECLARATOR - 4: /* f ( parmtypes ) */
//         warn("function not yet implemented", t);
//         break;
//     case DIRECT_DECLARATOR - 5: /* f (  ) */
//         warn("function not yet implemented", t);
//         break;
//     case DIRECT_DECLARATOR - 6: /* f ( idlist ) */
//         warn("function not yet implemented", t);
//         break;
//     }
// }

// void checkdeclared(tree_ptr t)
// {
//     int i;
//     char *s;

//     if (t == NULL)
//         return;
//     switch (t->label)
//     {
//     case INT_LITERAL:
//         t->type = integer_type;
//         return;
//     case MULTIPLICATIVE_EXPRESSION:
//     case MULTIPLICATIVE_EXPRESSION - 1:
//     case MULTIPLICATIVE_EXPRESSION - 2:
//     case ADDITIVE_EXPRESSION:
//     case ADDITIVE_EXPRESSION - 1:
//     {
//         checkdeclared(t->u.n.kids[0]);
//         checkdeclared(t->u.n.kids[1]);
//         t->type = compare_types(t->u.n.kids[0]->type, t->u.n.kids[1]->type, PLUS);
//         if (t->type == error_type)
//         {
//             error("type conflict", t);
//         }
//     }
//         return;
//     case PRIMARY_EXPRESSION:
//     {
//         /* this treenode denotes a variable reference */
//         struct st_entry *ste;
//         if ((ste = lookup_variable(t->u.n.kids[0]->u.t->text)) == NULL)
//         {
//             error("undeclared variable", t->u.n.kids[0]);
//             t->type = error_type;
//         }
//         else
//         {
//             t->type = ste->type;
//         }
//     }
//     case COMPOUND_STATEMENT:
//         return; /* empty body */
//     case COMPOUND_STATEMENT - 1:
//         return; /* only variables, no statements */
//     case COMPOUND_STATEMENT - 2:
//         checkdeclared(t->u.n.kids[0]);
//         return;
//     case COMPOUND_STATEMENT - 3:
//         checkdeclared(t->u.n.kids[1]);
//         return;
//     case FUNCTION_DEFINITION:
//         if (s = get_funcname(t->u.n.kids[0]))
//         {
//             struct st_entry *ste;
//             struct st *sav;
//             ste = lookup(current, s);
//             if (ste == NULL)
//             {
//                 fprintf(stderr, "can't find symtab for function %s\n", s);
//                 return;
//             }
//             sav = current;
//             current = ste->type->u.f.sym;
//             checkdeclared(t->u.n.kids[1]);
//             current = sav;
//         }
//         return;
//     case FUNCTION_DEFINITION - 1:
//         if (s = get_funcname(t->u.n.kids[1]))
//         {
//             struct st_entry *ste;
//             struct st *sav;
//             ste = lookup(current, s);
//             if (ste == NULL)
//             {
//                 fprintf(stderr, "can't find symtab for function %s\n", s);
//                 return;
//             }
//             sav = current;
//             current = ste->type->u.f.sym;
//             checkdeclared(t->u.n.kids[2]);
//             current = sav;
//         }
//         return;
//     case DECLARATION:
//         break;
//     }

//     if (t->label > 0)
//     {
//     }
//     else
//     {
//         for (i = 0; i < t->u.n.nkids; i++)
//             checkdeclared(t->u.n.kids[i]);
//     }
// }
