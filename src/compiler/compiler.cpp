#include <iostream>
#include <vector>

#include "parser/node.h"
#include "parser/error/error.h"

extern int yylineno;
extern int column;

extern FILE *yyin;
extern FILE *yyout;

int yyparse();

void yyerror(const std::string str)
{
    Error *err = new Error(str, yylineno, column);
    err->print();
}

void execute(Node *program)
{
    program->compile();
}

// Checks if the file can be opened and sets the input source of yylex to the file
void setInputSource(char *fname)
{
    FILE *inputFile = fopen(fname, "r");
    if (!inputFile)
    {
        std::cout << "Error opening " << fname << "! Input set to terminal." << std::endl;
    }
    else
        yyin = inputFile;
}

// Creates output file and sets output stream of yylex to file
void setOutputSource(char *fname)
{
    FILE *outputFile = fopen(fname, "w");
    if (!outputFile)
    {
        std::cout << "Error creating " << fname << "! Output set to terminal." << std::endl;
    }
    else
        // set lex to write to it instead of defaulting to STDOUT:
        yyout = outputFile;
}

int main(int argc, char *argv[])
{
    // Check if user supplied input and output files, and change streams accordingly
    if (argc >= 2)
    {
        setInputSource(argv[1]);
        if (argc >= 3)
        {
            setOutputSource(argv[2]);
        }
    }

    yyparse();

    return 0;
}