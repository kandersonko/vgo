#include <stdio.h>
#include <stdlib.h>
#include "token.h"
#include "tree.h"
#include "vgo.tab.h"
#include <string.h>

extern struct tree *ast_root;

extern int yylex();

int yyparse();

extern FILE *yyin;

extern char *yyfilename;

int yylex_destroy();

void print_error(int tokentype);

const char *get_filename_ext(const char *filename);

char *rename_go_file(char *name);

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        printf("ERROR: no file provided!\n");
        return 0;
    }

    tree_ptr ast = NULL;

    argc--;
    argv++;
    int i;

    for (i = 0; i < argc; i++)
    {
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

        int failed = yyparse();
        if (!failed)
        {
            // parse successfull

            print_tree(ast_root, 0);

            delete_tree(ast);
        }
        else
        {
            // parse failed due to error
            printf("ERROR: parsing failed for file \"%s\"!\n", yyfilename);
        }
        fclose(yyin);
    }

    yylex_destroy();

    return 0;
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
    const char *ext = get_filename_ext(name);
    if (!strcmp(ext, "go"))
    {
        return name;
    }
    if (!strcmp(ext, ""))
    {
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