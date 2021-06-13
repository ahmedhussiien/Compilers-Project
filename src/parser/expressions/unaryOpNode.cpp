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

void UnaryOpNode::compile()
{
    n->compile();

    switch (op)
    {
    case OP_NOT:
        fprintf(yyout, "NOT\n");
        break;

    case OP_UMINUS:
        fprintf(yyout, "NEG\n");
        break;

    default:
        return;
    }
}

DataType UnaryOpNode::getType()
{
    return n->getType();
}

UnaryOpNode::~UnaryOpNode()
{
    delete n;
}