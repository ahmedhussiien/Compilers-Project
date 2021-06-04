#ifndef __SWITCH_CASE_NODE_H_
#define __SWITCH_CASE_NODE_H_

#include <vector>

#include "node.h"
#include "caseNode.h"
#include "expressionNode.h"

using std::vector;

class SwitchCaseNode : public Node
{
    ExpressionNode *expr;
    vector<CaseNode *> cases;

public:
    SwitchCaseNode();

    void addCaseStatement(CaseNode *caseNode);
    void setExpression(ExpressionNode *expr);
    virtual int execute();

    ~SwitchCaseNode();
};

#endif
