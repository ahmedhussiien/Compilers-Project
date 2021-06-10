#include <vector>
#include "functionExecutionNode.h"

using std::vector;

FunctionExecutionNode::FunctionExecutionNode(string identifier,
                                             FunctionArgsNode *argsNode,
                                             SymbolTable *symbolTable)
    : ExpressionNode(), identifier(identifier), argsNode(argsNode),
      symbolTable(symbolTable) {}

int FunctionExecutionNode::execute()
{
    if (!symbolTable)
        return -1;

    FunctionSymbol *symbol = symbolTable->getFunctionSymbol(identifier);

    if (!symbol)
        return -1;

    FunctionParamsNode *paramsNode = symbol->getParamsNode();
    vector<DeclarationNode *> params = paramsNode->getParams();

    DeclarationNode *declarationNode;
    ExpressionNode *expr;
    for (int i = 0; i < params.size(); i++)
    {
        declarationNode = new DeclarationNode(*params[i]);
        expr = argsNode->getArg(i);

        if (expr)
            declarationNode->setExpressionNode(expr);

        if (!declarationNode->getExpressionNode())
            return -1; // throw "Missing arguments"

        declarationNode->execute();
        delete declarationNode;
    }

    return symbol->getStatementsListNode()->execute();
}

DataType FunctionExecutionNode::getType()
{
    if (!symbolTable)
        yyerror("Function error.");

    FunctionSymbol *symbol = symbolTable->getFunctionSymbol(identifier);

    if (!symbol)
        yyerror("Function not declared.");

    return symbol->getReturnType();
}

FunctionExecutionNode::~FunctionExecutionNode()
{
    delete argsNode;
}
