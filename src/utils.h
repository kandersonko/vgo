#if !defined(UTILS_H)
#define UTILS_H

enum ErrorCode
{
    KEYWORD_NOT_SUPPORTED = -1,
    OPERATOR_NOT_SUPPORTED = -2,
    UNTERMINATED_STRING = -3,
    CCOMMENT_NOT_ALLOWED = -4,
    UNTERMINATED_CCOMMENT = -5,
    INVALID_CHARACTER = -6,
    ILLEGAL_RUNE = -7,
    INVALID_VARNAME = -8,
    IMAGINARY_NOT_SUPPORTED = -9,
};

void *safe_malloc(size_t size);

// sample code from lecture notes (Dr. J)
void *alloc(int n, size_t size); /* calloc + check for NULL */

char *replace_str(const char *s, const char *oldW,
                  const char *newW);

char *strip_chars(char *text);

#endif // UTILS_H
