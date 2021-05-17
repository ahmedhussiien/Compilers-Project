#include "functionArgsNode.h"

FunctionArgsNode::FunctionArgsNode() : Node()
{
}

void FunctionArgsNode::addArg(ExpressionNode *arg)
{
    args.push_back(arg);
}

ExpressionNode *FunctionArgsNode::getArg(int index) const
{
    if (index < 0 || index >= args.size())
        return nullptr;

    return args[index];
}

int FunctionArgsNode::execute()
{
    return 0;
}

FunctionArgsNode::~FunctionArgsNode()
{
}
