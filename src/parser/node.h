#ifndef __NODE_H_
#define __NODE_H_

#include <cstdio>
#include <string>
extern FILE *yyout;
void yyerror(std::string s);

class Node
{

public:
    virtual int execute() = 0;
    virtual void compile(){};
    virtual ~Node(){};
};

#endif