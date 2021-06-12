#include "primitiveSymbol.h"

PrimitiveSymbol::PrimitiveSymbol(int value, bool isInitialized, bool isConst,
                                 DataType dataType)
    : value(value), isInitialized(isInitialized), isConst(isConst),
      dataType(dataType) {}

SymbolType PrimitiveSymbol::getType() { return PRIMITIVE; }

int PrimitiveSymbol::getValue() const { return value; }

bool PrimitiveSymbol::getIsConst() const { return isConst; }

bool PrimitiveSymbol::getIsInitialized() const { return isInitialized; }

DataType PrimitiveSymbol::getDataType() const { return dataType; }

void PrimitiveSymbol::setValue(int value) { this->value = value; }
