#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "token.h"
#include "tree.h"
#include "semantic.h"
#include "typecheck.h"
#include "codegen.h"
#include "tac.h"
#include "final.h"

extern struct tree *ast_root;

extern int yylex();

int yyparse();

extern FILE *yyin;

extern char *yyfilename;

int yylex_destroy();

void print_error(int tokentype);

const char *get_filename_ext(const char *filename);

char *rename_go_file(char *name);

sym_table_ptr current;

void generate_ic_file();

char *remove_ext(char *s, char ext_sep, char path_sep);

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        printf("ERROR: no file provided!\n");
        return 0;
    }

    argc--;
    argv++;

    int print_symtab = 0, print_tree_enabled = 0;

    int j;
    for (j = 0; j < argc; j++)
    {
        if (strcmp(argv[j], "-symtab") == 0)
        {
            print_symtab = 1;
        }
        if (strcmp(argv[j], "-ast") == 0)
        {
            print_tree_enabled = 1;
        }
    }
    int i;
    for (i = 0; i < argc; i++)
    {
        if (strcmp(argv[i], "-symtab") == 0 || strcmp(argv[i], "-ast") == 0)
        {
            continue;
        }
        yyfilename = rename_go_file(argv[i]);
        if (!yyfilename)
        {
            return -1;
        }

        if (!(yyin = fopen(yyfilename, "r")))
        {
            printf("ERROR: could not open file \"%s\"!\n", yyfilename);
            perror(argv[i]);
            return -1;
        }

        char *s = remove_ext(argv[i], '.', '/');

        char *ic_filename = strcat(s, ".ic");
        FILE *ic_file = fopen(ic_filename, "w+");

        char *asm_filename = strcat(remove_ext(argv[i], '.', '/'), ".s");
        FILE *asm_file = fopen(asm_filename, "w+");

        int failed = yyparse();
        if (!failed)
        {
            current = new_st(150, "global");
            globals = new_st(150, "static");
            stringpool = new_st(150, "string");
            populate(ast_root);
            // TODO: fix lost of prev scopes (symtabs)
            // both populate and typecheck should use the global symtab `current`
            if (print_symtab)
            {
                printf("============ symbol table for file: %s ===========\n", yyfilename);
                printsymbols(current, 0);
            }
            typecheck(ast_root);
            codegen(ast_root);

            if(print_tree_enabled)
            {
                printf("============ ast tree for file: %s ===========\n", yyfilename);
                print_tree(ast_root, 0);
                printf("============ done =============================\n");
            }

            generate_ic_file(ic_file, ast_root);
            emit_final_code(ast_root->code, asm_file, argv[i]);
            fclose(ic_file);
            fclose(asm_file);
        }
        else
        {
            // parse failed due to error
            printf("ERROR: parsing failed for file \"%s\"!\n", yyfilename);
        }
        delete_st(current);
        fclose(yyin);
    }

    delete_tree(ast_root);
    yylex_destroy();

    return 0;
}

void generate_ic_file(FILE *fp, tree_ptr n)
{
    if (!n)
        return;
    struct instr *code = n->code;
    while (code != NULL)
    {
        if (!code)
            return;
        if (code->src2.region == 0 && code->src2.offset == 0)
        {
            fprintf(fp, "%s\t %s:%d,%s:%d\n",
                   get_opcode_name(code->opcode),
                   get_region_name(code->dest.region), code->dest.offset,
                   get_region_name(code->src1.region), code->src1.offset);
        }
        else
        {
            fprintf(fp, "%s\t %s:%d,%s:%d,%s:%d\n",
                   get_opcode_name(code->opcode),
                   get_region_name(code->dest.region), code->dest.offset,
                   get_region_name(code->src1.region), code->src1.offset,
                   get_region_name(code->src2.region), code->src2.offset);
        }
        code = code->next;
    }
}

// code found on stackoverflow
// get a file extension from the filename
const char *get_filename_ext(const char *filename)
{
    const char *dot = strrchr(filename, '.');
    if (!dot || dot == filename)
        return "";
    return dot + 1;
}

char *rename_go_file(char *name)
{
    // check if file exists
    if (access(name, F_OK) != -1)
    {
        // file exists
        const char *ext = get_filename_ext(name);
        if (!strcmp(ext, "go"))
        {
            return name;
        }
        if (!strcmp(ext, ""))
        {
            // rename file
            char *newname = malloc(sizeof(*newname));
            strcpy(newname, name);
            strcat(newname, ".go");
            if (rename(name, newname))
            {
                fprintf(stderr, "Could not rename file!\n");
                return NULL;
            }
            free(newname);
            strcat(name, ".go");
            return name;
        }
        fprintf(stderr, "ERROR: invalid file extension \".%s\"\n", ext);
        return NULL;
    }
    fprintf(stderr, "ERROR: invalid file name \"%s\"\n", name);
    return NULL;
}

// code from stackoverflow
// link: https://stackoverflow.com/questions/2736753/how-to-remove-extension-from-file-name
char *remove_ext(char *s, char ext_sep, char path_sep)
{
    char *ret_str, *last_ext, *last_path;

    // Error checks and allocate string.

    if (s == NULL)
        return NULL;
    if ((ret_str = malloc(strlen(s) + 1)) == NULL)
        return NULL;

    // Make a copy and find the relevant characters.

    strcpy(ret_str, s);
    last_ext = strrchr(ret_str, ext_sep);
    last_path = (path_sep == 0) ? NULL : strrchr(ret_str, path_sep);

    // If it has an extension separator.

    if (last_ext != NULL)
    {
        // and it's to the right of the path separator.

        if (last_path != NULL)
        {
            if (last_path < last_ext)
            {
                // then remove it.

                *last_ext = '\0';
            }
        }
        else
        {
            // Has extension separator with no path separator.

            *last_ext = '\0';
        }
    }

    // Return the modified string.

    return ret_str;
}