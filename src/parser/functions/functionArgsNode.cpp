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

int FunctionArgsNode::getCount()
{
    return args.size();
}

void FunctionArgsNode::compile()
{
    for (ExpressionNode *arg : args)
    {
        arg->compile();
    }
}

FunctionArgsNode::~FunctionArgsNode()
{
}
