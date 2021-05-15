#ifndef __BINARY_OP_NODE_H_
#define __BINARY_OP_NODE_H_

#include "expressionNode.h"
#include "enums/binaryOperator.h"

class BinaryOpNode : public ExpressionNode
{
    ExpressionNode *n1, *n2;
    BinaryOperator op;

public:
    BinaryOpNode(BinaryOperator op, ExpressionNode *n1, ExpressionNode *n2);
    virtual int execute();

    ~BinaryOpNode();
};

#endif
