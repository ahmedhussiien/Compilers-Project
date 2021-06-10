
#include <stdio.h>
#include "print.h"

PrintNode::PrintNode(ExpressionNode *n) : n(n)
{
}

int PrintNode::execute()
{
    fprintf(yyout, "%d\n", n->execute());
    return 0;
}

DataType PrintNode::getType()
{
    return DTYPE_INT;
}
