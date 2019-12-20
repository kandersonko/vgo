#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "final.h"
#include "codegen.h"
#include "tac.h"

char *memref(struct addr place)
{

    char buffer[20];
    char *s;
    if (place.offset == -1 || place.region == -1)
    {
        return NULL;
    }
    switch (place.region)
    {
    case REGION_CONST:
    case REGION_GLOBAL:
    {
        snprintf(buffer, 20, "$%d", place.offset);
    }
    break;
    case REGION_LOCAL:
    case REGION_STRING:
    {
        snprintf(buffer, 20, "%d(%s)", -(place.offset + 1) * 8, "%rbp");
    }
    break;
    case REGION_LABEL:
    {
        snprintf(buffer, 20, ".L%d", place.offset);
    }
    break;

    default:

        snprintf(buffer, 20, ".L%d", place.offset);
        break;
    }

    s = strdup(buffer);
    return s;
}

struct code *add_code(struct code *root, char *s)
{
    if (root == NULL)
    {
        root->s = strdup(s);
        root->next = NULL;
    }
    else
    {
        struct code *temp = root;
        while (temp->next != NULL)
            temp = temp->next;
        temp->s = strdup(s);
        temp->next = NULL;
    }
    return root;
}

static void emit_expr(struct instr *ic, char *op, FILE *fp)
{
    char buffer[50];
    char *rax = "%rax";

    snprintf(buffer, 50, "\tmovq\t%s, %s", memref(ic->src1), rax);
    printf("%s\n", buffer);
    fprintf(fp, "%s\n", buffer);

    snprintf(buffer, 50, "\t%s\t%s, %s", op, memref(ic->src2), rax);
    printf("%s\n", buffer);
    fprintf(fp, "%s\n", buffer);

    snprintf(buffer, 50, "\tmovq\t%s, %s", rax, memref(ic->dest));
    printf("%s\n", buffer);
    fprintf(fp, "%s\n", buffer);
}

static void emit_header(FILE *fp, char* filename)
{
    fprintf(fp, "\t.file\t\"%s\"\n", filename);
    printf("\t.file\t\"%s\"\n", filename);

    fprintf(fp, "\t.section\t.rodata\n");
    printf("\t.section\t.rodata\n");
}

void emit_final_code(struct instr *ic, FILE *fp, char* filename)
{
    printf("================= FINAL CODE:==================\n");
    struct instr *temp = ic;
    // char *rax = "%rax";
    char buffer[50];
    
    emit_header(fp, filename);
    while (temp != NULL)
    {
        switch (temp->opcode)
        {
        case OP_ADD:
        case OP_SUB:
        case OP_DIV:
        case OP_MUL:
        {
            emit_expr(temp, get_opcode_name(temp->opcode), fp);
        }
            printf("\n");
            break;

        // case DECL_LABEL:
        // {
        //     snprintf(buffer, 50, "\tcmpq\t%s, %s", memref(ic->dest), memref(ic->src1));
        //     printf("%s\n", buffer);
        //     fprintf(fp, "%s\n", buffer);
        // }
        //     printf("\n");
        //     break;

        case OP_BEQ:
        {
            snprintf(buffer, 50, "\tcmpq\t%s, %s", memref(ic->dest), memref(ic->src1));
            printf("%s\n", buffer);
            fprintf(fp, "%s\n", buffer);

            snprintf(buffer, 50, "\tje\t%s", memref(ic->src1));
            printf("%s\n", buffer);
            fprintf(fp, "%s\n", buffer);
        }
            printf("\n");
            break;

        case OP_GOTO:
        {
            snprintf(buffer, 50, "\tjump\t%s", memref(ic->dest));
            printf("%s\n", buffer);
            fprintf(fp, "%s\n", buffer);
        }
            printf("\n");
            break;

        case DECL_LABEL:
        {
            snprintf(buffer, 50, "%s:", memref(ic->dest));
            printf("%s\n", buffer);
            fprintf(fp, "%s\n", buffer);
        }
            printf("\n");
            break;

        default:
            break;
        }
        temp = temp->next;
    }
    printf("================= DONE ==================\n");
}
