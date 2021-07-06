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
    int labels[cases.size()];
    for (int i = 0; i < cases.size(); i++)
    {
        labels[i] = labelCounter++;               // get label for current case
        cases[i]->getExpressionNode()->compile(); // push expression of case to stack
        expr->compile();                          // push switch expression to stack
        fprintf(yyout, "COMP_EQ\n");              // compare between values in stack
        fprintf(yyout, "JZ L%03d\n", labels[i]);  // if equal jump to appropriate label
    }

    int LastLabel = labelCounter++;
    fprintf(yyout, "JZ L%03d\n", LastLabel); // if didn't jump on all cases jump to after switch case

    for (int i = 0; i < cases.size(); i++)
    {
        fprintf(yyout, "L%03d:\n", labels[i]); // label of each case followed by the case itself
        cases[i]->compile();
    }

    fprintf(yyout, "L%03d:\n", LastLabel);
}

SwitchCaseNode::~SwitchCaseNode()
{
    delete expr;

    for (int i = 0; i < cases.size(); i++)
        delete cases[i];
}