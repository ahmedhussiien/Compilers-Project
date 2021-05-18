#ifndef __CONSTANT_NODE_H_
#define __CONSTANT_NODE_H_

#include "expressionNode.h"
#include "enums/dataType.h"
#include "symbolTable/primitiveValue.h"

class ConstantNode : public ExpressionNode
{
    PrimitiveValue *value;

public:
    ConstantNode(int value);
    ConstantNode(char *value);
    ConstantNode(float value);
    ConstantNode(bool value);

    virtual int execute();
};

#endif