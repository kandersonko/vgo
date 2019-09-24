
%{
#include <stdio.h>
#include<stdlib.h>
#include "go.tab.h"
#include "token.h"
#include "tree.h"
#include "utils.h"

int lasttoken;
int isender(int);
int tok(int);


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


"/*"([^*]|"*"+[^*/])*"*"+"/"		{ /* C comment */ }
"//".*					{ /* C++ comment */ }

"{"					{ return tok('{'); }
"}"					{ return tok('}'); }
"["					{ return tok('['); }
"]"					{ return tok(']'); }
"("					{ return tok('('); }
")"					{ return tok(')'); }
";"					{ return tok(';'); }
":"					{ return tok(':'); }
"?"					{ return tok('?'); }
"."					{ return tok('.'); }
"..."					{ return tok(LDDD); }
"+"					{ return tok('+'); }
"-"					{ return tok('-'); }
"*"					{ return tok('*'); }
"/"					{ return tok('/'); }
"%"					{ return tok('%'); }
"^"					{ return tok('^'); }
"&"					{ return tok('&'); }
"|"					{ return tok('|'); }
"~"					{ return tok('~'); }
"!"					{ return tok('!'); }
"="					{ return tok(LASOP); }
":="					{ return tok(LCOLAS); }
"<"					{ return tok(LLT); }
">"					{ return tok(LGT); }
"+="					{ return tok(LASOP); }
"-="					{ return tok(LASOP); }
"*="					{ return tok(LASOP); }
"/="					{ return tok(LASOP); }
"%="					{ return tok(LASOP); }
"^="					{ return tok(LASOP); }
"&="					{ return tok(LASOP); }
"|="					{ return tok(LASOP); }
"<<"					{ return tok(LLSH); }
">>"					{ return tok(LRSH); }
"=="					{ return tok(LEQ); }
"!="					{ return tok(LNE); }
"<="					{ return tok(LLE); }
">="					{ return tok(LGE); }
"&&"					{ return tok(LANDAND); }
"&^"					{ return tok(LANDNOT); }
"||"					{ return tok(LOROR); }
"++"					{ return tok(LINC); }
"--"					{ return tok(LDEC); }
","					{ return tok(','); }
"<-"					{ return tok(LCOMM); }

"bool"					{ return tok(LNAME); }
"break"					{ return tok(LBREAK); }
"case"					{ return tok(LCASE); }
"chan"					{ return tok(LCHAN); }
"const"					{ return tok(LCONST); }
"continue"				{ return tok(LCONTINUE); }
"default"				{ return tok(LDEFAULT); }
"defer"					{ return tok(LDEFER); }
"else"					{ return tok(LELSE); }
"fallthrough"				{ return tok(LFALL); }
"float64"				{ return tok(LNAME); }
"for"					{ return tok(LFOR); }
"func"					{ return tok(LFUNC); }
"go"					{ return tok(LGO); }
"goto"					{ return tok(LGOTO); }
"if"					{ return tok(LIF); }
"import"				{ return tok(LIMPORT); }
"int"					{ return tok(LNAME); }
"interface"				{ return tok(LINTERFACE); }
"map"					{ return tok(LMAP); }
"package"				{ return tok(LPACKAGE); }
"range"					{ return tok(LRANGE); }
"return"				{ return tok(LRETURN); }
"select"				{ return tok(LSELECT); }
"struct"				{ return tok(LSTRUCT); }
"switch"				{ return tok(LSWITCH); }
"type"					{ return tok(LTYPE); }
"var"					{ return tok(LVAR); }



"\n"					{ sval = "\0"; if(isender(lasttoken)) return tok(';'); }
[\t\f\v\r ]+				{ /* Ignore whitespace. */ }

        /*.               { set_token(LNAME); return INVALID_CHARACTER; }*/
[a-zA-Z_][a-zA-Z_0-9]*			{ return tok(LNAME); }

"0"[xX][0-9a-fA-F]+			{ return tok(LLITERAL); }
"0"[0-7]+				{ return tok(LLITERAL); }
[0-9]+					{ return tok(LLITERAL); }

{float}{exponent}?			{ return tok(LLITERAL); }
[0-9]+{exponent}			{ return tok(LLITERAL); }

"'"(\\.|[^\\"])"'"			{ return tok(LLITERAL); }

"\""(\\.|[^\\"])*"\""			{ return tok(LLITERAL); }

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
   if(i) set_token(i);
   return i;
}