#ifndef __RETURN_NODE_H_
#define __RETURN_NODE_H_

#include "node.h"
#include "expressionNode.h"

class ReturnNode : public Node
{
    ExpressionNode *exprNode;

public:
    ReturnNode(ExpressionNode *exprNode);
    virtual int execute();
    ~ReturnNode();
};

#endif
