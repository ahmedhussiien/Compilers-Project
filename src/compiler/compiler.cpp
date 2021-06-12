#include <iostream>
#include "parser/node.h"
#include "parser/error/error.h"

extern int yylineno;
extern int column;

extern FILE *yyin;
extern FILE *yyout;

int yyparse();

void yyerror(const char *str)
{
    Error *err = new Error(str, yylineno, column);
    err->print();
    exit(0);
}

void execute(Node *program)
{
    if (yyout == stdout) // if in interpreter mode, execute nodes right away.
    {
        program->execute();
    }
    else // if in compiler mode, don't execute just compile.
    {
        program->compile();
    }
}

// Checks if the file can be opened and sets the input source of yylex to the file
void setInputSource(char *fname)
{
    // open a file handle to a particular file:
    FILE *inputFile = fopen(fname, "r");
    // make sure it is valid:
    if (!inputFile)
    {
        std::cout << "Error opening " << fname << "! Running in interpreter mode." << std::endl;
    }
    else
        // set lex to read from it instead of defaulting to STDIN:
        yyin = inputFile;
}

// Creates output file and sets output stream of yylex to file
void setOutputSource(char *fname)
{
    // open a file handle to a particular file:
    FILE *outputFile = fopen(fname, "w");
    // make sure it is valid:
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
    else
        std::cout << "Running in Interpreter mode." << std::endl;
    yyparse();
    return 0;
}