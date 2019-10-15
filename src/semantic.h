#if !defined(SEMANTIC_H)
#define SEMANTIC_H

#include "symtab.h"
#include "tree.h"

#define pushscope(stp)         \
    do                         \
    {                          \
        stp->parent = current; \
        current = stp;         \
    } while (0)
#define popscope()                 \
    do                             \
    {                              \
        current = current->parent; \
    } while (0)

extern int errors;
extern int nerrors;

extern void printsymbols(sym_table_ptr st, int level);

void populate_symbol_tables(tree_ptr ast);
void populatesymbols(tree_ptr t);
void populate_init_declarators(tree_ptr t, type_ptr type);

void populate(tree_ptr n);
void populate_params(tree_ptr n);
void insert_w_typeinfo(tree_ptr n, sym_table_ptr st);

void dovariabledeclarator(tree_ptr n, type_ptr t);
void semanticerror(char *s, tree_ptr n);

void btfp(tree_ptr n);

type_ptr get_type(int type);

#endif // SEMANTIC_H
