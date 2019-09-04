
%{
#include<stdlib.h>
#include "vgo.tab.h"
#include "token.h"

token_ptr yytoken;

extern char* filename;

void set_token(int category)
{
    yytoken = create_token(category, filename, yylineno, yytext, 0, 0, "\0");
}


%}
%option noyywrap noinput nounput yylineno

digit           [0-9]
letter          [a-zA-Z]
literal         {letter}({letter}|{digit})*

%%


"func"          { set_token(LFUNC); return LFUNC; }

.               {  }

\n              {  }

<<EOF>>         { yylineno = 1; return 0; }
%%
