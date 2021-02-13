%
{
    void yyerror(char *s);
    #include<stdio.h>
    #include<stdlib.h>

}

%union {int INT; char* STR; float FLOAT; char CHAR;}
%start 
%token <INT> ICONST
%token <FLOAT> FCONST
%token <CHAR> CCONST
%token <STR> IDENTIFIER
%token <STR> STRING

