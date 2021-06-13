
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

void PrintNode::compile()
{
    n->compile();
    fprintf(yyout, "CALL print\n");
}

DataType PrintNode::getType()
{
    return DTYPE_INT;
}
