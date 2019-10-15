typeptr check_types(int operand, typeptr x, typeptr y)
{
    switch (operand)
    {
    case FUNCALL:
    {
        if (x->basetype != FUNC)
            return type_error("function expected", x);
        if (y->basetype != TUPLE)
            return type_error("tuple expected", y);
        if (x->u.f.nparams != y->u.t.nelems)
            return type_error("wrong number of parameters", y);

        /*
       * for-loop, compare types of arguments
       */
        for (int i = 0; i < x->u.f.nparams; i++)
            if (check_types(PARAM, x->u.f.params[i], y->u.t.elems[i]) ==
                TYPE_ERROR)
                return TYPE_ERROR;
        /*
       * If the call is OK, our type is the function return type.
       */
        return x->u.f.returntype;
        break;
    }
    }
}
