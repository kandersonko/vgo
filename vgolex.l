
%{
#include<stdlib.h>
#include "vgo.tab.h"
#include "token.h"

token_ptr yytoken;

extern char* filename;

int lineno = 0;

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
literal         { set_token(LLITERAL); return LLITERAL; }

\n { ++lineno; }

<<EOF>> return 0;
%%
