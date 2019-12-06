#include <stdio.h>
#include <stdlib.h>

#include "tree.h"
#include "tac.h"
#include "rules.h"
#include "go.tab.h"
#include "symtab.h"
#include "semantic.h"
#include "tac.h"
#include "type.h"

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

    loc -> .code region
    const -> .static region
    global -> global region
*/

static int newlabel()
{
    static int counter = 0;
    ++counter;
    return counter;
}

static int get_offset(tree_ptr n)
{
    if (n->prodrule == LNAME || n->prodrule == LLITERAL)
    {
        sym_entry_ptr entry = lookup_st(n->symtab, n->leaf->text);
        if (entry != NULL)
        {
            printf("FOUND OFFSET: %d for %s\n", entry->offset, n->leaf->text);
            return entry->offset;
        }
    }
    return 0;
}

// width in bytes
struct addr newtemp(tree_ptr n)
{
    struct addr temp;
    temp.offset = get_offset(n);

    if (n->prodrule == LLITERAL)
    {
        // printf("LLITERAL: %s %s\n", n->leaf->text, n->symtab->name);

        if (is_basic_type(n->leaf->basetype) == 1)
        {
            temp.region = REGION_CONST;
        }
        else
        {
            temp.region = REGION_LABEL;
        }
        return temp;
    }

    // printf("SYMBOL TABLE: %s\n", st->name);
    if (strcmp(n->symtab->name, "global") == 0)
    {
        temp.region = REGION_GLOBAL;
    }
    else
    {
        temp.region = REGION_LOCAL;
    }
    return temp;
}

static void generate_attributes(tree_ptr n)
{
    if (!n)
        return;

    int i;
    for (i = 0; i < n->nkids; i++)
    {
        generate_attributes(n->kids[i]);
    }

    add_symtab(n, current);

    switch (n->prodrule)
    {
    case LNAME:
    case LLITERAL:
        n->leaf->label = newlabel();
        n->leaf->place = newtemp(n);
        break;

        break;

    default:
        n->place = newtemp(n);
        break;
    }
}

// static void generate_location(tree_ptr n)
// {
// }

// static void generate_true_false(tree_ptr n)
// {
// }

// // for main
// static void generate_header(tree_ptr n)
// {
// }

// static void generate_ender(tree_ptr n)
// {
// }

// static void generate_ic_code(tree_ptr n)
// {
//     int i, j;
//     if (n == NULL)
//         return;

//     /*
//     * this is a post-order traversal, so visit kidsren first
//     */
//     for (i = 0; i < n->nkids; i++)
//         generate_ic_code(n->kids[i]);

//     /*
//     * back from kidsren, consider what we have to do with
//     * this node. The main thing we have to do, one way or
//     * another, is assign t->code
//     */
//     switch (n->label)
//     {
//     case OP_ADD:
//     {
//         struct instr *g;
//         n->code = concat(n->kids[0]->code, n->kids[1]->code);
//         g = gen(OP_ADD, n->place,
//                 n->kids[0]->place, n->kids[1]->place);
//         n->code = concat(n->code, g);
//         break;
//     }
//     /*
//     * ... really, a bazillion cases, up to one for each
//     * production rule (in the worst case)
//     */
//     default:
//         /* default is: concatenate our kids children's code */
//         n->code = NULL;
//         for (i = 0; i < n->nkids; i++)
//             n->code = concat(n->code, n->kids[i]->code);
//     }
// }

void codegen(tree_ptr n)
{
    generate_attributes(n);
}
