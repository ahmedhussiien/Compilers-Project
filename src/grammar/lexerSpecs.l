%{
#include <stdlib.h>
#include<iostream>
#include <string>
#include "parser.h"
#include "parser.hpp"

int nextColumn = 1;
int column = 1;

void yyerror(const std::string);

void incrementCursor() {
    column = nextColumn; 
    nextColumn += strlen(yytext);
}

void incrementCursor(char *str){
    column = nextColumn;

    for(char* i = str; *i != '\0'; i++) {
        if(*i == '\n')
            nextColumn = 1;
        else
            nextColumn++;
    }
}

%}

%option yylineno

%%

"//".*                       { incrementCursor(); } /* SINGLE LINE COMMENT */

[/][*]+([^*/][^*]*[*]+)+[/]  { incrementCursor(yytext); } /* MULTI LINE COMMENTS */

">="            { incrementCursor(); return GE; }
"<="            { incrementCursor(); return LE; }
"=="            { incrementCursor(); return EQ; }
"!="            { incrementCursor(); return NE; }
"and"           { incrementCursor(); return AND; }
"or"            { incrementCursor(); return OR; }
"not"           { incrementCursor(); return NOT; }

"char"          { incrementCursor(); return TYPE_CHAR; }
"int"           { incrementCursor(); return TYPE_INT; }
"float"         { incrementCursor(); return TYPE_FLOAT; }
"bool"          { incrementCursor(); return TYPE_BOOL; }
"void"          { incrementCursor(); return TYPE_VOID; }
"const"         { incrementCursor(); return CONST; }

"for"           { incrementCursor(); return FOR; }
"while"         { incrementCursor(); return WHILE; }
"do"            { incrementCursor(); return DO; }
"continue"      { incrementCursor(); return CONTINUE; }
"break"         { incrementCursor(); return BREAK; }

"if"            { incrementCursor(); return IF; }
"else"          { incrementCursor(); return ELSE; }
"switch"        { incrementCursor(); return SWITCH; }
"case"          { incrementCursor(); return CASE; }

"return"        { incrementCursor(); return RETURN; }
"print"         { incrementCursor(); return PRINT; }
"printSymbols"  { incrementCursor(); return PRINT_SYMBOLS;}


"true"              {
                        incrementCursor();
                        yylval.boolValue = true;
                        return BOOL;
                    }

"false"             {
                        incrementCursor();
                        yylval.boolValue = false;
                        return BOOL;
                    }
                
[a-zA-Z_][a-zA-Z0-9_]*      { 
                                incrementCursor();
                                yylval.identifierName = strdup(yytext);
                                return VARIABLE;
                            }

[0-9]+              {
                        incrementCursor();
                        yylval.intValue = atoi(yytext);
                        return INTEGER;
                    }

[0-9]+[.][0-9]+     {
                        incrementCursor();
                        yylval.floatValue = atof(yytext);
                        return FLOAT;
                    }

\'.\'               {
                        incrementCursor();
                        yylval.charValue = yytext[1];
                        return CHAR;
                    }

[-()<>=+*/;:{}.,]   { incrementCursor(); return *yytext; }


[ \t]+              { incrementCursor(); }

[\n]+               { incrementCursor(); nextColumn = 1; } 

.                   { incrementCursor(); yyerror("Unknown character");}

%%

int yywrap(void) {
    return 1;
}
