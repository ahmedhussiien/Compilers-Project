
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
        symbolTable->declareVariable(name, type, exprNode->execute(), isConst);
    }
    else
    {
        symbolTable->declareVariable(name, type, 0, isConst);
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
        symbolTable->declareVariable(name, type, exprNode->execute(), isConst);
    }
    else
    {
        symbolTable->declareVariable(name, type, 0, isConst);
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
    fprintf(yyout, ".DATA\n");
    string varType = (isConst) ? "EQU" : "DB";
    switch (type)
    {
    case DTYPE_INT:
        // init int
        if (exprNode)
            fprintf(yyout, "%s\t%s\t%d\n", name.c_str(), varType.c_str(), exprNode->execute());
        else
            fprintf(yyout, "%s\t%s\t0\n", name.c_str(), varType.c_str(), exprNode->execute());
        break;

    case DTYPE_FLOAT:
        // init float
        if (exprNode)
            fprintf(yyout, "%s\t%s\t%d\n", name.c_str(), varType.c_str(), exprNode->execute());
        else
            fprintf(yyout, "%s\t%s\t0\n", name.c_str(), varType.c_str(), exprNode->execute());
        break;
    case DTYPE_BOOL:
        // init bool
        if (exprNode)
            fprintf(yyout, "%s\t%s\t%d\n", name.c_str(), varType.c_str(), exprNode->execute());
        else
            fprintf(yyout, "%s\t%s\t0\n", name.c_str(), varType.c_str(), exprNode->execute());
        break;
    case DTYPE_CHAR:
        // init string
        if (exprNode)
            fprintf(yyout, "%s\t%s\t%s\n", name.c_str(), varType.c_str(), exprNode->execute());
        else
            fprintf(yyout, "%s\t%s\t\'\'\n", name.c_str(), varType.c_str());
        break;
    case DTYPE_VOID:
        // init void
        // void should give semantic error
        break;
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
