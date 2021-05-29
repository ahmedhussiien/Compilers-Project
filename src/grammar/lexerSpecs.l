%{
#include <stdlib.h>
#include <string>
#include "parser.h"
#include "parser.hpp"
void yyerror(std::string s);
%}

%%

"//".*                       { /* SINGLE LINE COMMENT */ }
[/][*]+([^*/][^*]*[*]+)+[/]  { /* MULTI LINE COMMENTS */ }

">="            return GE;
"<="            return LE;
"=="            return EQ;
"!="            return NE;
"++"            return INC;
"--"            return DEC;
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
"switch"        return SWITCH;
"case"          return CASE;

"return"        return RETURN;
"print"         return PRINT;


"true"              {
                        yylval.boolValue = true;
                        return BOOL;
                    }

"false"             {
                        yylval.boolValue = false;
                        return BOOL;
                    }
                
[a-zA-Z_][a-zA-Z0-9_]*      { 
                                yylval.identifierName = strdup(yytext);
                                return VARIABLE;
                            }

[0-9]+              {
                        yylval.intValue = atoi(yytext);
                        return INTEGER;
                    }

[0-9]+[.][0-9]+     {
                        yylval.floatValue = atof(yytext);
                        return FLOAT;
                    }

\"([^\"]*)\"        {
                        yylval.stringValue = strdup(yytext);
                        return STRING;
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
