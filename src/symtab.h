/*
 * Code adapted from lecture notes
 * by Dr. J
 * http://www2.cs.uidaho.edu/~jeffery/courses/445/lecture.html
 */
/*
 * Warning: this code may be incomplete or fragmentary!
 */

#ifndef SYMTAB_H
#define SYMTAB_H

#include "type.h"

typedef struct sym_table
{
    int nbuckets;               /* # of buckets */
    int entries;                /* # of symbols in the table */
    struct sym_table *parent;   /* enclosing scope, superclass etc. */
    struct typeinfo *scope;     /* what type do we belong to? */
    struct sym_entry **buckets; /* array of buckets */
    /*
    * more per-scope/per-symbol-table attributes go here
    */
} * sym_table_ptr;

/*
 * Entry in symbol table.
 */
typedef struct sym_entry
{
    // sym_table_ptr table;   /* what symbol table do we belong to*/
    char *text;            /* string */
    struct typeinfo *type; /* a.k.a. type_ptr, struct c_type *... */
    /* more symbol attributes go here for code generation */
    struct sym_entry *next;
} * sym_entry_ptr;

// symbol tables

/*
 * Prototypes
 */
sym_table_ptr new_st(int size);                     /* create symbol table */
void delete_st(sym_table_ptr st);                   /* destroy symbol table */
char *insert_stringpool(char *);                    /* enter string into pool */
char *install_sym(sym_table_ptr, char *, type_ptr); /* enter string into table */
int insert_sym(sym_table_ptr, char *, type_ptr);    /* enter symbol into table */
sym_entry_ptr lookup_st(sym_table_ptr st, char *s); /* lookup symbol */

extern sym_table_ptr stringpool; /* all idents seen in entire program */
extern sym_table_ptr globals;    /* global symbols */
extern sym_table_ptr current;    /* current */

#endif /* SYMTAB_H */
