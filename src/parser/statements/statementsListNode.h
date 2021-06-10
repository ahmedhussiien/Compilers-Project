#ifndef __STATEMENTS_LIST_NODE_H_
#define __STATEMENTS_LIST_NODE_H_

#include <vector>
#include "parser/node.h"

using std::vector;

class StatementsListNode : public Node
{
    vector<Node *> statements;

public:
    StatementsListNode();

    void addStatement(Node *statement);
    int execute();
    vector<Node *> getStatements();

    ~StatementsListNode();
};

#endif