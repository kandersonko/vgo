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
    {
        snprintf(buffer, 20, "$%d", place.offset);
    }
    break;
    case REGION_LOCAL:
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
        snprintf(buffer, 20, "stop mem!");
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

void emit_final_code(struct instr *ic, FILE *fp)
{
    printf("================= FINAL CODE:==================\n");
    struct instr *temp = ic;
    // char *rax = "%rax";
    // char buffer[50];
    while (temp != NULL)
    {
        switch (temp->opcode)
        {
        case OP_ADD:
        case OP_SUB:
        {
            emit_expr(temp, get_opcode_name(temp->opcode), fp);
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
