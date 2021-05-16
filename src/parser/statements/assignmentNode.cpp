#include "assignmentNode.h"

AssignmentNode::AssignmentNode(SymbolTable *symbolTable, char *name,
                               DataType type, ExpressionNode *exprNode)

    : Node(), symbolTable(symbolTable), name(name), type(type),
      exprNode(exprNode)
{
}

int AssignmentNode::execute()
{
    if (!exprNode)
        return -1;

    symbolTable->assignVariableValue(name, type, exprNode->execute());
    return 1;
}

AssignmentNode::~AssignmentNode()
{
    delete exprNode;
}
