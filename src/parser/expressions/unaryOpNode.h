#ifndef __UNARY_OP_NODE_H_
#define __UNARY_OP_NODE_H_

#include "expressionNode.h"
#include "enums/unaryOperator.h"

class UnaryOpNode : public ExpressionNode
{
    ExpressionNode *n;
    UnaryOperator op;

public:
    UnaryOpNode(UnaryOperator op, ExpressionNode *n);

    virtual int execute();
    virtual void compile();

    virtual DataType getType();
    ~UnaryOpNode();
};

#endif