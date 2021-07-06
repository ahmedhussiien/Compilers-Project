#ifndef __ASSIGNMENT_NODE_H_
#define __ASSIGNMENT_NODE_H_

#include <string>

#include "expressionNode.h"
#include "enums/dataType.h"
#include "symbolTable/symbolTable.h"

using std::string;

class AssignmentNode : public ExpressionNode
{
    SymbolTable *symbolTable;
    PrimitiveSymbol *symbol;
    ExpressionNode *exprNode;
    string name;

public:
    AssignmentNode(SymbolTable *symbolTable, char *name,
                   ExpressionNode *exprNode);

    virtual DataType getType();
    virtual void semanticCheck();

    virtual int execute();
    virtual void compile();

    ~AssignmentNode();
};

#endif