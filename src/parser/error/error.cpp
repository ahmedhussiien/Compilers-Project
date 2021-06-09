#include <iostream>
#include "error.h"

using std::cout;
using std::to_string;

Error::Error(string message, int lineNumber, int columnNumber)
    : message(message), lineNumber(lineNumber), columnNumber(columnNumber) {}

void Error::print()
{
    for (int i = 0; i < columnNumber - 1; i++)
        cout << "_";

    cout << "^\n";

    cout << toString() << "\n";
}

string Error::toString()
{
    return "error: " + message + " in line " + to_string(lineNumber) +
           ", column " + to_string(columnNumber) + "\n";
}