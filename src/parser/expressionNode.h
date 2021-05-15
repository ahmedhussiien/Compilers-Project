#ifndef __EXPRESSION_NODE_H_
#define __EXPRESSION_NODE_H_

#include "node.h"

class ExpressionNode : public Node
{

public:
    virtual int execute() = 0;
    virtual ~ExpressionNode(){};
};

#endif