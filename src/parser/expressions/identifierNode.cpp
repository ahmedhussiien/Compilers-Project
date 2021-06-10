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
    if (!symbolTable->isDeclared(name))
        yyerror("Referrencing undeclared variable.");
}