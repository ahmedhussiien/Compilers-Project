#include "returnNode.h"

ReturnNode::ReturnNode(ExpressionNode *exprNode)
    : exprNode(exprNode) {}

int ReturnNode::execute()
{
    return exprNode->execute();
}

ReturnNode::~ReturnNode()
{
    delete exprNode;
}