/*
 * Three Address Code - skeleton for CS 445
 */
#include <stdio.h>
#include <stdlib.h>
#include "tac.h"
#include "utils.h"
#include "tree.h"
#include "rules.h"
#include "go.tab.h"

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
    code->name = NULL;
    return code;
}

struct instr *gen_label(int opcode, struct addr dest)
{
    struct instr *code = safe_malloc(sizeof(struct instr));
    code->opcode = opcode;
    code->dest = dest;
    code->next = NULL;
    struct addr new_addr;
    new_addr.offset = -1;
    new_addr.region = -1;
    code->src1 = new_addr;
    code->src2 = new_addr;
    code->name = NULL;
    return code;
}

struct instr *gen_proc(int opcode, struct addr dest, char* name)
{
    struct instr *code = safe_malloc(sizeof(struct instr));
    code->opcode = opcode;
    code->dest = dest;
    code->next = NULL;
    struct addr new_addr;
    new_addr.offset = -1;
    new_addr.region = -1;
    code->src1 = new_addr;
    code->src2 = new_addr;
    code->name = strdup(name);
    printf("NAME: %s\n", code->name);
    return code;
}

// struct instr *gen_label(int opcode, struct addr dest, struct addr src1, struct addr src2)
// {
//     struct instr *code = safe_malloc(sizeof(struct instr));
//     code->opcode = opcode;
//     code->dest = dest;
//     code->src1 = src1;
//     code->src2 = src2;
//     code->next = NULL;
//     return code;
// }

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

char *get_opcode_name(int opcode)
{
    char *s;
    switch (opcode)
    {
    case OP_ADD:
        s = "addq";
        break;
    case OP_SUB:
        s = "subq";
        break;
    case OP_MUL:
        s = "mulq";
        break;
    case OP_DIV:
        s = "divq";
        break;
    case OP_NEG:
        s = "uminus";
        break;
    case OP_ASN:
        s = "movq";
        break;
    case OP_ADDR:
        s = "addr";
        break;
    case OP_LCONST:
        s = "lconst";
        break;
    case OP_SCONST:
        s = "sconst";
        break;
    case OP_GOTO:
        s = "goto";
        break;
    case OP_BLT:
        s = "bltq";
        break;
    case OP_BLE:
        s = "bleq";
        break;
    case OP_BGT:
        s = "bgtq";
        break;
    case OP_BGE:
        s = "bgeq";
        break;
    case OP_BEQ:
        s = "beqq";
        break;
    case OP_BNE:
        s = "bneq";
        break;
    case OP_BIF:
        s = "bifq";
        break;
    case OP_BNIF:
        s = "bnifq";
        break;
    case OP_PARM:
        s = "param";
        break;
    case OP_CALL:
        s = "call";
        break;
    case OP_RET:
        s = "ret";
        break;
    case OP_UMINUS:
        s = "uminus";
        break;
    case OP_AND:
        s = "andq";
        break;
    case OP_OR:
        s = "orq";
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
    case REGION_STRING:
        s = "string";
        break;
    default:
        s = "NULL";
        break;
    }
    return s;
}
