#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include "utils.h"

void yyerror(char *s);

void *safe_malloc(size_t size)
{
    void *ptr = malloc(size);
    if (!ptr)
    {
        fprintf(stderr, "malloc failed for size: %d!\n", (int)size);
        exit(EXIT_FAILURE);
    }
    return ptr;
}

// TODO: print the pointer and token - and check

void print_error(int tokentype)
{
    switch (tokentype)
    {
    case KEYWORD_NOT_SUPPORTED:
        yyerror("Go keyword not in VGo!\n");
        break;
    case OPERATOR_NOT_SUPPORTED:
        yyerror("Go operator not in VGo!\n");
        break;
    case UNTERMINATED_STRING:
        yyerror("ERROR: unterminated string found!\n");
        break;
    case CCOMMENT_NOT_ALLOWED:
        yyerror("C comments not allowed in VGo!\n");
        break;
    case UNTERMINATED_CCOMMENT:
        yyerror("Unterminated C comments!\nC comments not allowed in VGo!\n");
    case INVALID_CHARACTER:
        yyerror("Invalid character, not allowed in VGo!\n");
        break;
    case ILLEGAL_RUNE:
        yyerror("Invalid rune literal, not allowed in VGo!\n");
        break;
    case INVALID_VARNAME:
        yyerror("Invalid variable length, a length greater than 12 is not allowed in VGo!\n");
        break;
    case IMAGINARY_NOT_SUPPORTED:
        yyerror("Imaginary numbers are not allowed in VGo!\n");
        break;
    default:
        break;
    }
}