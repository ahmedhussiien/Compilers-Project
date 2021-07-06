#include "whileLoopNode.h"

WhileLoopNode::WhileLoopNode(ExpressionNode *conditionStatement,
                             Node *executionStatement)
    : conditionStatement(conditionStatement),
      executionStatement(executionStatement) {}

int WhileLoopNode::execute()
{
    while (conditionStatement->execute())
        executionStatement->execute();

    return 0;
}

void WhileLoopNode::compile()
{
    int label1, label2;

    fprintf(yyout, "L%03d:\n", label1 = labelCounter++);
    conditionStatement->compile();
    fprintf(yyout, "JZ L%03d\n", label2 = labelCounter++);
    executionStatement->compile();
    fprintf(yyout, "JMP L%03d\n", label1);
    fprintf(yyout, "L%03d:\n", label2);
}

WhileLoopNode::~WhileLoopNode()
{
    delete conditionStatement;
    delete executionStatement;
}
