/*
 * Code adapted from lecture notes
 * by Dr. J
 * http://www2.cs.uidaho.edu/~jeffery/courses/445/lecture.html
 */
#include <stdio.h>
#include <string.h>
#include "type.h"
#include "symtab.h"
#include "tree.h"
#include "utils.h"

struct typeinfo integer_type = {INT_TYPE};
struct typeinfo bool_type = {BOOL_TYPE};
struct typeinfo float64_type = {FLOAT64_TYPE};
struct typeinfo String_type = {STRING_TYPE};
struct typeinfo null_type = {NULL_TYPE};
struct typeinfo import_type = {IMPORT_TYPE};
struct typeinfo package_type = {PACKAGE_TYPE};
type_ptr null_type_ptr = &null_type;
type_ptr integer_type_ptr = &integer_type;
type_ptr bool_type_ptr = &bool_type;
type_ptr float64_type_ptr = &float64_type;
type_ptr String_type_ptr = &String_type;
type_ptr import_type_ptr = &import_type;
type_ptr package_type_ptr = &package_type;
char *typenames[] = {"null", "unknown", "import", "package", "int", "bool", "float64", "string", "struct", "function"};

type_ptr alcfunctype(tree_ptr return_type, tree_ptr param_type, sym_table_ptr st);

type_ptr alcstructtype(char *name, sym_table_ptr st);

type_ptr alctype(int basetype)
{
    type_ptr t;
    switch (basetype)
    {
    case INT_TYPE:
        return integer_type_ptr;
        break;
    case BOOL_TYPE:
        return bool_type_ptr;
        break;
    case FLOAT64_TYPE:
        return float64_type_ptr;
        break;
    case STRING_TYPE:
        return String_type_ptr;
        break;
    case IMPORT_TYPE:
        return import_type_ptr;
        break;
    case PACKAGE_TYPE:
        return package_type_ptr;
        break;
    default:
        t = (type_ptr)alloc(1, sizeof(struct typeinfo));
        if (t == NULL)
            return t;
        t->basetype = basetype;
        return t;
        break;
    }
}

type_ptr alcstructtype(char *name, sym_table_ptr st)
{
    type_ptr t = alctype(STRUCT_TYPE);
    if (t == NULL)
        return NULL;
    t->u.s.name = strdup(name);
    t->u.s.st = st;
    return t;
}

type_ptr alcfunctype(tree_ptr return_type, tree_ptr param_type, sym_table_ptr st)
{
    type_ptr t = alctype(FUNC_TYPE);
    if (t == NULL)
        return NULL;
    // rv.u.m.st = st;
    return t;
}

char *typename(type_ptr t)
{
    if (t == NULL)
        return "(NULL)";
    else if (t->basetype == STRUCT_TYPE)
    {
        return t->u.s.name;
    }
    else if (t->basetype == FUNC_TYPE)
    {
        return t->u.f.name;
    }
    return typenames[t->basetype - 1000000];
}

int get_basetype(char *s)
{
    if (strcmp(s, "int") == 0)
        return INT_TYPE;
    else if (strcmp(s, "bool") == 0)
        return BOOL_TYPE;
    else if (strcmp(s, "float64") == 0)
        return FLOAT64_TYPE;
    else if (strcmp(s, "string") == 0)
        return STRING_TYPE;

    return UNKNOW_TYPE;
}