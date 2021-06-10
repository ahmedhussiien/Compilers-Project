#include "statementsListNode.h"

StatementsListNode::StatementsListNode() {}

void StatementsListNode::addStatement(Node *statement)
{
    statements.push_back(statement);
}

int StatementsListNode::execute()
{
    if (statements.size() == 0)
        return 0;

    for (int i = 0; i < statements.size() - 1; i++)
        statements[i]->execute();

    return statements[statements.size() - 1]->execute();
}

vector<Node *> StatementsListNode::getStatements()
{
    return statements;
}

StatementsListNode::~StatementsListNode()
{
    for (int i = 0; i < statements.size(); i++)
        delete statements[i];
}
