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

void ReturnNode::compile()
{
    if (exprNode)
        exprNode->compile();
    fprintf(yyout, "RET\n");
}
ReturnNode::~ReturnNode()
{
    if (exprNode)
        delete exprNode;
}