#include "functionSymbol.h"

FunctionSymbol::FunctionSymbol(DataType returnType, FunctionParamsNode *params,
                               Node *statements)
    : returnType(returnType), params(params), statements(statements) {}

FunctionParamsNode *FunctionSymbol::getParamsNode() const
{
    return params;
}

Node *FunctionSymbol::getStatementsListNode() const
{
    return statements;
}

SymbolType FunctionSymbol::getType() { return FUNCTION; };
