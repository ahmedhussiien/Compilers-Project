#ifndef __FUNCTION_DECLARATION_NODE_H_
#define __FUNCTION_DECLARATION_NODE_H_

#include <string>

#include "node.h"
#include "functionParamsNode.h"
#include "statements/statementsListNode.h"

#include "symbolTable/symbolTable.h"
#include "enums/dataType.h"

using std::string;

class FunctionDeclarationNode : public Node
{
    SymbolTable *symbolTable;

    string name;
    DataType returnType;

    FunctionParamsNode *params;
    Node *statements;

public:
    FunctionDeclarationNode(SymbolTable *symbolTable, char *name, DataType returnType,
                            FunctionParamsNode *params, Node *statements);

    virtual int execute();
};

#endif