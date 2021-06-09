
#include <stdio.h>
#include "print.h"

PrintNode::PrintNode(ExpressionNode *n) : n(n)
{
}

int PrintNode::execute()
{
    int value = n->execute();
    fprintf(yyout, "%d\n", value);
    // printf("%d\n", n->execute());
    return 0;
}
