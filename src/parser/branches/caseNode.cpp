#include "caseNode.h"

CaseNode::CaseNode(ExpressionNode *expr, Node *statement)
    : expr(expr), statement(statement) {}

int CaseNode::execute()
{
    if (expr->execute())
        return statement->execute();

    return -1;
}

ExpressionNode *CaseNode::getExpressionNode() const
{
    return this->expr;
}

void CaseNode::compile()
{
    statement->compile();
    fprintf(yyout, "RET\n");
}

CaseNode::~CaseNode()
{
    delete expr;
    delete statement;
}