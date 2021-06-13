#include "assignmentNode.h"

AssignmentNode::AssignmentNode(SymbolTable *symbolTable, char *name,
                               ExpressionNode *exprNode)

    : symbolTable(symbolTable), name(name), exprNode(exprNode)
{
    symbol = symbolTable->getPrimitiveSymbol(name);
    // semanticCheck();
}

int AssignmentNode::execute()
{
    symbolTable->assignVariableValue(name, exprNode->getType(), exprNode->execute());
    return 1;
}

DataType AssignmentNode::getType() { return exprNode->getType(); }

void AssignmentNode::compile()
{
    exprNode->compile();
    symbolTable->assignVariableValue(name, exprNode->getType());
    fprintf(yyout, "POP %s\n", name.c_str());
}

void AssignmentNode::semanticCheck()
{
    if (exprNode->getType() != symbol->getDataType())
        yyerror("Variable type mismatch.");
}

AssignmentNode::~AssignmentNode() { delete exprNode; }
