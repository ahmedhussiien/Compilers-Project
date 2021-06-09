#include "parser/node.h"
#include "parser/error/error.h"

extern int yylineno;
extern int column;

int yyparse();

void yyerror(const char *str)
{
    Error *err = new Error(str, yylineno, column);
    err->print();
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