#include "returnNode.h"

ReturnNode::ReturnNode(ExpressionNode *exprNode)
    : exprNode(exprNode) {}

int ReturnNode::execute()
{
    if (exprNode)
        return exprNode->execute();
    else
        return 0;
}

DataType ReturnNode::getReturnType()
{
    if (exprNode)
        return exprNode->getType();
    else
        return DTYPE_VOID;
}

ReturnNode::~ReturnNode()
{
    if (exprNode)
        delete exprNode;
}