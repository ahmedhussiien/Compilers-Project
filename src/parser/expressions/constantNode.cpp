
#include "constantNode.h"

ConstantNode::ConstantNode(int value) : ExpressionNode()
{
    this->value = value;
}

ConstantNode::ConstantNode(bool value) : ExpressionNode()
{
    this->value = value;
}

ConstantNode::ConstantNode(float value) : ExpressionNode()
{
    this->value = value;
}

ConstantNode::ConstantNode(char *value) : ExpressionNode()
{
    this->value = *value;
}

int ConstantNode::execute()
{
    return value;
}
