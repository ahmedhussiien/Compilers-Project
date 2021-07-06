#ifndef __PRINT_SYMBOLS_NODE_H_
#define __PRINT_SYMBOLS_NODE_H_

#include "node.h"
#include "expressionNode.h"
#include "symbolTable/symbolTable.h"

class PrintSymbolsNode : public ExpressionNode
{
    SymbolTable *symbolTable;

public:
    PrintSymbolsNode(SymbolTable *symbolTable);
    virtual int execute();
    virtual void compile();
    virtual DataType getType();
};

#endif