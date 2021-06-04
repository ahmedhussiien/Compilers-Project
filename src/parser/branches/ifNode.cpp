#include "ifNode.h"

IfNode::IfNode(ExpressionNode *conditionStatement,
               Node *thenStatement,
               Node *elseStatement)
    : conditionStatement(conditionStatement), thenStatement(thenStatement),
      elseStatement(elseStatement) {}

int IfNode::execute()
{
    if (conditionStatement->execute())
        thenStatement->execute();
    else
    {
        if (elseStatement)
            elseStatement->execute();
    }

    return 0;
}

IfNode::~IfNode()
{
    delete conditionStatement;
    delete thenStatement;
    delete elseStatement;
}