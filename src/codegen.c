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

struct instr *ic;

static void print_code(struct instr *code, FILE *fp, int output_ir)
{
    if (code != NULL && code->opcode == 0)
        return;

    if (code->opcode == DECL_LABEL)
    {
        fprintf(fp, "L%d:\n", code->dest.offset);
        if (output_ir)
            printf("L%d:\n", code->dest.offset);
        return;
    }
    if (code->opcode == DECL_PROC)
    {
        fprintf(fp, "%s:\n", code->name);
        if (output_ir)
            printf("%s:\n", code->name);
        return;
    }
    if (code->opcode == OP_GOTO)
    {
        fprintf(fp, "goto L%d\n", code->dest.offset);
        if (output_ir)
            printf("goto L%d\n", code->dest.offset);
        return;
    }
    if (code->src2.region == -1 && code->src2.offset == -1)
    {
        fprintf(fp, "%s\t %s:%d,%s:%d\n",
                get_opcode_name(code->opcode),
                get_region_name(code->dest.region), code->dest.offset,
                get_region_name(code->src1.region), code->src1.offset);
        if (output_ir)
            printf("%s\t %s:%d,%s:%d\n",
                   get_opcode_name(code->opcode),
                   get_region_name(code->dest.region), code->dest.offset,
                   get_region_name(code->src1.region), code->src1.offset);
    }
    else if (code->src1.region == -1 && code->src1.offset == -1)
    {
        fprintf(fp, "%s\t %s:%d,%s:%d\n",
                get_opcode_name(code->opcode),
                get_region_name(code->dest.region), code->dest.offset,
                get_region_name(code->src2.region), code->src2.offset);
        if (output_ir)
            printf("%s\t %s:%d,%s:%d\n",
                   get_opcode_name(code->opcode),
                   get_region_name(code->dest.region), code->dest.offset,
                   get_region_name(code->src2.region), code->src2.offset);
    }
    else if (code->src1.region == -1 && code->src2.offset == -1)
    {
        fprintf(fp, "%s\t %s:%d\n",
                get_opcode_name(code->opcode),
                get_region_name(code->dest.region), code->dest.offset);
        if (output_ir)
            printf("%s\t %s:%d\n",
                   get_opcode_name(code->opcode),
                   get_region_name(code->dest.region), code->dest.offset);
    }
    else
    {
        fprintf(fp, "%s\t %s:%d,%s:%d,%s:%d\n",
                get_opcode_name(code->opcode),
                get_region_name(code->dest.region), code->dest.offset,
                get_region_name(code->src1.region), code->src1.offset,
                get_region_name(code->src2.region), code->src2.offset);
        if (output_ir)
            printf("%s\t %s:%d,%s:%d,%s:%d\n",
                   get_opcode_name(code->opcode),
                   get_region_name(code->dest.region), code->dest.offset,
                   get_region_name(code->src1.region), code->src1.offset,
                   get_region_name(code->src2.region), code->src2.offset);
    }
}

static struct addr newlabel()
{
    static int counter = 0;
    struct addr temp;
    temp.offset = counter;
    temp.region = REGION_LABEL;
    ++counter;
    return temp;
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
    return -1;
}

static struct addr get_addr(tree_ptr n, sym_table_ptr st)
{
    struct addr new_addr;
    if (n->prodrule == LLITERAL)
    {
        new_addr.offset = get_entry_offset(st, n->type, n->leaf->text);
        new_addr.region = get_entry_region(st, n->type, n->leaf->text);
        return new_addr;
    }
    if (n->prodrule == LNAME)
    {
        sym_entry_ptr entry = lookup(st, n->leaf->text);
        if (entry != NULL)
        {
            new_addr.offset = entry->offset;
            new_addr.region = entry->region;
            return new_addr;
        }
    }
    if (!st)
    {
        new_addr.offset = -1;
        new_addr.region = -1;
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

    n->place = newtemp(n);
    n->true = newlabel();
    n->false = newlabel();
    n->first = newlabel();
    n->follow = newlabel();

    switch (n->prodrule)
    {
    case LNAME:
    case LLITERAL:

        n->label = newlabel();
        break;

    default:

        break;
    }
}

static void get_place(tree_ptr n, struct addr *place)
{
    if (!n)
        return;

    int i;
    for (i = 0; i < n->nkids; i++)
        get_place(n->kids[i], place);

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

    n->place = newlocal(n);
    get_place(n->kids[0], &n->kids[0]->place);
    get_place(n->kids[2], &n->kids[2]->place);

    n->code = concat(n->kids[0]->code, n->kids[2]->code);
    struct instr *g = gen(opcode, n->place,
                          n->kids[0]->place, n->kids[2]->place);
    n->code = concat(n->code, g);
}

static void gen_unary_expr_ic(tree_ptr n, int opcode)
{
    if (opcode == 0)
        return;
    struct instr *g;
    
    n->place = newtemp(n);
    get_place(n->kids[1], &n->kids[1]->place);

    struct addr null_addr = {-1, -1};
    g = gen(opcode, n->place,
            n->kids[1]->place, null_addr);
    n->code = concat(n->code, g);
}

static void gen_assign_expr_ic(int opcode, tree_ptr n, tree_ptr right)
{
    if (opcode == 0)
        return;
    n->place = newlocal(n);
    right->place = newlocal(right);
    struct addr null_addr = {-1, -1};
    struct instr *g = gen(opcode, n->place,
                          right->place, null_addr);
    n->code = concat(n->code, g);
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

    switch (n->prodrule)
    {
    case R_SIMPLE_STMT + 1:
    case R_SIMPLE_STMT + 2:
    case R_CONSTDCL + 1:
    case R_VARDCL + 2: /* dcl_name_list '=' expr_list */
        {
            gen_assign_expr_ic(OP_ASN, n, n->kids[2]);
        }
        break;

    case R_VARDCL + 1: /* dcl_name_list '=' expr_list */
    {
        gen_assign_expr_ic(OP_ASN, n, n->kids[3]);
    }
    break;

    default:
        break;
    }
}

static void ic_commondcl(tree_ptr n)
{
    int i;
    if (n == NULL)
        return;

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

    for (i = 0; i < n->nkids; i++)
        ic_expression(n->kids[i]);

    switch (n->prodrule)
    {
    case R_EXPR + 1: // "||"
        gen_expr_ic(n, OP_OR);
        break;
    case R_EXPR + 2: // "&&"
        gen_expr_ic(n, OP_AND);
        break;
    case R_EXPR + 3: // "EQ "==""
        gen_expr_ic(n, OP_BEQ);
        break;
    case R_EXPR + 4: // "!="
        gen_expr_ic(n, OP_BNE);
        break;
    case R_EXPR + 5: // "<"
        gen_expr_ic(n, OP_BLT);
        break;
    case R_EXPR + 6: // "<="
        gen_expr_ic(n, OP_BLE);
        break;
    case R_EXPR + 7: // ">="
        gen_expr_ic(n, OP_BGE);
        break;
    case R_EXPR + 8: // ">"
        gen_expr_ic(n, OP_BGT);
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
   
    default:
        break;
    }
}

static void ic_condition(tree_ptr n)
{
    int i;
    if (n == NULL)
        return;

    for (i = 0; i < n->nkids; i++)
    {
        ic_condition(n->kids[i]);
    }
    for (i = 0; i < n->nkids; i++)
    {
        n->code = concat(n->code, n->kids[i]->code);
    }

    if (strcmp(n->prodname, "expr") == 0)
    {
        ic_expression(n);
    }

    switch (n->prodrule)
    {
    case R_IF_STMT:
    {
        struct instr *g1, *g2, *g3;
        if (n->kids[4]->nkids == 0)
        {
            n->kids[1]->true = newlabel(n); // E
            n->kids[1]->false = n->follow;
            n->kids[2]->follow = n->follow;

            g1 = gen_label(DECL_LABEL, n->kids[1]->true);
            g2 = gen_label(OP_GOTO, n->kids[1]->first);

            g3 = concat(g1, g2);
            n->code = concat(n->code, g3);
        }
        else
        {
        }
    }
    break;
    default:

        break;
    }
}

static void ic_function_dcl(tree_ptr n)
{
    int i;
    if (n == NULL)
        return;
    for (i = 0; i < n->nkids; i++)
        ic_function_dcl(n->kids[i]);

    switch (n->prodrule)
    {
    case R_FNDCL:
    {
        n->code = concat(n->code, gen_proc(DECL_PROC, n->first, n->kids[0]->kids[0]->leaf->text));
    }
    break;
    default:
        break;
    }
}

static void generate_ic_header()
{
}

static void generate_ic_code(tree_ptr n)
{

    int i;
    if (n == NULL)
        return;

    for (i = 0; i < n->nkids; i++)
        generate_ic_code(n->kids[i]);

    if (strcmp(n->prodname, "if_stmt") == 0)
    {
        ic_condition(n);
    }
    else if (strcmp(n->prodname, "common_dcl") == 0)
    {
        ic_commondcl(n);
    }
    else if (strcmp(n->prodname, "expr") == 0)
    {
        ic_expression(n);
    }
    else if (strcmp(n->prodname, "xfndcl") == 0)
    {
        ic_function_dcl(n);
    }

    for (i = 0; i < n->nkids; i++)
    {
        n->code = concat(n->code, n->kids[i]->code);
    }
}

static void print_ic_code(tree_ptr n, FILE *fp, int output_ir)
{
    if (!n)
        return;
    struct instr *code = n->code;
    while (code != NULL)
    {
        print_code(code, fp, output_ir);
        code = code->next;
    }
}

void emit_ic_code(tree_ptr n, FILE *fp, char *filename, int output_ir)
{
    if (output_ir)
    {
        printf("============ intermediate code for %s ===========\n", filename);
        print_ic_code(n, fp, output_ir);
        printf("============ done =============================\n");
    }
}

void codegen(tree_ptr n)
{
    generate_attributes(n);
    generate_ic_header();
    generate_ic_code(n);
}
