#include "functionParamsNode.h"

FunctionParamsNode::FunctionParamsNode() : Node()
{
}

void FunctionParamsNode::addParam(DeclarationNode *param)
{
    params.push_back(param);
}

const vector<DeclarationNode *> &FunctionParamsNode::getParams() const
{
    return params;
}

int FunctionParamsNode::execute()
{
    return 0;
}

void FunctionParamsNode::compile()
{
    for (DeclarationNode *param : params)
    {
        param->compileAsArg();
    }
}

FunctionParamsNode::~FunctionParamsNode()
{
    for (int i = 0; i < params.size(); i++)
        delete params[i];
}
