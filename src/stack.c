// code adapted from
// Adam Gavlá: https://gist.github.com/gavlak/9f7fd88f8e07e233ffafe3e1bd0c431f
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include "type.h"
#include "utils.h"

stack_ptr init_stack(int initial_size)
{
    stack_ptr stack = safe_malloc(sizeof(*stack));
    type_ptr *elements;

    elements = alloc(initial_size, sizeof(*elements));

    stack->elements = elements;
    stack->current_size = initial_size;
    stack->top = -1;
    printf("STACK INIT: %p %p| %d , %d\n", stack, stack->elements, stack->current_size, stack->top);
    return stack;
}

void destroy_stack(stack_ptr stack)
{
    if (stack == NULL)
        return;
    free(stack->elements);

    stack->elements = NULL;
    stack->current_size = 0;
    stack->top = -1;
}

void resize_stack(stack_ptr stack)
{
    type_ptr *resized_elements;
    resized_elements = (type_ptr *)alloc(stack->current_size * 2, sizeof(*resized_elements));

    memcpy(resized_elements, stack->elements, sizeof(type_ptr) * stack->top + 1);

    free(stack->elements);
    stack->elements = resized_elements;
    stack->current_size = stack->current_size * 2;
}

int is_stack_empty(stack_ptr stack)
{
    if (stack->top < 0)
        return 1;
    else
        return 0;
}

int is_stack_full(stack_ptr stack)
{
    if (stack == NULL)
        return 0;
    if (stack->top == stack->current_size - 1)
        return 1;
    else
        return 0;
}

void push_stack(stack_ptr stack, type_ptr data)
{
    if (stack == NULL)
        return;

    if (is_stack_full(stack) == 1)
        resize_stack(stack);

    stack->top = stack->top + 1;
    stack->elements[stack->top] = data;
}

type_ptr peek_stack(stack_ptr stack)
{
    if (stack == NULL)
        return NULL;
    return stack->elements[stack->top];
}

type_ptr pop_stack(stack_ptr stack)
{
    if (stack == NULL)
        return NULL;
    if (is_stack_empty(stack) == 0)
    {
        type_ptr data = stack->elements[stack->top];
        stack->top = stack->top - 1;
        return data;
    }

    fprintf(stderr, "Pop failed! Stack is empty\n");
    exit(1);
}
