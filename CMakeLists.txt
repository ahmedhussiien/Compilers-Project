cmake_minimum_required(VERSION 3.0.0)   
project(Compiler VERSION 0.1.0)             

set(CMAKE_CXX_STANDARD 14)

# A variable with all our parser source files
set(PARSER_SOURCES
    src/parser/expressions/binaryOpNode.cpp
    src/parser/expressions/constantNode.cpp
    src/parser/expressions/identifierNode.cpp
    src/parser/expressions/unaryOpNode.cpp
    src/parser/expressions/assignmentNode.cpp
    src/parser/expressions/printSymbolsNode.cpp
    src/parser/expressions/print.cpp
    
    src/parser/statements/declarationNode.cpp
    src/parser/statements/statementsListNode.cpp

    src/parser/branches/ifNode.cpp
    src/parser/branches/caseNode.cpp
    src/parser/branches/switchCaseNode.cpp
    
    src/parser/loops/forLoopNode.cpp
    src/parser/loops/doWhileLoopNode.cpp
    src/parser/loops/whileLoopNode.cpp
    
    src/parser/functions/returnNode.cpp
    src/parser/functions/functionArgsNode.cpp
    src/parser/functions/functionParamsNode.cpp
    src/parser/functions/functionExecutionNode.cpp
    src/parser/functions/functionDeclarationNode.cpp

    src/parser/error/error.cpp)

# A variable with all the symbol table files
set(SYMBOL_TABLE_SOURCES
    src/symbolTable/functionSymbol.cpp
    src/symbolTable/primitiveSymbol.cpp
    src/symbolTable/symbolTable.cpp )

# Define the directories in which to search for the included headers
include_directories(
        src/

        src/parser
        src/parser/branches
        src/parser/expressions
        src/parser/functions
        src/parser/loops
        src/parser/statements

        src/symbolTable
        src/enums
    )

# Bison & Flex targets
find_package(BISON)
find_package(FLEX)

# Generating the executables
BISON_TARGET(MyParser src/grammar/parserGrammar.y ${CMAKE_CURRENT_BINARY_DIR}/parser.cpp COMPILE_FLAGS -v)
FLEX_TARGET(MyScanner src/grammar/lexerSpecs.l  ${CMAKE_CURRENT_BINARY_DIR}/lexer.cpp)
ADD_FLEX_BISON_DEPENDENCY(MyScanner MyParser src/enums/enums.h src/parser/parser.h)

add_executable(interpreter
    src/interpreter/interpreter.cpp
    ${BISON_MyParser_OUTPUTS}
    ${FLEX_MyScanner_OUTPUTS}
    ${PARSER_SOURCES} 
    ${SYMBOL_TABLE_SOURCES}
)

add_executable(compiler
    src/compiler/compiler.cpp
    ${BISON_MyParser_OUTPUTS}
    ${FLEX_MyScanner_OUTPUTS}
    ${PARSER_SOURCES} 
    ${SYMBOL_TABLE_SOURCES}
)