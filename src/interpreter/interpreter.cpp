#include <iostream>
#include "parser/node.h"

using std::cout;
using std::to_string;

extern int yylineno;
extern int column;

int yyparse();

void yyerror(const char *str)
{
    cout << "error: " + str + " in line " + to_string(yylineno) +
                ", column " + to_string(column) + "\n";
}

void execute(Node *program)
{
    program->execute();
}

int main(void)
{
    yyparse();
    return 0;
}