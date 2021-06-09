#include "functionDeclarationNode.h"

FunctionDeclarationNode::FunctionDeclarationNode(SymbolTable *symbolTable, char *name, DataType returnType,
                                                 FunctionParamsNode *params, Node *statements)
    : Node(), symbolTable(symbolTable), name(name), returnType(returnType),
      params(params), statements(statements)
{
  symbolTable->declareFunction(name, returnType, params, statements);
}

int FunctionDeclarationNode::execute()
{
  return 1;
}
