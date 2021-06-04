#ifndef __KEYWORD_NODE_H_
#define __KEYWORD_NODE_H_

#include "node.h"
#include "enums/keyword.h"

class KeywordNode : public Node
{
    Keyword keyword;

public:
    KeywordNode(Keyword keyword) : keyword(keyword) {}
    virtual int execute() { return 0; }
};

#endif
