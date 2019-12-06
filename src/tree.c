#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "tree.h"
#include "type.h"
#include "utils.h"
#include "tac.h"

char *get_region_name(int region)
{
    char *s;
    switch (region)
    {
    case REGION_GLOBAL:
        s = "global";
        break;
    case REGION_LOCAL:
        s = "loc";
        break;
    case REGION_CONST:
        s = "const";
        break;
    case REGION_LABEL:
        s = "label";
        break;
    default:
        s = "NULL";
        break;
    }
    return s;
}

void print_tree(tree_ptr ast, int depth)
{
    if (!ast)
        return;

    printf("%*s | rule: %d | nkids: %d | label:%d\n", (int)strlen(ast->prodname) + depth, ast->prodname, ast->prodrule, ast->nkids, ast->label);

    if (ast->leaf)
    {
        printf("%*s -> ", depth + 6, "leaf");
        printf("cat: %d | type:%s width:%d label:%d | place: %s:%d | text: `%s` | lineno: %d | file: %s\n", ast->leaf->category,
               typename(alctype(ast->leaf->basetype)),
               ast->leaf->width,
               ast->leaf->label,
               get_region_name(ast->leaf->place.region),
               ast->leaf->place.offset, ast->leaf->text,
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
    // free(ast->type);
    // if (ast->symtab != NULL)
    // free(ast->symtab);
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

struct tree *new_leaf_node(int ruleno, char *prodname, struct token *leaf)
{
    return new_tree_node(ruleno, prodname, 0, NULL, leaf);
}

tree_ptr new_tree_node(int prodrule, char *prodname, int nkids, struct tree **kids, struct token *leaf)
{
    tree_ptr ast = safe_malloc(sizeof(*ast));
    ast->prodrule = prodrule;
    ast->prodname = strdup(prodname);
    ast->leaf = leaf;
    ast->nkids = nkids;
    ast->kids = kids;
    ast->type = alloc(1, sizeof(struct typeinfo));
    ast->type->basetype = 0;
    ast->basetype = 0;
    ast->width = 0;
    ast->label = 0;
    ast->code = alloc(1, sizeof(struct instr));
    ast->place.offset = 0;
    ast->place.region = 0;
    ast->symtab = alloc(1, sizeof(struct sym_table));
    return ast;
}

tree_ptr new_epsilon_tree(int prodrule, char *prodname)
{
    return new_tree_node(prodrule, prodname, 0, NULL, NULL);
}