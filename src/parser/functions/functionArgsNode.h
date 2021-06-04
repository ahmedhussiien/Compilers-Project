#ifndef __FUNCTION_ARGS_NODE_H_
#define __FUNCTION_ARGS_NODE_H_

#include <vector>

#include "node.h"
#include "expressionNode.h"

using std::vector;

class FunctionArgsNode : public Node
{
    vector<ExpressionNode *> args;

public:
    FunctionArgsNode();

    void addArg(ExpressionNode *arg);
    ExpressionNode *getArg(int index) const;

    virtual int execute();

    ~FunctionArgsNode();
};

#endif