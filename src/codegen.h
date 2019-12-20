#if !defined(CODEGEN_H)
#define CODEGEN_H

#include "tree.h"

void codegen(tree_ptr t);

struct addr newtemp(tree_ptr n);

void print_ic_code(tree_ptr n);

#endif // CODEGEN_H
