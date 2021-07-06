#ifndef __IDENTIFIER_NODE_H_
#define __IDENTIFIER_NODE_H_

#include <string>

#include "expressionNode.h"
#include "symbolTable/symbolTable.h"

using std::string;

class IdentifierNode : public ExpressionNode
{
    string name;
    SymbolTable *symbolTable;

public:
    IdentifierNode(SymbolTable *symbolTable, char *name);
    virtual void semanticCheck();

    virtual int execute();
    virtual void compile();

    virtual DataType getType();
};

#endif