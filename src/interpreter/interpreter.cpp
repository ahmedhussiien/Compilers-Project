#include <iostream>
#include "parser/node.h"

int yyparse();

void yyerror(std::string s)
{
    std::cout << s << "\n";
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