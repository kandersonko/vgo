#include <stdio.h>
#include <stdlib.h>
#include "token.h"
#include "vgo.tab.h"
#include <string.h>

extern int yylex();

int yyparse();

extern FILE *yyin;

char *filename;

int yylex_destroy();

void print_error(int tokentype);

const char *get_filename_ext(const char *filename);

char *rename_go_file(char *name);

void yyerror(char const *s)
{
    fprintf(stderr, "%s\n", s);
}

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        printf("ERROR: no file provided!\n");
        return 0;
    }

    tokenlist_ptr root = NULL;

    argc--;
    argv++;
    int i;

    for (i = 0; i < argc; i++)
    {
        filename = rename_go_file(argv[i]);
        if (!filename)
        {
            return -1;
        }

        if (!(yyin = fopen(filename, "r")))
        {
            printf("ERROR: could not open file \"%s\"!\n", filename);
            perror(argv[i]);
            return -1;
        }

        int parse_result = yyparse();
        if (parse_result == 0)
        {
            // parse successfull
        }
        else
        {
            // parse failed due to error
        }
        fclose(yyin);
    }

    print_list(root);

    delete_list(root);
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