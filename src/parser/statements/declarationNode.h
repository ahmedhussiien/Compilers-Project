#ifndef __DECLARATION_NODE_H_
#define __DECLARATION_NODE_H_

#include <string>

#include "node.h"
#include "expressionNode.h"
#include "enums/dataType.h"

using std::string;

class SymbolTable;

class DeclarationNode : public Node
{
    SymbolTable *symbolTable;

    string name;
    DataType type;
    bool isConst;

    ExpressionNode *exprNode;

public:
    DeclarationNode(SymbolTable *symbolTable, char *name, DataType type,
                    ExpressionNode *exprNode = nullptr, bool isConst = false);

    DeclarationNode(const DeclarationNode &node);

    string getName() const;
    DataType getDataType() const;
    bool getIsConst() const;
    ExpressionNode *getExpressionNode() const;

    void setExpressionNode(ExpressionNode *exprNode);

    virtual int execute();

    virtual void compile();

    ~DeclarationNode();
};

#endif