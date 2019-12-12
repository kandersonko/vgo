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
    if (code != NULL && code->opcode == 0)
        return;
    if (code->src2.region == 0 && code->src2.offset == 0)
    {
        printf("%s\t %s:%d,%s:%d\n",
               get_opcode_name(code->opcode),
               get_region_name(code->dest.region), code->dest.offset,
               get_region_name(code->src1.region), code->src1.offset);
    }
    else if (code->src1.region == 0 && code->src1.offset == 0)
    {
        printf("%s\t %s:%d,%s:%d\n",
               get_opcode_name(code->opcode),
               get_region_name(code->dest.region), code->dest.offset,
               get_region_name(code->src2.region), code->src2.offset);
    }
    else
    {
        printf("%s\t %s:%d,%s:%d,%s:%d\n",
               get_opcode_name(code->opcode),
               get_region_name(code->dest.region), code->dest.offset,
               get_region_name(code->src1.region), code->src1.offset,
               get_region_name(code->src2.region), code->src2.offset);
    }
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
        *st = find_symtab(n->leaf->text, current);
        if (*st == NULL)
            *st = find_symtab(n->leaf->text, globals);
        if (*st == NULL)
            *st = find_symtab(n->leaf->text, stringpool);
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
        printf("GETTING OFFSET FOR %s\n", n->leaf->text);

        if (is_basic_type(n->type->basetype))
            return get_entry_offset(st, n->type, n->leaf->text);
        if (st != NULL)
            printf("SYMTAB: %s\n", st->name);
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
        return st->size;
    }
    else
    {
        return n->symtab->size;
    }
    return 0;
}

static struct addr get_addr(tree_ptr n, sym_table_ptr st)
{
    struct addr new_addr;
    if (n->prodrule == LLITERAL)
    {
        new_addr.offset = get_entry_offset(st, n->type, n->leaf->text);
        new_addr.region = get_entry_region(st, n->type, n->leaf->text);

        // printf("FOUND ENTRY: %s:%s %s:%d\n", n->leaf->text, typename(n->type), get_region_name(new_addr.region), new_addr.offset);
        return new_addr;
    }
    if (n->prodrule == LNAME)
    {
        sym_entry_ptr entry = lookup(st, n->leaf->text);
        if (entry != NULL)
        {
            new_addr.offset = entry->offset;
            new_addr.region = entry->region;
            // printf("LOOKUP FOUND ENTRY: %s:%s %s:%d\n", n->leaf->text, typename(n->type), get_region_name(new_addr.region), new_addr.offset);

            return new_addr;
        }
    }
    if (!st)
    {
        new_addr.offset = 0;
        new_addr.region = 0;
        return new_addr;
    }
    if (strcmp(st->name, "global") == 0 || strcmp(st->name, "static") == 0)
    {
        new_addr.region = REGION_CONST;
        new_addr.offset = get_offset(n, st);
    }
    else
    {
        new_addr.region = REGION_LOCAL;
        new_addr.offset = get_offset(n, st);
    }
    return new_addr;
}

static struct addr newlocal(tree_ptr n)
{
    static int counter = 0;
    struct addr temp;
    temp.offset = counter;
    temp.region = REGION_LOCAL;
    counter++;
    return temp;
}
// width in bytes
struct addr newtemp(tree_ptr n)
{
    sym_table_ptr st = NULL;
    get_symtab(n, &st);
    struct addr temp = get_addr(n, st);
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

static void gen_expr_ic(tree_ptr n, int opcode)
{
    if (opcode == 0)
        return;

    // printf("SYMTABLE FOUND: %s %s\n", n->symtab->name, get_opcode_name(opcode));
    n->place = newlocal(n);
    get_place(n->kids[0], &n->kids[0]->place);
    get_place(n->kids[2], &n->kids[2]->place);
    // printf("PLACE SRC0: %s:%d\n", get_region_name(n->place.region), n->place.offset);
    // printf("PLACE SRC1: %s:%d\n", get_region_name(n->kids[0]->place.region), n->kids[0]->place.offset);
    // printf("PLACE SRC2: %s:%d\n", get_region_name(n->kids[2]->place.region), n->kids[2]->place.offset);
    n->code = concat(n->kids[0]->code, n->kids[2]->code);
    struct instr *g = gen(opcode, n->place,
                          n->kids[0]->place, n->kids[2]->place);
    n->code = concat(n->code, g);
}

static void gen_three_addr_code(int opcode, tree_ptr *dest, tree_ptr *src1, tree_ptr *src2)
{
    if (opcode == 0)
        return;
    (*dest)->place = newlocal(*dest);
    get_place(*src1, &(*src1)->place);
    get_place(*src2, &(*src2)->place);
    (*dest)->code = concat((*src1)->code, (*src2)->code);
    struct instr *g = gen(opcode, (*dest)->place,
                          (*src1)->place, (*src2)->place);
    (*dest)->code = concat((*dest)->code, g);
    printf("PRINTING CODE: %s %s:%d\n", get_opcode_name(g->opcode), get_region_name(g->src1.region), g->src1.offset);
    print_code((*dest)->code);
}

static void gen_unary_expr_ic(tree_ptr n, int opcode)
{
    if (opcode == 0)
        return;
    struct instr *g;
    // printf("UNARY SYMTABLE FOUND: %s %s\n", n->symtab->name, get_opcode_name(opcode));
    n->place = newtemp(n);
    get_place(n->kids[1], &n->kids[1]->place);
    // printf("PLACE SRC0: %s:%d\n", get_region_name(n->place.region), n->place.offset);
    // printf("PLACE SRC1: %s:%d\n", get_region_name(n->kids[0]->place.region), n->kids[0]->place.offset);
    // printf("PLACE SRC2: %s:%d\n", get_region_name(n->kids[2]->place.region), n->kids[2]->place.offset);
    struct addr null_addr = {0, 0};
    g = gen(opcode, n->place,
            n->kids[1]->place, null_addr);
    n->code = concat(n->code, g);
}

static void gen_assign_expr_ic(int opcode, tree_ptr n, tree_ptr right)
{
    if (opcode == 0)
        return;
    n->place = newlocal(n);
    // get_place(right, &right->place);
    right->place = newlocal(right);
    struct addr null_addr = {0, 0};
    struct instr *g = gen(opcode, n->place,
                          right->place, null_addr);
    n->code = concat(n->code, g);
}

static void get_child(tree_ptr n, tree_ptr *child)
{
    int i;
    if (n == NULL)
        return;

    /*
    * this is a post-order traversal, so visit kids first
    */
    for (i = 0; i < n->nkids; i++)
        get_child(n->kids[i], child);

    switch (n->prodrule)
    {
    case LLITERAL:
    case LNAME:
        *child = n;
        break;

    default:
        break;
    }
}

static void generate_dcl_ic_code(tree_ptr n)
{
    if (!n)
        return;
    int i;
    for (i = 0; i < n->nkids; i++)
    {
        generate_dcl_ic_code(n->kids[i]);
    }

    printf("PRODNAME: %s %d\n", n->prodname, n->prodrule);

    switch (n->prodrule)
    {
    case R_SIMPLE_STMT + 1:
    case R_SIMPLE_STMT + 2:
    case R_CONSTDCL + 1:
    case R_VARDCL + 2: /* dcl_name_list '=' expr_list */
        printf("VARDCL: \n");
        {
            // tree_ptr left = NULL, right = NULL;

            // get_child(n->kids[0], &left);
            // get_child(n->kids[2], &left);
            // printf("VARDCL: %s %s\n", left->leaf->text, right->leaf->text);

            gen_assign_expr_ic(OP_ASN, n, n->kids[2]);
        }
        break;

    case R_VARDCL + 1: /* dcl_name_list '=' expr_list */
        printf("VARDCL: \n");
        {
            // tree_ptr left = NULL, right = NULL;

            // get_child(n->kids[0], &left);
            // get_child(n->kids[3], &right);
            // printf("VARDCL: %s\n", right->leaf->text);

            gen_assign_expr_ic(OP_ASN, n, n->kids[3]);
        }
        break;

    default:
        // /* default is: concatenate our kids children's code */
        // // n->code = NULL;
        // // for (i = 0; i < n->nkids; i++)
        // //     n->code = concat(n->code, n->kids[i]->code);
        break;
    }
}

static void ic_commondcl(tree_ptr n)
{
    int i;
    if (n == NULL)
        return;

    /*
    * this is a post-order traversal, so visit kids first
    */
    for (i = 0; i < n->nkids; i++)
        ic_commondcl(n->kids[i]);

    if (strcmp(n->prodname, "common_dcl") == 0)
    {
        generate_dcl_ic_code(n);
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
    case R_EXPR + 1: // "||"
        break;
    case R_EXPR + 2: // "&&"
        break;
    case R_EXPR + 3: // "="
        gen_expr_ic(n, OP_ASN);
        break;
    case R_EXPR + 4: // "!="
        break;
    case R_EXPR + 5: // "<"
        break;
    case R_EXPR + 6: // "<="
        break;
    case R_EXPR + 7: // ">="
        break;
    case R_EXPR + 8: // ">"
        break;
    case R_EXPR + 9: // "+"
        gen_expr_ic(n, OP_ADD);
        break;
    case R_EXPR + 10: // "-"
        gen_expr_ic(n, OP_SUB);
        break;
    case R_EXPR + 11: // "|"
        break;
    case R_EXPR + 12: // "*"
        gen_expr_ic(n, OP_MUL);
        break;
    case R_EXPR + 13: // "/"
        gen_expr_ic(n, OP_DIV);
        break;
    case R_EXPR + 14: // "%"
        break;
    case R_EXPR + 15: // "&"
        break;
    case R_EXPR + 16: // "ANDNOT"
        break;
    case R_EXPR + 17: // "LLSH"
        break;
    case R_EXPR + 18: // "LRSH"
        break;
    case R_EXPR + 19: // "LCOMM"
        break;

    // unary operations
    case R_UEXPR + 1: // "pointer *id"
        break;
    case R_UEXPR + 2: // "+id"
        break;
    case R_UEXPR + 3: // "-id"
        gen_unary_expr_ic(n, OP_UMINUS);
        break;
    case R_UEXPR + 4: // "!id"
        gen_unary_expr_ic(n, OP_NOT);
        break;
    case R_UEXPR + 5: // "~id"
        gen_unary_expr_ic(n, OP_NEG);
        break;
    /*
    * ... really, a bazillion cases, up to one for each
    * production rule (in the worst case)
    */
    default:
        /* default is: concatenate our kids children's code */
        // n->code = NULL;
        for (i = 0; i < n->nkids; i++)
            n->code = concat(n->code, n->kids[i]->code);
    }
}

static void generate_ic_header()
{
}

static void generate_ic_code(tree_ptr n)
{
    generate_ic_header();
    ic_commondcl(n);
    ic_expression(n);
}

static void print_ic_code(tree_ptr n)
{
    if (!n)
        return;
    struct instr *code = n->code;
    while (code != NULL)
    {
        print_code(code);
        code = code->next;
    }
}

void codegen(tree_ptr n)
{
    generate_attributes(n);
    generate_ic_code(n);
    print_ic_code(n);
}
