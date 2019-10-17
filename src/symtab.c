/*
 * Code adapted from lecture notes
 * by Dr. J
 * http://www2.cs.uidaho.edu/~jeffery/courses/445/lecture.html
 */
/*
 * symtab.c
 */

/*
 * The functions in this file maintain a hash table of strings
 *   and manage string buffers.  String buffers are large
 *   contiguous blocks of memory used to store many strings,
 *   to avoid the overhead cost associated with using malloc(3)
 *   for thousands of tiny allocations.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symtab.h"
#include "token.h"
#include "rules.h"
#include "utils.h"
#include "go.tab.h"

#define S_BUF_SIZE 1024 /* initial size of the string buffer */

sym_table_ptr global_table;

/*
 * str_buf references a string buffer. Strings are built a
 *  character at a time. When a buffer "fragment" is filled,
 *  another is allocated and the the current string copied to it.
 */
struct str_buf_frag
{
    struct str_buf_frag *next; /* next buffer fragment */
    char s[1];                 /* variable size buffer */
};

struct str_buf
{
    unsigned int size;             /* total size of current buffer */
    char *p;                       /* next free character in buffer */
    char *end;                     /* end of current buffer */
    struct str_buf_frag *frag_lst; /* list of buffer fragments */
};

static struct str_buf buf;
sym_table_ptr stringpool;
sym_table_ptr globals;
sym_table_ptr current;

void init_sbuf(struct str_buf *);  /* initialize an sbuf struct */
void clear_sbuf(struct str_buf *); /* free struct buffer storage */
void new_sbuf(struct str_buf *);   /* allocate add'l buffer */

/*
 * new_st - construct symbol (hash) table.
 *  Allocate space first for the structure, then
 *  for the array of buckets.
 */
sym_table_ptr new_st(int nbuckets)
{
    sym_table_ptr st;
    st = (sym_table_ptr)safe_malloc(sizeof(struct sym_table));
    struct sym_entry **buckets = alloc(nbuckets, sizeof(*buckets));
    st->buckets = buckets;
    st->nbuckets = nbuckets;
    st->entries = 0;
    if (buf.frag_lst == NULL)
    {
        init_sbuf(&buf);
        stringpool = new_st(149);
    }
    return st;
}

/*
 * delete_st - destruct symbol table.
 */
void delete_st(sym_table_ptr st)
{
    if (!st)
        return;
    sym_entry_ptr se, se1;
    int h;

    for (h = 0; h < st->nbuckets; ++h)
        for (se = st->buckets[h]; se != NULL; se = se1)
        {
            se1 = se->next;
            free(se->text);
            free((char *)se);
        }
    free((char *)st);
}

/*
 * init_sbuf - initialize a new sbuf struct, allocating an initial buffer.
 */
void init_sbuf(struct str_buf *sbuf)
{
    sbuf->size = S_BUF_SIZE;
    sbuf->frag_lst = (struct str_buf_frag *)safe_malloc((unsigned int)(sizeof(struct str_buf_frag) + (S_BUF_SIZE - 1)));
    sbuf->frag_lst->next = NULL;
    sbuf->p = sbuf->frag_lst->s;
    sbuf->end = sbuf->p + S_BUF_SIZE;
}

/*
 * clear_sbuf - free string buffer storage.
 */
void clear_sbuf(struct str_buf *sbuf)
{
    struct str_buf_frag *sbf, *sbf1;

    for (sbf = sbuf->frag_lst; sbf != NULL; sbf = sbf1)
    {
        sbf1 = sbf->next;
        free((char *)sbf);
    }
    sbuf->frag_lst = NULL;
    sbuf->p = NULL;
    sbuf->end = NULL;
}

/*
 * new_sbuf - allocate a new buffer for a sbuf struct, copying the
 *   partially created string from the end of full buffer to the new one.
 */
void new_sbuf(struct str_buf *sbuf)
{
    struct str_buf_frag *sbf;

    /*
    * The new buffer is larger than the old one to insure that any
    *  size string can be buffered.
    */
    sbuf->size *= 2;
    sbf = (struct str_buf_frag *)safe_malloc((unsigned int)(sizeof(struct str_buf_frag) + (sbuf->size - 1)));
    sbf->next = sbuf->frag_lst;
    sbuf->frag_lst = sbf;
    sbuf->p = sbf->s;
    sbuf->end = sbuf->p + sbuf->size;
}

static char *insert_sbuf(struct str_buf *sb, char *s)
{
    char *rv;
    int l = strlen(s);
    if (sb->p + l + 1 >= sb->end)
        new_sbuf(sb);
    strcpy(sb->p, s);
    rv = sb->p;
    sb->p += l + 1;
    return rv;
}

/*
 * Compute hash value.
 */
int hash(sym_table_ptr st, char *s)
{
    register int h = 0;
    register char c;
    while ((c = *s++))
    {
        h += c & 0377;
        h *= 37;
    }
    if (h < 0)
        h = -h;
    return h % st->nbuckets;
}

/*
 * install_sym - install a symbol.
 *  - this is for entering strings in the string pool
 *  - find out if the string at the end of the buffer is in
 *   the string table. If not, put it there. Return a pointer
 *   to the string in the table.
 */
char *install_sym(sym_table_ptr st, char *text, type_ptr type)
{
    int h;
    struct sym_entry *entry;

    h = hash(st, text);
    for (entry = st->buckets[h]; entry != NULL; entry = entry->next)
        if (!strcmp(text, entry->text))
        {
            /*
          * A copy of the string is already in the table.
          */
            return entry->text;
        }

    /*
    * The string is not in the table. Add the copy from the
    *  buffer to the table.
    */
    entry = (sym_entry_ptr)safe_malloc((unsigned int)sizeof(struct sym_entry));
    entry->next = st->buckets[h];
    st->buckets[h] = entry;
    if (st == stringpool)
        entry->text = insert_sbuf(&buf, text);
    else
        entry->text = text;
    entry->type = type;
    st->entries++;
    return entry->text;
}

/*
 * insert_stringpool - install a symbol in the global table.
 *  - find out if the string at the end of the buffer is in
 *   the string table. If not, put it there. Return a pointer
 *   to the string in the table.
 */
char *insert_stringpool(char *s)
{
    return install_sym(stringpool, s, NULL);
}

int insert_sym(sym_table_ptr st, char *s, type_ptr t)
{
    int h;
    struct sym_entry *entry;

    h = hash(st, s);
    for (entry = st->buckets[h]; entry != NULL; entry = entry->next)
        if (!strcmp(s, entry->text))
        {
            /*
          * A copy of the string is already in the table.
          */
            return 0;
        }

    /*
    * The string is not in the table. Add the copy from the
    *  buffer to the table.
    */
    entry = (sym_entry_ptr)safe_malloc((unsigned int)sizeof(struct sym_entry));
    entry->next = st->buckets[h];
    // entry->table = st;
    st->buckets[h] = entry;
    if (st == stringpool)
        entry->text = insert_sbuf(&buf, s);
    else
        entry->text = strdup(s);
    entry->type = t;
    st->entries++;
    return 1;
}

/*
 * lookup_st - search the symbol table for a given symbol, return its entry.
 */
sym_entry_ptr lookup_st(sym_table_ptr st, char *s)
{
    int h;
    sym_entry_ptr entry;

    h = hash(st, s);
    for (entry = st->buckets[h]; entry != NULL; entry = entry->next)
        if (strcmp(s, entry->text) == 0)
        {
            /*
          *  Return a pointer to the symbol table entry.
          */
            return entry;
        }
    return NULL;
}
