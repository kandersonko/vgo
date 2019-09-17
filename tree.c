#include "tree.h"
#include "utils.h"

int treeprint(struct tree *t, int depth)
{
    int i;

    printf("%*s %s: %d\n", depth * 2, " ", humanreadable(t->prodrule), t->nkids);

    for (i = 0; i < t->nkids; i++)
        treeprint(t->kids[i], depth + 1);
}

void add_tree_node(tree_ptr t, int prodrule, char *prodname, int nkids, struct tree **kids, struct token *leaf)
{
}

tree_ptr new_tree_node(int prodrule, char *prodname, int nkids, struct tree **kids, struct token *leaf)
{
    tree_ptr t = safe_malloc(sizeof(*t));
    t->prodrule = prodrule;
    t->prodname = prodname;
    t->leaf = leaf;
    t->nkids = nkids;
    t->kids = kids;
}