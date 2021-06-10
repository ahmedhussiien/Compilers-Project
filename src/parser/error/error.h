#ifndef __ERROR_H_
#define __ERROR_H_

#include <string>

using std::string;

class Error
{
    int lineNumber;
    int columnNumber;
    string message;

public:
    Error(string message, int lineNumber, int columnNumber);
    void print();
    string toString();
};

#endif