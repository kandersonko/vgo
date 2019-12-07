/*
 * Three Address Code - skeleton for CS 445
 */
#include <stdio.h>
#include <stdlib.h>
#include "tac.h"
#include "utils.h"

// TODO: create  this function
// void print_code(struct instr * code)

struct instr *gen(int opcode, struct addr dest, struct addr src1, struct addr src2)
{
    struct instr *code = safe_malloc(sizeof(struct instr));
    code->opcode = opcode;
    code->dest = dest;
    code->src1 = src1;
    code->src2 = src2;
    code->next = NULL;
    return code;
}

struct instr *copylist(struct instr *l)
{
    if (l == NULL)
        return NULL;
    struct instr *lcopy = gen(l->opcode, l->dest, l->src1, l->src2);
    lcopy->next = copylist(l->next);
    return lcopy;
}

struct instr *append(struct instr *l1, struct instr *l2)
{
    if (l1 == NULL)
        return l2;
    struct instr *ltmp = l1;
    while (ltmp->next != NULL)
        ltmp = ltmp->next;
    ltmp->next = l2;
    return l1;
}

struct instr *concat(struct instr *l1, struct instr *l2)
{
    return append(copylist(l1), l2);
}

/*
#define OP_ADD 3001
*/
char *get_opcode_name(int opcode)
{
    char *s;
    switch (opcode)
    {
    case OP_ADD:
        s = "add";
        break;

    default:
        s = "OPCODE";
        break;
    }
    return s;
}

char *get_region_name(int region)
{
    char *s;
    switch (region)
    {
    case REGION_GLOBAL:
        s = "global";
        break;
    case REGION_LOCAL:
        s = "loc";
        break;
    case REGION_CONST:
        s = "const";
        break;
    case REGION_LABEL:
        s = "label";
        break;
    default:
        s = "NULL";
        break;
    }
    return s;
}
