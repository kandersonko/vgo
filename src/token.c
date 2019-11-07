#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "token.h"
#include "utils.h"

void yyerror(char *s);

// create a token struct
token_ptr create_token(int category, char *filename, int lineno, char *text, int ival, int bval, double dval, char *sval, int basetype)
{
    token_ptr temp = safe_malloc(sizeof(*temp));
    temp->category = category;
    temp->basetype = basetype;
    temp->filename = strdup(filename);
    temp->lineno = lineno;
    temp->text = strdup(text);
    temp->ival = ival;
    temp->bval = bval;
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
