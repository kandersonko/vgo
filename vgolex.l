
%{
#include<stdlib.h>
#include "vgo.tab.h"
#include "token.h"



token_ptr yytoken;

extern char* filename;

char *sval = "\0";
int ival;
double dval;


void set_token(int category)
{
    yytoken = create_token(category, filename, yylineno, yytext, ival, dval, sval);
}

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

// TODO: handle hex, binary, octal integers (0x23, 0b101, 0o35)


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




%x comment
%%

    /* Supported keywords */
func          { set_token(LFUNC); return LFUNC; }

map          { set_token(LMAP); return LMAP; }

struct          { set_token(LSTRUCT); return LSTRUCT; }

type          { set_token(LTYPE); return LTYPE; }

const          { set_token(LCONST); return LCONST; }

package          { set_token(LPACKAGE); return LPACKAGE; }

import          { set_token(LIMPORT); return LIMPORT; }

var          { set_token(LVAR); return LVAR; }

for          { set_token(LFOR); return LFOR; }

if          { set_token(LIF); return LIF; }

else          { set_token(LELSE); return LELSE; }

return          { set_token(LRETURN); return LRETURN; }


    /* Not supported keywords */
break          { set_token(LBREAK); return KEYWORD_NOT_SUPPORTED; }
case          { set_token(LCASE); return KEYWORD_NOT_SUPPORTED; }
chan          { set_token(LCHAN); return KEYWORD_NOT_SUPPORTED; }
fallthrough          { set_token(LFALL); return KEYWORD_NOT_SUPPORTED; }
continue          { set_token(LCONTINUE); return KEYWORD_NOT_SUPPORTED; }
default          { set_token(LDEFAULT); return KEYWORD_NOT_SUPPORTED; }
defer          { set_token(LDEFER); return KEYWORD_NOT_SUPPORTED; }
goto          { set_token(LGOTO); return KEYWORD_NOT_SUPPORTED; }
range          { set_token(LRANGE); return KEYWORD_NOT_SUPPORTED; }
interface          { set_token(LINTERFACE); return KEYWORD_NOT_SUPPORTED; }
go                { set_token(LGO); return KEYWORD_NOT_SUPPORTED; }
switch          { set_token(LSWITCH); return KEYWORD_NOT_SUPPORTED; }
select          { set_token(LSELECT); return KEYWORD_NOT_SUPPORTED; }


    /* Supported operators */

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
";"           { set_token(LSEMICOLON); return LSEMICOLON; }
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
","           { set_token(LCOMMA); return LCOMMA; }


    /* Not supported operators */
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
"^"          { set_token(LINVALIDOP); return OPERATOR_NOT_SUPPORTED;  }



    /* TODO: handle lexical errors */

    /* compound tokens */


    /* comments */

"/*" { BEGIN(comment); }
<comment>"*/" {  BEGIN(INITIAL); set_token(LCCOMMENT); return CCOMMENT_NOT_ALLOWED; }
<comment>([^*]|\n)+|.
<comment><<EOF>> {  sval = yytext; set_token(LCCOMMENT); return UNTERMINATED_CCOMMENT; }
 /* C++ comment, a common extension */
"//".*\n    {  }


    /* string constant */
\"[^\"\n]*\"    { sval = strip_chars(yytext); set_token(LSTRING); free(sval); return LSTRING; }
\"[^\"\n]*$     { sval = " "; set_token(LSTRING); return UNTERMINATED_STRING;}

    /* runes */
{invalid_runes}  { set_token(LRUNE); return ILLEGAL_RUNE; }
{runes}  { set_token(LRUNE); return LRUNE; }


    /* identifier */
[a-zA-Z_]([a-zA-Z0-9_]){0,11}  { sval = ""; set_token(LNAME); return LNAME; } 
[a-zA-Z_]([a-zA-Z0-9_]){12,}  { sval = ""; set_token(LNAME); return INVALID_VARNAME; } 

    /* numbers */
{imaginary}     { set_token(LIMAGINARY); return IMAGINARY_NOT_SUPPORTED; }
{hex}  { ival = (int)strtol(yytext, NULL, 16); set_token(LHEX); return LHEX; }
{binary}  { ival = (int)strtol(yytext, NULL, 2); set_token(LBINARY); return LBINARY; }
{octal}  { ival = (int)strtol(yytext, NULL, 8); set_token(LOCTAL); return LOCTAL; }
{integer}  { ival = atoi(yytext); set_token(LINT); return LINT; }
{real}  { dval = atof(yytext); set_token(LREAL); return LREAL; }

    /* new line, unknown characters, and eof */
    /* print lexical error not recognized! */

[ \t\n]+        { sval = "\0"; }

.               { set_token(LINVALIDCHAR); return INVALID_CHARACTER; }

<<EOF>>         { yylineno = 1; return 0; }
%%

