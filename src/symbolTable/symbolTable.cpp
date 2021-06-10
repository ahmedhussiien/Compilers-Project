#include <string>
#include <unordered_map>

#include "functionSymbol.h"
#include "primitiveSymbol.h"
#include "symbolTable.h"
#include "symbol.h"

#include "enums/dataType.h"

bool SymbolTable::isDeclared(string identifier)
{
    auto it = table.find(identifier);
    return it != table.end();
}

void SymbolTable::declareVariable(string identifier, DataType dataType,
                                  int value, bool isConst)
{
    if (isDeclared(identifier))
        yyerror("Variable already declared.");

    PrimitiveSymbol *symbol = new PrimitiveSymbol(value, isConst, dataType);

    table[identifier] = symbol;
}

void SymbolTable::declareFunction(string identifier, DataType returnType,
                                  FunctionParamsNode *params,
                                  Node *statements)
{
    if (isDeclared(identifier))
        yyerror("Function already declared.");

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
        return nullptr;

    return symbol;
}

FunctionSymbol *SymbolTable::getFunctionSymbol(string identifier) const
{
    auto it = table.find(identifier);
    if (it == table.end())
        return nullptr;

    FunctionSymbol *symbol = dynamic_cast<FunctionSymbol *>(it->second);

    if (!symbol)
        return nullptr;

    return symbol;
}

void SymbolTable::assignVariableValue(string identifier, DataType type,
                                      int value)
{
    auto it = table.find(identifier);
    if (it == table.end())
        yyerror("Undeclared variable."); // throw "Undeclared variable!";

    PrimitiveSymbol *symbol = dynamic_cast<PrimitiveSymbol *>(it->second);

    if (!symbol)
        yyerror("Cannot assign value to function."); // throw "Cannot assign value to function!";

    if (symbol->getIsConst())
        yyerror("Cannot reassign constant variable."); // throw "Cannot assign value to constant!";

    if (type != symbol->getDataType())
        yyerror("Type mismatch"); // throw "Type mismatch!";

    symbol->setValue(value);
}

int SymbolTable::getVariableValue(string identifier) const
{
    auto it = table.find(identifier);
    if (it == table.end())
        yyerror("Undeclared variable."); // throw "Undeclared variable!";

    PrimitiveSymbol *symbol = dynamic_cast<PrimitiveSymbol *>(it->second);

    if (!symbol)
        yyerror("Cannot cast function to primitive symbol."); // throw "Cannot cast function to primitive symbol!";

    return symbol->getValue();
}

DataType SymbolTable::getVariableType(string identifier) const
{
    auto it = table.find(identifier);
    if (it == table.end())
        yyerror("Undeclared variable.");

    PrimitiveSymbol *symbol = dynamic_cast<PrimitiveSymbol *>(it->second);

    if (!symbol)
        yyerror("Variable error.");

    return symbol->getDataType();
}