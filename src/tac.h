/*
 * Three Address Code - skeleton for CS 445
 */
#ifndef TAC_H
#define TAC_H

struct addr
{
    int region, offset;
};

/* Regions: */
#define REGION_GLOBAL 2001 /* can assemble as relative to the pc */
#define REGION_LOCAL 2002  /* can assemble as relative to the ebp */
#define REGION_CLASS 2003  /* can assemble as relative to the 'this' register */
#define REGION_LABEL 2004  /* pseudo-region for labels in the code region */
#define REGION_CONST 2005  /* pseudo-region for immediate mode constants */

struct instr
{
    int opcode;
    struct addr dest, src1, src2;
    struct instr *next;
};

/* Opcodes, per lecture notes */
#define OP_ADD 3001
#define OP_SUB 3002
#define OP_MUL 3003
#define OP_DIV 3004
#define OP_NEG 3005
#define OP_ASN 3006
#define OP_ADDR 3007
#define OP_LCONST 3008
#define OP_SCONST 3009
#define OP_GOTO 3010
#define OP_BLT 3011
#define OP_BLE 3012
#define OP_BGT 3013
#define OP_BGE 3014
#define OP_BEQ 3015
#define OP_BNE 3016
#define OP_BIF 3017
#define OP_BNIF 3018
#define OP_PARM 3019
#define OP_CALL 3020
#define OP_RET 3021

/* declarations/pseudo instructions */
#define DECL_GLOB 3051
#define DECL_PROC 3052
#define DECL_LOCAL 3053
#define DECL_LABEL 3054
#define DECL_END 3055

struct instr *gen(int, struct addr, struct addr, struct addr);
struct instr *concat(struct instr *, struct instr *);

#endif
