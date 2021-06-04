#ifndef __PRIMITIVE_SYMBOL_H_
#define __PRIMITIVE_SYMBOL_H_

#include "enums/dataType.h"
#include "symbol.h"

class PrimitiveSymbol : public Symbol
{
    int value;
    bool isConst;
    DataType dataType;

public:
    PrimitiveSymbol(int value, bool isConst, DataType dataType);

    int getValue() const;
    bool getIsConst() const;
    DataType getDataType() const;

    void setValue(int value);

    virtual SymbolType getType();
};

#endif