#ifndef __FUNCTION_EXECUTION_NODE_H_
#define __FUNCTION_EXECUTION_NODE_H_

#include <string>

#include "expressionNode.h"
#include "functionArgsNode.h"
#include "statements/declarationNode.h"

#include "symbolTable/symbolTable.h"

using std::string;

class FunctionExecutionNode : public ExpressionNode
{
    string identifier;
    FunctionArgsNode *argsNode;
    SymbolTable *symbolTable;

public:
    FunctionExecutionNode(string identifier, FunctionArgsNode *argsNode,
                          SymbolTable *symbolTable);

    virtual int execute();
    virtual void compile();
    virtual void semanticCheck();
    virtual DataType getType();
    ~FunctionExecutionNode();
};

#endif