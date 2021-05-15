#ifndef __NODE_H_
#define __NODE_H_

class Node
{

public:
    virtual int execute() = 0;
    virtual ~Node(){};
};

#endif