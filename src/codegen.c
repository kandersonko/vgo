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

static void print_code(struct instr *code)
{
    if (!code)
        return;
    printf("%s\t %s:%d,%s:%d,%s:%d\n",
           get_opcode_name(code->opcode),
           get_region_name(code->dest.region), code->dest.offset,
           get_region_name(code->src1.region), code->src1.offset,
           get_region_name(code->src2.region), code->src2.offset);
}

static int newlabel()
{
    static int counter = 0;
    ++counter;
    return counter;
}

static void get_symtab(tree_ptr n, sym_table_ptr *st)
{
    if (!n)
        return;
    int i;
    for (i = 0; i < n->nkids; i++)
    {
        get_symtab(n->kids[i], st);
    }

    switch (n->prodrule)
    {
    case LNAME:
    case LLITERAL:
        *st = find_symtab(n->leaf->text);
        break;

    default:
        break;
    }
}

static int get_offset(tree_ptr n, sym_table_ptr st)
{
    sym_entry_ptr entry;
    if (n->prodrule == LNAME || n->prodrule == LLITERAL)
    {
        if (st != NULL)
            entry = lookup_st(st, n->leaf->text);
        else
        {
            entry = lookup_st(n->symtab, n->leaf->text);
        }

        if (entry != NULL)
        {
            printf("FOUND OFFSET: %d for %s\n", entry->offset, n->leaf->text);
            return entry->offset;
        }
    }
    if (st != NULL)
    {
        printf("FOUND SYMTAB: %s\n", st->name);
        return st->size;
    } else {
        return n->symtab->size;
    }
    return 0;
}

static int get_local_global_region(tree_ptr n, sym_table_ptr st)
{
    int region = REGION_LABEL;
    sym_table_ptr temp = NULL;
    if (st != NULL)
        temp = st;
    else
        temp = n->symtab;

    if (n->prodrule == LLITERAL)
    {
        return REGION_CONST;
    }

    if (strcmp(temp->name, "global") == 0)
    {
        region = REGION_CONST;
    }
    else if (strcmp(temp->name, "static") == 0)
    {
        region = REGION_CONST;
    }
    else
    {
        region = REGION_LOCAL;
    }

    return region;
}

// width in bytes
struct addr newtemp(tree_ptr n)
{
    struct addr temp;
    sym_table_ptr st = NULL;
    get_symtab(n, &st);

    temp.offset = get_offset(n, st);
    temp.region = get_local_global_region(n, st);
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
        n->label = newlabel();
        n->place = newtemp(n);
        n->leaf->label = n->label;
        n->leaf->place = n->place;
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

static void get_place(tree_ptr n, struct addr *place)
{
    if (!n)
        return;

    int i;
    for (i = 0; i < n->nkids; i++)
        get_place(n->kids[i], place);

    /*
    * back from kids, consider what we have to do with
    * this node. The main thing we have to do, one way or
    * another, is assign t->code
    */
    switch (n->prodrule)
    {
    case LNAME:
    case LLITERAL:
        *place = n->place;
        break;
    default:
        break;
    }
}

static void ic_expression(tree_ptr n)
{
    int i;
    if (n == NULL)
        return;

    /*
    * this is a post-order traversal, so visit kids first
    */
    for (i = 0; i < n->nkids; i++)
        ic_expression(n->kids[i]);

    /*
    * back from kids, consider what we have to do with
    * this node. The main thing we have to do, one way or
    * another, is assign t->code
    */
    switch (n->prodrule)
    {
    case R_EXPR + 9: // "+"
    {
        struct instr *g;
        printf("SYMTABLE FOUND: %s\n", n->symtab->name);
        n->place = newtemp(n);
        get_place(n->kids[0], &n->kids[0]->place);
        get_place(n->kids[2], &n->kids[2]->place);
        printf("PLACE SRC0: %s:%d\n", get_region_name(n->place.region), n->place.offset);
        printf("PLACE SRC1: %s:%d\n", get_region_name(n->kids[0]->place.region), n->kids[0]->place.offset);
        printf("PLACE SRC2: %s:%d\n", get_region_name(n->kids[2]->place.region), n->kids[2]->place.offset);
        n->code = concat(n->kids[0]->code, n->kids[2]->code);
        g = gen(OP_ADD, n->place,
                n->kids[0]->place, n->kids[2]->place);
        n->code = concat(n->code, g);
    }
    break;
    /*
    * ... really, a bazillion cases, up to one for each
    * production rule (in the worst case)
    */
    default:
        /* default is: concatenate our kids children's code */
        n->code = NULL;
        for (i = 0; i < n->nkids; i++)
            n->code = concat(n->code, n->kids[i]->code);
    }
}

static void generate_ic_code(tree_ptr n)
{
    ic_expression(n);
}

static void print_ic_code(tree_ptr n)
{
    if (!n)
        return;
    struct instr *code = n->code;
    while (code != NULL)
    {
        switch (code->opcode)
        {
        case OP_ADD:
            print_code(code);
            break;

        default:
            break;
        }
        code = code->next;
    }
}

void codegen(tree_ptr n)
{
    generate_attributes(n);
    generate_ic_code(n);
    print_ic_code(n);
}
