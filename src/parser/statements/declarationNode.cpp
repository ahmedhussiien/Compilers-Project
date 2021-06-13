
#include "declarationNode.h"
#include "symbolTable/symbolTable.h"

DeclarationNode::DeclarationNode(SymbolTable *symbolTable, char *name,
                                 DataType type, ExpressionNode *exprNode,
                                 bool isConst)
    : Node(), symbolTable(symbolTable), name(name), type(type),
      isConst(isConst), exprNode(exprNode)
{
    semanticCheck();
    if (exprNode)
    {
        symbolTable->declareVariable(name, type, exprNode->execute(), true, isConst);
    }
    else
    {
        symbolTable->declareVariable(name, type, 0, false, isConst);
    }
}

DeclarationNode::DeclarationNode(const DeclarationNode &node)
{
    name = node.name;
    type = node.type;
    isConst = node.isConst;
    exprNode = node.exprNode;
    symbolTable = node.symbolTable;
    semanticCheck();
    if (exprNode)
    {
        symbolTable->declareVariable(name, type, exprNode->execute(), true, isConst);
    }
    else
    {
        symbolTable->declareVariable(name, type, 0, false, isConst);
    }
}

string DeclarationNode::getName() const
{
    return name;
}

DataType DeclarationNode::getDataType() const
{
    return type;
}

bool DeclarationNode::getIsConst() const
{
    return isConst;
}

ExpressionNode *DeclarationNode::getExpressionNode() const
{
    return exprNode;
}

void DeclarationNode::setExpressionNode(ExpressionNode *exprNode)
{
    this->exprNode = exprNode;
}

int DeclarationNode::execute()
{
    return 1;
}

void DeclarationNode::compile()
{
    if (exprNode)
    {
        exprNode->compile();
        fprintf(yyout, "POP %s\n", name.c_str());
    }
}

void DeclarationNode::semanticCheck()
{
    if (type == DTYPE_VOID)
        yyerror("Incomplete type is not allowed.");
    if (exprNode)
    {
        if (exprNode->getType() != type)
            yyerror("Variable type mismatch.");
    }
}

DeclarationNode::~DeclarationNode()
{
    delete exprNode;
    exprNode = nullptr;
}
