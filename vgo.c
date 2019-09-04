#include <stdio.h>
#include <stdlib.h>
#include "token.h"
#include "vgo.tab.h"

extern int yylex();
extern int yylineno;
extern char *yytext;

extern int yyleng;
extern int yylineno;

extern FILE *yyin;

char *filename;

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
    int compile_error = 0;
    char *error_file;
    int error_lineno;
    for (i = 0; i < argc; i++)
    {

        filename = argv[i];
        // TODO: check filename ends with .go or append it
        int tokentype;

        if (!(yyin = fopen(filename, "r")))
        {
            printf("ERROR: could not open file \"%s\"!\n", filename);
            perror(argv[i]);
            return 1;
        }
        // yypush_buffer_state(yy_create_buffer(yyin, YY_BUFFER_SIZE));

        while ((tokentype = yylex()))
        {
            root = add_node(root, yytoken);
            error_lineno = yytoken->lineno;
            free(yytoken);
            if (tokentype == -1)
            {
                compile_error = 1;
                error_file = filename;
                break;
            }
        }
        fclose(yyin); // not sure
    }

    print_list(root);

    delete_list(root);
    yylex_destroy();

    if (compile_error)
    {
        fprintf(stderr, "Go keyword not in VGo!\nERROR: found in file \"%s\" at line %d!\n", error_file, error_lineno);
        return -1;
    }

    return 0;
}