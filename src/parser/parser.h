#ifndef __PARSER_H_
#define __PARSER_H_

#include "node.h"
#include "expressionNode.h"
#include "keywordNode.h"

#include "statements/statementsListNode.h"
#include "statements/declarationNode.h"

#include "expressions/unaryOpNode.h"
#include "expressions/binaryOpNode.h"
#include "expressions/constantNode.h"
#include "expressions/identifierNode.h"
#include "expressions/assignmentNode.h"
#include "expressions/print.h"

#include "branches/ifNode.h"
#include "branches/caseNode.h"
#include "branches/switchCaseNode.h"

#include "loops/doWhileLoopNode.h"
#include "loops/WhileLoopNode.h"
#include "loops/forLoopNode.h"

#include "functions/returnNode.h"
#include "functions/functionArgsNode.h"
#include "functions/functionParamsNode.h"
#include "functions/functionExecutionNode.h"
#include "functions/functionDeclarationNode.h"

#endif