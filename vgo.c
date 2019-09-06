#include <stdio.h>
#include <stdlib.h>
#include "token.h"
#include "vgo.tab.h"
#include <string.h>

extern int yylex();
extern int yylineno;
extern char *yytext;

extern int yyleng;
extern int yylineno;

extern FILE *yyin;

char *filename;

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

    tokenlist_ptr root = NULL;

    argc--;
    argv++;
    int i;
    char *error_file;
    int error_lineno;
    int tokentype;

    for (i = 0; i < argc; i++)
    {
        filename = rename_go_file(argv[i]);
        if (!filename)
        {
            return -1;
        }
        // TODO: check filename ends with .go or append it. if the filename contains a dot "." stop and print invalid filename

        if (!(yyin = fopen(filename, "r")))
        {
            printf("ERROR: could not open file \"%s\"!\n", filename);
            perror(argv[i]);
            return -1;
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
                print_error(tokentype);
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

    // free(filename);

    return 0;
}

void print_error(int tokentype)
{
    switch (tokentype)
    {
    case KEYWORD_NOT_SUPPORTED:
        fprintf(stderr, "Go keyword not in VGo!\n");
        break;
    case OPERATOR_NOT_SUPPORTED:
        fprintf(stderr, "Go operator not in VGo!\n");
        break;
    case UNTERMINATED_STRING:
        fprintf(stderr, "ERROR: unterminated string found!\n");
        break;
    case CCOMMENT_NOT_ALLOWED:
        fprintf(stderr, "C comments not allowed in VGo!\n");
        break;
    case UNTERMINATED_CCOMMENT:
        fprintf(stderr, "Unterminated C comments!\nC comments not allowed in VGo!\n");
    case INVALID_CHARACTER:
        fprintf(stderr, "Invalid character, not allowed in VGo!\n");
        break;
    case ILLEGAL_RUNE:
        fprintf(stderr, "Invalid rune literal, not allowed in VGo!\n");
        break;
    case INVALID_VARNAME:
        fprintf(stderr, "Invalid variable length, a length greater than 12 is not allowed in VGo!\n");
        break;
    case IMAGINARY_NOT_SUPPORTED:
        fprintf(stderr, "Imaginary numbers are not allowed in VGo!\n");
        break;
    default:
        break;
    }
}
// TODO: example -> no example.go, example.c -> wrong extension or usage for extension

// code found on stackoverflow
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
// TODO: add comment about external codes