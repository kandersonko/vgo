#if !defined(CODEGEN_H)
#define CODEGEN_H

#include "tree.h"

void codegen(tree_ptr t);

struct addr newtemp(tree_ptr n);

void emit_ic_code(tree_ptr n, FILE *fp, char* filename, int output_ir);


#endif // CODEGEN_H
