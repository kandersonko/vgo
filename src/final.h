#if !defined(FINAL_H)
#define FINAL_H

#include "tac.h"

void emit_final_code(struct instr* ic, FILE *fp, char* filename, int output_asm);

struct code
{
    char *s;
    struct code * next;
};

#endif // FINAL_H