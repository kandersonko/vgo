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

void *alloc(int n, size_t size)
{
    char *ptr = calloc(n, size);
    if (ptr == NULL)
    {
        fprintf(stderr, "alloc(%d): out of memory\n", (int)n);
        exit(-1);
    }
    return ptr;
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

// remove \t \n and quotes (") from string
char *strip_chars(char *text)
{
    char *s1, *s2, *s3;
    s1 = replace_str(text, "\\t", " ");
    s2 = (s1 != NULL) ? replace_str(s1, "\\n", "") : text;
    s3 = (s2 != NULL) ? replace_str(s2, "\"", "") : text;

    free(s1);
    free(s2);
    return s3;
}