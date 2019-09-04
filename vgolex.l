
%{
#include<stdlib.h>
#include "vgo.tab.h"
#include "token.h"

#define KEYWORD_NOT_SUPPORTED -1

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

"map"          { set_token(LMAP); return LMAP; }

"struct"          { set_token(LSTRUCT); return LSTRUCT; }

"type"          { set_token(LTYPE); return LTYPE; }

"const"          { set_token(LCONST); return LCONST; }

"package"          { set_token(LPACKAGE); return LPACKAGE; }

"import"          { set_token(LIMPORT); return LIMPORT; }

"var"          { set_token(LVAR); return LVAR; }

"for"          { set_token(LFOR); return LFOR; }

"if"          { set_token(LIF); return LIF; }

"else"          { set_token(LELSE); return LELSE; }

"return"          { set_token(LRETURN); return LRETURN; }



"break"          { set_token(LBREAK); return KEYWORD_NOT_SUPPORTED; }
"case"          { set_token(LCASE); return KEYWORD_NOT_SUPPORTED; }
"chan"          { set_token(LCHAN); return KEYWORD_NOT_SUPPORTED; }
"fallthrough"          { set_token(LFALL); return KEYWORD_NOT_SUPPORTED; }
"continue"          { set_token(LCONTINUE); return KEYWORD_NOT_SUPPORTED; }
"default"          { set_token(LDEFAULT); return KEYWORD_NOT_SUPPORTED; }
"defer"          { set_token(LDEFER); return KEYWORD_NOT_SUPPORTED; }
"goto"          { set_token(LGOTO); return KEYWORD_NOT_SUPPORTED; }
"range"          { set_token(LRANGE); return KEYWORD_NOT_SUPPORTED; }
"interface"          { set_token(LINTERFACE); return KEYWORD_NOT_SUPPORTED; }
"go"          { set_token(LGO); return KEYWORD_NOT_SUPPORTED; }
"switch"          { set_token(LSWITCH); return KEYWORD_NOT_SUPPORTED; }
"select"          { set_token(LSELECT); return KEYWORD_NOT_SUPPORTED; }











.               {  }

\n              {  }

<<EOF>>         { yylineno = 1; return 0; }
%%

