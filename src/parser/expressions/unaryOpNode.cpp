#include "unaryOpNode.h"

UnaryOpNode::UnaryOpNode(UnaryOperator op, ExpressionNode *n) : ExpressionNode(), op(op), n(n)
{
    semanticCheck();
}

int UnaryOpNode::execute()
{
    switch (op)
    {
    case OP_NOT:
        return !n->execute();

    case OP_UMINUS:
        return -n->execute();

    default:
        return 0;
    }
}

DataType UnaryOpNode::getType()
{
    return n->getType();
}

void UnaryOpNode::semanticCheck()
{
    // there isn't really an implementation for this
}

UnaryOpNode::~UnaryOpNode()
{
    delete n;
}