#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "token.h"
#include "utils.h"

void yyerror(char *s);

// create a token struct
token_ptr create_token(int category, char *filename, int lineno, char *text, int ival, double dval, char *sval)
{
    token_ptr temp = safe_malloc(sizeof(*temp));
    // token_ptr temp;
    // temp = malloc(sizeof(*temp));
    // if (!temp)
    // {
    //     perror("malloc");
    //     return NULL;
    // }
    // memset(temp, 0, sizeof(*temp));
    temp->category = category;
    temp->filename = strdup(filename);
    temp->lineno = lineno;
    temp->text = strdup(text);
    temp->ival = ival;
    temp->dval = dval;
    temp->sval = strdup(sval);
    return temp;
}

// delete the token struct
void delete_token(token_ptr t)
{
    if (!t)
    {
        return;
    }

    free(t->filename);
    free(t->text);
    free(t->sval);
    free(t);
    t = NULL;
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