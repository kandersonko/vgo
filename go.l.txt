/*
 * VGo lexical analyzer, reference edition. Among other things, yours builds
 * token structures that this one omits.
 */

%{
#include <ctype.h>
#include <stdio.h>

#include "go.tab.h"

int lasttoken;
int lineno;
int isender(int);
int tok(int);

static int yywrap(void);
%}

%option nounput
%option noinput

float				([0-9]*\.[0-9]+)|([0-9]+\.)
exponent			[eE][-+]?[0-9]+

%%

"\n"					{ lineno++; if (isender(lasttoken)) return tok(';'); }
[\t\f\v\r ]+				{ /* Ignore whitespace. */ }

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

[a-zA-Z_][a-zA-Z_0-9]*			{ return tok(LNAME); }

"0"[xX][0-9a-fA-F]+			{ return tok(LLITERAL); }
"0"[0-7]+				{ return tok(LLITERAL); }
[0-9]+					{ return tok(LLITERAL); }

{float}{exponent}?			{ return tok(LLITERAL); }
[0-9]+{exponent}			{ return tok(LLITERAL); }

"'"(\\.|[^\\"])"'"			{ return tok(LLITERAL); }

"\""(\\.|[^\\"])*"\""			{ return tok(LLITERAL); }

.					{ fprintf(stderr, "%d: unexpected character `%c'\n", lineno, yytext[0]); exit(1); }

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

static int
yywrap(void)
{
	return 1;
}
