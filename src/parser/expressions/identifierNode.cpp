#include "identifierNode.h"

IdentifierNode::IdentifierNode(SymbolTable *symbolTable, char *name)
    : ExpressionNode(), symbolTable(symbolTable), name(name) {}

int IdentifierNode::execute() { return symbolTable->getVariableValue(name); }
