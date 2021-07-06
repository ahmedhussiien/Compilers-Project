#include <vector>
#include "functionExecutionNode.h"

using std::vector;

FunctionExecutionNode::FunctionExecutionNode(string identifier,
                                             FunctionArgsNode *argsNode,
                                             SymbolTable *symbolTable)
    : ExpressionNode(), identifier(identifier), argsNode(argsNode),
      symbolTable(symbolTable)
{
    semanticCheck();
}

void FunctionExecutionNode::compile()
{
    // semanticCheck();
    argsNode->compile();
    fprintf(yyout, "CALL %s\n", identifier.c_str());
}

int FunctionExecutionNode::execute()
{
    FunctionSymbol *symbol = symbolTable->getFunctionSymbol(identifier);

    if (!symbol)
    {
        yyerror("Undeclared function.");
        return -1;
    }

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
            yyerror("Missing arguments in function call.");

        declarationNode->execute();
        delete declarationNode;
    }

    return symbol->getStatementsListNode()->execute();
}

void FunctionExecutionNode::semanticCheck()
{
    if (!symbolTable)
        yyerror("Couldn't access symbol table.");

    FunctionSymbol *symbol = symbolTable->getFunctionSymbol(identifier);

    if (!symbol)
        return yyerror("Undeclared function.");

    FunctionParamsNode *paramsNode = symbol->getParamsNode();
    vector<DeclarationNode *> params = paramsNode->getParams(); // arguments in function declaration

    if (params.size() != argsNode->getCount())
        yyerror("Arguments mismatch.");

    for (int i = 0; i < params.size(); i++)
    {
        if (params[i]->getDataType() != argsNode->getArg(i)->getType())
            yyerror("Arguments mismatch.");
    }
}

DataType FunctionExecutionNode::getType()
{
    FunctionSymbol *symbol = symbolTable->getFunctionSymbol(identifier);

    if (!symbol)
        return DTYPE_VOID;

    return symbol->getReturnType();
}

FunctionExecutionNode::~FunctionExecutionNode()
{
    delete argsNode;
}
