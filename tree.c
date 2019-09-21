#include <stdio.h>
#include <assert.h>
#include "tree.h"
#include "utils.h"

void print_tree(tree_ptr ast, int depth)
{
    if (!ast)
        return;
    int i;
    printf("Printing tree:\n");

    printf("rule %d:%s \tnkids: %d \tdepth: %d\n", ast->prodrule, ast->prodname, ast->nkids, depth);
    if (ast->leaf)
    {
        printf("\tleaf:");
        printf("\tcat: %d, \ttext: %s, \tlineno: %d, \tfile: %s\n",
               ast->leaf->category,
               ast->leaf->text,
               ast->leaf->lineno,
               ast->leaf->filename);
    }
    else
        printf("\tNo leaves!\n");

    for (i = 0; i < ast->nkids; i++)
        print_tree(ast->kids[i], depth + 1);
}

void print_kids(struct tree **kids, int nkids)
{
    int i;
    printf("Printing kid:\n");
    for (i = 0; i < nkids; i++)
    {
        if (kids[i])
            printf("kid: %d %s - %d\n", kids[i]->prodrule, kids[i]->prodname, kids[i]->nkids);
        else
            printf("no kid at index %d\n", i);
    }
}

void delete_tree(tree_ptr ast)
{
}

struct tree **create_tree_kids(int nkids, ...)
{
    assert(nkids > 0);
    va_list argp;
    va_start(argp, nkids);

    struct tree **kids = safe_malloc(nkids * sizeof(*kids));
    int i = 0;
    while (i < nkids)
    {
        // struct tree *kid = argp;
        kids[i] = va_arg(argp, struct tree *);
        i++;
    }
    va_end(argp);
    return kids;
}

tree_ptr new_tree_node(int prodrule, char *prodname, int nkids, struct tree **kids, struct token *leaf)
{
    tree_ptr ast = safe_malloc(sizeof(*ast));
    ast->prodrule = prodrule;
    ast->prodname = prodname;
    ast->leaf = leaf;
    ast->nkids = nkids;
    ast->kids = kids;
    return ast;
}
