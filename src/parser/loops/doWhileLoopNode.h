#ifndef __DO_WHILE_LOOP_NODE_H_
#define __DO_WHILE_LOOP_NODE_H_

#include "node.h"
#include "expressionNode.h"

class DoWhileLoopNode : public Node
{
    ExpressionNode *conditionStatement;
    Node *executionStatement;

public:
    DoWhileLoopNode(ExpressionNode *conditionStatement,
                    Node *executionStatement);

    virtual int execute();
    virtual void compile();

    ~DoWhileLoopNode();
};

#endif
