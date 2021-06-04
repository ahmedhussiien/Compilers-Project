#include "primitiveSymbol.h"

PrimitiveSymbol::PrimitiveSymbol(int value, bool isConst, DataType dataType)
    : value(value), isConst(isConst), dataType(dataType) {}

SymbolType PrimitiveSymbol::getType() { return PRIMITIVE; }

int PrimitiveSymbol::getValue() const
{
    return value;
}

bool PrimitiveSymbol::getIsConst() const
{
    return isConst;
}

DataType PrimitiveSymbol::getDataType() const
{
    return dataType;
}

void PrimitiveSymbol::setValue(int value)
{
    this->value = value;
}
