#ifndef __CASE_NODE_H_
#define __CASE_NODE_H_

#include "node.h"
#include "expressionNode.h"

class CaseNode : public Node
{
    ExpressionNode *expr;
    Node *statement;

public:
    CaseNode(ExpressionNode *expr, Node *statement);

    virtual int execute();
    ExpressionNode *getExpressionNode() const;
    void compile();

    ~CaseNode();
};

#endif
