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

#define YYDEBUG 1
int yydebug=1;

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
	
   fprintf(stderr, "syntax error: unespected '%s' token in file %s, line %d\n",
	   yytext,yyfilename, yylineno);
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

%type<ast>		hidden_fndcl hidden_type_misc hidden_type_recv_chan

%type<ast>		package lconst hidden_interfacedcl_list hidden_type
%type<ast>		hidden_pkg_importsym hidden_import_list hidden_import

%type<ast> 		imports import import_stmt import_safety 
%type<ast> 		import_stmt_list import_package hidden_funarg_list
%type<ast>		osemi ohidden_funarg_list ohidden_funres ohidden_structdcl_list

%type<ast> 		lbrace import_here hidden_structdcl_list
%type<ast>		sym packname fnlitdcl
%type<ast>		oliteral error

%type<ast>		stmt ntype 
%type<ast>		arg_type hidden_pkgtype 
%type<ast>		case caseblock hidden_funarg
%type<ast>		compound_stmt dotname embed expr complitexpr bare_complitexpr
%type<ast>		expr_or_type hidden_structdcl
%type<ast>		fndcl fnliteral hidden_type_non_recv_chan
%type<ast>		for_body for_header for_stmt if_header if_stmt non_dcl_stmt
%type<ast>		interfacedcl keyval labelname name
%type<ast>		name_or_type non_expr_type
%type<ast>		new_name dcl_name oexpr typedclname
%type<ast>		onew_name hidden_interfacedcl
%type<ast>		osimple_stmt pexpr pexpr_no_paren
%type<ast>		pseudocall range_stmt select_stmt
%type<ast>		simple_stmt hidden_funres hidden_literal
%type<ast>		switch_stmt uexpr hidden_type_func
%type<ast>		xfndcl typedcl start_complit

%type<ast>		xdcl fnbody fnres loop_body dcl_name_list
%type<ast>		new_name_list expr_list keyval_list braced_keyval_list expr_or_type_list xdcl_list
%type<ast>		oexpr_list caseblock_list elseif elseif_list else stmt_list oarg_type_list_ocomma ocomma arg_type_list
%type<ast>		interfacedcl_list vardcl vardcl_list structdcl structdcl_list
%type<ast>		common_dcl constdcl constdcl1 constdcl_list typedcl_list

%type<ast>		convtype comptype dotdotdot hidden_constant
%type<ast>		indcl interfacetype structtype ptrtype
%type<ast>		recvchantype non_recvchantype othertype fnret_type fntype

%type<ast>		hidden_importsym ohidden_interfacedcl_list



%left		LCOMM	/* outside the usual hierarchy; here for good error<token> messages */

%left		LOROR
%left		LANDAND
%left		LEQ LNE LLE LGE LLT LGT
%left		'+' '-' '|' '^'
%left		'*' '/' '%' '&' LLSH LRSH LANDNOT

%type<t>	'{' '}' '?' '+' '-' '|' '^' '*' '/' '%' '&' ';' ',' '`'

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

%%
file:	package imports xdcl_list
	{
		// tree_ptr new_tree_node(int prodrule, char *prodname, int nkids, struct tree **kids, struct token *leaf)
		// struct tree **create_tree_kids(int nkids, ...)
		struct token *leaf = NULL;
		int nkids = 3;
		struct tree** kids = create_tree_kids(nkids, $1, $2, $3);
		$$ = new_tree_node(++ruleno, "file", nkids, kids, leaf);
		ast_root = $$;
	}
;

package:
	%empty %prec NotPackage 
	{
		yyerror("package statement must be first");
		exit(1);
	}
|	LPACKAGE sym ';' 
	{ 
		// tree_ptr new_tree_node(int prodrule, char *prodname, int nkids, struct tree **kids, struct token *leaf)
		// struct tree **create_tree_kids(int nkids, ...)
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $2);
		$$ = new_tree_node(++ruleno, "package", nkids, kids, $1);
	}
;

imports:
	%empty
	{
		$$ = new_tree_node(++ruleno, "imports", 0, NULL, NULL);
	}	
|	imports import ';' 
	{
		struct token *leaf = NULL;
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
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $1);
		$$ = new_tree_node(++ruleno, "import_stmt", nkids, kids, leaf);
	}
;

import_stmt_list:
	import_stmt
	{
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $1);
		$$ = new_tree_node(++ruleno, "import_stmt_list", nkids, kids, leaf);
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
		$$ = new_tree_node(++ruleno, "import_safety", 0, NULL, NULL);
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
		$$ = new_tree_node(++ruleno, "xdcl", 0, NULL, NULL);
	}
|	common_dcl
	{
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $1);
		$$ = new_tree_node(++ruleno, "xdcl", nkids, kids, leaf);
	}
|	xfndcl
	{
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $1);
		$$ = new_tree_node(++ruleno, "xdcl", nkids, kids, leaf);
	}
|	non_dcl_stmt
	{
		yyerror("non-declaration statement outside function body");
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $1);
		$$ = new_tree_node(++ruleno, "xdcl", nkids, kids, leaf);
	}
|	error
	{
		$$ = new_tree_node(++ruleno, "xdcl", 0, NULL, NULL);
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
		struct token *leaf = NULL;
		int nkids = 3;
		struct tree** kids = create_tree_kids(nkids, $1, $2, $4);
		$$ = new_tree_node(++ruleno, "vardcl", nkids, kids, leaf);
	}
|	dcl_name_list '=' expr_list
	{
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, $1, $3);
		$$ = new_tree_node(++ruleno, "vardcl", nkids, kids, leaf);
	}
	;

constdcl:
	dcl_name_list ntype '=' expr_list
	{
		struct token *leaf = NULL;
		int nkids = 3;
		struct tree** kids = create_tree_kids(nkids, $1, $2, $4);
		$$ = new_tree_node(++ruleno, "constdcl", nkids, kids, leaf);
	}
|	dcl_name_list '=' expr_list
	{
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, $1, $3);
		$$ = new_tree_node(++ruleno, "constdcl", nkids, kids, leaf);
	}
;

constdcl1:
	constdcl
	{
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $1);
		$$ = new_tree_node(++ruleno, "constdcl1", nkids, kids, leaf);
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
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $1);
		$$ = new_tree_node(++ruleno, "constdcl1", nkids, kids, leaf);
	}
;

typedclname:
	sym
	{
		// the name becomes visible right here, not at the end
		// of the declaration.
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $1);
		$$ = new_tree_node(++ruleno, "typedclname", nkids, kids, leaf);
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
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $1);
		$$ = new_tree_node(++ruleno, "simple_stmt", nkids, kids, leaf);
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
		struct token *leaf = NULL;
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

case:
	LCASE expr_or_type_list ':'
	{
		struct token *leaf = $1;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $2);
		$$ = new_tree_node(++ruleno, "case", nkids, kids, leaf);
	}
|	LCASE expr_or_type_list '=' expr ':'
	{
		struct token *leaf = $1;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, $2, $4);
		$$ = new_tree_node(++ruleno, "case", nkids, kids, leaf);
	}
|	LCASE expr_or_type_list LCOLAS expr ':'
	{
		// TODO: maybe concat tokens?
		struct token *leaf = $1;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, $2, $4);
		$$ = new_tree_node(++ruleno, "case", nkids, kids, leaf);
	}
|	LDEFAULT ':'
	{
		struct token *leaf = $1;
		int nkids = 0;
		struct tree** kids = NULL;
		$$ = new_tree_node(++ruleno, "case", nkids, kids, leaf);
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

caseblock:
	case
	{
		// If the last token read by the lexer was consumed
		// as part of the case, clear it (parser has cleared yychar).
		// If the last token read by the lexer was the lookahead
		// leave it alone (parser has it cached in yychar).
		// This is so that the stmt_list action doesn't look at
		// the case tokens if the stmt_list is empty.
		yylast = yychar;
	}
	stmt_list
	{
		int last;

		// This is the only place in the language where a statement
		// list is not allowed to drop the final semicolon, because
		// it's the only place where a statement list is not followed 
		// by a closing brace.  Handle the error for pedantry.

		// Find the final token of the statement list.
		// yylast is lookahead; yyprev is last of stmt_list
		last = yyprev;

		if(last > 0 && last != ';' && yychar != '}')
			yyerror("missing statement after label");

		struct token *leaf = NULL; // TODO: not sure ?
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $1);
		$$ = new_tree_node(++ruleno, "caseblock", nkids, kids, leaf);
	}
;

caseblock_list:
	%empty
	{
		$$ = new_tree_node(++ruleno, "caseblock_list", 0, NULL, NULL);
	}
|	caseblock_list caseblock
	{
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, $1, $2);
		$$ = new_tree_node(++ruleno, "caseblock_list", nkids, kids, leaf);
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

range_stmt:
	expr_list '=' LRANGE expr
	{
		struct token *leaf = $3;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, $1, $4);
		$$ = new_tree_node(++ruleno, "range_stmt", nkids, kids, leaf);
	}
|	expr_list LCOLAS LRANGE expr
	{
		struct token *leaf = $3; // TODO: concat tokens
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, $1, $4);
		$$ = new_tree_node(++ruleno, "range_stmt", nkids, kids, leaf);
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
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $1);
		$$ = new_tree_node(++ruleno, "for_header", nkids, kids, leaf);
	}
|	range_stmt
	{
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $1);
		$$ = new_tree_node(++ruleno, "for_header", nkids, kids, leaf);
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
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $1);
		$$ = new_tree_node(++ruleno, "if_header", nkids, kids, leaf);
	}
|	osimple_stmt ';' osimple_stmt
	{
		struct token *leaf = NULL;
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
		$$ = new_tree_node(++ruleno, "elseif_list", 0, NULL, NULL);
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
		$$ = new_tree_node(++ruleno, "else", 0, NULL, NULL);
	}
|	LELSE compound_stmt
	elseif_list elseif
	{
		struct token *leaf = $1;
		int nkids = 3;
		struct tree** kids = create_tree_kids(nkids, $2, $3, $4);
		$$ = new_tree_node(++ruleno, "else", nkids, kids, leaf);
	}
;

switch_stmt:
	LSWITCH
	if_header
	LBODY caseblock_list '}'
	elseif_list elseif
	{
		struct token *leaf = $1; // TODO: maybe concat tokens
		int nkids = 4;
		struct tree** kids = create_tree_kids(nkids, $2, $4, $6, $7);
		$$ = new_tree_node(++ruleno, "switch_stmt", nkids, kids, leaf);
	}
;

select_stmt:
	LSELECT
	LBODY caseblock_list '}'
	{
		struct token *leaf = $1; // TODO: maybe concat tokens
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $3);
		$$ = new_tree_node(++ruleno, "select_stmt", nkids, kids, leaf);
	}
;

/*
 * expressions
 */
expr:
	uexpr
	{
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $1);
		$$ = new_tree_node(++ruleno, "expr", nkids, kids, leaf);
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
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $1);
		$$ = new_tree_node(++ruleno, "uexpr", nkids, kids, leaf);
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
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $1);
		$$ = new_tree_node(++ruleno, "pexpr_no_paren", nkids, kids, leaf);
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
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $1);
		$$ = new_tree_node(++ruleno, "pexpr_no_paren", nkids, kids, leaf);
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
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $1);
		$$ = new_tree_node(++ruleno, "pexpr_no_paren", nkids, kids, leaf);
	}
;

start_complit:
	%empty
	{
		// composite expression.
		// make node early so we get the right line number.
		$$ = new_tree_node(++ruleno, "start_complit", 0, NULL, NULL);
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
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $1);
		$$ = new_tree_node(++ruleno, "bare_complitexpr", nkids, kids, leaf);
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
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $1);
		$$ = new_tree_node(++ruleno, "complitexpr", nkids, kids, leaf);
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
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $1);
		$$ = new_tree_node(++ruleno, "pexpr", nkids, kids, leaf);
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
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $1);
		$$ = new_tree_node(++ruleno, "expr_or_type", nkids, kids, leaf);
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
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $1);
		$$ = new_tree_node(++ruleno, "name_or_type", nkids, kids, leaf);
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
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $1);
		$$ = new_tree_node(++ruleno, "new_name", nkids, kids, leaf);
	}
;

dcl_name:
	sym
	{
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $1);
		$$ = new_tree_node(++ruleno, "new_name", nkids, kids, leaf);
	}
;

onew_name:
	%empty
	{
		$$ = new_tree_node(++ruleno, "onew_name", 0, NULL, NULL);
	}
|	new_name
	{
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $1);
		$$ = new_tree_node(++ruleno, "onew_name", nkids, kids, leaf);
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
		struct token* leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $1);
		$$ = new_tree_node(++ruleno, "sym", nkids, kids, leaf);
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
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $1);
		$$ = new_tree_node(++ruleno, "labelname", nkids, kids, leaf);
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
	recvchantype
	{
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $1);
		$$ = new_tree_node(++ruleno, "ntype", nkids, kids, leaf);
	}
|	fntype
	{
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $1);
		$$ = new_tree_node(++ruleno, "ntype", nkids, kids, leaf);
	}
|	othertype
	{
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $1);
		$$ = new_tree_node(++ruleno, "ntype", nkids, kids, leaf);
	}
|	ptrtype
	{
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $1);
		$$ = new_tree_node(++ruleno, "ntype", nkids, kids, leaf);
	}
|	dotname
	{
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $1);
		$$ = new_tree_node(++ruleno, "ntype", nkids, kids, leaf);
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
	recvchantype
	{
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $1);
		$$ = new_tree_node(++ruleno, "non_expr_type", nkids, kids, leaf);
	}
|	fntype
	{
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $1);
		$$ = new_tree_node(++ruleno, "non_expr_type", nkids, kids, leaf);
	}
|	othertype
	{
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $1);
		$$ = new_tree_node(++ruleno, "non_expr_type", nkids, kids, leaf);
	}
|	'*' non_expr_type
	{
		struct token *leaf = $1;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $2);
		$$ = new_tree_node(++ruleno, "non_expr_type", nkids, kids, leaf);
	}
;

non_recvchantype:
	fntype
	{
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $1);
		$$ = new_tree_node(++ruleno, "non_recvchantype", nkids, kids, leaf);
	}
|	othertype
	{
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $1);
		$$ = new_tree_node(++ruleno, "non_recvchantype", nkids, kids, leaf);
	}
|	ptrtype
	{
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $1);
		$$ = new_tree_node(++ruleno, "non_recvchantype", nkids, kids, leaf);
	}
|	dotname
	{
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $1);
		$$ = new_tree_node(++ruleno, "non_recvchantype", nkids, kids, leaf);
	}
|	'(' ntype ')'
	{
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $2);
		$$ = new_tree_node(++ruleno, "non_recvchantype", nkids, kids, leaf);
	}
;

convtype:
	fntype
	{
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $1);
		$$ = new_tree_node(++ruleno, "convtype", nkids, kids, leaf);
	}
|	othertype
	{
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $1);
		$$ = new_tree_node(++ruleno, "convtype", nkids, kids, leaf);
	}

comptype:
	othertype
	{
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $1);
		$$ = new_tree_node(++ruleno, "comptype", nkids, kids, leaf);
	}
;

fnret_type:
	recvchantype
	{
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $1);
		$$ = new_tree_node(++ruleno, "fnret_type", nkids, kids, leaf);
	}
|	fntype
	{
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $1);
		$$ = new_tree_node(++ruleno, "fnret_type", nkids, kids, leaf);
	}
|	othertype
	{
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $1);
		$$ = new_tree_node(++ruleno, "fnret_type", nkids, kids, leaf);
	}
|	ptrtype
	{
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $1);
		$$ = new_tree_node(++ruleno, "fnret_type", nkids, kids, leaf);
	}
|	dotname
	{
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $1);
		$$ = new_tree_node(++ruleno, "fnret_type", nkids, kids, leaf);
	}
;

dotname:
	name
	{
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $1);
		$$ = new_tree_node(++ruleno, "dotname", nkids, kids, leaf);
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
|	LCHAN non_recvchantype
	{
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, $1, $2);
		$$ = new_tree_node(++ruleno, "othertype", nkids, kids, leaf);
	}
|	LCHAN LCOMM ntype
	{
		struct token *leaf = NULL;
		int nkids = 3;
		struct tree** kids = create_tree_kids(nkids, $1, $2, $3);
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
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $1);
		$$ = new_tree_node(++ruleno, "othertype", nkids, kids, leaf);
	}
|	interfacetype
	{
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $1);
		$$ = new_tree_node(++ruleno, "othertype", nkids, kids, leaf);
	}
;

ptrtype:
	'*' ntype
	{
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $2);
		$$ = new_tree_node(++ruleno, "ptrtype", nkids, kids, leaf);
	}
;

recvchantype:
	LCOMM LCHAN ntype
	{
		struct token *leaf = $1;	// TODO: concat tokens ?
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $3);
		$$ = new_tree_node(++ruleno, "recvchantype", nkids, kids, leaf);
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

interfacetype:
	LINTERFACE lbrace interfacedcl_list osemi '}'
	{
		struct token *leaf = $1;
		int nkids = 3;
		struct tree** kids = create_tree_kids(nkids, $2, $3, $4);
		$$ = new_tree_node(++ruleno, "interfacetype", nkids, kids, leaf);
	}
|	LINTERFACE lbrace '}'
	{
		struct token *leaf = $1;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $2);
		$$ = new_tree_node(++ruleno, "interfacetype", nkids, kids, leaf);
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

hidden_fndcl:
	hidden_pkg_importsym '(' ohidden_funarg_list ')' ohidden_funres
	{
		struct token *leaf = NULL;
		int nkids = 3;
		struct tree** kids = create_tree_kids(nkids, $1, $3, $5);
		$$ = new_tree_node(++ruleno, "hidden_fndcl", nkids, kids, leaf);
	}
|	'(' hidden_funarg_list ')' sym '(' ohidden_funarg_list ')' ohidden_funres
	{
		struct token *leaf = NULL;
		int nkids = 4;
		struct tree** kids = create_tree_kids(nkids, $2, $4, $6, %8);
		$$ = new_tree_node(++ruleno, "hidden_fndcl", nkids, kids, leaf);
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
		$$ = new_tree_node(++ruleno, "fnbody", 0, NULL, NULL);
	}
|	'{' stmt_list '}'
	{
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $2);
		$$ = new_tree_node(++ruleno, "fnbody", nkids, kids, leaf);
	}
;

fnres:
	%empty %prec NotParen
	{
		$$ = new_tree_node(++ruleno, "fnres", 0, NULL, NULL);
	}
|	fnret_type
	{
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $1);
		$$ = new_tree_node(++ruleno, "fnres", nkids, kids, leaf);
	}
|	'(' oarg_type_list_ocomma ')'
	{
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $2);
		$$ = new_tree_node(++ruleno, "fnres", nkids, kids, leaf);
	}
;

fnlitdcl:
	fntype
	{
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $1);
		$$ = new_tree_node(++ruleno, "fnlitdcl", nkids, kids, leaf);
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
		$$ = new_tree_node(++ruleno, "xdcl_list", 0, NULL, NULL);
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
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $1);
		$$ = new_tree_node(++ruleno, "vardcl_list", nkids, kids, leaf);
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
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $1);
		$$ = new_tree_node(++ruleno, "constdcl_list", nkids, kids, leaf);
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
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $1);
		$$ = new_tree_node(++ruleno, "typedcl_list", nkids, kids, leaf);
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
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $1);
		$$ = new_tree_node(++ruleno, "structdcl_list", nkids, kids, leaf);
	}
|	structdcl_list ';' structdcl
	{
		struct token *leaf = $2;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, $1, $3);
		$$ = new_tree_node(++ruleno, "structdcl_list", nkids, kids, leaf);
	}
;

interfacedcl_list:
	interfacedcl
	{
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $1);
		$$ = new_tree_node(++ruleno, "interfacedcl_list", nkids, kids, leaf);
	}
|	interfacedcl_list ';' interfacedcl
	{
		struct token *leaf = $2;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, $1, $3);
		$$ = new_tree_node(++ruleno, "interfacedcl_list", nkids, kids, leaf);
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
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $1);
		$$ = new_tree_node(++ruleno, "embed", nkids, kids, leaf);
	}
;

interfacedcl:
	new_name indcl
	{
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, $1, $2);
		$$ = new_tree_node(++ruleno, "interfacedcl", nkids, kids, leaf);
	}
|	packname
	{
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $1);
		$$ = new_tree_node(++ruleno, "interfacedcl", nkids, kids, leaf);
	}
|	'(' packname ')'
	{
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $2);
		$$ = new_tree_node(++ruleno, "interfacedcl", nkids, kids, leaf);
	}
;

indcl:
	'(' oarg_type_list_ocomma ')' fnres
	{
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, $2, $4);
		$$ = new_tree_node(++ruleno, "indcl", nkids, kids, leaf);
	}
;

/*
 * function arguments.
 */
arg_type:
	name_or_type
	{
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $1);
		$$ = new_tree_node(++ruleno, "arg_type", nkids, kids, leaf);
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
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $1);
		$$ = new_tree_node(++ruleno, "arg_type", nkids, kids, leaf);
	}
;

arg_type_list:
	arg_type
	{
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $1);
		$$ = new_tree_node(++ruleno, "arg_type_list", nkids, kids, leaf);
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
		$$ = new_tree_node(++ruleno, "oarg_type_list_ocomma", 0, NULL, NULL);
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
		$$ = new_tree_node(++ruleno, "stmt", 0, NULL, NULL);
	}
|	compound_stmt
	{
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $1);
		$$ = new_tree_node(++ruleno, "stmt", nkids, kids, leaf);
	}
|	common_dcl
	{
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $1);
		$$ = new_tree_node(++ruleno, "stmt", nkids, kids, leaf);
	}
|	non_dcl_stmt
	{
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $1);
		$$ = new_tree_node(++ruleno, "stmt", nkids, kids, leaf);
	}
|	error
	{
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $1);
		$$ = new_tree_node(++ruleno, "stmt", nkids, kids, leaf);
	}
;

non_dcl_stmt:
	simple_stmt
	{
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $1);
		$$ = new_tree_node(++ruleno, "non_dcl_stmt", nkids, kids, leaf);
	}
|	for_stmt
	{
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $1);
		$$ = new_tree_node(++ruleno, "non_dcl_stmt", nkids, kids, leaf);
	}
|	switch_stmt
	{
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $1);
		$$ = new_tree_node(++ruleno, "non_dcl_stmt", nkids, kids, leaf);
	}
|	select_stmt
	{
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $1);
		$$ = new_tree_node(++ruleno, "non_dcl_stmt", nkids, kids, leaf);
	}
|	if_stmt
	{
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $1);
		$$ = new_tree_node(++ruleno, "non_dcl_stmt", nkids, kids, leaf);
	}
|	labelname ':'
	stmt
	{
		struct token *leaf = NULL;
		int nkids = 22;
		struct tree** kids = create_tree_kids(nkids, $1, $3);
		$$ = new_tree_node(++ruleno, "non_dcl_stmt", nkids, kids, leaf);
	}
|	LFALL
	{
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $1);
		$$ = new_tree_node(++ruleno, "non_dcl_stmt", nkids, kids, leaf);
	}
|	LBREAK onew_name
	{
		struct token *leaf = $1;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $2);
		$$ = new_tree_node(++ruleno, "non_dcl_stmt", nkids, kids, leaf);
	}
|	LCONTINUE onew_name
	{
		struct token *leaf = $1;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $2);
		$$ = new_tree_node(++ruleno, "non_dcl_stmt", nkids, kids, leaf);
	}
|	LGO pseudocall
	{
		struct token *leaf = $1;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $2);
		$$ = new_tree_node(++ruleno, "non_dcl_stmt", nkids, kids, leaf);
	}
|	LDEFER pseudocall
	{
		struct token *leaf = $1;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $2);
		$$ = new_tree_node(++ruleno, "non_dcl_stmt", nkids, kids, leaf);
	}
|	LGOTO new_name
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
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $1);
		$$ = new_tree_node(++ruleno, "stmt_list", nkids, kids, leaf);
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
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $1);
		$$ = new_tree_node(++ruleno, "new_name_list", nkids, kids, leaf);
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
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $1);
		$$ = new_tree_node(++ruleno, "dcl_name_list", nkids, kids, leaf);
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
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $1);
		$$ = new_tree_node(++ruleno, "expr_list", nkids, kids, leaf);
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
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $1);
		$$ = new_tree_node(++ruleno, "expr_or_type_list", nkids, kids, leaf);
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
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $1);
		$$ = new_tree_node(++ruleno, "keyval_list", nkids, kids, leaf);
	}
|	bare_complitexpr
	{
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $1);
		$$ = new_tree_node(++ruleno, "keyval_list", nkids, kids, leaf);
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
		$$ = new_tree_node(++ruleno, "braced_keyval_list", 0, NULL, NULL);
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
		$$ = new_tree_node(++ruleno, "osemi", 0, NULL, NULL);
	}
|	';'
	{
		$$ = new_tree_node(++ruleno, "osemi", 0, NULL, $1);
	}
	;

ocomma:
	%empty
	{
		$$ = new_tree_node(++ruleno, "ocomma", 0, NULL, NULL);
	}
|	','
	{
		$$ = new_tree_node(++ruleno, "ocomma", 0, NULL, $1);
	}
	;

oexpr:
	%empty
	{
		$$ = new_tree_node(++ruleno, "oexpr", 0, NULL, NULL);
	}
|	expr
	{
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $1);
		$$ = new_tree_node(++ruleno, "oexpr", nkids, kids, leaf);
	}
	;

oexpr_list:
	%empty
	{
		$$ = new_tree_node(++ruleno, "oexpr_list", 0, NULL, NULL);
	}
|	expr_list
	{
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $1);
		$$ = new_tree_node(++ruleno, "oexpr_list", nkids, kids, leaf);
	}
;

osimple_stmt:
	%empty
	{
		$$ = new_tree_node(++ruleno, "osimple_stmt", 0, NULL, NULL);
	}
|	simple_stmt
	{
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $1);
		$$ = new_tree_node(++ruleno, "osimple_stmt", nkids, kids, leaf);
	}
;

ohidden_funarg_list:
	%empty
	{
		$$ = new_tree_node(++ruleno, "ohidden_funarg_list", 0, NULL, NULL);
	}
|	hidden_funarg_list
	{
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $1);
		$$ = new_tree_node(++ruleno, "ohidden_funarg_list", nkids, kids, leaf);
	}
;

ohidden_structdcl_list:
	%empty
	{
		$$ = new_tree_node(++ruleno, "ohidden_structdcl_list", 0, NULL, NULL);
	}
|	hidden_structdcl_list
	{
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $1);
		$$ = new_tree_node(++ruleno, "ohidden_structdcl_list", nkids, kids, leaf);
	}
;

ohidden_interfacedcl_list:
	%empty
	{
		$$ = new_tree_node(++ruleno, "ohidden_interfacedcl_list", 0, NULL, NULL);
	}	
|	hidden_interfacedcl_list
	{
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $1);
		$$ = new_tree_node(++ruleno, "ohidden_interfacedcl_list", nkids, kids, leaf);
	}
;

oliteral:
	%empty
	{
		$$ = new_tree_node(++ruleno, "oliteral", 0, NULL, NULL);
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
hidden_import:
	LIMPORT LNAME LLITERAL ';'
	{
		struct token *leaf = $1; // TODO: concat tokens ?
		$$ = new_tree_node(++ruleno, "hidden_import", 0, NULL, leaf);
	}
|	LVAR hidden_pkg_importsym hidden_type ';'
	{
		struct token *leaf = $1;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, $2, $3);
		$$ = new_tree_node(++ruleno, "hidden_import", nkids, kids, leaf);
	}
|	LCONST hidden_pkg_importsym '=' hidden_constant ';'
	{
		struct token *leaf = $1;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, $2, $4);
		$$ = new_tree_node(++ruleno, "hidden_import", nkids, kids, leaf);
	}
|	LCONST hidden_pkg_importsym hidden_type '=' hidden_constant ';'
	{
		struct token *leaf = $1;
		int nkids = 3;
		struct tree** kids = create_tree_kids(nkids, $2, $3, $5);
		$$ = new_tree_node(++ruleno, "hidden_import", nkids, kids, leaf);
	}
|	LTYPE hidden_pkgtype hidden_type ';'
	{
		struct token *leaf = $1;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, $2, $3);
		$$ = new_tree_node(++ruleno, "hidden_import", nkids, kids, leaf);
	}
|	LFUNC hidden_fndcl fnbody ';'
	{
		struct token *leaf = $1;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, $2, $3);
		$$ = new_tree_node(++ruleno, "hidden_import", nkids, kids, leaf);
	}
;

hidden_pkg_importsym:
	hidden_importsym
	{
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $1);
		$$ = new_tree_node(++ruleno, "hidden_pkg_importsym", nkids, kids, leaf);
	}
	;

hidden_pkgtype:
	hidden_pkg_importsym
	{
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $1);
		$$ = new_tree_node(++ruleno, "hidden_pkgtype", nkids, kids, leaf);
	}
;

/*
 *  importing types
 */

hidden_type:
	hidden_type_misc
	{
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $1);
		$$ = new_tree_node(++ruleno, "hidden_type", nkids, kids, leaf);
	}
|	hidden_type_recv_chan
	{
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $1);
		$$ = new_tree_node(++ruleno, "hidden_type", nkids, kids, leaf);
	}
|	hidden_type_func
	{
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $1);
		$$ = new_tree_node(++ruleno, "hidden_type", nkids, kids, leaf);
	}
;

hidden_type_non_recv_chan:
	hidden_type_misc
	{
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $1);
		$$ = new_tree_node(++ruleno, "hidden_type_non_recv_chan", nkids, kids, leaf);
	}	
|	hidden_type_func
	{
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $1);
		$$ = new_tree_node(++ruleno, "hidden_type_non_recv_chan", nkids, kids, leaf);
	}
;

hidden_type_misc:
	hidden_importsym
	{
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $1);
		$$ = new_tree_node(++ruleno, "hidden_type_misc", nkids, kids, leaf);
	}
|	LNAME
	{
		$$ = new_tree_node(++ruleno, "hidden_type_misc", 0, NULL, $1);
	}
|	'[' ']' hidden_type
	{
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $3);
		$$ = new_tree_node(++ruleno, "hidden_type_misc", nkids, kids, leaf);
	}
|	'[' LLITERAL ']' hidden_type
	{
		struct token *leaf = $2;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $4);
		$$ = new_tree_node(++ruleno, "hidden_type_misc", nkids, kids, leaf);
	}
|	LMAP '[' hidden_type ']' hidden_type
	{
		struct token *leaf = $1;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, $3, $5);
		$$ = new_tree_node(++ruleno, "hidden_type_misc", nkids, kids, leaf);
	}
|	LSTRUCT '{' ohidden_structdcl_list '}'
	{
		struct token *leaf = $1;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $3);
		$$ = new_tree_node(++ruleno, "hidden_type_misc", nkids, kids, leaf);
	}
|	LINTERFACE '{' ohidden_interfacedcl_list '}'
	{
		struct token *leaf = $1;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $3);
		$$ = new_tree_node(++ruleno, "hidden_type_misc", nkids, kids, leaf);
	}
|	'*' hidden_type
	{
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $2);
		$$ = new_tree_node(++ruleno, "hidden_type_misc", nkids, kids, leaf);
	}
|	LCHAN hidden_type_non_recv_chan
	{
		struct token *leaf = $1;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $2);
		$$ = new_tree_node(++ruleno, "hidden_type_misc", nkids, kids, leaf);
	}
|	LCHAN '(' hidden_type_recv_chan ')'
	{
		struct token *leaf = $1;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $3);
		$$ = new_tree_node(++ruleno, "hidden_type_misc", nkids, kids, leaf);
	}
|	LCHAN LCOMM hidden_type
	{
		struct token *leaf = $1; // TODO: concat tokens ?
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $3);
		$$ = new_tree_node(++ruleno, "hidden_type_misc", nkids, kids, leaf);
	}
;

hidden_type_recv_chan:
	LCOMM LCHAN hidden_type
	{
		struct token *leaf = $1; // TODO: concat tokens ?
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $3);
		$$ = new_tree_node(++ruleno, "hidden_type_recv_chan", nkids, kids, leaf);
	}
;

hidden_type_func:
	LFUNC '(' ohidden_funarg_list ')' ohidden_funres
	{
		struct token *leaf = $1; 
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, $3, $5);
		$$ = new_tree_node(++ruleno, "hidden_type_func", nkids, kids, leaf);
	}
;

hidden_funarg:
	sym hidden_type oliteral
	{
		struct token *leaf = NULL; 
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, $2, $3);
		$$ = new_tree_node(++ruleno, "hidden_funarg", nkids, kids, leaf);
	}
|	sym LDDD hidden_type oliteral
	{
		struct token *leaf = $2; 
		int nkids = 3;
		struct tree** kids = create_tree_kids(nkids, $1, $3, $4);
		$$ = new_tree_node(++ruleno, "hidden_funarg", nkids, kids, leaf);
	}
;

hidden_structdcl:
	sym hidden_type oliteral
	{
		struct token *leaf = NULL; 
		int nkids = 3;
		struct tree** kids = create_tree_kids(nkids, $1, $2, $3);
		$$ = new_tree_node(++ruleno, "hidden_structdcl", nkids, kids, leaf);
	}
;

hidden_interfacedcl:
	sym '(' ohidden_funarg_list ')' ohidden_funres
	{
		struct token *leaf = NULL; 
		int nkids = 3;
		struct tree** kids = create_tree_kids(nkids, $1, $3, $5);
		$$ = new_tree_node(++ruleno, "hidden_interfacedcl", nkids, kids, leaf);
	}
|	hidden_type
	{
		struct token *leaf = NULL; 
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $1);
		$$ = new_tree_node(++ruleno, "hidden_interfacedcl", nkids, kids, leaf);
	}
;

ohidden_funres:
	%empty
	{
		$$ = new_tree_node(++ruleno, "ohidden_funres", 0, NULL, NULL);
	}
|	hidden_funres
	{
		struct token *leaf = NULL; 
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $1);
		$$ = new_tree_node(++ruleno, "ohidden_funres", nkids, kids, leaf);
	}
;

hidden_funres:
	'(' ohidden_funarg_list ')'
	{
		struct token *leaf = NULL; 
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $2);
		$$ = new_tree_node(++ruleno, "hidden_funres", nkids, kids, leaf);
	}
|	hidden_type
	{
		struct token *leaf = NULL; 
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $1);
		$$ = new_tree_node(++ruleno, "hidden_funres", nkids, kids, leaf);
	}
;

/*
 *  importing constants
 */

hidden_literal:
	LLITERAL
	{
		struct token *leaf = $1; 
		$$ = new_tree_node(++ruleno, "hidden_literal", 0, NULL, leaf);
	}
|	'-' LLITERAL
	{
		struct token *leaf = $2; 
		$$ = new_tree_node(++ruleno, "hidden_literal", 0, NULL, leaf);
	}
|	sym
	{
		struct token *leaf = NULL; 
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $1);
		$$ = new_tree_node(++ruleno, "hidden_literal", nkids, kids, leaf);
	}
;

hidden_constant:
	hidden_literal
	{
		struct token *leaf = NULL; 
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $1);
		$$ = new_tree_node(++ruleno, "hidden_constant", nkids, kids, leaf);
	}
|	'(' hidden_literal '+' hidden_literal ')'
	{
		struct token *leaf = NULL; 
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, $2, $4);
		$$ = new_tree_node(++ruleno, "hidden_constant", nkids, kids, leaf);
	}
;

hidden_import_list:
	%empty
	{
		$$ = new_tree_node(++ruleno, "hidden_import_list", 0, NULL, NULL);
	}
|	hidden_import_list hidden_import
	{
		struct token *leaf = NULL; 
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, $1, $2);
		$$ = new_tree_node(++ruleno, "hidden_import_list", nkids, kids, leaf);
	}
;

hidden_funarg_list:
	hidden_funarg
	{
		struct token *leaf = NULL; 
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $1);
		$$ = new_tree_node(++ruleno, "hidden_funarg_list", nkids, kids, leaf);
	}
|	hidden_funarg_list ',' hidden_funarg
	{
		struct token *leaf = NULL; 
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, $1, $3);
		$$ = new_tree_node(++ruleno, "hidden_funarg_list", nkids, kids, leaf);
	}
;

hidden_structdcl_list:
	hidden_structdcl
	{
		struct token *leaf = NULL; 
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $1);
		$$ = new_tree_node(++ruleno, "hidden_structdcl_list", nkids, kids, leaf);
	}
|	hidden_structdcl_list ';' hidden_structdcl
	{
		struct token *leaf = NULL; 
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, $1, $3);
		$$ = new_tree_node(++ruleno, "hidden_structdcl_list", nkids, kids, leaf);
	}
;

hidden_interfacedcl_list:
	hidden_interfacedcl
	{
		struct token *leaf = NULL; 
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, $1);
		$$ = new_tree_node(++ruleno, "hidden_interfacedcl_list", nkids, kids, leaf);
	}
|	hidden_interfacedcl_list ';' hidden_interfacedcl
	{
		struct token *leaf = NULL; 
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, $1, $3);
		$$ = new_tree_node(++ruleno, "hidden_interfacedcl_list", nkids, kids, leaf);
	}
;

%%
