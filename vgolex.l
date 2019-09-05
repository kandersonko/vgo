
%{
#include<stdlib.h>
#include "vgo.tab.h"
#include "token.h"



token_ptr yytoken;

extern char* filename;

char *sval = "\0";


void set_token(int category)
{
    yytoken = create_token(category, filename, yylineno, yytext, 0, 0, sval);
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

%}
%option noyywrap noinput nounput yylineno

digit           [0-9]
letter          [a-zA-Z]
literal         {letter}({letter}|{digit})*

%x comment str
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




    /* Not supported operators */
"<<"          { set_token(LLSH); return OPERATOR_NOT_SUPPORTED;  }
">>"          { set_token(LRSH); return OPERATOR_NOT_SUPPORTED;  }
"<<="          { set_token(LINVALIDOP); return OPERATOR_NOT_SUPPORTED;  }
">>="          { set_token(LINVALIDOP); return OPERATOR_NOT_SUPPORTED;  }
"/="          { set_token(LINVALIDOP); return OPERATOR_NOT_SUPPORTED;  }
"%="          { set_token(LINVALIDOP); return OPERATOR_NOT_SUPPORTED;  }
"<-"          { set_token(LINVALIDOP); return OPERATOR_NOT_SUPPORTED;  }
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
"//".*\n    {  sval = yytext; set_token(LCOMMENT); return LCOMMENT; }


    /* string constant */
\"[^\"\n]*\"    { sval = strip_chars(yytext); set_token(LSTRING); free(sval); return LSTRING; }
\"[^\"\n]*$     { sval = " "; set_token(LSTRING); return UNTERMINATED_STRING;}

    /* new line, unknown characters, and eof */

.               {  }

[ \t\n]+        { sval = "\0"; }

<<EOF>>         { yylineno = 1; return 0; }
%%

