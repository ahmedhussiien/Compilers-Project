#ifndef __SYMBOL_H_
#define __SYMBOL_H_

enum SymbolType
{
    PRIMITIVE,
    FUNCTION
};

class Symbol
{

public:
    virtual SymbolType getType() = 0;
};

#endif