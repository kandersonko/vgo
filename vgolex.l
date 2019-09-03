
%{
#include<stdlib.h>
#include "vgo.tab.h"
#include "token.h"

token_ptr yytoken;

extern char* filename;

int lineno = 0;

void set_token(int category)
{
    char* text = (yytext) ? yytext : " ";
    yytoken = create_token(category, filename, lineno, text, 0, 0, yytext);
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
