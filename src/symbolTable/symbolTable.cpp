#include <string>
#include <unordered_map>

#include "functionSymbol.h"
#include "primitiveSymbol.h"
#include "symbol.h"
#include "symbolTable.h"

#include "enums/dataType.h"

bool SymbolTable::isDeclared(string identifier)
{
    auto it = table.find(identifier);
    return it != table.end();
}

void SymbolTable::declareVariable(string identifier, DataType dataType,
                                  int value, bool isInitialized, bool isConst)
{
    if (isDeclared(identifier))
        return yyerror("Variable already declared.");

    PrimitiveSymbol *symbol = new PrimitiveSymbol(value, isInitialized, isConst, dataType);

    table[identifier] = symbol;
}

void SymbolTable::declareFunction(string identifier, DataType returnType,
                                  FunctionParamsNode *params,
                                  Node *statements)
{
    if (isDeclared(identifier))
        return yyerror("Function already declared.");

    FunctionSymbol *symbol = new FunctionSymbol(returnType, params, statements);
    table[identifier] = symbol;
}

PrimitiveSymbol *SymbolTable::getPrimitiveSymbol(string identifier) const
{
    auto it = table.find(identifier);
    if (it == table.end())
        return nullptr;

    PrimitiveSymbol *symbol = dynamic_cast<PrimitiveSymbol *>(it->second);

    if (!symbol)
    {
        yyerror("Cannot cast function to primitive symbol.");
        return nullptr;
    }

    return symbol;
}

FunctionSymbol *SymbolTable::getFunctionSymbol(string identifier) const
{
    auto it = table.find(identifier);
    if (it == table.end())
        return nullptr;

    FunctionSymbol *symbol = dynamic_cast<FunctionSymbol *>(it->second);

    if (!symbol)
    {
        yyerror("Cannot cast a primitive to function symbol.");
        return nullptr;
    }

    return symbol;
}

void SymbolTable::assignVariableValue(string identifier, DataType type,
                                      int value)
{
    auto it = table.find(identifier);
    if (it == table.end())
        return yyerror("Undeclared variable '" + identifier + "' .");

    PrimitiveSymbol *symbol = dynamic_cast<PrimitiveSymbol *>(it->second);

    if (!symbol)
        return yyerror("Cannot assign value to function.");

    if (symbol->getIsConst())
        return yyerror("Cannot reassign constant variable.");

    if (type != symbol->getDataType())
        return yyerror("Type mismatch");

    symbol->setIsInitialized(true);
    symbol->setValue(value);
}

int SymbolTable::getVariableValue(string identifier) const
{
    auto it = table.find(identifier);
    if (it == table.end())
    {
        yyerror("Undeclared variable '" + identifier + "' .");
        return -1;
    }

    PrimitiveSymbol *symbol = dynamic_cast<PrimitiveSymbol *>(it->second);

    if (!symbol)
    {
        yyerror("Cannot cast function to primitive symbol.");
        return -1;
    }

    return symbol->getValue();
}

DataType SymbolTable::getVariableType(string identifier) const
{
    auto it = table.find(identifier);
    if (it == table.end())
    {
        yyerror("Undeclared variable '" + identifier + "' .");
        return DTYPE_VOID;
    }

    PrimitiveSymbol *symbol = dynamic_cast<PrimitiveSymbol *>(it->second);

    if (!symbol)
    {
        yyerror("Variable error.");
        return DTYPE_VOID;
    }

    return symbol->getDataType();
}