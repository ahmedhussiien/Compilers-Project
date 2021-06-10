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
    string name;
    DataType type;

    ExpressionNode *exprNode;

public:
    AssignmentNode(SymbolTable *symbolTable, char *name, DataType type,
                   ExpressionNode *exprNode = nullptr);

    virtual int execute();
    virtual DataType getType();
    ~AssignmentNode();
};

#endif