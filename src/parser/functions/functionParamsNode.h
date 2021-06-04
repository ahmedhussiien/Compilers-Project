#ifndef __FUNCTION_PARAMS_NODE_H_
#define __FUNCTION_PARAMS_NODE_H_

#include <vector>

#include "node.h"
#include "statements/declarationNode.h"

using std::vector;

class FunctionParamsNode : public Node
{
    vector<DeclarationNode *> params;

public:
    FunctionParamsNode();

    void addParam(DeclarationNode *param);
    const vector<DeclarationNode *> &getParams() const;

    virtual int execute();

    ~FunctionParamsNode();
};

#endif