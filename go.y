// Copyright 2009 The Go Authors. All rights reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file
// (a copy is at www2.cs.uidaho.edu/~jeffery/courses/445/go/LICENSE).

/*
 * Go language grammar adapted from Go 1.2.2.
 *
 * The Go semicolon rules are:
 *
 *  1. all statements and declarations are terminated by semicolons.
 *  2. semicolons can be omitted before a closing ) or }.
 *  3. semicolons are inserted by the lexer before a newline
 *      following a specific list of tokens.
 *
 * Rules #1 and #2 are accomplished by writing the lists as
 * semicolon-separated lists with an optional trailing semicolon.
 * Rule #3 is implemented in yylex.
 */

%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "token.h"
#include "tree.h"
#include "utils.h"
#include "rules.h"

// #define YYDEBUG 1
// int yydebug=1;

// TODO: Remove all warnings (useless rule, etc)

struct tree* ast_root;

int yylex (void);
// void yyerror (char const *);

int yylast;
int yyprev;

// for location tracking
// typedef struct YYLTYPE
// {
// 	int first_line;
// 	int first_column;
// 	int last_line;
// 	int last_column;
// } YYLTYPE;

enum ErrorCode error_code;
char* yyfilename;
int yylineno;
char* yytext;

int ruleno = 0;

void yyerror(const char *s)
{
	fprintf(stderr, "%s\n", s);
	fprintf(stderr, "syntax error: unexpected '%s' token in file %s, line %d\n",
	   yytext,yyfilename, yylineno);
	exit(2);
}


%}

// specify union types
%union {
	struct tree* ast;
	struct token* t;
}

%token<t>		LLITERAL
%token<t>		LASOP LCOLAS
%token<t>		LBREAK LCASE LCHAN LCONST LCONTINUE LDDD
%token<t>		LDEFAULT LDEFER LELSE LFALL LFOR LFUNC LGO LGOTO
%token<t>		LIF LIMPORT LINTERFACE LMAP LNAME
%token<t>		LPACKAGE LRANGE LRETURN LSELECT LSTRUCT LSWITCH
%token<t>		LTYPE LVAR

%token<t>		LANDAND LANDNOT LBODY LCOMM LDEC LEQ LGE LGT
%token<t>		LIGNORE LINC LLE LLSH LLT LNE LOROR LRSH


%type<ast>		file

%type<ast>		package lconst

%type<ast> 		imports import import_stmt import_safety 
%type<ast> 		import_stmt_list import_package
%type<ast>		osemi

%type<ast> 		lbrace import_here
%type<ast>		sym packname fnlitdcl 
%type<ast>		oliteral error

%type<ast>		stmt ntype 
%type<ast>		arg_type 
%type<ast>		compound_stmt dotname embed expr complitexpr bare_complitexpr
%type<ast>		expr_or_type
%type<ast>		fndcl fnliteral
%type<ast>		for_body for_header for_stmt if_header if_stmt non_dcl_stmt
%type<ast>		keyval labelname name
%type<ast>		name_or_type non_expr_type
%type<ast>		new_name dcl_name oexpr typedclname
%type<ast>		osimple_stmt pexpr pexpr_no_paren
%type<ast>		pseudocall 
%type<ast>		simple_stmt 
%type<ast>		uexpr 
%type<ast>		xfndcl typedcl start_complit

%type<ast>		xdcl fnbody fnres loop_body dcl_name_list
%type<ast>		new_name_list expr_list keyval_list braced_keyval_list expr_or_type_list xdcl_list
%type<ast>		oexpr_list elseif elseif_list else stmt_list oarg_type_list_ocomma ocomma arg_type_list
%type<ast>		vardcl vardcl_list structdcl structdcl_list
%type<ast>		common_dcl constdcl constdcl1 constdcl_list typedcl_list

%type<ast>		convtype comptype dotdotdot
%type<ast>		structtype ptrtype
%type<ast>		othertype fnret_type fntype

%type<ast>		hidden_importsym



%left		LCOMM	/* outside the usual hierarchy; here for good error<token> messages */

%left		LOROR
%left		LANDAND
%left		LEQ LNE LLE LGE LLT LGT
%left		'+' '-' '|' '^'
%left		'*' '/' '%' '&' LLSH LRSH LANDNOT

%type<t>	'{' '}' '?' '+' '-' '|' '^' '*' '/' '%' '&' ';' ',' '`' '.' '='

/*
 * manual override of shift/reduce conflicts.
 * the general form is that we assign a precedence
 * to the token being shifted and then introduce
 * NotToken with lower precedence or PreferToToken with higher
 * and annotate the reducing rule accordingly.
 */
%left		NotPackage
%left		LPACKAGE

%left		NotParen
%left<t>	'('

%left<t>	')'
%left		PreferToRightParen


%error-verbose

%token END 0 "end of file"

// TODO: free unused token to prevent memory leak

%%
file:	package imports xdcl_list
	{
		// tree_ptr new_tree_node(int prodrule, char *prodname, int nkids, struct tree **kids, struct token *leaf)
		// struct tree **create_tree_kids(int nkids, ...)
		struct token *leaf = NULL;
		int nkids = 3;
		struct tree** kids = create_tree_kids(nkids, $1, $2, $3);
		$$ = new_tree_node(R_FILE, "file", nkids, kids, leaf);
		ast_root = $$;
	}
;

package:
	%empty %prec NotPackage 
	{
		yyerror("package statement must be first");
		$$ = NULL;
		exit(2);
	}
|	LPACKAGE sym ';' 
	{ 
		// tree_ptr new_tree_node(int prodrule, char *prodname, int nkids, struct tree **kids, struct token *leaf)
		// struct tree **create_tree_kids(int nkids, ...)
		struct token *leaf = $1;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $2);
		$$ = new_tree_node(++ruleno, "package", nkids, kids, leaf);
	}
;

imports:
	%empty
	{
		$$ = NULL;
	}	
|	imports import ';' 
	{
		struct token *leaf = $3;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, $1, $2);
		$$ = new_tree_node(++ruleno, "imports", nkids, kids, leaf);
	}
;

import:
	LIMPORT import_stmt
	{
		struct token *leaf = $1;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $2);
		$$ = new_tree_node(++ruleno, "import", nkids, kids, leaf);
	}
|	LIMPORT '(' import_stmt_list osemi ')'
	{
		struct token *leaf = $1;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, $3, $4);
		$$ = new_tree_node(++ruleno, "import", nkids, kids, leaf);
	}
|	LIMPORT '(' ')'
	{
		struct token *leaf = $1;
		int nkids = 0;
		struct tree** kids = NULL;
		$$ = new_tree_node(++ruleno, "import", nkids, kids, leaf);
	}
;

import_stmt:
	import_here import_package
	{
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, $1, $2);
		$$ = new_tree_node(++ruleno, "import_stmt", nkids, kids, leaf);
	}
|	import_here
	{
		$$ = $1;
	}
;

import_stmt_list:
	import_stmt
	{
		$$ = $1;
	}
|	import_stmt_list ';' import_stmt
	{
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, $1, $3);
		$$ = new_tree_node(++ruleno, "import_stmt_list", nkids, kids, leaf);
	}
;

import_here:
	LLITERAL
	{
		struct token *leaf = $1;
		int nkids = 0;
		struct tree** kids = NULL;
		$$ = new_tree_node(++ruleno, "import_here", nkids, kids, leaf);
	}
|	sym LLITERAL
	{
		struct token *leaf = $2;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $1);
		$$ = new_tree_node(++ruleno, "import_here", nkids, kids, leaf);
	}
|	'.' LLITERAL
	{
		struct token *leaf = $2;
		int nkids = 0;
		struct tree** kids = NULL;
		$$ = new_tree_node(++ruleno, "import_here", nkids, kids, leaf);
	}
;

import_package:
	LPACKAGE LNAME import_safety ';'
	{
		// TODO: concat package and name
		struct token *leaf = $2;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $3);
		$$ = new_tree_node(++ruleno, "import_package", nkids, kids, leaf);
	}
;

import_safety:
	%empty
	{
		$$ = NULL;
	}
|	LNAME
	{
		struct token *leaf = $1;
		int nkids = 1;
		struct tree** kids = NULL;
		$$ = new_tree_node(++ruleno, "import_safety", nkids, kids, leaf);
	}
;

/*
 * declarations
 */
xdcl:
	%empty 
	{
		yyerror("empty top-level declaration");
		$$ = NULL;
	}
|	common_dcl
	{
		$$ = $1;
	}
|	xfndcl
	{
		$$ = $1;
	}
|	non_dcl_stmt
	{
		yyerror("non-declaration statement outside function body");
		$$ = $1;
	}
|	error
	{
		$$ = $1;
	}
	;

common_dcl:
	LVAR vardcl
	{
		struct token *leaf = $1;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $2);
		$$ = new_tree_node(++ruleno, "common_dcl", nkids, kids, leaf);
	}
|	LVAR '(' vardcl_list osemi ')'
	{
		struct token *leaf = $1;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, $3, $4);
		$$ = new_tree_node(++ruleno, "common_dcl", nkids, kids, leaf);
	}
|	LVAR '(' ')'
	{
		struct token *leaf = $1;
		int nkids = 0;
		struct tree** kids = NULL;
		$$ = new_tree_node(++ruleno, "common_dcl", nkids, kids, leaf);
	}
|	lconst constdcl
	{
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, $1, $2);
		$$ = new_tree_node(++ruleno, "common_dcl", nkids, kids, leaf);
	}
|	lconst '(' constdcl osemi ')'
	{
		struct token *leaf = NULL;
		int nkids = 3;
		struct tree** kids = create_tree_kids(nkids, $1, $3, $4);
		$$ = new_tree_node(++ruleno, "common_dcl", nkids, kids, leaf);
	}
|	lconst '(' constdcl ';' constdcl_list osemi ')'
	{
		struct token *leaf = NULL;
		int nkids = 4;
		struct tree** kids = create_tree_kids(nkids, $1, $3, $5, $6);
		$$ = new_tree_node(++ruleno, "common_dcl", nkids, kids, leaf);
	}
|	lconst '(' ')'
	{
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $1);
		$$ = new_tree_node(++ruleno, "common_dcl", nkids, kids, leaf);
	}
|	LTYPE typedcl
	{
		struct token *leaf = $1;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $2);
		$$ = new_tree_node(++ruleno, "common_dcl", nkids, kids, leaf);
	}
|	LTYPE '(' typedcl_list osemi ')'
	{
		struct token *leaf = $1;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, $3, $4);
		$$ = new_tree_node(++ruleno, "common_dcl", nkids, kids, leaf);
	}
|	LTYPE '(' ')'
	{
		struct token *leaf = $1;
		int nkids = 0;
		struct tree** kids = NULL;
		$$ = new_tree_node(++ruleno, "common_dcl", nkids, kids, leaf);
	}
;

lconst:
	LCONST
	{
		struct token *leaf = $1;
		int nkids = 0;
		struct tree** kids = NULL;
		$$ = new_tree_node(++ruleno, "lconst", nkids, kids, leaf);
	}
;

vardcl:
	dcl_name_list ntype
	{
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, $1, $2);
		$$ = new_tree_node(++ruleno, "vardcl", nkids, kids, leaf);
	}
|	dcl_name_list ntype '=' expr_list
	{
		struct token *leaf = $3;
		int nkids = 3;
		struct tree** kids = create_tree_kids(nkids, $1, $2, $4);
		$$ = new_tree_node(++ruleno, "vardcl", nkids, kids, leaf);
	}
|	dcl_name_list '=' expr_list
	{
		struct token *leaf = $2;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, $1, $3);
		$$ = new_tree_node(++ruleno, "vardcl", nkids, kids, leaf);
	}
	;

constdcl:
	dcl_name_list ntype '=' expr_list
	{
		struct token *leaf = $3;
		int nkids = 3;
		struct tree** kids = create_tree_kids(nkids, $1, $2, $4);
		$$ = new_tree_node(++ruleno, "constdcl", nkids, kids, leaf);
	}
|	dcl_name_list '=' expr_list
	{
		struct token *leaf = $2;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, $1, $3);
		$$ = new_tree_node(++ruleno, "constdcl", nkids, kids, leaf);
	}
;

constdcl1:
	constdcl
	{
		$$ = $1;
	}
|	dcl_name_list ntype
	{
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, $1, $2);
		$$ = new_tree_node(++ruleno, "constdcl1", nkids, kids, leaf);
	}
|	dcl_name_list
	{
		$$ = $1;
	}
;

typedclname:
	sym
	{
		// the name becomes visible right here, not at the end
		// of the declaration.
		$$ = $1;
	}
;

typedcl:
	typedclname ntype
	{
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, $1, $2);
		$$ = new_tree_node(++ruleno, "typedcl", nkids, kids, leaf);
	}
;

simple_stmt:
	expr
	{
		$$ = $1;
	}
|	expr LASOP expr
	{
		struct token *leaf = $2;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, $1, $3);
		$$ = new_tree_node(++ruleno, "simple_stmt", nkids, kids, leaf);
	}
|	expr_list '=' expr_list
	{
		struct token *leaf = $2;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, $1, $3);
		$$ = new_tree_node(++ruleno, "simple_stmt", nkids, kids, leaf);
	}
|	expr_list LCOLAS expr_list
	{
		struct token *leaf = $2;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, $1, $3);
		$$ = new_tree_node(++ruleno, "simple_stmt", nkids, kids, leaf);
	}
|	expr LINC
	{
		struct token *leaf = $2;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $1);
		$$ = new_tree_node(++ruleno, "simple_stmt", nkids, kids, leaf);
	}
|	expr LDEC
	{
		struct token *leaf = $2;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $1);
		$$ = new_tree_node(++ruleno, "simple_stmt", nkids, kids, leaf);
	}
;

compound_stmt:
	'{' 
	stmt_list '}'
	{
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $2);
		$$ = new_tree_node(++ruleno, "compound_stmt", nkids, kids, leaf);
	}
;

loop_body:
	LBODY
	stmt_list '}'
	{
		struct token *leaf = $1;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $2);
		$$ = new_tree_node(++ruleno, "loop_body", nkids, kids, leaf);
	}
;

for_header:
	osimple_stmt ';' osimple_stmt ';' osimple_stmt
	{
		struct token *leaf = NULL;
		int nkids = 3;
		struct tree** kids = create_tree_kids(nkids, $1, $3, $5);
		$$ = new_tree_node(++ruleno, "for_header", nkids, kids, leaf);
	}
|	osimple_stmt
	{
		$$ = $1;
	}
;

for_body:
	for_header loop_body
	{
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, $1, $2);
		$$ = new_tree_node(++ruleno, "for_body", nkids, kids, leaf);
	}
;

for_stmt:
	LFOR
	for_body
	{
		struct token *leaf = $1;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $2);
		$$ = new_tree_node(++ruleno, "for_stmt", nkids, kids, leaf);
	}
	;

if_header:
	osimple_stmt
	{
		$$ = $1;
	}
|	osimple_stmt ';' osimple_stmt
	{
		struct token *leaf = $2;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, $1, $3);
		$$ = new_tree_node(++ruleno, "if_header", nkids, kids, leaf);
	}
;

/* IF cond body (ELSE IF cond body)* (ELSE block)? */
if_stmt:
	LIF
	if_header
	loop_body
	elseif_list else
	{
		struct token *leaf = $1;
		int nkids = 4;
		struct tree** kids = create_tree_kids(nkids, $2, $3, $4, $5);
		$$ = new_tree_node(++ruleno, "if_stmt", nkids, kids, leaf);
	}
;

elseif:
	LELSE LIF 
	if_header loop_body
	{
		struct token *leaf = $1; // TODO: maybe concat tokens "elseif"
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, $3, $4);
		$$ = new_tree_node(++ruleno, "elseif", nkids, kids, leaf);
	}
;

elseif_list:
	%empty
	{
		$$ = NULL;
	}
|	elseif_list elseif
	{
		struct token *leaf = NULL; 
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, $1, $2);
		$$ = new_tree_node(++ruleno, "elseif_list", nkids, kids, leaf);
	}
;

else:
	%empty
	{
		$$ = NULL;
	}
|	LELSE compound_stmt
	{
		struct token *leaf = $1;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $2);
		$$ = new_tree_node(++ruleno, "else", nkids, kids, leaf);
	}
;

/*
 * expressions
 */
expr:
	uexpr
	{
		$$ = $1;
	}
|	expr LOROR expr
	{
		struct token *leaf = $2;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, $1, $3);
		$$ = new_tree_node(++ruleno, "expr", nkids, kids, leaf);
	}
|	expr LANDAND expr
	{
		struct token *leaf = $2;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, $1, $3);
		$$ = new_tree_node(++ruleno, "expr", nkids, kids, leaf);
	}
|	expr LEQ expr
	{
		struct token *leaf = $2;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, $1, $3);
		$$ = new_tree_node(++ruleno, "expr", nkids, kids, leaf);
	}
|	expr LNE expr
	{
		struct token *leaf = $2;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, $1, $3);
		$$ = new_tree_node(++ruleno, "expr", nkids, kids, leaf);
	}
|	expr LLT expr
	{
		struct token *leaf = $2;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, $1, $3);
		$$ = new_tree_node(++ruleno, "expr", nkids, kids, leaf);
	}
|	expr LLE expr
	{
		struct token *leaf = $2;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, $1, $3);
		$$ = new_tree_node(++ruleno, "expr", nkids, kids, leaf);
	}
|	expr LGE expr
	{
		struct token *leaf = $2;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, $1, $3);
		$$ = new_tree_node(++ruleno, "expr", nkids, kids, leaf);
	}
|	expr LGT expr
	{
		struct token *leaf = $2;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, $1, $3);
		$$ = new_tree_node(++ruleno, "expr", nkids, kids, leaf);
	}
|	expr '+' expr
	{
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, $1, $3);
		$$ = new_tree_node(++ruleno, "expr", nkids, kids, leaf);
	}
|	expr '-' expr
	{
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, $1, $3);
		$$ = new_tree_node(++ruleno, "expr", nkids, kids, leaf);
	}
|	expr '|' expr
	{
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, $1, $3);
		$$ = new_tree_node(++ruleno, "expr", nkids, kids, leaf);
	}
|	expr '^' expr
	{
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, $1, $3);
		$$ = new_tree_node(++ruleno, "expr", nkids, kids, leaf);
	}
|	expr '*' expr
	{
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, $1, $3);
		$$ = new_tree_node(++ruleno, "expr", nkids, kids, leaf);
	}
|	expr '/' expr
	{
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, $1, $3);
		$$ = new_tree_node(++ruleno, "expr", nkids, kids, leaf);
	}
|	expr '%' expr
	{
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, $1, $3);
		$$ = new_tree_node(++ruleno, "expr", nkids, kids, leaf);
	}
|	expr '&' expr
	{
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, $1, $3);
		$$ = new_tree_node(++ruleno, "expr", nkids, kids, leaf);
	}
|	expr LANDNOT expr
	{
		struct token *leaf = $2;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, $1, $3);
		$$ = new_tree_node(++ruleno, "expr", nkids, kids, leaf);
	}
|	expr LLSH expr
	{
		struct token *leaf = $2;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, $1, $3);
		$$ = new_tree_node(++ruleno, "expr", nkids, kids, leaf);
	}
|	expr LRSH expr
	/* not an expression anymore, but left in so we can give a good error */
	{
		struct token *leaf = $2;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, $1, $3);
		$$ = new_tree_node(++ruleno, "expr", nkids, kids, leaf);
	}
|	expr LCOMM expr
	{
		struct token *leaf = $2;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, $1, $3);
		$$ = new_tree_node(++ruleno, "expr", nkids, kids, leaf);
	}
;

uexpr:
	pexpr
	{
		$$ = $1;
	}
|	'*' uexpr
	{
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $2);
		$$ = new_tree_node(++ruleno, "uexpr", nkids, kids, leaf);
	}
|	'&' uexpr
	{
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $2);
		$$ = new_tree_node(++ruleno, "uexpr", nkids, kids, leaf);
	}
|	'+' uexpr
	{
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $2);
		$$ = new_tree_node(++ruleno, "uexpr", nkids, kids, leaf);
	}
|	'-' uexpr
	{
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $2);
		$$ = new_tree_node(++ruleno, "uexpr", nkids, kids, leaf);
	}
|	'!' uexpr
	{
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $2);
		$$ = new_tree_node(++ruleno, "uexpr", nkids, kids, leaf);
	}
|	'~' uexpr
	{
		yyerror("the bitwise complement operator is ^");
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $2);
		$$ = new_tree_node(++ruleno, "uexpr", nkids, kids, leaf);
	}
|	'^' uexpr
	{
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $2);
		$$ = new_tree_node(++ruleno, "uexpr", nkids, kids, leaf);
	}
|	LCOMM uexpr
	{
		struct token *leaf = $1;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $2);
		$$ = new_tree_node(++ruleno, "uexpr", nkids, kids, leaf);
	}
;

/*
 * call-like statements that
 * can be preceded by 'defer' and 'go'
 */
pseudocall:
	pexpr '(' ')'
	{
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $1);
		$$ = new_tree_node(++ruleno, "pseudocall", nkids, kids, leaf);
	}
|	pexpr '(' expr_or_type_list ocomma ')'
	{
		struct token *leaf = NULL;
		int nkids = 3;
		struct tree** kids = create_tree_kids(nkids, $1, $3, $4);
		$$ = new_tree_node(++ruleno, "pseudocall", nkids, kids, leaf);
	}
|	pexpr '(' expr_or_type_list LDDD ocomma ')'
	{
		struct token *leaf = $4;
		int nkids = 3;
		struct tree** kids = create_tree_kids(nkids, $1, $3, $5);
		$$ = new_tree_node(++ruleno, "pseudocall", nkids, kids, leaf);
	}
;

pexpr_no_paren:
	LLITERAL
	{
		struct token *leaf = $1;
		int nkids = 0;
		struct tree** kids = NULL;
		$$ = new_tree_node(++ruleno, "pexpr_no_paren", nkids, kids, leaf);
	}
|	name
	{
		$$ = $1;
	}
|	pexpr '.' sym
	{
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, $1, $3);
		$$ = new_tree_node(++ruleno, "pexpr_no_paren", nkids, kids, leaf);
	}
|	pexpr '.' '(' expr_or_type ')'
	{
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, $1, $4);
		$$ = new_tree_node(++ruleno, "pexpr_no_paren", nkids, kids, leaf);
	}
|	pexpr '.' '(' LTYPE ')'
	{
		struct token *leaf = $4;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $1);
		$$ = new_tree_node(++ruleno, "pexpr_no_paren", nkids, kids, leaf);
	}
|	pexpr '[' expr ']'
	{
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, $1, $3);
		$$ = new_tree_node(++ruleno, "pexpr_no_paren", nkids, kids, leaf);
	}
|	pexpr '[' oexpr ':' oexpr ']'
	{
		struct token *leaf = NULL;
		int nkids = 3;
		struct tree** kids = create_tree_kids(nkids, $1, $3, $5);
		$$ = new_tree_node(++ruleno, "pexpr_no_paren", nkids, kids, leaf);
	}
|	pexpr '[' oexpr ':' oexpr ':' oexpr ']'
	{
		struct token *leaf = NULL;
		int nkids = 4;
		struct tree** kids = create_tree_kids(nkids, $1, $3, $5, $7);
		$$ = new_tree_node(++ruleno, "pexpr_no_paren", nkids, kids, leaf);
	}
|	pseudocall
	{
		$$ = $1;
	}
|	convtype '(' expr ocomma ')'
	{
		struct token *leaf = NULL;
		int nkids = 3;
		struct tree** kids = create_tree_kids(nkids, $1, $3, $4);
		$$ = new_tree_node(++ruleno, "pexpr_no_paren", nkids, kids, leaf);
	}
|	comptype lbrace start_complit braced_keyval_list '}'
	{
		struct token *leaf = NULL;
		int nkids = 4;
		struct tree** kids = create_tree_kids(nkids, $1, $2, $3, $4);
		$$ = new_tree_node(++ruleno, "pexpr_no_paren", nkids, kids, leaf);
	}
|	pexpr_no_paren '{' start_complit braced_keyval_list '}'
	{
		struct token *leaf = NULL;
		int nkids = 3;
		struct tree** kids = create_tree_kids(nkids, $1, $3, $4);
		$$ = new_tree_node(++ruleno, "pexpr_no_paren", nkids, kids, leaf);
	}
|	'(' expr_or_type ')' '{' start_complit braced_keyval_list '}'
	{
		yyerror("cannot parenthesize type in composite literal");

		struct token *leaf = NULL;
		int nkids = 3;
		struct tree** kids = create_tree_kids(nkids, $2, $5, $6);
		$$ = new_tree_node(++ruleno, "pexpr_no_paren", nkids, kids, leaf);
	}
|	fnliteral
	{
		$$ = $1;
	}
;

start_complit:
	%empty
	{
		// composite expression.
		// make node early so we get the right line number.
		$$ = NULL;
	}
;

keyval:
	expr ':' complitexpr
	{
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, $1, $3);
		$$ = new_tree_node(++ruleno, "keyval", nkids, kids, leaf);
	}
;

bare_complitexpr:
	expr
	{
		$$ = $1;
	}
|	'{' start_complit braced_keyval_list '}'
	{
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, $2, $3);
		$$ = new_tree_node(++ruleno, "bare_complitexpr", nkids, kids, leaf);
	}
;

complitexpr:
	expr
	{
		$$ = $1;
	}
|	'{' start_complit braced_keyval_list '}'
	{
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, $2, $3);
		$$ = new_tree_node(++ruleno, "complitexpr", nkids, kids, leaf);
	}
;

pexpr:
	pexpr_no_paren
	{
		$$ = $1;
	}
|	'(' expr_or_type ')'
	{
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $2);
		$$ = new_tree_node(++ruleno, "pexpr", nkids, kids, leaf);
	}
;

expr_or_type:
	expr
	{
		$$ = $1;
	}
|	non_expr_type	%prec PreferToRightParen
	{
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $1);
		$$ = new_tree_node(++ruleno, "expr_or_type", nkids, kids, leaf);
	}
;

name_or_type:
	ntype
	{
		$$ = $1;

	}
;

lbrace:
	LBODY
	{
		struct token *leaf = $1;
		int nkids = 0;
		struct tree** kids = NULL;
		$$ = new_tree_node(++ruleno, "lbrace", nkids, kids, leaf);
	}
|	'{'
	{
		struct token *leaf = $1;
		int nkids = 0;
		struct tree** kids = NULL;
		$$ = new_tree_node(++ruleno, "lbrace", nkids, kids, leaf);
	}
;

/*
 * names and types
 *	newname is used before declared
 *	oldname is used after declared
 */
new_name:
	sym
	{
		$$ = $1;
	}
;

dcl_name:
	sym
	{
		$$ = $1;
	}
;

sym:
	LNAME
	{
		struct token* leaf = $1;
		int nkids = 0;
		struct tree** kids = NULL;
		$$ = new_tree_node(++ruleno, "sym", nkids, kids, leaf);
	}
|	hidden_importsym
	{
		$$ = $1;
	}
|	'?'
	{
		struct token* leaf = $1;
		int nkids = 0;
		struct tree** kids = NULL;
		$$ = new_tree_node(++ruleno, "sym", nkids, kids, leaf);
	}
;

hidden_importsym:
	'@' LLITERAL '.' LNAME
	{
		struct token* leaf = $2; // TODO: concat tokens ?
		int nkids = 0;
		struct tree** kids = NULL;
		$$ = new_tree_node(++ruleno, "sym", nkids, kids, leaf);
	}
|	'@' LLITERAL '.' '?'
	{
		struct token* leaf = $2; // TODO: concat tokens ?
		int nkids = 0;
		struct tree** kids = NULL;
		$$ = new_tree_node(++ruleno, "sym", nkids, kids, leaf);
	}
;

name:
	sym	%prec NotParen
	{
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $1);
		$$ = new_tree_node(++ruleno, "name", nkids, kids, leaf);
	}
;

labelname:
	new_name
	{
		$$ = $1;
	}
;

/*
 * to avoid parsing conflicts, type is split into
 *	channel types
 *	function types
 *	parenthesized types
 *	any other type
 * the type system makes additional restrictions,
 * but those are not implemented in the grammar.
 */
dotdotdot:
	LDDD
	{
		yyerror("final argument in variadic function missing type");

		struct token *leaf = $1;
		int nkids = 0;
		struct tree** kids = NULL;
		$$ = new_tree_node(++ruleno, "dotdotdot", nkids, kids, leaf);
	}
|	LDDD ntype
	{
		struct token *leaf = $1;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $2);
		$$ = new_tree_node(++ruleno, "dotdotdot", nkids, kids, leaf);
	}
;

ntype:
	fntype
	{
		$$ = $1;
	}
|	othertype
	{
		$$ = $1;
	}
|	ptrtype
	{
		$$ = $1;
	}
|	dotname
	{
		$$ = $1;
	}
|	'(' ntype ')'
	{
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $2);
		$$ = new_tree_node(++ruleno, "ntype", nkids, kids, leaf);
	}
;

non_expr_type:
	fntype
	{
		$$ = $1;
	}
|	othertype
	{
		$$ = $1;
	}
|	'*' non_expr_type
	{
		struct token *leaf = $1;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $2);
		$$ = new_tree_node(++ruleno, "non_expr_type", nkids, kids, leaf);
	}
;

convtype:
	fntype
	{
		$$ = $1;
	}
|	othertype
	{
		$$ = $1;
	}
;

comptype:
	othertype
	{
		$$ = $1;
	}
;

fnret_type:
	fntype
	{
		$$ = $1;
	}
|	othertype
	{
		$$ = $1;
	}
|	ptrtype
	{
		$$ = $1;
	}
|	dotname
	{
		$$ = $1;
	}
;

dotname:
	name
	{
		$$ = $1;
	}
|	name '.' sym
	{
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, $1, $3);
		$$ = new_tree_node(++ruleno, "dotname", nkids, kids, leaf);
	}
;

othertype:
	'[' oexpr ']' ntype
	{
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, $2, $4);
		$$ = new_tree_node(++ruleno, "othertype", nkids, kids, leaf);
	}	
|	'[' LDDD ']' ntype
	{
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, $2, $4);
		$$ = new_tree_node(++ruleno, "othertype", nkids, kids, leaf);
	}
|	LMAP '[' ntype ']' ntype
	{
		struct token *leaf = NULL;
		int nkids = 3;
		struct tree** kids = create_tree_kids(nkids, $1, $3, $5);
		$$ = new_tree_node(++ruleno, "othertype", nkids, kids, leaf);
	}
|	structtype
	{
		$$ = $1;
	}
;

ptrtype:
	'*' ntype
	{
		$$ = $2;
	}
;

structtype:
	LSTRUCT lbrace structdcl_list osemi '}'
	{
		struct token *leaf = $1;
		int nkids = 3;
		struct tree** kids = create_tree_kids(nkids, $2, $3, $4);
		$$ = new_tree_node(++ruleno, "structtype", nkids, kids, leaf);
	}
|	LSTRUCT lbrace '}'
	{
		struct token *leaf = $1;	
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $2);
		$$ = new_tree_node(++ruleno, "structtype", nkids, kids, leaf);
	}
;

/*
 * function stuff
 * all in one place to show how crappy it all is
 */
xfndcl:
	LFUNC fndcl fnbody
	{
		struct token *leaf = $1;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, $2, $3);
		$$ = new_tree_node(++ruleno, "xfndcl", nkids, kids, leaf);
	}
;

fndcl:
	sym '(' oarg_type_list_ocomma ')' fnres
	{
		struct token *leaf = NULL;
		int nkids = 3;
		struct tree** kids = create_tree_kids(nkids, $1, $3, $5);
		$$ = new_tree_node(++ruleno, "fndcl", nkids, kids, leaf);
	}
|	'(' oarg_type_list_ocomma ')' sym '(' oarg_type_list_ocomma ')' fnres
	{
		struct token *leaf = NULL;
		int nkids = 4;
		struct tree** kids = create_tree_kids(nkids, $2, $4, $6, $8);
		$$ = new_tree_node(++ruleno, "fndcl", nkids, kids, leaf);
	}
;


fntype:
	LFUNC '(' oarg_type_list_ocomma ')' fnres
	{
		struct token *leaf = $1;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, $3, $5);
		$$ = new_tree_node(++ruleno, "fntype", nkids, kids, leaf);
	}
;

fnbody:
	%empty
	{
		$$ = NULL;
	}
|	'{' stmt_list '}'
	{
		$$ = $2;
	}
;

fnres:
	%empty %prec NotParen
	{
		$$ = NULL;
	}
|	fnret_type
	{
		$$ = $1;
	}
|	'(' oarg_type_list_ocomma ')'
	{
		$$ = $2;
	}
;

fnlitdcl:
	fntype
	{
		$$ = $1;
	}
;

fnliteral:
	fnlitdcl lbrace stmt_list '}'
	{
		struct token *leaf = NULL;
		int nkids = 3;
		struct tree** kids = create_tree_kids(nkids, $1, $2, $3);
		$$ = new_tree_node(++ruleno, "fnliteral", nkids, kids, leaf);
	}
|	fnlitdcl error
	{
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, $1, $2);
		$$ = new_tree_node(++ruleno, "fnliteral", nkids, kids, leaf);
	}
;

/*
 * lists of things
 * note that they are left recursive to conserve yacc stack. they need to
 * be reversed to interpret correctly
 */
xdcl_list:
	%empty
	{
		$$ = NULL;
	}
|	xdcl_list xdcl ';'
	{
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, $1, $2);
		$$ = new_tree_node(++ruleno, "xdcl_list", nkids, kids, leaf);
	}
;

vardcl_list:
	vardcl
	{
		$$ = $1;
	}
|	vardcl_list ';' vardcl
	{
		struct token *leaf = $2;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, $1, $3);
		$$ = new_tree_node(++ruleno, "vardcl_list", nkids, kids, leaf);
	}
;

constdcl_list:
	constdcl1
	{
		$$ = $1;
	}
|	constdcl_list ';' constdcl1
	{
		struct token *leaf = $2;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, $1, $3);
		$$ = new_tree_node(++ruleno, "constdcl_list", nkids, kids, leaf);
	}
;

typedcl_list:
	typedcl
	{
		$$ = $1;
	}
|	typedcl_list ';' typedcl
	{
		struct token *leaf = $2;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, $1, $3);
		$$ = new_tree_node(++ruleno, "typedcl_list", nkids, kids, leaf);
	}
;

structdcl_list:
	structdcl
	{
		$$ = $1;
	}
|	structdcl_list ';' structdcl
	{
		struct token *leaf = $2;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, $1, $3);
		$$ = new_tree_node(++ruleno, "structdcl_list", nkids, kids, leaf);
	}
;

structdcl:
	new_name_list ntype oliteral
	{
		struct token *leaf = NULL;
		int nkids = 3;
		struct tree** kids = create_tree_kids(nkids, $1, $2, $3);
		$$ = new_tree_node(++ruleno, "structdcl", nkids, kids, leaf);
	}
|	embed oliteral
	{
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, $1, $2);
		$$ = new_tree_node(++ruleno, "structdcl", nkids, kids, leaf);
	}
|	'(' embed ')' oliteral
	{
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, $2, $4);
		$$ = new_tree_node(++ruleno, "structdcl", nkids, kids, leaf);
	}
|	'*' embed oliteral
	{
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, $2, $3);
		$$ = new_tree_node(++ruleno, "structdcl", nkids, kids, leaf);
	}
|	'(' '*' embed ')' oliteral
	{
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, $3, $5);
		$$ = new_tree_node(++ruleno, "structdcl", nkids, kids, leaf);
	}
|	'*' '(' embed ')' oliteral
	{
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, $3, $5);
		$$ = new_tree_node(++ruleno, "structdcl", nkids, kids, leaf);
	}
	;

packname:
	LNAME
	{
		struct token *leaf = $1;
		int nkids = 1;
		struct tree** kids = NULL;
		$$ = new_tree_node(++ruleno, "packname", nkids, kids, leaf);
	}
|	LNAME '.' sym
	{
		struct token *leaf = $1;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $3);
		$$ = new_tree_node(++ruleno, "packname", nkids, kids, leaf);
	}
;

embed:
	packname
	{
		$$ = $1;
	}
;

/*
 * function arguments.
 */
arg_type:
	name_or_type
	{
		$$ = $1;
	}
|	sym name_or_type
	{
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, $1, $2);
		$$ = new_tree_node(++ruleno, "arg_type", nkids, kids, leaf);
	}
|	sym dotdotdot
	{
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, $1, $2);
		$$ = new_tree_node(++ruleno, "arg_type", nkids, kids, leaf);
	}
|	dotdotdot
	{
		$$ = $1;
	}
;

arg_type_list:
	arg_type
	{
		$$ = $1;
	}
|	arg_type_list ',' arg_type
	{
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, $1, $3);
		$$ = new_tree_node(++ruleno, "arg_type_list", nkids, kids, leaf);
	}
	;

oarg_type_list_ocomma:
	%empty
	{
		$$ = NULL;
	}
|	arg_type_list ocomma
	{
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, $1, $2);
		$$ = new_tree_node(++ruleno, "oarg_type_list_ocomma", nkids, kids, leaf);
	}
;

/*
 * statement
 */
stmt:
	%empty
	{
		$$ = NULL;
	}
|	compound_stmt
	{
		$$ = $1;
	}
|	common_dcl
	{
		$$ = $1;
	}
|	non_dcl_stmt
	{
		$$ = $1;
	}
|	error
	{
		$$ = $1;
	}
;

non_dcl_stmt:
	simple_stmt
	{
		
		$$ = $1;
	}
|	for_stmt
	{
		
		$$ = $1;
	}
|	if_stmt
	{
		$$ = $1;
	}
|	labelname ':'
	stmt
	{
		struct token *leaf = NULL;
		int nkids = 22;
		struct tree** kids = create_tree_kids(nkids, $1, $3);
		$$ = new_tree_node(++ruleno, "non_dcl_stmt", nkids, kids, leaf);
	}
|	LGO pseudocall
	{
		struct token *leaf = $1;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $2);
		$$ = new_tree_node(++ruleno, "non_dcl_stmt", nkids, kids, leaf);
	}
|	LRETURN oexpr_list
	{
		struct token *leaf = $1;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $2);
		$$ = new_tree_node(++ruleno, "non_dcl_stmt", nkids, kids, leaf);
	}
;

stmt_list:
	stmt
	{
		$$ = $1;
	}
|	stmt_list ';' stmt
	{
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, $1, $3);
		$$ = new_tree_node(++ruleno, "stmt_list", nkids, kids, leaf);
	}
;

new_name_list:
	new_name
	{
		$$ = $1;
	}
|	new_name_list ',' new_name
	{
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, $1, $3);
		$$ = new_tree_node(++ruleno, "new_name_list", nkids, kids, leaf);
	}
	;

dcl_name_list:
	dcl_name
	{
		$$ = $1;
	}
|	dcl_name_list ',' dcl_name
	{
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, $1, $3);
		$$ = new_tree_node(++ruleno, "dcl_name_list", nkids, kids, leaf);
	}
;

expr_list:
	expr
	{
		$$ = $1;
	}
|	expr_list ',' expr
	{
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, $1, $3);
		$$ = new_tree_node(++ruleno, "expr_list", nkids, kids, leaf);
	}
;

expr_or_type_list:
	expr_or_type
	{
		$$ = $1;
	}
|	expr_or_type_list ',' expr_or_type
	{
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, $1, $3);
		$$ = new_tree_node(++ruleno, "expr_or_type_list", nkids, kids, leaf);
	}
;

/*
 * list of combo of keyval and val
 */
keyval_list:
	keyval
	{
		$$ = $1;
	}
|	bare_complitexpr
	{
		$$ = $1;
	}
|	keyval_list ',' keyval
	{
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, $1, $3);
		$$ = new_tree_node(++ruleno, "keyval_list", nkids, kids, leaf);
	}
|	keyval_list ',' bare_complitexpr
	{
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, $1, $3);
		$$ = new_tree_node(++ruleno, "keyval_list", nkids, kids, leaf);
	}
	;

braced_keyval_list:
	%empty
	{
		$$ = NULL;
	}
|	keyval_list ocomma
	{
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, $1, $2);
		$$ = new_tree_node(++ruleno, "braced_keyval_list", nkids, kids, leaf);
	}
;

/*
 * optional things
 */
osemi:
	%empty
	{
		$$ = NULL;
	}
|	';'
	{
		$$ = new_tree_node(++ruleno, "osemi", 0, NULL, $1);
	}
	;

ocomma:
	%empty
	{
		$$ = NULL;
	}
|	','
	{
		$$ = new_tree_node(++ruleno, "ocomma", 0, NULL, $1);
	}
	;

oexpr:
	%empty
	{
		$$ = NULL;
	}
|	expr
	{
		$$ = $1;
	}
	;

oexpr_list:
	%empty
	{
		$$ = NULL;
	}
|	expr_list
	{
		$$ = $1;
	}
;

osimple_stmt:
	%empty
	{
		$$ = NULL;
	}
|	simple_stmt
	{
		$$ = $1;
	}
;


oliteral:
	%empty
	{
		$$ = NULL;
	}	
|	LLITERAL
	{
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $1);
		$$ = new_tree_node(++ruleno, "oliteral", nkids, kids, leaf);
	}
;

/*
 * import syntax from package header
 */


/*
 *  importing types
 */


/*
 *  importing constants
 */


%%
