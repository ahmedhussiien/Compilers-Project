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
        char charValue;
    } value;

    int getIntValue()
    {
        if (type == DTYPE_FLOAT)
            return value.floatValue;

        return value.intValue;
    }
};

#endif