%{
#include <stdlib.h>
#include <string>
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

"int"           return TYPE_INT;
"const"         return CONST;

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
