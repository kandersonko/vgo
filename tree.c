#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "tree.h"
#include "utils.h"

void print_tree(tree_ptr ast, int depth)
{
    if (!ast)
        return;

    // TODO: maybe print only node with a leaf node

    // TODO: indent by depth number

    printf("%*s | rule: %d | nkids: %d\n", (int)strlen(ast->prodname) + depth, ast->prodname, ast->prodrule, ast->nkids);

    // TODO: don't need the depth in printing

    if (ast->leaf)
    {
        printf("%*s -> ", depth + 6, "leaf");
        printf("cat: %d | text: %s | lineno: %d | file: %s\n", ast->leaf->category,
               ast->leaf->text,
               ast->leaf->lineno,
               ast->leaf->filename);
    }
    // else
    //     printf("%*d\tNo leaves!\n", depth + 1, depth);

    int i;
    for (i = 0; i < ast->nkids; i++)
        print_tree(ast->kids[i], depth + 1);
}

void delete_tree(tree_ptr ast)
{
    if (!ast)
    {
        return;
    }

    int i;
    for (i = 0; i < ast->nkids; i++)
        delete_tree(ast->kids[i]);

    delete_token(ast->leaf);
    free(ast->kids);
    free(ast->prodname);
    free(ast);
    ast = NULL;
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
    ast->prodname = strdup(prodname);
    ast->leaf = leaf;
    ast->nkids = nkids;
    ast->kids = kids;
    return ast;
}
