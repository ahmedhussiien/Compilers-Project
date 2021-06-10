
#include "binaryOpNode.h"

BinaryOpNode::BinaryOpNode(BinaryOperator op, ExpressionNode *n1, ExpressionNode *n2)
    : ExpressionNode(), op(op), n1(n1), n2(n2)
{
    semanticCheck();
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
    if (op == OP_PLUS || op == OP_MINUS || op == OP_MULTIPLY || op == OP_DIVIDE)
    {
        return n1->getType();
    }
    else
        return DTYPE_BOOL;
}

void BinaryOpNode::semanticCheck()
{
    if (op == OP_PLUS || op == OP_MINUS || op == OP_MULTIPLY || op == OP_DIVIDE)
    {
        if (!isNumericOperands())
            yyerror("Operands type mismatch.");
    }
    else
    {
        if (n1->getType() != n2->getType())
            yyerror("Operands type mismatch.");
    }
}

bool BinaryOpNode::isNumericOperands()
{
    DataType n1type = n1->getType();
    DataType n2type = n2->getType();
    return (n1type < 3) && (n2type < 3);
}

BinaryOpNode::~BinaryOpNode()
{
    delete n1;
    delete n2;
}
