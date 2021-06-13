#include "doWhileLoopNode.h"

DoWhileLoopNode::DoWhileLoopNode(ExpressionNode *conditionStatement,
                                 Node *executionStatement)
    : conditionStatement(conditionStatement),
      executionStatement(executionStatement) {}

int DoWhileLoopNode::execute()
{
    do
    {
        executionStatement->execute();
    } while (conditionStatement->execute());

    return 0;
}

void DoWhileLoopNode::compile()
{
    int label1, label2;

    fprintf(yyout, "L%03d:\n", label1 = labelCounter++);
    executionStatement->compile();
    conditionStatement->compile();
    fprintf(yyout, "JZ L%03d\n", label2 = labelCounter++);
    fprintf(yyout, "JMP L%03d\n", label1);
    fprintf(yyout, "L%03d:\n", label2);
}

DoWhileLoopNode::~DoWhileLoopNode()
{
    delete conditionStatement;
    delete executionStatement;
}
