#include "identifierNode.h"

IdentifierNode::IdentifierNode(SymbolTable *symbolTable, char *name)
    : ExpressionNode(), symbolTable(symbolTable), name(name)
{
    semanticCheck();
}

int IdentifierNode::execute() { return symbolTable->getVariableValue(name); }

DataType IdentifierNode::getType()
{
    return symbolTable->getVariableType(name);
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