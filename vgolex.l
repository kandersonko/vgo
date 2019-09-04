
%{
#include<stdlib.h>
#include "vgo.tab.h"
#include "token.h"

#define KEYWORD_NOT_SUPPORTED -1
#define OPERATOR_NOT_SUPPORTED -2
#define UNTERMINATED_STRING -3


token_ptr yytoken;

extern char* filename;

char *sval = "\0";


void set_token(int category)
{
    yytoken = create_token(category, filename, yylineno, yytext, 0, 0, sval);
}

char* concat(const char *s1, const char *s2)
{
    char *result = malloc(strlen(s1) + strlen(s2) + 1); // +1 for the null-terminator
    // in real code you would check for errors in malloc here
    strcpy(result, s1);
    strcat(result, s2);
    return result;
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


    /* string constant */
\"[^\"\n]*\"    { sval = yytext; set_token(LSTRING); return LSTRING; }
\"[^\"\n]*$     { sval = yytext; set_token(LSTRING); return UNTERMINATED_STRING;}

    /* new line, unknown characters, and eof */

.               {  }

[ \t\n]+        { sval = "\0"; }

<<EOF>>         { yylineno = 1; return 0; }
%%

