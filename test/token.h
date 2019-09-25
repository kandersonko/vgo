#ifndef TOKEN_H
#define TOKEN_H

struct token
{
    int category;   /* the integer code returned by yylex */
    char *text;     /* the actual string (lexeme) matched */
    int lineno;     /* the line number on which the token occurs */
    char *filename; /* the source file in which the token occurs */
    int ival;       /* for integer constants, store binary value here */
    double dval;    /* for real constants, store binary value here */
    char *sval;     /* for string constants, malloc space, de-escape, store */
                    /*    the string (less quotes and after escapes) here */
};

typedef struct token *token_ptr;

extern token_ptr yytoken;

token_ptr create_token(int category, char *filename, int lineno, char *text, int ival, double dval, char *sval);

void delete_token(token_ptr t);

char *replace_str(const char *s, const char *oldW,
                  const char *newW);

#endif