
#include <stdio.h>
#include "print.h"

PrintNode::PrintNode(ExpressionNode *n) : n(n)
{
}

int PrintNode::execute()
{
    printf("%d\n", n->execute());
    return 0;
}
