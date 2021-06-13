#ifndef __NODE_H_
#define __NODE_H_

#include <cstdio>
#include <string>
#include "dataType.h"

extern FILE *yyout;
extern int labelCounter;

void yyerror(const std::string str);

class Node
{

public:
    virtual int execute() = 0;
    virtual void compile(){};
    virtual void semanticCheck(){};
    virtual ~Node(){};
};

#endif