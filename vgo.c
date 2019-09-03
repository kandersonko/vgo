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

    // tokenlist_ptr root = NULL;
    // token_ptr yytoken = malloc(sizeof(token_ptr));

    argc--;
    argv++;
    int i;
    for (i = 0; i < argc; i++)
    {
        filename = argv[i];
        // TODO: check filename ends with .go or append it
        int tokentype;

        if (!(yyin = fopen(filename, "r")))
        {
            printf("ERROR: could not open %s!\n", filename);
            perror(argv[i]);
            return 1;
        }
        // yypush_buffer_state(yy_create_buffer(yyin, YY_BUFFER_SIZE));

        while ((tokentype = yylex()))
        {
            printf("yytoken file: %s\n", yytoken->filename);
            printf("yytoken text: %s\n", yytoken->text);
            // printf("yytoken lineno: %s\n", yytoken->lineno);
            free(yytoken->filename);
            free(yytoken->text);
            free(yytoken->sval);
            free(yytoken);
            // root = add_node(root, yytoken);
            // delete_token(yytoken);
        }
        fclose(yyin); // not sure
    }
    yytoken = NULL;
    // print_list(root);

    // delete_list(root);
    // free(yytoken);
    // yytoken = NULL;

    yylex_destroy();
    return 0;
}