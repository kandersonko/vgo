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
