#include "functionDeclarationNode.h"

FunctionDeclarationNode::FunctionDeclarationNode(SymbolTable *symbolTable, char *name, DataType returnType,
                                                 FunctionParamsNode *params, Node *statements)
    : Node(), symbolTable(symbolTable), name(name), returnType(returnType),
      params(params), statements(statements)
{
  semanticCheck();
  symbolTable->declareFunction(name, returnType, params, statements);
}

int FunctionDeclarationNode::execute()
{
  return 1;
}

void FunctionDeclarationNode::semanticCheck()
{
  if (returnType == DTYPE_VOID)
  { // return type is void, all return statements should be of type void
    StatementsListNode *stmtsList = dynamic_cast<StatementsListNode *>(statements);
    vector<Node *> stmtsVector = stmtsList->getStatements();
    for (Node *node : stmtsVector)
    {
      ReturnNode *rn = dynamic_cast<ReturnNode *>(node);
      if (rn)
      {
        if (rn->getReturnType() != DTYPE_VOID)
          yyerror("Expected void return type.");
      }
    }
  }
  else
  { // return type is any, so there must be return statements and they should all be same type
    bool hasReturn = false;
    StatementsListNode *stmtsList = dynamic_cast<StatementsListNode *>(statements);
    vector<Node *> stmtsVector = stmtsList->getStatements();
    for (Node *node : stmtsVector)
    {
      ReturnNode *rn = dynamic_cast<ReturnNode *>(node);
      if (rn)
      {
        hasReturn = true;
        if (rn->getReturnType() != returnType)
        {
          std::string type = DataTypeStr[returnType];
          type = "Expected " + type + " return type.";
          yyerror(type.c_str());
        }
      }
    }
    if (!hasReturn)
      yyerror("Function must have return statement.");
  }
}