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
