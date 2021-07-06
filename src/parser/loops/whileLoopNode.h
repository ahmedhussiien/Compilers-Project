#ifndef __WHILE_LOOP_NODE_H_
#define __WHILE_LOOP_NODE_H_

#include "node.h"
#include "expressionNode.h"

class WhileLoopNode : public Node
{
    ExpressionNode *conditionStatement;
    Node *executionStatement;

public:
    WhileLoopNode(ExpressionNode *conditionStatement,
                  Node *executionStatement);

    virtual int execute();
    virtual void compile();

    ~WhileLoopNode();
};

#endif
