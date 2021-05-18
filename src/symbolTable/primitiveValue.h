#ifndef __PRIMITIVE_VALUE_H_
#define __PRIMITIVE_VALUE_H_

#include "enums/dataType.h"

struct PrimitiveValue
{
    DataType type;

    union
    {
        int intValue;
        float floatValue;
        bool boolValue;
        const char *charPtr;
    } value;

    ~PrimitiveValue()
    {
        if (type == DTYPE_STRING && value.charPtr)
            delete value.charPtr;
    }
};

#endif