#ifndef __IF_NODE_H_
#define __IF_NODE_H_

#include "node.h"
#include "expressionNode.h"

class IfNode : public Node
{
    ExpressionNode *conditionStatement;
    Node *thenStatement, *elseStatement;

public:
    IfNode(ExpressionNode *conditionStatement,
           Node *thenStatement,
           Node *elseStatement);

    virtual int execute();

    virtual ~IfNode();
};

#endif
