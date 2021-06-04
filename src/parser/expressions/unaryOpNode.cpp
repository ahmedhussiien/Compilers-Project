#include "unaryOpNode.h"

UnaryOpNode::UnaryOpNode(UnaryOperator op, ExpressionNode *n) : ExpressionNode(), op(op), n(n)
{
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

UnaryOpNode::~UnaryOpNode()
{
    delete n;
}