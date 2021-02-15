%{
    #include<stdio.h>
    #include<stdlib.h>
    #include "symboltable.c"
// #define YYSTYPE char *
     int yylex();
    
    int scope = 0;

void yyerror(const char* s)
{
  printf( "%s\n",s);
  exit(1);
}

// typedef struct YYLTYPE
// {
//     int first_line;
//     int first_column;
//     int last_line;
//     int last_column;
//     char *filename; /* use to keep track of which file we're currently in */
//     int hel;    /* no errors = 0, warning = 1, error = 2, fatal = 3 */
// } YYLTYPE;

// # define YYLTYPE_IS_DECLARED 1

%}

%token T_MAIN T_WHILE T_IF T_ELSE T_INCLUDE T_HEADER T_SWITCH T_CASE T_PRINT
%token T_INT T_DOUBLE T_BOOL T_CHAR T_STRING T_VOID  
%token T_COUT T_CIN T_EXT T_INS T_BREAK T_DEFAULT
%token T_GE T_LE T_EQ T_NE T_OR T_AND T_NEWLINE
%token T_CHAR_VAL T_FLOAT_VAL T_INTEGER_VAL T_STRING_VAL IDENTIFIER

%error-verbose

%left ','
%left '+' '-'
%left '*' '/'
%left '<' '>'
%right '='

 /* ADD THESE */
%token T_INC T_DEC
%token T_TRUE T_FALSE
%token T_RETURN T_CONST T_AUTO

%start BEGIN
%type <intval> T_INT T_STRING T_DOUBLE T_VOID T_BOOL T_CHAR 
%type <strval> T_FLOAT_VAL T_INTEGER_VAL T_CHAR_VAL T_STRING_VAL IDENTIFIER
%type <intval> Type
// %type <strval> preproc

%union {int intval; char* strval;};
%%
 
BEGIN: preproc 
	;

preproc: T_INCLUDE '<' T_HEADER '>'  preproc
      | T_INCLUDE  "\"" T_HEADER "\""  preproc
      | main
      ;

main: T_INT T_MAIN CompoundStatement {printf("main\n");}
      | T_VOID T_MAIN CompoundStatement 
      | 
      ;

CompoundStatement : '{' {printf("opened\n");scope++; } Statements '}' {printf("closed\n");scope--; }  
       |
;

Statements : Statements Decleration 
        | CompoundStatement   
        | Statements While     {printf("while\n");}
        | Statements Assignment 
        | Statements Switch
        | ';'
        | Statements Return {printf("returned\n");}
        | Statements Print
        | Statements Output
        ;

S : S Decleration  
        | S While     {printf("while\n");}
        | S Assignment 
        | ';'
        | S Return {printf("returned\n");}
        | S Print {printf("called\n");}
        ;

Print : T_PRINT '(' T_STRING_VAL ')' ';'
        
Decleration : Type IDENTIFIER '=' exp ';' {printf("Decleration\n");}  
        | Type IDENTIFIER ';'  
        | Type IDENTIFIER '[' exp ']' ';'
        ;
Assignment : IDENTIFIER '=' exp ';' {printf("assignment\n");}
        | Input
        ;
Input : T_CIN ">>" IDENTIFIER ';'
        ;

Output : T_COUT "<<" T_STRING_VAL ';'
        ;
exp : '(' exp ')'
	| exp '+' exp
	| exp '-' exp
	| exp '*' exp
	| exp '/' exp
    | IDENTIFIER T_INC {check($1,scope, @1.first_line);}
    | IDENTIFIER T_DEC {check($1,scope, @1.first_line);}
    | T_INC IDENTIFIER {check($2,scope, @2.first_line);}
    | T_DEC IDENTIFIER {check($2,scope, @2.first_line);}
    | IDENTIFIER {check($1,scope, @1.first_line); printf("simple IDENTIFIER\n");}
    | consttype
	;

Type : T_INT {$$ = 1;}
	| T_DOUBLE {$$ = 2;}
	| T_VOID {$$ = 3;}
    | T_CHAR  {$$ = 4;}
    | T_STRING {$$ = 5;}
;

consttype : T_INTEGER_VAL 
	| T_FLOAT_VAL 
    | T_CHAR_VAL 
    | T_STRING_VAL 
;


Return : T_RETURN IDENTIFIER ';'
    | T_RETURN consttype ';' {printf("return\n");}
    | T_RETURN ';' 
    ;


While : T_WHILE '(' check ')' CompoundStatement
	;
    
check : consttype 
    | IDENTIFIER relop exp
    | T_TRUE
    | T_FALSE
    ;


relop : '<' | '>' | T_NE | T_EQ ; 

Switch : T_SWITCH '(' exp ')' '{' CaseLabel '}' {printf("switch\n");}
;

CaseLabel : Case
    | Case Default
    |
;
 
Case : C {printf("inside2\n");}
    | Case C {printf("inside\n");}
;

C : T_CASE consttype ':' S T_BREAK ';' {printf("case\n");}
    ;

Default : T_DEFAULT ':' S ';'
    ;


%%

 // #include "lex.yy.c"
int main(){
    yylloc.first_line=yylloc.last_line=1;
    yylloc.first_column=yylloc.last_column=0;
    yyparse();
    
}

int yywrap()
{
  return(1);
}