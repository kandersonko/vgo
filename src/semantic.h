/*
 * Code adapted from lecture notes
 * by Dr. J
 * http://www2.cs.uidaho.edu/~jeffery/courses/445/lecture.html
 */
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
#define popscope()                                             \
    do                                                         \
    {                                                          \
        push_stack(current->parent->children, current->scope); \
        current = current->parent;                             \
    } while (0)

extern int errors;
extern int nerrors;

extern void printsymbols(sym_table_ptr st, int level);

void populate_symbol_tables(tree_ptr ast);
void populatesymbols(tree_ptr t);

void populate(tree_ptr n);
void populate_params(tree_ptr n);
void insert_w_typeinfo(tree_ptr n, sym_table_ptr st);

type_ptr kid_type(tree_ptr kid);
#endif // SEMANTIC_H
