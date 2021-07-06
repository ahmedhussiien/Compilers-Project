#ifndef __SYMBOL_TABLE_H_
#define __SYMBOL_TABLE_H_

#include <string>
#include <unordered_map>

using std::string;
using std::unordered_map;

#include "functionSymbol.h"
#include "primitiveSymbol.h"
#include "symbol.h"

#include "enums/dataType.h"

class SymbolTable
{
    unordered_map<string, Symbol *> table;

public:
    SymbolTable() {}

    bool isDeclared(string identifier);

    void declareVariable(string identifier, DataType dataType, int value,
                         bool isInitialized, bool isConst = false);

    void declareFunction(string identifier, DataType returnType,
                         FunctionParamsNode *params, Node *statements);

    PrimitiveSymbol *getPrimitiveSymbol(string identifier) const;
    FunctionSymbol *getFunctionSymbol(string identifier) const;
    int getVariableValue(string identifier) const;
    DataType getVariableType(string identifier) const;

    void printSymbols() const;
    void assignVariableValue(string identifier, DataType type, int value = 0);
};

#endif