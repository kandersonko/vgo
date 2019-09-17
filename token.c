#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "token.h"
#include "vgo.tab.h"

void yyerror(char *s);

// create a token struct
token_ptr create_token(int category, char *filename, int lineno, char *text, int ival, double dval, char *sval)
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

// create a node of the linkedlist
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
    copy_token(temp, t);
    return temp;
}

// add a node to the end of the linkedlist
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

// delete the token struct
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

// delete the linkedlist
void delete_list(tokenlist_ptr root)
{
    tokenlist_ptr temp;

    while (root != NULL)
    {
        temp = root;
        root = root->next;
        delete_token(temp->t);
        free(temp);
    }
    free(root);
    root = NULL;
}

// copy a token struct to a node of the linkedlist
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

// code found from Geeks for Geeks website
// replace a set of characters of the old string from characters from the new string
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

// print a node (token struct) of the linkedlist
static void print_node(tokenlist_ptr current)
{
    printf("%8d\t%20s\t%10d\t%20s\t",
           current->t->category,
           current->t->text,
           current->t->lineno,
           current->t->filename);
}

// print the linkedlist
void print_list(tokenlist_ptr root)
{
    tokenlist_ptr current = root;
    printf("%8s\t%20s\t%10s\t%20s\t%10s\n", "Category", "Text", "Lineno", "Filename", "Ival/Sval");
    while (current != NULL)
    {
        print_node(current);
        // Handle ival/sval output
        switch (current->t->category)
        {
        case LSTRING:
            printf("%10s\n", current->t->sval);
            break;
        case LINT:
        case LBINARY:
        case LOCTAL:
        case LHEX:
            printf("%10d\n", current->t->ival);
            break;
        case LREAL:
            printf("%10f\n", current->t->dval);
            break;
        default:
            printf("%10s\n", " ");
            break;
        }

        current = current->next;
    }
}