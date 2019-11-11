// code adapted from
// Adam Gavlá: https://gist.github.com/gavlak/9f7fd88f8e07e233ffafe3e1bd0c431f

#if !defined(STACK_H)
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "type.h"

typedef struct stack
{
    type_ptr *elements;
    int current_size;
    int top;
} * stack_ptr;

stack_ptr init_stack(int initial_size);
void destroy_stack(stack_ptr stack);
void resize_stack(stack_ptr stack);
int is_stack_empty(stack_ptr stack);
int is_stack_full(stack_ptr stack);
void push_stack(stack_ptr stack, type_ptr data);
type_ptr peek_stack(stack_ptr stack);
type_ptr pop_stack(stack_ptr stack);

#endif // STACK_H
