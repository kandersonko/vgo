#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "token.h"

token_ptr create_token(int category, char *filename, int lineno, char *text, int ival, int dval, char *sval)
{
    token_ptr temp;
    temp = malloc(sizeof(struct token));
    if (!temp)
        return;
    temp->category = category;
    temp->filename = strdup(filename);
    temp->lineno = lineno;
    temp->text = strdup(text);
    temp->ival = ival;
    temp->dval = dval;
    temp->sval = strdup(sval);
    return temp;
}

tokenlist_ptr create_node(token_ptr t)
{
    tokenlist_ptr temp;
    temp = (tokenlist_ptr)malloc(sizeof(struct tokenlist));
    temp->t = (token_ptr)malloc(sizeof(struct token));
    temp->t = t;
    temp->next = NULL;
    return temp;
}

tokenlist_ptr add_node(tokenlist_ptr root, token_ptr t)
{
    tokenlist_ptr temp = create_node(t);
    if (root == NULL)
        root = temp;
    else
    {
        tokenlist_ptr current = root;
        while (current->next != NULL)
            current = current->next;
        current->next = temp;
    }
    return root;
}

void delete_token(token_ptr t)
{
    if (t == NULL)
        return;
    free(t->filename);
    free(t->text);
    free(t);
    t = NULL;
}

void delete_list(tokenlist_ptr root)
{
    tokenlist_ptr temp;

    while (root != NULL)
    {
        temp = root;
        root = root->next;
        free(temp->t);
        free(temp);
    }
}

void print_list(tokenlist_ptr root)
{
    tokenlist_ptr current = root;
    while (current != NULL)
    {
        // printf("[%s, %d, %d, %s, %f, %d, %s] -> ",
        //        current->t->filename,
        //        current->t->lineno,
        //        current->t->category,
        //        current->t->text,
        //        current->t->dval,
        //        current->t->ival,
        //        current->t->sval);
        printf("[%s] -> ",
               current->t->filename);
        current = current->next;
    }
    printf("NULL\n");
}
