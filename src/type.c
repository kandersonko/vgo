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

struct typeinfo integer_type = {INT_TYPE, 4};
struct typeinfo bool_type = {BOOL_TYPE, 1};
struct typeinfo float64_type = {FLOAT64_TYPE, 8};
struct typeinfo String_type = {STRING_TYPE, 8};
struct typeinfo null_type = {NULL_TYPE, 0};
struct typeinfo import_type = {IMPORT_TYPE, 1};
// struct typeinfo package_type = {PACKAGE_TYPE};
type_ptr null_type_ptr = &null_type;
type_ptr integer_type_ptr = &integer_type;
type_ptr bool_type_ptr = &bool_type;
type_ptr float64_type_ptr = &float64_type;
type_ptr String_type_ptr = &String_type;
type_ptr import_type_ptr = &import_type;
// type_ptr package_type_ptr = &package_type;

char *typenames[] = {"null", "unknown", "import", "package", "int", "bool", "float64", "string", "struct", "array", "function", "map", "char"};

type_ptr alcfunctype(tree_ptr return_type, tree_ptr param_type, sym_table_ptr st);

type_ptr alcstructtype(char *name, sym_table_ptr st);

type_ptr alctype(int basetype)
{
    type_ptr t;
    switch (basetype)
    {
    case INT_TYPE:
        t = integer_type_ptr;
        break;
    case BOOL_TYPE:
        t = bool_type_ptr;
        break;
    case FLOAT64_TYPE:
        t = float64_type_ptr;
        break;
    case STRING_TYPE:
        t = String_type_ptr;
        break;
    case IMPORT_TYPE:
        t = import_type_ptr;
        break;
    // case PACKAGE_TYPE:
    //     t = package_type_ptr;
    //     break;
    default:
        t = (type_ptr)alloc(1, sizeof(struct typeinfo));
        t->basetype = basetype;
        break;
    }
    return t;
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
    else if (t->basetype == 0)
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

int is_basic_type(int basetype)
{
    switch (basetype)
    {
    case INT_TYPE:
    case STRING_TYPE:
    case FLOAT64_TYPE:
        return 1;
    default:
        return 0;
    }
}

int get_basetype_width(int basetype)
{
    int width = 0;
    switch (basetype)
    {
    case INT_TYPE:
    case STRING_TYPE:
        width = 4;
        break;
    case FLOAT64_TYPE:
        width = 8;
        break;
    default:

        break;
    }
    return width;
}

int get_func_width(type_ptr t, paramlist params)
{
    int size = 0;
    paramlist temp = params;
    while (temp != NULL)
    {
        if (params->type->basetype == FUNC_TYPE)
        {
            size += get_func_width(params->type, params->type->u.f.parameters);
        }
        else
        {
            size += params->type->width;
        }
        temp = temp->next;
    }
    return size;
}
