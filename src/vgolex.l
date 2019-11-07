
%{
#include <stdio.h>
#include<stdlib.h>
#include "go.tab.h"
#include "token.h"
#include "tree.h"
#include "type.h"
#include "utils.h"

int lasttoken;
int isender(int);
int tok(int);


char* yyfilename;
char* yytext;

char *sval = "\0";
int ival;
double dval;
int basetype;

void set_token(int category)
{
yylval.t = create_token(category, yyfilename, yylineno, yytext, ival, dval, sval, basetype);
    basetype = 0;
    ival = 0;
    dval = 0.0;
    sval = "\0";
}

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


invalid_ops     "<<"|">>"|"<<="|">>="|"/="|"%="|"<-"|":"|"&"|"&^"|"&^="|"&="|"*="|"|="|"|"|":="|"^"

invalid_keywords    "break"|"case"|"chan"|"fallthrough"|"continue"|"default"|"defer"|"goto"|"range"|"interface"|"go"|"switch"|"select"

%x comment
%%


"/*"([^*]|"*"+[^*/])*"*"+"/"		{ /* C comment */ }
"//".*					{ /* C++ comment */ }

    /* Supported operators */
"=="          { return tok(LEQ); }
"<"          { return tok(LLT);   }
">"          { return tok(LGT);  }
"<="          { return tok(LLE);  }
">="          { return tok(LGE);  }
"!="          { return tok(LNE);  }
"&&"          { return tok(LANDAND);   }
"||"          { return tok(LOROR);  }
"="          { return tok('=');   }
"+="          { return tok(LASOP);   }
"-="          { return tok(LASOP);   }
"++"           { return tok(LINC); }
"--"           { return tok(LDEC); }
"..."           { return tok(LDDD); }
";"           { return tok(';');  }
"."           { return tok('.');  }
"{"           { return tok('{'); }
"}"           { return tok('}');  }
"("           { return tok('(');  }
")"           { return tok(')'); }
"["           { return tok('['); }
"]"           { return tok(']');  }
"+"           { return tok('+');  }
"-"           { return tok('-'); }
"/"           { return tok('/');  }
"*"           { return tok('*');  }
"%"           { return tok('%');  }
"!"           { return tok('!');  }
","           { return tok(','); }


    /* Not supported operators */
{invalid_ops} { fprintf(stderr, "ERROR: invalid VGO operator `%s` at line %d in file `%s`\n", yytext, yylineno, yyfilename); exit(1);}


    /* supported keywords */
"bool"					{ return tok(LNAME); }
"const"					{ return tok(LCONST); }
"else"					{ return tok(LELSE); }
"float64"				{ return tok(LNAME); }
"for"					{ return tok(LFOR); }
"func"					{ return tok(LFUNC); }
"if"					{ return tok(LIF); }
"import"				{ return tok(LIMPORT); }
"int"					{ return tok(LNAME); }
"map"					{ return tok(LMAP); }
"package"				{ return tok(LPACKAGE); }
"return"				{ return tok(LRETURN); }
"struct"				{ return tok(LSTRUCT); }
"type"					{ return tok(LTYPE); }
"var"					{ return tok(LVAR); }

    /* Not supported keywords */
{invalid_keywords}  { fprintf(stderr, "ERROR: invalid VGO keyword `%s` at line %d in file `%s`\n", yytext, yylineno, yyfilename); exit(1);}


"\n"					{ sval = "\0"; if(isender(lasttoken)) return tok(';'); }
[\t\f\v\r ]+				{ /* Ignore whitespace. */ }



[a-zA-Z_][a-zA-Z_0-9]*			{ basetype = STRING_TYPE; sval = yytext; return tok(LNAME); }

"0"[xX][0-9a-fA-F]+			{ basetype = INT_TYPE; ival = (int)strtol(yytext, NULL, 16); return tok(LLITERAL); }
"0"[0-7]+				{  basetype = INT_TYPE; ival = (int)strtol(yytext, NULL, 8); return tok(LLITERAL); }
[0-9]+					{ basetype = INT_TYPE; ival = atoi(yytext); return tok(LLITERAL); }

{float}{exponent}?			{ basetype = FLOAT64_TYPE; dval = atof(yytext); return tok(LLITERAL); }
[0-9]+{exponent}			{ basetype = FLOAT64_TYPE; ival = atoi(yytext); return tok(LLITERAL); }

"\'"(\\.|[^\\"])"\'"			{ basetype = STRING_TYPE; sval = yytext; return tok(LLITERAL); }

{invalid_runes}     {fprintf(stderr, "%d: invalid runes `%s`\n", yylineno, yytext); exit(1);}

"\""(\\.|[^\\"])*"\""			{ basetype = STRING_TYPE; sval = yytext; return tok(LLITERAL); }

.					{ fprintf(stderr, "ERROR: unexpected character `%c` at line %d in file %s\n", yytext[0], yylineno, yyfilename); exit(1); }
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