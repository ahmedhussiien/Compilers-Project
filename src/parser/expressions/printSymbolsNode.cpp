
#include "printSymbolsNode.h"
#include <stdio.h>

PrintSymbolsNode::PrintSymbolsNode(SymbolTable *symbolTable)
    : symbolTable(symbolTable) {}

int PrintSymbolsNode::execute()
{
    symbolTable->printSymbols();
    return 0;
}

void PrintSymbolsNode::compile()
{
    symbolTable->printSymbols();
}

DataType PrintSymbolsNode::getType() { return DTYPE_INT; }
