#ifndef TYPE_H
#define TYPE_H

/* base types. In the real thing, there will be many more base types */
#define NULL_TYPE 1000000
#define UNKNOW_TYPE 1000001
#define INT_TYPE 1000002
#define FLOAT64_TYPE 1000003
#define STRING_TYPE 1000004
#define STRUCT_TYPE 1000005
#define ARRAY_TYPE 1000006
#define FUNC_TYPE 1000007
#define MAP_TYPE 1000008
#define CHAR_TYPE 1000009

typedef struct param
{
    char *name;
    struct typeinfo *type;
    struct param *next;
} * paramlist;

typedef struct typeinfo
{
    int basetype;
    union {
        struct mapinfo
        {
            struct typeinfo *indextype;
            struct typeinfo *elemtype;
        } m;
        struct arrayinfo
        {
            int size;
            struct typeinfo *elemtype;
        } a;
        struct structinfo
        {
            char *name;
            struct sym_table *st;
        } s;
        struct funcinfo
        {
            char *name; /* ? */
            struct sym_table *st;
            struct typeinfo *returntype;
            int nparams;
            struct param *parameters;
        } f;
    } u;
} * type_ptr;

extern struct typeinfo integer_type;
extern struct sym_table *foo;

char *typename(type_ptr t);

extern type_ptr integer_type_ptr;
extern type_ptr null_type_ptr;
extern type_ptr String_type_ptr;
extern char *typenames[];

// Convert int code to type
type_ptr alctype(int);

int get_basetype(char *s);

void delete_type(type_ptr t);

#endif
