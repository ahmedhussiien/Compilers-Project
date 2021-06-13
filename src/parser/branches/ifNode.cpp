#include "ifNode.h"

IfNode::IfNode(ExpressionNode *conditionStatement,
               Node *thenStatement,
               Node *elseStatement)
    : conditionStatement(conditionStatement), thenStatement(thenStatement),
      elseStatement(elseStatement) {}

int IfNode::execute()
{
    if (conditionStatement->execute())
        thenStatement->execute();
    else
    {
        if (elseStatement)
            elseStatement->execute();
    }

    return 0;
}

void IfNode::compile()
{
    int label1, label2;

    conditionStatement->compile();
    fprintf(yyout, "JZ L%03d\n", label1 = labelCounter++);
    thenStatement->compile();

    if (elseStatement)
    {
        fprintf(yyout, "JMP L%03d\n", label2 = labelCounter++);
        fprintf(yyout, "L%03d:\n", label1);
        elseStatement->compile();
        fprintf(yyout, "L%03d:\n", label2);
    }
    else
    {
        fprintf(yyout, "L%03d:\n", label1);
    }
}

IfNode::~IfNode()
{
    delete conditionStatement;
    delete thenStatement;
    delete elseStatement;
}