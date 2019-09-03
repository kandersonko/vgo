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

struct tokenlist
{
    struct token *t;
    struct tokenlist *next;
};

typedef struct token *token_ptr;
typedef struct tokenlist *tokenlist_ptr;

extern token_ptr yytoken;

token_ptr create_token(int category, char *filename, int lineno, char *text, int ival, int dval, char *sval);

tokenlist_ptr create_node(token_ptr t);

tokenlist_ptr add_node(tokenlist_ptr root, token_ptr t);

void delete_token(token_ptr t);

void delete_list(tokenlist_ptr root);

void copy_token(tokenlist_ptr root, token_ptr t);

void print_list(tokenlist_ptr root);

#endif