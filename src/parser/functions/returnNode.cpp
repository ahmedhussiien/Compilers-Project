#include "returnNode.h"

ReturnNode::ReturnNode(ExpressionNode *exprNode)
    : exprNode(exprNode) {}

int ReturnNode::execute()
{
    return exprNode->execute();
}

DataType ReturnNode::getReturnType()
{
    return exprNode->getType();
}

ReturnNode::~ReturnNode()
{
    delete exprNode;
}