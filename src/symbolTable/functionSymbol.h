#ifndef __FUNCTION_SYMBOL_H_
#define __FUNCTION_SYMBOL_H_

#include "enums/dataType.h"
#include "parser/functions/functionParamsNode.h"

#include "symbol.h"

class FunctionSymbol : public Symbol
{
    DataType returnType;
    FunctionParamsNode *params;
    Node *statements;

public:
    FunctionSymbol(DataType returnType, FunctionParamsNode *params = nullptr,
                   Node *statements = nullptr);

    FunctionParamsNode *getParamsNode() const;
    Node *getStatementsListNode() const;

    virtual SymbolType getType();
};

#endif