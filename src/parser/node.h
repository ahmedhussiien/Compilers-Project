#ifndef __NODE_H_
#define __NODE_H_

#include <cstdio>
extern FILE *yyout;

class Node
{

public:
    virtual int execute() = 0;
    virtual void compile(){};
    virtual ~Node(){};
};

#endif