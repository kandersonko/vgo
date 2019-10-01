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

#endif // UTILS_H
