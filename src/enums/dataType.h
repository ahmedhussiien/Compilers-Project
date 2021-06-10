#ifndef __DATA_TYPE_H_
#define __DATA_TYPE_H_

enum DataType
{
    DTYPE_INT,
    DTYPE_FLOAT,
    DTYPE_BOOL,
    DTYPE_STRING,
    DTYPE_VOID
};

static const char *DataTypeStr[] = {"int", "flaot", "bool", "string", "void"};

#endif