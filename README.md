# Cpp-mini-compiler
Implementation of a mini-compiler for the C++ language.

The constructs focussed on are while loop and switch case, along with arrays and functions. The following stages have been implemented:

        1) Lexical Analysis   
        2) Symbol Table generation    
        3) Syntax Analyzer   
        4) Semantic Analyzer   
        5) Generating Intermediate Code (3- address code)   
        6) Code optimization   
The first five stages were implemented by means of tools lex and yacc, while code optimization was done using python.
  
The following have been handled by the mini compiler:

        1) Data Types considered are as int, double, char   
        2) Operators handled include arithmetic (+-,*,/,++,--) and relational ( <, >, <=, >=, == )   
        3) The compiler can detect single and multi line comments   
        4) While and Switch Case constructs are handled    
        5) Arrays are incorporated    
        6) The errors detected include undeclared variables, redeclaration in same scope and type mismatch in arithmetic expressions   
        7) Syntax errors are reported along with their line number    
