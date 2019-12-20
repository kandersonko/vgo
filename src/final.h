#if !defined(FINAL_H)
#define FINAL_H

#include "tac.h"

void emit_final_code(struct instr* ic, FILE *fp);

struct code
{
    char *s;
    struct code * next;
};

#endif // FINAL_H
