#include "identifierNode.h"

IdentifierNode::IdentifierNode(SymbolTable *symbolTable, char *name)
    : ExpressionNode(), symbolTable(symbolTable), name(name)
{
    // semanticCheck();
}

int IdentifierNode::execute()
{
    PrimitiveSymbol *symbol = symbolTable->getPrimitiveSymbol(name);

    if (!symbol)
    {
        yyerror("Referrencing undeclared variable '" + name + "'.");
        return 0;
    }

    if (!symbol->getIsInitialized())
    {
        yyerror("Variable '" + name + "' is used before initialization.");
        return 0;
    }

    return symbol->getValue();
}

DataType IdentifierNode::getType()
{
    return symbolTable->getVariableType(name);
}

void IdentifierNode::compile()
{
    PrimitiveSymbol *symbol = symbolTable->getPrimitiveSymbol(name);

    if (!symbol)
        yyerror("Referrencing undeclared variable '" + name + "'.");

    if (symbol && !symbol->getIsInitialized())
        yyerror("Variable '" + name + "' is used before initialization.");

    fprintf(yyout, "PUSH %s\n", name.c_str());
}

void IdentifierNode::semanticCheck()
{
    PrimitiveSymbol *symbol = symbolTable->getPrimitiveSymbol(name);

    if (!symbol)
    {
        yyerror("Referrencing undeclared variable'" + name + "'.");
        return;
    }

    if (!symbol->getIsInitialized())
    {
        yyerror("Variable '" + name + "' is used before initialization.");
        return;
    }
}