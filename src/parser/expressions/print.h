#ifndef __PRINT_NODE_H_
#define __PRINT_NODE_H_

#include "node.h"
#include "expressionNode.h"
#include <cstdio>
extern FILE *yyout;

class PrintNode : public ExpressionNode
{
    ExpressionNode *n;

public:
    PrintNode(ExpressionNode *n);
    virtual int execute();
};

#endif