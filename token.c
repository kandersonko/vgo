#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "token.h"
#include "vgo.tab.h"

token_ptr create_token(int category, char *filename, int lineno, char *text, int ival, int dval, char *sval)
{
    token_ptr temp;
    temp = malloc(sizeof(*temp));
    if (!temp)
    {
        perror("malloc");
        return NULL;
    }
    memset(temp, 0, sizeof(*temp));
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
    temp = malloc(sizeof(*temp));
    if (!temp)
    {
        perror("malloc");
        return NULL;
    }
    memset(temp, 0, sizeof(*temp));
    // temp->t = t;
    copy_token(temp, t);
    return temp;
}

tokenlist_ptr add_node(tokenlist_ptr root, token_ptr t)
{
    tokenlist_ptr temp = create_node(t);
    if (root == NULL)
    {
        root = temp;
    }
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
    {
        free(t);
        return;
    }
    free(t->filename);
    free(t->text);
    free(t->sval);
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
        delete_token(temp->t);
        // free(temp->t);
        free(temp);
    }
    free(root);
    root = NULL;
}

void copy_token(tokenlist_ptr root, token_ptr t)
{
    root->t = malloc(sizeof(*root->t));
    if (!root->t)
    {
        perror("malloc");
        return;
    }
    memset(root->t, 0, sizeof(*root->t));
    root->t->filename = t->filename;
    root->t->category = t->category;
    root->t->ival = t->ival;
    root->t->dval = t->dval;
    root->t->sval = t->sval;
    root->t->text = t->text;
    root->t->lineno = t->lineno;
    root->next = NULL;
}

char *replace_str(const char *s, const char *oldW,
                  const char *newW)
{
    char *result;
    int i, cnt = 0;
    int newWlen = strlen(newW);
    int oldWlen = strlen(oldW);

    // Counting the number of times old word
    // occur in the string
    for (i = 0; s[i] != '\0'; i++)
    {
        if (strstr(&s[i], oldW) == &s[i])
        {
            cnt++;

            // Jumping to index after the old word.
            i += oldWlen - 1;
        }
    }

    // Making new string of enough length
    result = (char *)malloc(i + cnt * (newWlen - oldWlen) + 1);
    if (!result)
    {
        perror("malloc");
        return NULL;
    }

    i = 0;
    while (*s)
    {
        // compare the substring with the result
        if (strstr(s, oldW) == s)
        {
            strcpy(&result[i], newW);
            i += newWlen;
            s += oldWlen;
        }
        else
            result[i++] = *s++;
    }

    result[i] = '\0';
    return result;
}

void print_list(tokenlist_ptr root)
{
    tokenlist_ptr current = root;
    printf("%8s\t%20s\t%10s\t%20s\t%10s\n", "Category", "Text", "Lineno", "Filename", "Ival/Sval");
    char *isval;
    while (current != NULL)
    {
        switch (current->t->category)
        {
        case LSTRING:
            isval = current->t->sval;
            break;

        default:
            isval = " ";
            break;
        }
        // TODO: Handle ival/sval ouput
        printf("%8d\t%20s\t%10d\t%20s\t%10s\n",
               current->t->category,
               current->t->text,
               current->t->lineno,
               current->t->filename,
               isval);

        current = current->next;
    }
}
