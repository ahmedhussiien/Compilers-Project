#include "forLoopNode.h"

ForLoopNode::ForLoopNode(Node *initialStatement, Node *conditionStatement,
                         Node *incrementStatement,
                         Node *executionStatement)
    : initialStatement(initialStatement),
      conditionStatement(conditionStatement),
      incrementStatement(incrementStatement),
      executionStatement(executionStatement) {}

int ForLoopNode::execute()
{
    for (initialStatement->execute(); conditionStatement->execute(); incrementStatement->execute())
        executionStatement->execute();

    return 0;
}

ForLoopNode::~ForLoopNode()
{
    delete initialStatement;
    delete conditionStatement;
    delete incrementStatement;
    delete executionStatement;
}
