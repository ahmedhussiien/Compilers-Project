#include "forLoopNode.h"

ForLoopNode::ForLoopNode(Node *initialStatement, Node *conditionStatement,
                         Node *incrementStatement,
                         Node *executionStatement)
    : initialStatement(initialStatement),
      conditionStatement(conditionStatement),
      incrementStatement(incrementStatement),
      executionStatement(executionStatement) {}

int ForLoopNode::execute()
{
    for (initialStatement->execute(); conditionStatement->execute(); incrementStatement->execute())
        executionStatement->execute();

    return 0;
}

void ForLoopNode::compile()
{
    int label1, label2;

    initialStatement->compile();

    fprintf(yyout, "L%03d:\n", label1 = labelCounter++);
    conditionStatement->compile();

    fprintf(yyout, "JZ L%03d\n", label2 = labelCounter++);
    executionStatement->compile();
    incrementStatement->compile();

    fprintf(yyout, "JMP L%03d\n", label1);
    fprintf(yyout, "L%03d:\n", label2);
}

ForLoopNode::~ForLoopNode()
{
    delete initialStatement;
    delete conditionStatement;
    delete incrementStatement;
    delete executionStatement;
}
