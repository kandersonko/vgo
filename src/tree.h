#ifndef TREE_H
#define TREE_H

#define MAX_KIDS_SIZE 10

#include "token.h"
#include "type.h"
#include "symtab.h"
#include <stdarg.h>

struct tree
{
    int prodrule;
    char *prodname;
    int nkids;
    int basetype;
    struct typeinfo *type;
    struct sym_table *symtab;
    struct tree **kids;
    struct token *leaf;
};

typedef struct tree *tree_ptr;

void print_tree(tree_ptr ast, int depth);

void delete_tree(tree_ptr ast);

struct tree **create_tree_kids(int nkids, ...);

struct tree *new_leaf_node(int ruleno, char *prodname, struct token *leaf);

tree_ptr new_tree_node(int prodrule, char *prodname, int nkids, struct tree **kids, struct token *leaf);

tree_ptr new_epsilon_tree(int prodrule, char *prodname);

#endif