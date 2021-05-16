%{
#include <stdlib.h>
#include <string>
#include "parser.h"
#include "parser.hpp"
void yyerror(std::string s);
%}

%%

">="            return GE;
"<="            return LE;
"=="            return EQ;
"!="            return NE;
"and"           return AND;
"or"            return OR;
"not"           return NOT;

"string"        return TYPE_STRING;
"int"           return TYPE_INT;
"float"         return TYPE_FLOAT;
"bool"          return TYPE_BOOL;
"void"          return TYPE_VOID;
"const"         return CONST;

"for"           return FOR;
"while"         return WHILE;
"do"            return DO;
"continue"      return CONTINUE;
"break"         return BREAK;

"if"            return IF;
"else"          return ELSE;

"int"           return TYPE_INT;
"const"         return CONST;

"print"         return PRINT;


[a-zA-Z_][a-zA-Z0-9_]*      { 
                                yylval.identifierName = strdup(yytext);
                                return VARIABLE;
                            }

[0-9]+              {
                        yylval.intValue = atoi(yytext);
                        return INTEGER;
                    }

[-()<>=+*/;:{}.,]   {
                        return *yytext;
                    }


[ \t\n]+            ;       /* ignore whitespace */

.                   {
                        yyerror("Unknown character");
                    }
%%

int yywrap(void) {
    return 1;
}
