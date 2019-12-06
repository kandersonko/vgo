#ifndef TOKEN_H
#define TOKEN_H
#include "tac.h"

struct token
{
    int category;   /* the integer code returned by yylex */
    int basetype;   // for typechecking
    int width;
    int label;
    char *text;     /* the actual string (lexeme) matched */
    int lineno;     /* the line number on which the token occurs */
    char *filename; /* the source file in which the token occurs */
    int ival;       /* for integer constants, store binary value here */
    int bval;       /* for boolean values 1 -> true, 0 -> false, -1 -> not set */
    double dval;    /* for real constants, store binary value here */
    char *sval;     /* for string constants, malloc space, de-escape, store */
                    /*    the string (less quotes and after escapes) here */
    struct addr place;
};

typedef struct token *token_ptr;

extern token_ptr yytoken;

token_ptr create_token(int category, char *filename, int lineno, char *text, int ival, int bval, double dval, char *sval, int basetype);

void delete_token(token_ptr t);

#endif