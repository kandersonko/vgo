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
	fprintf(stderr, "ERROR: found '%s' token at line %d in file %s\n",
	   yytext,yylineno,yyfilename);
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
%type<ast>		oliteral error complitexpr

%type<ast>		stmt ntype 
%type<ast>		arg_type 
%type<ast>		compound_stmt dotname embed expr
%type<ast>		expr_or_type
%type<ast>		fndcl fnliteral
%type<ast>		for_body for_header for_stmt if_header if_stmt non_dcl_stmt
%type<ast>		name
%type<ast>		name_or_type non_expr_type
%type<ast>		new_name dcl_name oexpr typedclname
%type<ast>		osimple_stmt pexpr pexpr_no_paren
%type<ast>		pseudocall 
%type<ast>		simple_stmt 
%type<ast>		uexpr 
%type<ast>		xfndcl typedcl

%type<ast>		xdcl fnbody fnres loop_body dcl_name_list
%type<ast>		new_name_list expr_list expr_or_type_list xdcl_list
%type<ast>		oexpr_list elseif elseif_list else stmt_list oarg_type_list_ocomma ocomma arg_type_list
%type<ast>		vardcl vardcl_list structdcl structdcl_list
%type<ast>		common_dcl constdcl constdcl1 constdcl_list typedcl_list

%type<ast>		convtype comptype braced_keyval_list start_complit dotdotdot
%type<ast>		structtype ptrtype keyval keyval_list bare_complitexpr
%type<ast>		othertype fnret_type fntype

%type<ast>		hidden_importsym



%left		LCOMM	/* outside the usual hierarchy; here for good error<token> messages */

%left		LOROR
%left		LANDAND
%left		LEQ LNE LLE LGE LLT LGT
%left		'+' '-' '|' '^'
%left		'*' '/' '%' '&' LLSH LRSH LANDNOT

%type<t>	'{' '}' '?' '+' '-' '|' '^' '*' '/' '%' '&' ';' ',' '`' '.' '=' '!' '~' '[' ']' '@' '<' ':'

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
		int nkids = 3;
		struct tree** kids = create_tree_kids(nkids, $1, $2, $3);
		$$ = new_tree_node(R_FILE, "file", nkids, kids, NULL);
		ast_root = $$;
	}
;

package:
	%empty %prec NotPackage 
	{
		yyerror("package statement must be first");
		$$ = new_epsilon_tree(R_PACKAGE, "package");
		exit(2);
	}
|	LPACKAGE sym ';' 
	{
		int nkids = 3;
		struct tree* t1 = new_leaf_node($1->category, "package", $1);
		struct tree* t3 = new_leaf_node($3->category, "package", $3);
		struct tree** kids = create_tree_kids(nkids, t1, $2, t3);
		$$ = new_tree_node(R_PACKAGE+1, "package", nkids, kids, NULL);
	}
;

imports:
	%empty
	{
		$$ = new_epsilon_tree(R_IMPORTS, "imports");
	}	
|	imports import ';' 
	{
		int nkids = 3;
		struct tree* t3 = new_leaf_node($3->category, "imports", $3);
		struct tree** kids = create_tree_kids(nkids, $1, $2, t3);
		$$ = new_tree_node(R_IMPORTS+1, "imports", nkids, kids, NULL);
	}
;

import:
	LIMPORT import_stmt
	{
		int nkids = 2;
		struct tree* t1 = new_leaf_node($1->category, "import", $1);
		struct tree** kids = create_tree_kids(nkids, t1, $2);
		$$ = new_tree_node(R_IMPORT, "import", nkids, kids, NULL);
	}
|	LIMPORT '(' import_stmt_list osemi ')'
	{
		int nkids = 5;
		struct tree* t1 = new_leaf_node($1->category, "import", $1);
		struct tree* t2 = new_leaf_node($2->category, "import", $2);
		struct tree* t5 = new_leaf_node($5->category, "import", $5);
		struct tree** kids = create_tree_kids(nkids, t1, t2, $3, $4, t5);
		$$ = new_tree_node(R_IMPORT+1, "import", nkids, kids, NULL);
	}
|	LIMPORT '(' ')'
	{
		int nkids = 3;
		struct tree* t1 = new_leaf_node($1->category, "import", $1);
		struct tree* t2 = new_leaf_node($2->category, "import", $2);
		struct tree* t3 = new_leaf_node($3->category, "import", $3);
		struct tree** kids = create_tree_kids(nkids, t1, t2, t3);
		$$ = new_tree_node(R_IMPORT+2, "import", nkids, kids, NULL);
	}
;

import_stmt:
	import_here import_package
	{
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, $1, $2);
		$$ = new_tree_node(R_IMPORT_STMT, "import_stmt", nkids, kids, NULL);
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
		int nkids = 3;
		struct tree* t2 = new_leaf_node($2->category, "import_stmt_list", $2);
		struct tree** kids = create_tree_kids(nkids, $1, t2, $3);
		$$ = new_tree_node(R_IMPORT_STMT_LIST+1, "import_stmt_list", nkids, kids, NULL);
	}
;

import_here:
	LLITERAL
	{
		int nkids = 1;
		struct tree* t1 = new_leaf_node(LLITERAL, "import_here", $1);
		struct tree** kids = create_tree_kids(nkids, t1);
		$$ = new_tree_node(R_IMPORT_HERE, "import_here", nkids, kids, NULL);
	}
|	sym LLITERAL
	{
		int nkids = 2;
		struct tree* t2 = new_leaf_node(LLITERAL, "import_here", $2);
		struct tree** kids = create_tree_kids(nkids, $1, t2);
		$$ = new_tree_node(R_IMPORT_HERE+1, "import_here", nkids, kids, NULL);
	}
|	'.' LLITERAL
	{
		int nkids = 2;
		struct tree* t1 = new_leaf_node($1->category, "import_here", $1);
		struct tree* t2 = new_leaf_node(LLITERAL, "import_here", $2);
		struct tree** kids = create_tree_kids(nkids, t1, t2);
		$$ = new_tree_node(R_IMPORT_HERE+2, "import_here", nkids, kids, NULL);
	}
;

import_package:
	LPACKAGE LNAME import_safety ';'
	{
		int nkids = 4;
		struct tree* t1 = new_leaf_node($1->category, "import_package", $1);
		struct tree* t2 = new_leaf_node($2->category, "import_package", $2);
		struct tree* t4 = new_leaf_node($4->category, "import_package", $4);
		struct tree** kids = create_tree_kids(nkids, t1, t2, $3, t4);
		$$ = new_tree_node(R_IMPORT_PACKAGE, "import_package", nkids, kids, NULL);
	}
;

import_safety:
	%empty
	{
		$$ = new_epsilon_tree(R_IMPORT_SAFETY, "import_safety");
	}
|	LNAME
	{
		int nkids = 1;
		struct tree* t1 = new_leaf_node($1->category, "import_safety", $1);
		struct tree** kids = create_tree_kids(nkids, t1);
		$$ = new_tree_node(R_IMPORT_SAFETY+1, "import_safety", nkids, kids, NULL);
	}
;

/*
 * declarations
 */
xdcl:
	%empty 
	{
		yyerror("empty top-level declaration");
		$$ = new_epsilon_tree(R_XDCL, "xdcl");
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
		int nkids = 2;
		struct tree* t1 = new_leaf_node($1->category, "common_dcl", $1);
		struct tree** kids = create_tree_kids(nkids, t1, $2);
		$$ = new_tree_node(R_COMMON_DCL, "common_dcl", nkids, kids, NULL);
	}
|	LVAR '(' vardcl_list osemi ')'
	{
		int nkids = 5;
		struct tree* t1 = new_leaf_node($1->category, "common_dcl", $1);
		struct tree* t2 = new_leaf_node($2->category, "common_dcl", $2);
		struct tree* t5 = new_leaf_node($5->category, "common_dcl", $5);
		struct tree** kids = create_tree_kids(nkids, t1, t2, $3, $4, t5);
		$$ = new_tree_node(R_COMMON_DCL+1, "common_dcl", nkids, kids, NULL);
	}
|	LVAR '(' ')'
	{
		int nkids = 3;
		struct tree* t1 = new_leaf_node($1->category, "common_dcl", $1);
		struct tree* t2 = new_leaf_node($2->category, "common_dcl", $2);
		struct tree* t3 = new_leaf_node($3->category, "common_dcl", $3);
		struct tree** kids = create_tree_kids(nkids, t1, t2, t3);
		$$ = new_tree_node(R_COMMON_DCL+2, "common_dcl", nkids, kids, NULL);
	}
|	lconst constdcl
	{
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, $1, $2);
		$$ = new_tree_node(R_COMMON_DCL+3, "common_dcl", nkids, kids, NULL);
	}
|	lconst '(' constdcl osemi ')'
	{
		int nkids = 5;
		struct tree* t2 = new_leaf_node($2->category, "common_dcl", $2);
		struct tree* t5 = new_leaf_node($5->category, "common_dcl", $5);
		struct tree** kids = create_tree_kids(nkids, $1, t2, $3, $4, t5);
		$$ = new_tree_node(R_COMMON_DCL+4, "common_dcl", nkids, kids, NULL);
	}
|	lconst '(' constdcl ';' constdcl_list osemi ')'
	{
		int nkids = 7;
		struct tree* t2 = new_leaf_node($2->category, "common_dcl", $2);
		struct tree* t4 = new_leaf_node($4->category, "common_dcl", $4);
		struct tree* t7 = new_leaf_node($7->category, "common_dcl", $7);
		struct tree** kids = create_tree_kids(nkids, $1, t2, $3, t4, $5, $6, t7);
		$$ = new_tree_node(R_COMMON_DCL+5, "common_dcl", nkids, kids, NULL);
	}
|	lconst '(' ')'
	{
		int nkids = 3;
		struct tree* t2 = new_leaf_node($2->category, "common_dcl", $2);
		struct tree* t3 = new_leaf_node($3->category, "common_dcl", $3);
		struct tree** kids = create_tree_kids(nkids, $1, t2, t3);
		$$ = new_tree_node(R_COMMON_DCL+6, "common_dcl", nkids, kids, NULL);
	}
|	LTYPE typedcl
	{
		int nkids = 2;
		struct tree* t1 = new_leaf_node($1->category, "common_dcl", $1);
		struct tree** kids = create_tree_kids(nkids, t1, $2);
		$$ = new_tree_node(R_COMMON_DCL+7, "common_dcl", nkids, kids, NULL);
	}
|	LTYPE '(' typedcl_list osemi ')'
	{
		int nkids = 5;
		struct tree* t1 = new_leaf_node($1->category, "common_dcl", $1);
		struct tree* t2 = new_leaf_node($2->category, "common_dcl", $2);
		struct tree* t5 = new_leaf_node($5->category, "common_dcl", $5);
		struct tree** kids = create_tree_kids(nkids, t1, t2, $3, $4, t5);
		$$ = new_tree_node(R_COMMON_DCL+8, "common_dcl", nkids, kids, NULL);
	}
|	LTYPE '(' ')'
	{
		int nkids = 3;
		struct tree* t1 = new_leaf_node($1->category, "common_dcl", $1);
		struct tree* t2 = new_leaf_node($2->category, "common_dcl", $2);
		struct tree* t3 = new_leaf_node($3->category, "common_dcl", $3);
		struct tree** kids = create_tree_kids(nkids, t1, t2, t3);
		$$ = new_tree_node(R_COMMON_DCL+9, "common_dcl", nkids, kids, NULL);
	}
;

lconst:
	LCONST
	{
		int nkids = 1;
		struct tree* t1 = new_leaf_node($1->category, "lconst", $1);
		struct tree** kids = create_tree_kids(nkids, t1);
		$$ = new_tree_node(R_LCONST, "lconst", nkids, kids, NULL);
	}
;

vardcl:
	dcl_name_list ntype
	{
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, $1, $2);
		$$ = new_tree_node(R_VARDCL, "vardcl", nkids, kids, NULL);
	}
|	dcl_name_list ntype '=' expr_list
	{
		int nkids = 4;
		struct tree* t3 = new_leaf_node($3->category, "vardcl", $3);
		struct tree** kids = create_tree_kids(nkids, $1, $2, t3, $4);
		$$ = new_tree_node(R_VARDCL+1, "vardcl", nkids, kids, NULL);
	}
|	dcl_name_list '=' expr_list
	{
		int nkids = 3;
		struct tree* t2 = new_leaf_node($2->category, "vardcl", $2);
		struct tree** kids = create_tree_kids(nkids, $1, t2, $3);
		$$ = new_tree_node(R_VARDCL+2, "vardcl", nkids, kids, NULL);
	}
	;

constdcl:
	dcl_name_list ntype '=' expr_list
	{
		int nkids = 4;
		struct tree* t3 = new_leaf_node($3->category, "constdcl", $3);
		struct tree** kids = create_tree_kids(nkids, $1, $2, t3, $4);
		$$ = new_tree_node(R_CONSTDCL, "constdcl", nkids, kids, NULL);
	}
|	dcl_name_list '=' expr_list
	{
		int nkids = 3;
		struct tree* t2 = new_leaf_node($2->category, "constdcl", $2);
		struct tree** kids = create_tree_kids(nkids, $1, t2, $3);
		$$ = new_tree_node(R_CONSTDCL+1, "constdcl", nkids, kids, NULL);
	}
;

constdcl1:
	constdcl
	{
		$$ = $1;
	}
|	dcl_name_list ntype
	{
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, $1, $2);
		$$ = new_tree_node(R_CONSTDCL1+1, "constdcl1", nkids, kids, NULL);
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
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, $1, $2);
		$$ = new_tree_node(R_TYPEDCL, "typedcl", nkids, kids, NULL);
	}
;

simple_stmt:
	expr
	{
		$$ = $1;
	}
|	expr LASOP expr
	{
		int nkids = 3;
		struct tree* t2 = new_leaf_node($2->category, "simple_stmt", $2);
		struct tree** kids = create_tree_kids(nkids, $1, t2, $3);
		$$ = new_tree_node(R_SIMPLE_STMT+1, "simple_stmt", nkids, kids, NULL);
	}
|	expr_list '=' expr_list
	{
		int nkids = 3;
		struct tree* t2 = new_leaf_node($2->category, "simple_stmt", $2);
		struct tree** kids = create_tree_kids(nkids, $1, t2, $3);
		$$ = new_tree_node(R_SIMPLE_STMT+2, "simple_stmt", nkids, kids, NULL);
	}
|	expr_list LCOLAS expr_list
	{
		int nkids = 3;
		struct tree* t2 = new_leaf_node($2->category, "simple_stmt", $2);
		struct tree** kids = create_tree_kids(nkids, $1, t2, $3);
		$$ = new_tree_node(R_SIMPLE_STMT+3, "simple_stmt", nkids, kids, NULL);
	}
|	expr LINC
	{
		int nkids = 2;
		struct tree* t2 = new_leaf_node($2->category, "simple_stmt", $2);
		struct tree** kids = create_tree_kids(nkids, $1, t2);
		$$ = new_tree_node(R_SIMPLE_STMT+4, "simple_stmt", nkids, kids, NULL);
	}
|	expr LDEC
	{
		int nkids = 2;
		struct tree* t2 = new_leaf_node($2->category, "simple_stmt", $2);
		struct tree** kids = create_tree_kids(nkids, $1, t2);
		$$ = new_tree_node(R_SIMPLE_STMT+5, "simple_stmt", nkids, kids, NULL);
	}
;

compound_stmt:
	'{' 
	stmt_list '}'
	{
		int nkids = 3;
		struct tree* t1 = new_leaf_node($1->category, "compound_stmt", $1);
		struct tree* t3 = new_leaf_node($3->category, "compound_stmt", $3);
		struct tree** kids = create_tree_kids(nkids, t1, $2, t3);
		$$ = new_tree_node(R_COMPOUND_STMT, "compound_stmt", nkids, kids, NULL);
	}
;

loop_body:
	'{'
	stmt_list '}'
	{
		int nkids = 3;
		struct tree* t1 = new_leaf_node($1->category, "loop_body", $1);
		struct tree* t3 = new_leaf_node($3->category, "loop_body", $3);
		struct tree** kids = create_tree_kids(nkids, t1, $2, t3);
		$$ = new_tree_node(R_LOOP_BODY, "loop_body", nkids, kids, NULL);
	}
;

for_header:
	osimple_stmt ';' osimple_stmt ';' osimple_stmt
	{
		int nkids = 5;
		struct tree* t2 = new_leaf_node($2->category, "for_header", $2);
		struct tree* t4 = new_leaf_node($4->category, "for_header", $4);
		struct tree** kids = create_tree_kids(nkids, $1, t2, $3, t4, $5);
		$$ = new_tree_node(R_FOR_HEADER, "for_header", nkids, kids, NULL);
	}
|	osimple_stmt
	{
		$$ = $1;
	}
;

for_body:
	for_header loop_body
	{
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, $1, $2);
		$$ = new_tree_node(R_FOR_BODY, "for_body", nkids, kids, NULL);
	}
;

for_stmt:
	LFOR
	for_body
	{
		int nkids = 2;
		struct tree* t1 = new_leaf_node($1->category, "for_stmt", $1);
		struct tree** kids = create_tree_kids(nkids, t1, $2);
		$$ = new_tree_node(R_FOR_STMT, "for_stmt", nkids, kids, NULL);
	}
	;

if_header:
	osimple_stmt
	{
		$$ = $1;
	}
|	osimple_stmt ';' osimple_stmt
	{
		int nkids = 3;
		struct tree* t2 = new_leaf_node($2->category, "if_header", $2);
		struct tree** kids = create_tree_kids(nkids, $1, t2, $3);
		$$ = new_tree_node(R_IF_HEADER+1, "if_header", nkids, kids, NULL);
	}
;

/* IF cond body (ELSE IF cond body)* (ELSE block)? */
if_stmt:
	LIF
	if_header
	loop_body
	elseif_list else
	{
		int nkids = 5;
		struct tree* t1 = new_leaf_node($1->category, "if_stmt", $1);
		struct tree** kids = create_tree_kids(nkids, t1, $2, $3, $4, $5);
		$$ = new_tree_node(R_IF_STMT, "if_stmt", nkids, kids, NULL);
	}
;

elseif:
	LELSE LIF 
	if_header loop_body
	{
		int nkids = 4;
		struct tree* t1 = new_leaf_node($1->category, "elseif", $1);
		struct tree* t2 = new_leaf_node($2->category, "elseif", $2);
		struct tree** kids = create_tree_kids(nkids, t1, t2, $3, $4);
		$$ = new_tree_node(R_ELSEIF, "elseif", nkids, kids, NULL);
	}
;

elseif_list:
	%empty
	{
		$$ = new_epsilon_tree(R_ELSEIF_LIST, "elseif_list");
	}
|	elseif_list elseif
	{
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, $1, $2);
		$$ = new_tree_node(R_ELSEIF_LIST+1, "elseif_list", nkids, kids, NULL);
	}
;

else:
	%empty
	{
		$$ = new_epsilon_tree(R_ELSE, "else");
	}
|	LELSE compound_stmt
	{
		int nkids = 2;
		struct tree* t1 = new_leaf_node($1->category, "else", $1);
		struct tree** kids = create_tree_kids(nkids, t1, $2);
		$$ = new_tree_node(R_ELSE+1, "else", nkids, kids, NULL);
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
		int nkids = 3;
		struct tree* t2 = new_leaf_node($2->category, "expr", $2);
		struct tree** kids = create_tree_kids(nkids, $1, t2, $3);
		$$ = new_tree_node(R_EXPR+1, "expr", nkids, kids, NULL);
	}
|	expr LANDAND expr
	{
		int nkids = 3;
		struct tree* t2 = new_leaf_node($2->category, "expr", $2);
		struct tree** kids = create_tree_kids(nkids, $1, t2, $3);
		$$ = new_tree_node(R_EXPR+2, "expr", nkids, kids, NULL);
	}
|	expr LEQ expr
	{
		int nkids = 3;
		struct tree* t2 = new_leaf_node($2->category, "expr", $2);
		struct tree** kids = create_tree_kids(nkids, $1, t2, $3);
		$$ = new_tree_node(R_EXPR+3, "expr", nkids, kids, NULL);
	}
|	expr LNE expr
	{
		int nkids = 3;
		struct tree* t2 = new_leaf_node($2->category, "expr", $2);
		struct tree** kids = create_tree_kids(nkids, $1, t2, $3);
		$$ = new_tree_node(R_EXPR+4, "expr", nkids, kids, NULL);
	}
|	expr LLT expr
	{
		int nkids = 3;
		struct tree* t2 = new_leaf_node($2->category, "expr", $2);
		struct tree** kids = create_tree_kids(nkids, $1, t2, $3);
		$$ = new_tree_node(R_EXPR+5, "expr", nkids, kids, NULL);
	}
|	expr LLE expr
	{
		int nkids = 3;
		struct tree* t2 = new_leaf_node($2->category, "expr", $2);
		struct tree** kids = create_tree_kids(nkids, $1, t2, $3);
		$$ = new_tree_node(R_EXPR+6, "expr", nkids, kids, NULL);
	}
|	expr LGE expr
	{
		int nkids = 3;
		struct tree* t2 = new_leaf_node($2->category, "expr", $2);
		struct tree** kids = create_tree_kids(nkids, $1, t2, $3);
		$$ = new_tree_node(R_EXPR+7, "expr", nkids, kids, NULL);
	}
|	expr LGT expr
	{
		int nkids = 3;
		struct tree* t2 = new_leaf_node($2->category, "expr", $2);
		struct tree** kids = create_tree_kids(nkids, $1, t2, $3);
		$$ = new_tree_node(R_EXPR+8, "expr", nkids, kids, NULL);
	}
|	expr '+' expr
	{
		int nkids = 3;
		struct tree* t2 = new_leaf_node($2->category, "expr", $2);
		struct tree** kids = create_tree_kids(nkids, $1, t2, $3);
		$$ = new_tree_node(R_EXPR+9, "expr", nkids, kids, NULL);
	}
|	expr '-' expr
	{
		int nkids = 3;
		struct tree* t2 = new_leaf_node($2->category, "expr", $2);
		struct tree** kids = create_tree_kids(nkids, $1, t2, $3);
		$$ = new_tree_node(R_EXPR+10, "expr", nkids, kids, NULL);
	}
|	expr '|' expr
	{
		int nkids = 3;
		struct tree* t2 = new_leaf_node($2->category, "expr", $2);
		struct tree** kids = create_tree_kids(nkids, $1, t2, $3);
		$$ = new_tree_node(R_EXPR+11, "expr", nkids, kids, NULL);
	}
|	expr '*' expr
	{
		int nkids = 3;
		struct tree* t2 = new_leaf_node($2->category, "expr", $2);
		struct tree** kids = create_tree_kids(nkids, $1, t2, $3);
		$$ = new_tree_node(R_EXPR+12, "expr", nkids, kids, NULL);
	}
|	expr '/' expr
	{
		int nkids = 3;
		struct tree* t2 = new_leaf_node($2->category, "expr", $2);
		struct tree** kids = create_tree_kids(nkids, $1, t2, $3);
		$$ = new_tree_node(R_EXPR+13, "expr", nkids, kids, NULL);
	}
|	expr '%' expr
	{
		int nkids = 3;
		struct tree* t2 = new_leaf_node($2->category, "expr", $2);
		struct tree** kids = create_tree_kids(nkids, $1, t2, $3);
		$$ = new_tree_node(R_EXPR+14, "expr", nkids, kids, NULL);
	}
|	expr '&' expr
	{
		int nkids = 3;
		struct tree* t2 = new_leaf_node($2->category, "expr", $2);
		struct tree** kids = create_tree_kids(nkids, $1, t2, $3);
		$$ = new_tree_node(R_EXPR+15, "expr", nkids, kids, NULL);
	}
|	expr LANDNOT expr
	{
		int nkids = 3;
		struct tree* t2 = new_leaf_node($2->category, "expr", $2);
		struct tree** kids = create_tree_kids(nkids, $1, t2, $3);
		$$ = new_tree_node(R_EXPR+16, "expr", nkids, kids, NULL);
	}
|	expr LLSH expr
	{
		int nkids = 3;
		struct tree* t2 = new_leaf_node($2->category, "expr", $2);
		struct tree** kids = create_tree_kids(nkids, $1, t2, $3);
		$$ = new_tree_node(R_EXPR+17, "expr", nkids, kids, NULL);
	}

|	expr LRSH expr
	{
		int nkids = 3;
		struct tree* t2 = new_leaf_node($2->category, "expr", $2);
		struct tree** kids = create_tree_kids(nkids, $1, t2, $3);
		$$ = new_tree_node(R_EXPR+18, "expr", nkids, kids, NULL);
	}
|	expr LCOMM expr
	{
		int nkids = 3;
		struct tree* t2 = new_leaf_node($2->category, "expr", $2);
		struct tree** kids = create_tree_kids(nkids, $1, t2, $3);
		$$ = new_tree_node(R_EXPR+19, "expr", nkids, kids, NULL);
	}
;

uexpr:
	pexpr
	{
		$$ = $1;
	}
|	'*' uexpr
	{
		int nkids = 2;
		struct tree* t1 = new_leaf_node($1->category, "uexpr", $1);
		struct tree** kids = create_tree_kids(nkids, t1, $2);
		$$ = new_tree_node(R_UEXPR+1, "uexpr", nkids, kids, NULL);
	}
|	'+' uexpr
	{
		int nkids = 2;
		struct tree* t1 = new_leaf_node($1->category, "uexpr", $1);
		struct tree** kids = create_tree_kids(nkids, t1, $2);
		$$ = new_tree_node(R_UEXPR+2, "uexpr", nkids, kids, NULL);
	}
|	'-' uexpr
	{
		int nkids = 2;
		struct tree* t1 = new_leaf_node($1->category, "uexpr", $1);
		struct tree** kids = create_tree_kids(nkids, t1, $2);
		$$ = new_tree_node(R_UEXPR+3, "uexpr", nkids, kids, NULL);
	}
|	'!' uexpr
	{
		int nkids = 2;
		struct tree* t1 = new_leaf_node($1->category, "uexpr", $1);
		struct tree** kids = create_tree_kids(nkids, t1, $2);
		$$ = new_tree_node(R_UEXPR+4, "uexpr", nkids, kids, NULL);
	}
|	'~' uexpr
	{
		yyerror("the bitwise complement operator is ^");
		int nkids = 2;
		struct tree* t1 = new_leaf_node($1->category, "uexpr", $1);
		struct tree** kids = create_tree_kids(nkids, t1, $2);
		$$ = new_tree_node(R_UEXPR+5, "uexpr", nkids, kids, NULL);
	}
|	LCOMM uexpr
	{
		int nkids = 2;
		struct tree* t1 = new_leaf_node($1->category, "uexpr", $1);
		struct tree** kids = create_tree_kids(nkids, t1, $2);
		$$ = new_tree_node(R_UEXPR+6, "uexpr", nkids, kids, NULL);
	}
;

/*
 * call-like statements that
 * can be preceded by 'defer' and 'go'
 */
pseudocall:
	pexpr '(' ')'
	{
		int nkids = 3;
		struct tree* t3 = new_leaf_node($2->category, "pseudocall", $3);
		struct tree* t2 = new_leaf_node($3->category, "pseudocall", $2);
		struct tree** kids = create_tree_kids(nkids, $1, t2, t3);
		$$ = new_tree_node(R_PSEUDOCALL, "pseudocall", nkids, kids, NULL);
	}
|	pexpr '(' expr_or_type_list ocomma ')'
	{
		int nkids = 5;
		struct tree* t2 = new_leaf_node($2->category, "pseudocall", $2);
		struct tree* t5 = new_leaf_node($5->category, "pseudocall", $5);
		struct tree** kids = create_tree_kids(nkids, $1, t2, $3, $4, t5);
		$$ = new_tree_node(R_PSEUDOCALL+1, "pseudocall", nkids, kids, NULL);
	}
|	pexpr '(' expr_or_type_list LDDD ocomma ')'
	{
		int nkids = 6;
		struct tree* t2 = new_leaf_node($2->category, "pseudocall", $2);
		struct tree* t4 = new_leaf_node($4->category, "pseudocall", $4);
		struct tree* t6 = new_leaf_node($6->category, "pseudocall", $6);
		struct tree** kids = create_tree_kids(nkids, $1, t2, $3, t4, $5, t6);
		$$ = new_tree_node(R_PSEUDOCALL+2, "pseudocall", nkids, kids, NULL);
	}
;

pexpr_no_paren:
	LLITERAL
	{
		int nkids = 1;
		struct tree* t1 = new_leaf_node($1->category, "pexpr_no_paren", $1);
		struct tree** kids = create_tree_kids(nkids, t1);
		$$ = new_tree_node(R_PEXPR_NO_PAREN, "pexpr_no_paren", nkids, kids, NULL);
	}
|	name
	{
		$$ = $1;
	}
|	pexpr '.' sym
	{
		int nkids = 3;
		struct tree* t2 = new_leaf_node($2->category, "pexpr_no_paren", $2);
		struct tree** kids = create_tree_kids(nkids, $1, t2, $3);
		$$ = new_tree_node(R_PEXPR_NO_PAREN+2, "pexpr_no_paren", nkids, kids, NULL);
	}
|	pexpr '.' '(' expr_or_type ')'
	{
		int nkids = 5;
		struct tree* t2 = new_leaf_node($2->category, "pexpr_no_paren", $2);
		struct tree* t3 = new_leaf_node($3->category, "pexpr_no_paren", $3);
		struct tree* t5 = new_leaf_node($5->category, "pexpr_no_paren", $5);
		struct tree** kids = create_tree_kids(nkids, $1, t2, t3, $4, t5);
		$$ = new_tree_node(R_PEXPR_NO_PAREN+3, "pexpr_no_paren", nkids, kids, NULL);
	}
|	pexpr '.' '(' LTYPE ')'
	{
		int nkids = 5;
		struct tree* t2 = new_leaf_node($2->category, "pexpr_no_paren", $2);
		struct tree* t3 = new_leaf_node($3->category, "pexpr_no_paren", $3);
		struct tree* t4 = new_leaf_node($4->category, "pexpr_no_paren", $4);
		struct tree* t5 = new_leaf_node($5->category, "pexpr_no_paren", $5);
		struct tree** kids = create_tree_kids(nkids, $1, t2, t3, t4, t5);
		$$ = new_tree_node(R_PEXPR_NO_PAREN+4, "pexpr_no_paren", nkids, kids, NULL);
	}
|	pexpr '[' expr ']'
	{
		int nkids = 4;
		struct tree* t2 = new_leaf_node($2->category, "pexpr_no_paren", $2);
		struct tree* t4 = new_leaf_node($4->category, "pexpr_no_paren", $4);
		struct tree** kids = create_tree_kids(nkids, $1, t2, $3, t4);
		$$ = new_tree_node(R_PEXPR_NO_PAREN+5, "pexpr_no_paren", nkids, kids, NULL);
	}
|	pseudocall
	{
		$$ = $1;
	}
|	convtype '(' expr ocomma ')'
	{
		int nkids = 5;
		struct tree* t2 = new_leaf_node($2->category, "pexpr_no_paren", $2);
		struct tree* t5 = new_leaf_node($5->category, "pexpr_no_paren", $5);
		struct tree** kids = create_tree_kids(nkids, $1, t2, $3, $4, t5);
		$$ = new_tree_node(R_PEXPR_NO_PAREN+7, "pexpr_no_paren", nkids, kids, NULL);
	}
|	comptype lbrace start_complit braced_keyval_list '}' 
	{
		int nkids = 5;
		struct tree* t5 = new_leaf_node($5->category, "pexpr_no_paren", $5);
		struct tree** kids = create_tree_kids(nkids, $1, $2, $3, $4, t5);
		$$ = new_tree_node(R_PEXPR_NO_PAREN+8, "pexpr_no_paren", nkids, kids, NULL);
	}
|	fnliteral
	{
		$$ = $1;
	}
;


pexpr:
	pexpr_no_paren
	{
		$$ = $1;
	}
|	'(' expr_or_type ')'
	{
		int nkids = 3;
		struct tree* t1 = new_leaf_node($1->category, "pexpr", $1);
		struct tree* t3 = new_leaf_node($3->category, "pexpr", $3);
		struct tree** kids = create_tree_kids(nkids, t1, $2, t3);
		$$ = new_tree_node(R_PEXPR+1, "pexpr", nkids, kids, NULL);
	}
;

expr_or_type:
	expr
	{
		$$ = $1;
	}
|	non_expr_type %prec PreferToRightParen
	{
		$$ = $1;
	}
;

name_or_type:
	ntype
	{
		$$ = $1;

	}
;

lbrace:
	'{'
	{
		int nkids = 1;
		struct tree* t1 = new_leaf_node($1->category, "lbrace", $1);
		struct tree** kids = create_tree_kids(nkids, t1);
		$$ = new_tree_node(R_LBRACE, "lbrace", nkids, kids, NULL);
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
		int nkids = 1;
		struct tree* t1 = new_leaf_node($1->category, "sym", $1);
		struct tree** kids = create_tree_kids(nkids, t1);
		$$ = new_tree_node(R_SYM, "sym", nkids, kids, NULL);
	}
|	hidden_importsym
	{
		$$ = $1;
	}
|	'?'
	{
		int nkids = 1;
		struct tree* t1 = new_leaf_node($1->category, "sym", $1);
		struct tree** kids = create_tree_kids(nkids, t1);
		$$ = new_tree_node(R_SYM+2, "sym", nkids, kids, NULL);
	}
;

hidden_importsym:
	'@' LLITERAL '.' LNAME
	{
		int nkids = 4;
		struct tree* t1 = new_leaf_node($1->category, "hidden_importsym", $1);
		struct tree* t2 = new_leaf_node($2->category, "hidden_importsym", $2);
		struct tree* t3 = new_leaf_node($3->category, "hidden_importsym", $3);
		struct tree* t4 = new_leaf_node($4->category, "hidden_importsym", $4);
		struct tree** kids = create_tree_kids(nkids, t1, t2, t3, t4);
		$$ = new_tree_node(R_HIDDEN_IMPORTSYM, "hidden_importsym", nkids, kids, NULL);
	}
|	'@' LLITERAL '.' '?'
	{
		int nkids = 4;
		struct tree* t1 = new_leaf_node($1->category, "hidden_importsym", $1);
		struct tree* t2 = new_leaf_node($2->category, "hidden_importsym", $2);
		struct tree* t3 = new_leaf_node($3->category, "hidden_importsym", $3);
		struct tree* t4 = new_leaf_node($4->category, "hidden_importsym", $4);
		struct tree** kids = create_tree_kids(nkids, t1, t2, t3, t4);
		$$ = new_tree_node(R_HIDDEN_IMPORTSYM+1, "hidden_importsym", nkids, kids, NULL);
	}
;

name:
	sym	%prec NotParen
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

		int nkids = 1;
		struct tree* t1 = new_leaf_node($1->category, "dotdotdot", $1);
		struct tree** kids = create_tree_kids(nkids, t1);
		$$ = new_tree_node(R_DOTDOTDOT, "dotdotdot", nkids, kids, NULL);
	}
|	LDDD ntype
	{
		int nkids = 2;
		struct tree* t1 = new_leaf_node($1->category, "dotdotdot", $1);
		struct tree** kids = create_tree_kids(nkids, t1, $2);
		$$ = new_tree_node(R_DOTDOTDOT+1, "dotdotdot", nkids, kids, NULL);
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
		int nkids = 3;
		struct tree* t1 = new_leaf_node($1->category, "ntype", $1);
		struct tree* t3 = new_leaf_node($3->category, "ntype", $3);
		struct tree** kids = create_tree_kids(nkids, t1, $2, t3);
		$$ = new_tree_node(R_NTYPE+4, "ntype", nkids, kids, NULL);
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
		int nkids = 2;
		struct tree* t1 = new_leaf_node($1->category, "non_expr_type", $1);
		struct tree** kids = create_tree_kids(nkids, t1, $2);
		$$ = new_tree_node(R_NON_EXPR_TYPE+2, "non_expr_type", nkids, kids, NULL);
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
		int nkids = 3;
		struct tree* t2 = new_leaf_node($2->category, "dotname", $2);
		struct tree** kids = create_tree_kids(nkids, $1, t2, $3);
		$$ = new_tree_node(R_DOTNAME+1, "dotname", nkids, kids, NULL);
	}
;

othertype:
	'[' oexpr ']' ntype
	{
		int nkids = 4;
		struct tree* t1 = new_leaf_node($1->category, "othertype", $1);
		struct tree* t3 = new_leaf_node($3->category, "othertype", $3);
		struct tree** kids = create_tree_kids(nkids, t1, $2, t3, $4);
		$$ = new_tree_node(R_OTHERTYPE, "othertype", nkids, kids, NULL);
	}	
|	'[' LDDD ']' ntype
	{
		int nkids = 4;
		struct tree* t1 = new_leaf_node($1->category, "othertype", $1);
		struct tree* t2 = new_leaf_node($2->category, "othertype", $2);
		struct tree* t3 = new_leaf_node($3->category, "othertype", $3);
		struct tree** kids = create_tree_kids(nkids, t1, t2, t3, $4);
		$$ = new_tree_node(R_OTHERTYPE+1, "othertype", nkids, kids, NULL);
	}
|	LMAP '[' ntype ']' ntype
	{
		int nkids = 5;
		struct tree* t1 = new_leaf_node($1->category, "othertype", $1);
		struct tree* t2 = new_leaf_node($2->category, "othertype", $2);
		struct tree* t4 = new_leaf_node($4->category, "othertype", $4);
		struct tree** kids = create_tree_kids(nkids, t1, t2, $3, t4, $5);
		$$ = new_tree_node(R_OTHERTYPE+2, "othertype", nkids, kids, NULL);
	}
|	structtype
	{
		$$ = $1;
	}
;

ptrtype:
	'*' ntype
	{
		int nkids = 2;
		struct tree* t1 = new_leaf_node($1->category, "ptrtype", $1);
		struct tree** kids = create_tree_kids(nkids, t1, $2);
		$$ = new_tree_node(R_PTRTYPE, "ptrtype", nkids, kids, NULL);
	}
;

structtype:
	LSTRUCT lbrace structdcl_list osemi '}'
	{
		int nkids = 5;
		struct tree* t1 = new_leaf_node($1->category, "structtype", $1);
		struct tree* t5 = new_leaf_node($5->category, "structtype", $5);
		struct tree** kids = create_tree_kids(nkids, t1, $2, $3, $4, t5);
		$$ = new_tree_node(R_STRUCTTYPE, "structtype", nkids, kids, NULL);
	}
|	LSTRUCT lbrace '}'
	{
		int nkids = 3;
		struct tree* t1 = new_leaf_node($1->category, "structtype", $1);
		struct tree* t3 = new_leaf_node($3->category, "structtype", $3);
		struct tree** kids = create_tree_kids(nkids, t1, $2, t3);
		$$ = new_tree_node(R_STRUCTTYPE+1, "structtype", nkids, kids, NULL);
	}
;

/*
 * function stuff
 * all in one place to show how crappy it all is
 */
xfndcl:
	LFUNC fndcl fnbody
	{
		int nkids = 3;
		struct tree* t1 = new_leaf_node($1->category, "xfndcl", $1);
		struct tree** kids = create_tree_kids(nkids, t1, $2, $3);
		$$ = new_tree_node(R_XFNDCL, "xfndcl", nkids, kids, NULL);
	}
;

fndcl:
	sym '(' oarg_type_list_ocomma ')' fnres
	{
		int nkids = 5;
		struct tree* t2 = new_leaf_node($2->category, "fndcl", $2);
		struct tree* t4 = new_leaf_node($4->category, "fndcl", $4);
		struct tree** kids = create_tree_kids(nkids, $1, t2, $3, t4, $5);
		$$ = new_tree_node(R_FNDCL, "fndcl", nkids, kids, NULL);
	}
|	'(' oarg_type_list_ocomma ')' sym '(' oarg_type_list_ocomma ')' fnres
	{
		int nkids = 8;
		struct tree* t1 = new_leaf_node($1->category, "fndcl", $1);
		struct tree* t3 = new_leaf_node($3->category, "fndcl", $3);
		struct tree* t5 = new_leaf_node($5->category, "fndcl", $5);
		struct tree* t7 = new_leaf_node($7->category, "fndcl", $7);
		struct tree** kids = create_tree_kids(nkids, t1, $2, t3, $4, t5, $6, t7, $8);
		$$ = new_tree_node(R_FNDCL+1, "fndcl", nkids, kids, NULL);
	}
;


fntype:
	LFUNC '(' oarg_type_list_ocomma ')' fnres
	{
		int nkids = 5;
		struct tree* t1 = new_leaf_node($1->category, "fntype", $1);
		struct tree* t2 = new_leaf_node($2->category, "fntype", $2);
		struct tree* t4 = new_leaf_node($4->category, "fntype", $4);
		struct tree** kids = create_tree_kids(nkids, t1, t2, $3, t4, $5);
		$$ = new_tree_node(R_FNTYPE, "fntype", nkids, kids, NULL);
	}
;

fnbody:
	%empty
	{
		$$ = new_epsilon_tree(R_FNBODY, "fnbody");
	}
|	'{' stmt_list '}'
	{
		int nkids = 3;
		struct tree* t1 = new_leaf_node($1->category, "fnbody", $1);
		struct tree* t3 = new_leaf_node($3->category, "fnbody", $3);
		struct tree** kids = create_tree_kids(nkids, t1, $2, t3);
		$$ = new_tree_node(R_FNBODY+1, "fnbody", nkids, kids, NULL);
	}
;

fnres:
	%empty %prec NotParen
	{
		$$ = new_epsilon_tree(R_FNRES, "fnres");
	}
|	fnret_type
	{
		$$ = $1;
	}
|	'(' oarg_type_list_ocomma ')'
	{
		int nkids = 3;
		struct tree* t1 = new_leaf_node($1->category, "fnres", $1);
		struct tree* t3 = new_leaf_node($3->category, "fnres", $3);
		struct tree** kids = create_tree_kids(nkids, t1, $2, t3);
		$$ = new_tree_node(R_FNRES+2, "fnres", nkids, kids, NULL);
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
		int nkids = 4;
		struct tree* t4 = new_leaf_node($4->category, "fnliteral", $4);
		struct tree** kids = create_tree_kids(nkids, $1, $2, $3, t4);
		$$ = new_tree_node(R_FNLITERAL, "fnliteral", nkids, kids, NULL);
	}
|	fnlitdcl error
	{
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, $1, $2);
		$$ = new_tree_node(R_FNLITERAL+1, "fnliteral", nkids, kids, NULL);
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
		$$ = new_epsilon_tree(R_XDCL_LIST, "xdcl_list");
	}
|	xdcl_list xdcl ';'
	{
		int nkids = 3;
		struct tree* t3 = new_leaf_node($3->category, "xdcl_list", $3);
		struct tree** kids = create_tree_kids(nkids, $1, $2, t3);
		$$ = new_tree_node(R_XDCL_LIST+1, "xdcl_list", nkids, kids, NULL);
	}
;

vardcl_list:
	vardcl
	{
		$$ = $1;
	}
|	vardcl_list ';' vardcl
	{
		int nkids = 3;
		struct tree* t2 = new_leaf_node($2->category, "vardcl_list", $2);
		struct tree** kids = create_tree_kids(nkids, $1, t2, $3);
		$$ = new_tree_node(R_VARDCL_LIST+1, "vardcl_list", nkids, kids, NULL);
	}
;

constdcl_list:
	constdcl1
	{
		$$ = $1;
	}
|	constdcl_list ';' constdcl1
	{
		int nkids = 3;
		struct tree* t2 = new_leaf_node($2->category, "constdcl_list", $2);
		struct tree** kids = create_tree_kids(nkids, $1, t2, $3);
		$$ = new_tree_node(R_CONSTDCL_LIST+1, "constdcl_list", nkids, kids, NULL);
	}
;

typedcl_list:
	typedcl
	{
		$$ = $1;
	}
|	typedcl_list ';' typedcl
	{
		int nkids = 3;
		struct tree* t2 = new_leaf_node($2->category, "typedcl_list", $2);
		struct tree** kids = create_tree_kids(nkids, $1, t2, $3);
		$$ = new_tree_node(R_TYPEDCL_LIST+1, "typedcl_list", nkids, kids, NULL);
	}
;

structdcl_list:
	structdcl
	{
		$$ = $1;
	}
|	structdcl_list ';' structdcl
	{
		int nkids = 3;
		struct tree* t2 = new_leaf_node($2->category, "structdcl_list", $2);
		struct tree** kids = create_tree_kids(nkids, $1, t2, $3);
		$$ = new_tree_node(R_STRUCTDCL_LIST+1, "structdcl_list", nkids, kids, NULL);
	}
;

structdcl:
	new_name_list ntype oliteral
	{
		int nkids = 3;
		struct tree** kids = create_tree_kids(nkids, $1, $2, $3);
		$$ = new_tree_node(R_STRUCTDCL, "structdcl", nkids, kids, NULL);
	}
|	embed oliteral
	{
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, $1, $2);
		$$ = new_tree_node(R_STRUCTDCL+1, "structdcl", nkids, kids, NULL);
	}
|	'(' embed ')' oliteral
	{
		int nkids = 4;
		struct tree* t1 = new_leaf_node($1->category, "structdcl", $1);
		struct tree* t3 = new_leaf_node($3->category, "structdcl", $3);
		struct tree** kids = create_tree_kids(nkids, t1, $2, t3, $4);
		$$ = new_tree_node(R_STRUCTDCL+2, "structdcl", nkids, kids, NULL);
	}
|	'*' embed oliteral
	{
		int nkids = 3;
		struct tree* t1 = new_leaf_node($1->category, "structdcl", $1);
		struct tree** kids = create_tree_kids(nkids, t1, $2, $3);
		$$ = new_tree_node(R_STRUCTDCL+3, "structdcl", nkids, kids, NULL);
	}
|	'(' '*' embed ')' oliteral
	{
		int nkids = 5;
		struct tree* t1 = new_leaf_node($1->category, "structdcl", $1);
		struct tree* t2 = new_leaf_node($2->category, "structdcl", $2);
		struct tree* t4 = new_leaf_node($4->category, "structdcl", $4);
		struct tree** kids = create_tree_kids(nkids, t1, t2, $3, t4, $5);
		$$ = new_tree_node(R_STRUCTDCL+4, "structdcl", nkids, kids, NULL);
	}
|	'*' '(' embed ')' oliteral
	{
		int nkids = 5;
		struct tree* t1 = new_leaf_node($1->category, "structdcl", $1);
		struct tree* t2 = new_leaf_node($2->category, "structdcl", $2);
		struct tree* t4 = new_leaf_node($4->category, "structdcl", $4);
		struct tree** kids = create_tree_kids(nkids, t1, t2, $3, t4, $5);
		$$ = new_tree_node(R_STRUCTDCL+5, "structdcl", nkids, kids, NULL);
	}
	;

packname:
	LNAME
	{
		int nkids = 1;
		struct tree* t1 = new_leaf_node($1->category, "packname", $1);
		struct tree** kids = create_tree_kids(nkids, t1);
		$$ = new_tree_node(R_PACKNAME, "packname", nkids, kids, NULL);
	}
|	LNAME '.' sym
	{
		int nkids = 3;
		struct tree* t1 = new_leaf_node($1->category, "packname", $1);
		struct tree* t2 = new_leaf_node($2->category, "packname", $2);
		struct tree** kids = create_tree_kids(nkids, t1, t2, $3);
		$$ = new_tree_node(R_PACKNAME+1, "packname", nkids, kids, NULL);
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
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, $1, $2);
		$$ = new_tree_node(R_ARG_TYPE+1, "arg_type", nkids, kids, NULL);
	}
|	sym dotdotdot
	{
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, $1, $2);
		$$ = new_tree_node(R_ARG_TYPE+2, "arg_type", nkids, kids, NULL);
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
		int nkids = 3;
		struct tree* t2 = new_leaf_node($2->category, "arg_type_list", $2);
		struct tree** kids = create_tree_kids(nkids, $1, t2, $3);
		$$ = new_tree_node(R_ARG_TYPE_LIST+1, "arg_type_list", nkids, kids, NULL);
	}
	;

oarg_type_list_ocomma:
	%empty
	{
		$$ = new_epsilon_tree(R_OARG_TYPE_LIST_OCOMMA, "oarg_type_list_ocomma");
	}
|	arg_type_list ocomma
	{
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, $1, $2);
		$$ = new_tree_node(R_OARG_TYPE_LIST_OCOMMA+1, "oarg_type_list_ocomma", nkids, kids, NULL);
	}
;

/*
 * statement
 */
stmt:
	%empty
	{
		$$ = new_epsilon_tree(R_STMT, "stmt");
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
|	LRETURN oexpr_list
	{
		int nkids = 2;
		struct tree* t1 = new_leaf_node($1->category, "non_dcl_stmt", $1);
		struct tree** kids = create_tree_kids(nkids, t1, $2);
		$$ = new_tree_node(R_NON_DCL_STMT+3, "non_dcl_stmt", nkids, kids, NULL);
	}
;

stmt_list:
	stmt
	{
		$$ = $1;
	}
|	stmt_list ';' stmt
	{
		int nkids = 3;
		struct tree* t2 = new_leaf_node($2->category, "stmt_list", $2);
		struct tree** kids = create_tree_kids(nkids, $1, t2, $3);
		$$ = new_tree_node(R_STMT_LIST+1, "stmt_list", nkids, kids, NULL);
	}
;

new_name_list:
	new_name
	{
		$$ = $1;
	}
|	new_name_list ',' new_name
	{
		int nkids = 3;
		struct tree* t2 = new_leaf_node($2->category, "new_name_list", $2);
		struct tree** kids = create_tree_kids(nkids, $1, t2, $3);
		$$ = new_tree_node(R_NEW_NAME_LIST+1, "new_name_list", nkids, kids, NULL);
	}
	;

dcl_name_list:
	dcl_name
	{
		$$ = $1;
	}
|	dcl_name_list ',' dcl_name
	{
		int nkids = 3;
		struct tree* t2 = new_leaf_node($2->category, "dcl_name_list", $2);
		struct tree** kids = create_tree_kids(nkids, $1, t2, $3);
		$$ = new_tree_node(R_DCL_NAME_LIST+1, "dcl_name_list", nkids, kids, NULL);
	}
;

expr_list:
	expr
	{
		$$ = $1;
	}
|	expr_list ',' expr
	{
		int nkids = 3;
		struct tree* t2 = new_leaf_node($2->category, "expr_list", $2);
		struct tree** kids = create_tree_kids(nkids, $1, t2, $3);
		$$ = new_tree_node(R_EXPR_LIST+1, "expr_list", nkids, kids, NULL);
	}
;

expr_or_type_list:
	expr_or_type
	{
		$$ = $1;
	}
|	expr_or_type_list ',' expr_or_type
	{
		int nkids = 3;
		struct tree* t2 = new_leaf_node($2->category, "expr_or_type_list", $2);
		struct tree** kids = create_tree_kids(nkids, $1, t2, $3);
		$$ = new_tree_node(R_EXPR_OR_TYPE_LIST+1, "expr_or_type_list", nkids, kids, NULL);
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
		int nkids = 3;
		struct tree* t2 = new_leaf_node($2->category, "keyval_list", $2);
		struct tree** kids = create_tree_kids(nkids, $1, t2, $3);
		$$ = new_tree_node(R_KEYVAL_LIST+2, "keyval_list", nkids, kids, NULL);
	}
|	keyval_list ',' bare_complitexpr
	{
		int nkids = 3;
		struct tree* t2 = new_leaf_node($2->category, "keyval_list", $2);
		struct tree** kids = create_tree_kids(nkids, $1, t2, $3);
		$$ = new_tree_node(R_KEYVAL_LIST+3, "keyval_list", nkids, kids, NULL);
	}
;

 braced_keyval_list:
	%empty
	{
		$$ = new_epsilon_tree(R_BRACED_KEYVAL_LIST, "braced_keyval_list");
	}
	|	keyval_list ocomma
	{
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, $1, $2);
		$$ = new_tree_node(R_BRACED_KEYVAL_LIST+1, "braced_keyval_list", nkids, kids, NULL);
	}
;

/*
 * optional things
 */

osemi:
	%empty
	{
		$$ = new_epsilon_tree(R_OSEMI, "osemi");
	}
|	';'
	{
		int nkids = 1;
		struct tree* t1 = new_leaf_node($1->category, "osemi", $1);
		struct tree** kids = create_tree_kids(nkids, t1);
		$$ = new_tree_node(R_OSEMI+1, "osemi", nkids, kids, NULL);
	}
	;

ocomma:
	%empty
	{
		$$ = new_epsilon_tree(R_OCOMMA, "ocomma");
	}
|	','
	{
		int nkids = 1;
		struct tree* t1 = new_leaf_node($1->category, "ocomma", $1);
		struct tree** kids = create_tree_kids(nkids, t1);
		$$ = new_tree_node(R_OCOMMA+1, "ocomma", nkids, kids, NULL);
	}
	;

oexpr:
	%empty
	{
		$$ = new_epsilon_tree(R_OEXPR, "oexpr");
	}
|	expr
	{
		$$ = $1;
	}
	;

oexpr_list:
	%empty
	{
		$$ = new_epsilon_tree(R_OEXPR_LIST, "oexpr_list");
	}
|	expr_list
	{
		$$ = $1;
	}
;

osimple_stmt:
	%empty
	{
		$$ = new_epsilon_tree(R_OSIMPLE_STMT, "osimple_stmt");		
	}
|	simple_stmt
	{
		$$ = $1;
	}
;


oliteral:
	%empty
	{
		$$ = new_epsilon_tree(R_OLITERAL, "oliteral");		
	}	
|	LLITERAL
	{
		int nkids = 1;
		struct tree* t1 = new_leaf_node($1->category, "oliteral", $1);
		struct tree** kids = create_tree_kids(nkids, t1);
		$$ = new_tree_node(R_OLITERAL+1, "oliteral", nkids, kids, NULL);
	}
;

start_complit:
%empty
	{
		$$ = new_epsilon_tree(R_START_COMPLIT, "start_complit");		
	}	
;


keyval:
	expr ':' complitexpr
	{
		int nkids = 3;
		struct tree* t2 = new_leaf_node($2->category, "keyval", $2);
		struct tree** kids = create_tree_kids(nkids, $1, t2, $3);
		$$ = new_tree_node(R_KEYVAL, "keyval", nkids, kids, NULL);
	}
	;

bare_complitexpr:
	expr
	{
		$$ = $1;
	}
|	'{' start_complit braced_keyval_list '}'
	{
		int nkids = 4;
		struct tree* t1 = new_leaf_node($1->category, "bare_complitexpr", $1);
		struct tree* t4 = new_leaf_node($4->category, "bare_complitexpr", $4);
		struct tree** kids = create_tree_kids(nkids, t1, $2, $3, t4);
		$$ = new_tree_node(R_BARE_COMPLITEXPR+1, "bare_complitexpr", nkids, kids, NULL);
	}
;

complitexpr:
	expr
	{
		$$ = $1;
	}
|	'{' start_complit braced_keyval_list '}'
	{
		int nkids = 4;
		struct tree* t1 = new_leaf_node($1->category, "bare_complitexpr", $1);
		struct tree* t4 = new_leaf_node($4->category, "bare_complitexpr", $4);
		struct tree** kids = create_tree_kids(nkids, t1, $2, $3, t4);
		$$ = new_tree_node(R_COMPLITEXPR+1, "complitexpr", nkids, kids, NULL);
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
