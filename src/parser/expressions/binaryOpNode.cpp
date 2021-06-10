
#include "binaryOpNode.h"

BinaryOpNode::BinaryOpNode(BinaryOperator op, ExpressionNode *n1, ExpressionNode *n2)
    : ExpressionNode(), op(op), n1(n1), n2(n2)
{
}

int BinaryOpNode::execute()
{
    switch (op)
    {
    case OP_PLUS:
        return n1->execute() + n2->execute();

    case OP_MINUS:
        return n1->execute() - n2->execute();

    case OP_MULTIPLY:
        return n1->execute() * n2->execute();

    case OP_DIVIDE:
        return n1->execute() / n2->execute();

    case OP_LESS_THAN:
        return n1->execute() < n2->execute();

    case OP_GREATER_THAN:
        return n1->execute() > n2->execute();

    case OP_LE:
        return n1->execute() <= n2->execute();

    case OP_GE:
        return n1->execute() >= n2->execute();

    case OP_NE:
        return n1->execute() != n2->execute();

    case OP_EQ:
        return n1->execute() == n2->execute();

    case OP_AND:
        return n1->execute() && n2->execute();

    case OP_OR:
        return n1->execute() || n2->execute();

    default:
        return 0;
    }
}

DataType BinaryOpNode::getType()
{
    return n1->getType();
}

BinaryOpNode::~BinaryOpNode()
{
    delete n1;
    delete n2;
}
