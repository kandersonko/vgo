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

// static void get_symtab(tree_ptr n, sym_table_ptr *st)
// {
//     if (!n)
//         return;
//     int i;
//     for (i = 0; i < n->nkids; i++)
//     {
//         get_symtab(n->kids[i], st);
//     }

//     switch (n->prodrule)
//     {
//     case LNAME:
//     case LLITERAL:
//         *st = find_symtab(n->leaf->text);
//         break;

//     default:
//         break;
//     }
// }

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
    case OP_SUB:
        s = "sub";
        break;
    case OP_MUL:
        s = "mul";
        break;
    case OP_DIV:
        s = "div";
        break;
    case OP_NEG:
        s = "uminus";
        break;
    case OP_ASN:
        s = "mov";
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
        s = "blt";
        break;
    case OP_BLE:
        s = "ble";
        break;
    case OP_BGT:
        s = "bgt";
        break;
    case OP_BGE:
        s = "bge";
        break;
    case OP_BEQ:
        s = "beq";
        break;
    case OP_BNE:
        s = "bne";
        break;
    case OP_BIF:
        s = "bif";
        break;
    case OP_BNIF:
        s = "bnif";
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
        s = "and";
        break;
    case OP_OR:
        s = "or";
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
