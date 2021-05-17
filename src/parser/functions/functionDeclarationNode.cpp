#include "functionDeclarationNode.h"

FunctionDeclarationNode::FunctionDeclarationNode(SymbolTable *symbolTable, char *name, DataType returnType,
                                                 FunctionParamsNode *params, Node *statements)
    : Node(), symbolTable(symbolTable), name(name), returnType(returnType),
      params(params), statements(statements)
{
}

int FunctionDeclarationNode::execute()
{
  symbolTable->declareFunction(name, returnType, params, statements);
  return 1;
}
