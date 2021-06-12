%{
#include <iostream>
#include <string>

#include "enums/enums.h"
#include "symbolTable/symbolTable.h"
#include "symbolTable/primitiveValue.h"
#include "parser/parser.h"

#define YYERROR_VERBOSE 1

void execute(Node*);
int yylex(void);
void yyerror(const char *str);

SymbolTable symbolTable;
%}

%union {
    int intValue;
    float floatValue;
    bool boolValue;
    char charValue;

    char* identifierName;
    DataType datatype; 

    Node *nPtr;
    ConstantNode* valuePtr;
    ExpressionNode* exprPtr;
    DeclarationNode* declarationPtr;
    StatementsListNode* statementListPtr;

    FunctionArgsNode* funcArgsPtr;
    FunctionParamsNode* funcParamsPtr;
    FunctionDeclarationNode* funcDeclarationPtr;

    SwitchCaseNode* switchCasePtr;
    CaseNode* casePtr;
};

%token <identifierName>     VARIABLE
%token <intValue>           INTEGER
%token <charValue>          CHAR
%token <floatValue>         FLOAT
%token <boolValue>          BOOL

%type <nPtr>                stmt branch_stmt loop_stmt program variable_declaration_stmt
%type <exprPtr>             expr standard_functions
%type <casePtr>             case_stmt
%type <valuePtr>            value
%type <datatype>            variable_type
%type <switchCasePtr>       switch_stmt case_stmt_list
%type <statementListPtr>    stmt_list 
%type <declarationPtr>      variable_declaration

%type <funcArgsPtr>         function_args
%type <funcParamsPtr>       function_params
%type <funcDeclarationPtr>  function_declaration_stmt

// Data types
%token TYPE_INT TYPE_FLOAT TYPE_CHAR TYPE_BOOL TYPE_VOID
%token CONST

// Loops
%token WHILE FOR DO CONTINUE BREAK

// Branches
%token IF SWITCH CASE
%nonassoc IFX
%nonassoc ELSE

// Operators
%right '='
%left AND OR NOT
%left INC DEC
%left GE LE EQ NE '>' '<'
%left '+' '-'
%left '*' '/'
%nonassoc UMINUS

// Standard functions
%token PRINT

// Reserved keywords
%token RETURN

%%
program:
       program stmt        { execute($2); delete $2; }
    | /* NULL */           {}
    ;

stmt_list:
    stmt { 
        $$ = new StatementsListNode();
        $$->addStatement($1);
    }
    | stmt_list stmt {   
        $$ = $1;
        $$->addStatement($2);
    };

stmt:
        expr ';'                    { $$ = $1; }
    |   variable_declaration_stmt   { $$ = $1; }
    |   function_declaration_stmt   { $$ = $1; }
    |   loop_stmt                   { $$ = $1; }
    |   branch_stmt                 { $$ = $1; }
    |   switch_stmt                 { $$ = $1; }
    |   RETURN expr ';'             { $$ = new ReturnNode($2);}
    |   ';'                         { $$ = new StatementsListNode(); }
    |   '{' '}'                     { $$ = new StatementsListNode(); }
    |   '{' stmt_list '}'           { $$ = $2; }
    ;

loop_stmt:
        WHILE '(' expr ')' stmt                 { $$ = new WhileLoopNode($3, $5); }
    |   FOR '(' stmt stmt expr ')' stmt         { $$ = new ForLoopNode($3, $4, $5, $7); }
    |   DO stmt WHILE '(' expr ')'              { $$ = new DoWhileLoopNode($5, $2); }
    |   BREAK ';'                               { $$ = new KeywordNode(KW_BREAK);}
    |   CONTINUE ';'                            { $$ = new KeywordNode(KW_CONTINUE);}
    ;

branch_stmt:
        IF '(' expr ')' stmt %prec IFX          { $$ = new IfNode($3, $5, nullptr); }
    |   IF '(' expr ')' stmt ELSE stmt          { $$ = new IfNode($3, $5, $7); }
    ;

switch_stmt:
    SWITCH '(' expr ')' '{' case_stmt_list '}'  { 
        $$ = $6; $$->setExpression($3); 
    };

case_stmt_list:
    case_stmt { 
        $$ = new SwitchCaseNode(); 
        $$->addCaseStatement($1); 
    }
    |   
    case_stmt_list case_stmt {
        $$ = $1;
        $$->addCaseStatement($2)
    }
    ;

case_stmt:
        CASE expr ':' stmt            { $$ = new CaseNode($2, $4); }
    ;

function_declaration_stmt:
        variable_type VARIABLE '(' function_params ')' stmt      { $$ = new FunctionDeclarationNode(&symbolTable, $2, $1, $4, $6); }
    ;

function_params:
    /* NULL */ {   
        $$ = new FunctionParamsNode(); 
    } 
    | variable_declaration {
        $$ = new FunctionParamsNode();
        $$->addParam($1);
    }
    | function_params ',' variable_declaration { 
        $$ = $1;
        $$->addParam($3); 
    };

function_args:
    /* NULL */ { 
        $$ = new FunctionArgsNode(); 
    } 
    | expr { 
        $$ = new FunctionArgsNode();
        $$->addArg($1);
    }
    | function_args ',' expr  { 
        $$ = $1;
        $$->addArg($3);
    };

variable_declaration_stmt:
        variable_declaration ';'    { $$ = $1; }
    ;

variable_declaration:
        variable_type VARIABLE                   { $$ = new DeclarationNode(&symbolTable, $2, $1); }
    |   variable_type VARIABLE '=' expr          { $$ = new DeclarationNode(&symbolTable, $2, $1, $4);}
    |   CONST variable_type VARIABLE '=' expr    { $$ = new DeclarationNode(&symbolTable, $3, $2, $5, true); }
    ;
    
expr:
        value                           { $$ = $1 ; }
    |   VARIABLE                        { $$ = new IdentifierNode(&symbolTable, $1); }
    |   NOT expr                        { $$ = new UnaryOpNode(OP_NOT, $2); }
    |   '-' expr %prec UMINUS           { $$ = new UnaryOpNode(OP_UMINUS, $2); }
    |   expr '+' expr                   { $$ = new BinaryOpNode(OP_PLUS, $1, $3); }
    |   expr '-' expr                   { $$ = new BinaryOpNode(OP_MINUS, $1, $3); }
    |   expr '*' expr                   { $$ = new BinaryOpNode(OP_MULTIPLY, $1, $3); }
    |   expr '/' expr                   { $$ = new BinaryOpNode(OP_DIVIDE, $1, $3); }
    |   expr '<' expr                   { $$ = new BinaryOpNode(OP_LESS_THAN, $1, $3); }
    |   expr '>' expr                   { $$ = new BinaryOpNode(OP_GREATER_THAN, $1, $3); }
    |   expr GE expr                    { $$ = new BinaryOpNode(OP_GE, $1, $3); }
    |   expr LE expr                    { $$ = new BinaryOpNode(OP_LE, $1, $3); }
    |   expr NE expr                    { $$ = new BinaryOpNode(OP_NE, $1, $3); }
    |   expr EQ expr                    { $$ = new BinaryOpNode(OP_EQ, $1, $3); }
    |   expr AND expr                   { $$ = new BinaryOpNode(OP_AND, $1, $3); }
    |   expr OR expr                    { $$ = new BinaryOpNode(OP_OR, $1, $3); }
    |   VARIABLE '=' expr               { $$ = new AssignmentNode(&symbolTable, $1, DTYPE_INT, $3); }
    |   VARIABLE '(' function_args ')'  { $$ = new FunctionExecutionNode($1, $3, &symbolTable);}
    |   standard_functions              { $$ = $1; }
    |   '(' expr ')'                    { $$ = $2; }
    ;

standard_functions:
        PRINT '(' expr ')'      { $$ = new PrintNode($3); }
    ;

variable_type:
        TYPE_INT        { $$ = DTYPE_INT ;}
    |   TYPE_FLOAT      { $$ = DTYPE_FLOAT ;}
    |   TYPE_BOOL       { $$ = DTYPE_BOOL ;}
    |   TYPE_CHAR     { $$ = DTYPE_CHAR ;}
    |   TYPE_VOID       { $$ = DTYPE_VOID ;}
    ;

value:
        INTEGER      { $$ = new ConstantNode($1); }
    |   FLOAT        { $$ = new ConstantNode($1); }
    |   BOOL         { $$ = new ConstantNode($1); }
    |   CHAR       { $$ = new ConstantNode($1); }
    ;

%%