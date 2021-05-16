#ifndef __FOR_LOOP_NODE_H_
#define __FOR_LOOP_NODE_H_

#include "node.h"
#include "statements/statementsListNode.h"

class ForLoopNode : public Node
{
    Node *initialStatement, *conditionStatement, *incrementStatement,
        *executionStatement;

public:
    ForLoopNode(Node *initialStatement, Node *conditionStatement,
                Node *incrementStatement, Node *executionStatement);

    virtual int execute();

    ~ForLoopNode();
};

#endif
