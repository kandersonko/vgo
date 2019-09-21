
%{
#include<stdlib.h>
#include "go.tab.h"
#include "token.h"
#include "tree.h"
#include "utils.h"

int lasttoken;
int isender(int);
int tok(int);

token_ptr yytoken;

char* yyfilename = NULL;
char* yytext;

char *sval = "\0";
int ival;
double dval;

void set_token(int category)
{
    yylval.t = create_token(category, yyfilename, yylineno, yytext, ival, dval, sval);
}

// remove \t \n and quotes (") from string
char* strip_chars(char* text)
{
    char *s1, *s2, *s3;
    s1 = replace_str(text, "\\t", " ");
    s2 = (s1 != NULL) ? replace_str(s1, "\\n", "") : text;
    s3 = (s2 != NULL) ? replace_str(s2, "\"", "") : text;
    
    free(s1);
    free(s2);
    return s3;
}

// TODO: declare union type for yylval

%}
%option noyywrap noinput nounput yylineno


digit           [0-9]+
binary          "0"("b"|"B")(0|1)+
octal           "0"("o"|"O")([0-7])+
hex             "0"("x"|"X")[0-9A-Fa-f]+
integer         [+-]?[0-9]+
real            [+-]?[0-9]*"."[0-9]+ 
number          {digit}|{integer}|{binary}|{octal}|{hex}|{real}
invalid_runes           "\'\\"[xu][0-9a-fA-F]{4}"\'"|"\'\\U"[0-9a-fA-F]{8}"\'"|"\'\\"[abfrv]"\'"
runes           "\'\\"[nt\\']"\'"
imaginary   ({number})"i"


float				([0-9]*\.[0-9]+)|([0-9]+\.)
exponent			[eE][-+]?[0-9]+



%x comment
%%

    /* types */
    /* "true"|"false"  { set_token(LBOOL); return LBOOL; }
    "bool"|"int"|"float64"|"string"  { set_token(LVARTYPE); return LVARTYPE; } */


    /* Supported keywords */
func          { set_token(LFUNC); return tok(LFUNC); }

map          { set_token(LMAP); return tok(LMAP); }

struct          { set_token(LSTRUCT); return tok(LSTRUCT); }

type          { set_token(LTYPE); return tok(LTYPE); }

const          { set_token(LCONST); return tok(LCONST); }

package          { set_token(LPACKAGE); return tok(LPACKAGE); }

import          { set_token(LIMPORT); return tok(LIMPORT); }

var          { set_token(LVAR); return tok(LVAR); }

for          { set_token(LFOR); return tok(LFOR); }

if          { set_token(LIF); return tok(LIF); }

else          { set_token(LELSE); return tok(LELSE); }

return          { set_token(LRETURN); return tok(LRETURN); }


    /* Not supported keywords */
break          { set_token(LBREAK); return tok(KEYWORD_NOT_SUPPORTED); }
case          { set_token(LCASE); return tok(KEYWORD_NOT_SUPPORTED); }
chan          { set_token(LCHAN); return tok(KEYWORD_NOT_SUPPORTED); }
fallthrough          { set_token(LFALL); return tok(KEYWORD_NOT_SUPPORTED); }
continue          { set_token(LCONTINUE); return tok(KEYWORD_NOT_SUPPORTED); }
default          { set_token(LDEFAULT); return tok(KEYWORD_NOT_SUPPORTED); }
defer          { set_token(LDEFER); return tok(KEYWORD_NOT_SUPPORTED); }
goto          { set_token(LGOTO); return tok(KEYWORD_NOT_SUPPORTED); }
range          { set_token(LRANGE); return tok(KEYWORD_NOT_SUPPORTED); }
interface          { set_token(LINTERFACE); return tok(KEYWORD_NOT_SUPPORTED); }
go                { set_token(LGO); return tok(KEYWORD_NOT_SUPPORTED); }
switch          { set_token(LSWITCH); return tok(KEYWORD_NOT_SUPPORTED); }
select          { set_token(LSELECT); return tok(KEYWORD_NOT_SUPPORTED); }
    
    
    /* Supported operators */
";"           { set_token(';'); return tok(';'); }
"("           { set_token('('); return tok('('); }
")"           { set_token(')'); return tok(')'); }
    /*
    "=="          { set_token(LEQ); return LEQ;  }
    "<"          { set_token(LLT); return LLT;  }
    ">"          { set_token(LGT); return LGT;  }
    "<="          { set_token(LLE); return LLE;  }
    ">="          { set_token(LGE); return LGE;  }
    "!="          { set_token(LNE); return LNE;  }
    "&&"          { set_token(LANDAND); return LANDAND;  }
    "||"          { set_token(LOROR); return LOROR;  }
    "="          { set_token(LASOP); return LASOP;  }
    "+="          { set_token(LCOMPOP); return LCOMPOP;  }
    "-="          { set_token(LCOMPOP); return LCOMPOP;  }
    "++"           { set_token(LINC); return LINC; }
    "--"           { set_token(LDEC); return LDEC; }
    "..."           { set_token(LDDD); return LDDD; }
    "."           { set_token(LDOT); return LDOT; }
    "{"           { set_token(LLBODY); return LLBODY; }
    "}"           { set_token(LRBODY); return LRBODY; }
    "("           { set_token(LLPAREN); return LLPAREN; }
    ")"           { set_token(LRPAREN); return LRPAREN; }
    "["           { set_token(LLBRACKET); return LLBRACKET; }
    "]"           { set_token(LRBRACKET); return LRBRACKET; }
    "+"           { set_token(LPLUS); return LPLUS; }
    "-"           { set_token(LMINUS); return LMINUS; }
    "/"           { set_token(LDIV); return LDIV; }
    "*"           { set_token(LMUL); return LMUL; }
    "%"           { set_token(LMOD); return LMOD; }
    "!"           { set_token(LNOT); return LNOT; }
    ","           { set_token(LCOMMA); return LCOMMA; } */


        /* Not supported operators */
    /*
    "<<"          { set_token(LLSH); return OPERATOR_NOT_SUPPORTED;  }
    ">>"          { set_token(LRSH); return OPERATOR_NOT_SUPPORTED;  }
    "<<="          { set_token(LINVALIDOP); return OPERATOR_NOT_SUPPORTED;  }
    ">>="          { set_token(LINVALIDOP); return OPERATOR_NOT_SUPPORTED;  }
    "/="          { set_token(LINVALIDOP); return OPERATOR_NOT_SUPPORTED;  }
    "%="          { set_token(LINVALIDOP); return OPERATOR_NOT_SUPPORTED;  }
    "<-"          { set_token(LCOMM); return LCOMM;  }
    ":"          { set_token(LINVALIDOP); return OPERATOR_NOT_SUPPORTED;  }
    "&"          { set_token(LINVALIDOP); return OPERATOR_NOT_SUPPORTED;  }
    "&^"          { set_token(LANDNOT); return OPERATOR_NOT_SUPPORTED;  }
    "&^="          { set_token(LANDNOT); return OPERATOR_NOT_SUPPORTED;  }
    "&="          { set_token(LINVALIDOP); return OPERATOR_NOT_SUPPORTED;  }
    "*="          { set_token(LINVALIDOP); return OPERATOR_NOT_SUPPORTED;  }
    "|="          { set_token(LINVALIDOP); return OPERATOR_NOT_SUPPORTED;  }
    "|"          { set_token(LINVALIDOP); return OPERATOR_NOT_SUPPORTED;  }
    ":="          { set_token(LCOLAS); return OPERATOR_NOT_SUPPORTED;  }
    "^"          { set_token(LINVALIDOP); return OPERATOR_NOT_SUPPORTED;  } */



    /* TODO: handle lexical errors */

    /* compound tokens */


    /* multiline comments */
    "/*" { BEGIN(comment); }
    <comment>"*/" {  BEGIN(INITIAL); return CCOMMENT_NOT_ALLOWED; }
    <comment>([^*]|\n)+|.
    <comment><<EOF>> { return UNTERMINATED_CCOMMENT; }

 /* single line comment */
"//".*\n    {  }


    /* string constants */
    /*
    \"[^\"\n]*\"    { sval = strip_chars(yytext); set_token(LSTRING); free(sval); return LSTRING; }
    \"[^\"\n]*$     { sval = " "; set_token(LSTRING); return UNTERMINATED_STRING;}
    */

    /* runes */
    /*
    {invalid_runes}  { set_token(LRUNE); return ILLEGAL_RUNE; }
    {runes}  { set_token(LRUNE); return LRUNE; }
    */


    /* identifiers */
    /*[a-zA-Z_]([a-zA-Z0-9_]){0,11}  { sval = ""; set_token(LNAME); return LNAME; } 
    [a-zA-Z_]([a-zA-Z0-9_]){12,}  { sval = ""; set_token(LNAME); return INVALID_VARNAME; }*/


    /* numbers */
    /*
    {imaginary}     { set_token(LIMAGINARY); return IMAGINARY_NOT_SUPPORTED; }
    {hex}  { ival = (int)strtol(yytext, NULL, 16); set_token(LHEX); return LHEX; }
    {binary}  { ival = (int)strtol(yytext, NULL, 2); set_token(LBINARY); return LBINARY; }
    {octal}  { ival = (int)strtol(yytext, NULL, 8); set_token(LOCTAL); return LOCTAL; }
    {integer}  { ival = atoi(yytext); set_token(LINT); return LINT; }
    {real}  { dval = atof(yytext); set_token(LREAL); return LREAL; } */


    /* new line, unknown characters, and eof */
        /*[ \t\n]+        { sval = "\0"; } */
"\n"					{ sval = "\0"; if(isender(lasttoken)) return tok(';'); }
[\t\f\v\r ]+				{ /* Ignore whitespace. */ }

        /*.               { set_token(LNAME); return INVALID_CHARACTER; }*/
[a-zA-Z_][a-zA-Z_0-9]*			{ set_token(LNAME); return tok(LNAME); }

"0"[xX][0-9a-fA-F]+			{ set_token(LLITERAL); return tok(LLITERAL); }
"0"[0-7]+				{ set_token(LLITERAL); return tok(LLITERAL); }
[0-9]+					{ return tok(LLITERAL); }

{float}{exponent}?			{ set_token(LLITERAL); return tok(LLITERAL); }
[0-9]+{exponent}			{ set_token(LLITERAL); return tok(LLITERAL); }

"'"(\\.|[^\\"])"'"			{ set_token(LLITERAL); return tok(LLITERAL); }

"\""(\\.|[^\\"])*"\""			{ set_token(LLITERAL); return tok(LLITERAL); }

.					{ fprintf(stderr, "%d: unexpected character `%c'\n", yylineno, yytext[0]); exit(1); }
    /* end of file */
<<EOF>>         { yylineno = 1; return tok(0); }
%%


/* return true for tokens that require a newline to insert a semi-colon */
int isender(int i)
{
	switch(i) {
	case LNAME: case LLITERAL: case ')': case '}': case ']':
	     return 1;
	}
	return 0;
}


int tok(int i)
{
   lasttoken = i;
   return i;
}