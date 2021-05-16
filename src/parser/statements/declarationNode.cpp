
#include "declarationNode.h"
#include "symbolTable/symbolTable.h"

DeclarationNode::DeclarationNode(SymbolTable *symbolTable, char *name,
                                 DataType type, ExpressionNode *exprNode,
                                 bool isConst)
    : Node(), symbolTable(symbolTable), name(name), type(type),
      isConst(isConst), exprNode(exprNode) {}

DeclarationNode::DeclarationNode(const DeclarationNode &node)
{
    name = node.name;
    type = node.type;
    isConst = node.isConst;
    exprNode = node.exprNode;
    symbolTable = node.symbolTable;
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
    if (exprNode)
    {
        symbolTable->declareVariable(name, type, exprNode->execute(), isConst);
    }
    else
    {
        symbolTable->declareVariable(name, type, 0, isConst);
    }

    return 1;
}

DeclarationNode::~DeclarationNode()
{
    delete exprNode;
    exprNode = nullptr;
}
