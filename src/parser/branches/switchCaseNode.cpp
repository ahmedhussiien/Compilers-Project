#include "switchCaseNode.h"

SwitchCaseNode::SwitchCaseNode() {}

void SwitchCaseNode::addCaseStatement(CaseNode *caseNode)
{
    cases.push_back(caseNode);
}

void SwitchCaseNode::setExpression(ExpressionNode *expr)
{
    this->expr = expr;
}

int SwitchCaseNode::execute()
{
    if (!expr)
        return -1;

    int val = expr->execute();

    for (int i = 0; i < cases.size(); i++)
    {
        if (val == cases[i]->getExpressionNode()->execute())
            cases[i]->execute();
    }

    return 0;
}

void SwitchCaseNode::compile()
{
}

SwitchCaseNode::~SwitchCaseNode()
{
    delete expr;

    for (int i = 0; i < cases.size(); i++)
        delete cases[i];
}