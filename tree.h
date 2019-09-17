#ifndef TREE_H
#define TREE_H

#include "token.h"

struct tree
{
    int prodrule;
    char *prodname;
    int nkids;
    struct tree **kids;
    struct token *leaf;
};

typedef struct tree *tree_ptr;

int treeprint(struct tree *t, int depth);

void add_tree_node(tree_ptr t, int prodrule, char *prodname, int nkids, struct tree **kids, struct token *leaf);

tree_ptr new_tree_node(int prodrule, char *prodname, int nkids, struct tree **kids, struct token *leaf);

#endif