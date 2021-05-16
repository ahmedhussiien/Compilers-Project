#include "whileLoopNode.h"

WhileLoopNode::WhileLoopNode(ExpressionNode *conditionStatement,
                             Node *executionStatement)
    : conditionStatement(conditionStatement),
      executionStatement(executionStatement) {}

int WhileLoopNode::execute()
{
    while (conditionStatement->execute())
        executionStatement->execute();

    return 0;
}

WhileLoopNode::~WhileLoopNode()
{
    delete conditionStatement;
    delete executionStatement;
}
