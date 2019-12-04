#include <stdio.h>
#include <stdlib.h>

#include "tree.h"
#include "tac.h"

// TODO: starting
/*
    1) start with the leaf node
    2) .place generation for symtab
    3) .label generation
    4) add attributes .true & .false for booleans expressions


    Generating labels:
    1) for functions:
        generate label for
        - function name/start of function block
    2) for if/elseif/else stmts
        generate labels .true & .false for conditions
        generate labels for then parts

    #options 2
    generate .first & .follow


    // use tree level & node kids number to generate unique labels
*/

static void generate_label(tree_ptr t)
{
}

static void generate_location(tree_ptr t)
{
}

static void generate_true_false(tree_ptr t)
{
}

static int newlabel()
{
    static int counter = 0;
    ++counter;
    return counter;
}

static void newtemp()
{
}

// for main
static void generate_header(tree_ptr n)
{
}

static void generate_ender(tree_ptr n)
{
}

void codegen(tree_ptr t)
{
    int i, j;
    if (t == NULL)
        return;

    /*
    * this is a post-order traversal, so visit kidsren first
    */
    for (i = 0; i < t->nkids; i++)
        codegen(t->kids[i]);

    /*
    * back from kidsren, consider what we have to do with
    * this node. The main thing we have to do, one way or
    * another, is assign t->code
    */
    switch (t->label)
    {
    case OP_ADD:
    {
        struct instr *g;
        t->code = concat(t->kids[0]->code, t->kids[1]->code);
        g = gen(OP_ADD, t->address,
                t->kids[0]->address, t->kids[1]->address);
        t->code = concat(t->code, g);
        break;
    }
    /*
    * ... really, a bazillion cases, up to one for each
    * production rule (in the worst case)
    */
    default:
        /* default is: concatenate our kids children's code */
        t->code = NULL;
        for (i = 0; i < t->nkids; i++)
            t->code = concat(t->code, t->kids[i]->code);
    }
}
