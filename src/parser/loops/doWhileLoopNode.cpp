#include "doWhileLoopNode.h"

DoWhileLoopNode::DoWhileLoopNode(ExpressionNode *conditionStatement,
                                 Node *executionStatement)
    : conditionStatement(conditionStatement),
      executionStatement(executionStatement) {}

int DoWhileLoopNode::execute()
{
    do
    {
        executionStatement->execute();
    } while (conditionStatement->execute());

    return 0;
}

DoWhileLoopNode::~DoWhileLoopNode()
{
    delete conditionStatement;
    delete executionStatement;
}
