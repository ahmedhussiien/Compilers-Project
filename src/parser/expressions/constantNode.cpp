
#include "constantNode.h"

ConstantNode::ConstantNode(int value) : ExpressionNode()
{
    this->value = new PrimitiveValue();
    this->value->type = DTYPE_INT;
    this->value->value.intValue = value;
}

ConstantNode::ConstantNode(bool value) : ExpressionNode()
{
    this->value = new PrimitiveValue();
    this->value->type = DTYPE_BOOL;
    this->value->value.boolValue = value;
}

ConstantNode::ConstantNode(float value) : ExpressionNode()
{
    this->value = new PrimitiveValue();
    this->value->type = DTYPE_FLOAT;
    this->value->value.floatValue = value;
}

ConstantNode::ConstantNode(char *value) : ExpressionNode()
{
    this->value = new PrimitiveValue();
    this->value->type = DTYPE_STRING;
    this->value->value.charPtr = value;
}

int ConstantNode::execute()
{
    return value->value.intValue;
}
