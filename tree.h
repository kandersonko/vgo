#ifndef TREE_H
#define TREE_H

#define MAX_KIDS_SIZE 10

#include "token.h"
#include <stdarg.h>

struct tree
{
    int prodrule;
    char *prodname;
    int nkids;
    struct tree **kids;
    struct token *leaf;
};

typedef struct tree *tree_ptr;

// int treeprint(struct tree *t, int depth);

void print_tree(tree_ptr ast, int depth);

void print_kids(struct tree **kids, int nkids);

void delete_tree(tree_ptr ast);

struct tree **create_tree_kids(int nkids, ...);

tree_ptr new_tree_node(int prodrule, char *prodname, int nkids, struct tree **kids, struct token *leaf);

#endif