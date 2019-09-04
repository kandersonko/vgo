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
    char *error_file;
    int error_lineno;
    int tokentype;

    for (i = 0; i < argc; i++)
    {

        filename = argv[i];
        // TODO: check filename ends with .go or append it

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
            if (tokentype < 0)
            {
                error_file = filename;
                print_list(root);
                if (tokentype == -1)
                    fprintf(stderr, "Go keyword not in VGo!\n");
                else if (tokentype == -2)
                    fprintf(stderr, "Go operator not in VGo!\n");
                fprintf(stderr, "ERROR: found in file \"%s\" at line %d!\n", error_file, error_lineno);

                delete_list(root);
                fclose(yyin);
                yylex_destroy();

                return -1;
            }
        }
        fclose(yyin); // not sure
    }

    print_list(root);

    delete_list(root);
    yylex_destroy();

    return 0;
}