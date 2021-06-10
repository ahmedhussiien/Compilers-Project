#include "assignmentNode.h"

AssignmentNode::AssignmentNode(SymbolTable *symbolTable, char *name,
                               DataType type, ExpressionNode *exprNode)

    : symbolTable(symbolTable), name(name), type(type),
      exprNode(exprNode)
{
    semanticCheck();
}

int AssignmentNode::execute()
{
    if (!exprNode)
        return -1;

    symbolTable->assignVariableValue(name, type, exprNode->execute());
    return 1;
}

DataType AssignmentNode::getType()
{
    return type;
}

void AssignmentNode::semanticCheck()
{
    if (exprNode->getType() != type)
        yyerror("Variable type mismatch.");
}

AssignmentNode::~AssignmentNode()
{
    delete exprNode;
}
