%{
    #include<stdio.h>
    #include<stdlib.h>
    #include "symboltable.c"
    int yylex();
    int scope = 0;

void yyerror(const char *str)
{
    extern int yylineno;
    fprintf(stderr,"Error | Line: %d\n%s\n",yylineno,str);
}


#define YY_USER_ACTION yylloc.first_line = yylloc.last_line = yylineno;

%}
%locations
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

%token T_INC T_DEC
%token T_TRUE T_FALSE
%token T_RETURN T_CONST T_AUTO

%start BEGIN
%type <intval> T_INT T_STRING T_DOUBLE T_VOID T_BOOL T_CHAR 
%type <strval> T_FLOAT_VAL T_INTEGER_VAL T_CHAR_VAL T_STRING_VAL IDENTIFIER
%type <intval> Type

%union {int intval; char* strval;};

%%
 
BEGIN: preproc 
	;

preproc: T_INCLUDE '<' T_HEADER '>'  preproc {printf("is defined at line %d\n",  @$.first_line);}
      | T_INCLUDE  "\"" T_HEADER "\""  preproc
      | main
      ;

main: T_INT T_MAIN CompoundStatement 
      | T_VOID T_MAIN CompoundStatement 
      | 
      ;

CompoundStatement : '{' {scope++; } Statements '}' {printf("closed\n");scope--; }  
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
        | Statements increment
        | Statements decrement
        ;

// just ; inside case doesn't work
S : Decleration S 
        | While S     {printf("while\n");}
        | Assignment S
        | Return  S{printf("returned\n");}
        | Print S{printf("called\n");}
        | Switch S {printf("second\n");}
        |
        ;

Print : T_PRINT '(' T_STRING_VAL ')' ';' {printf("%s",T_STRING_VAL);}

        
Decleration : Type IDENTIFIER '=' exp ';' {lookup($2,scope, $1, @2.first_line); check($2,scope,@2.first_line); printf("Decleration\n");}  
        | Type Listvariables ';' {printf("line number%d",@1.first_line);}
        | ArrayDec 
        ;

ArrayDec : Type IDENTIFIER '[' exp ']' ';'
            | Type IDENTIFIER '[' exp ']' '=' '{' ArrayObj '}' ';'

ArrayObj : consttype 
        |ArrayObj ',' consttype
        | 
        ;

Listvariables : Listvariables ',' IDENTIFIER 
        | IDENTIFIER 
        ;
Assignment : IDENTIFIER '=' exp ';' {check($1,scope, @1.first_line); printf("assignment\n");}
        | IDENTIFIER '[' T_INTEGER_VAL ']' '=' consttype ';' {check($1,scope, @1.first_line); printf("assignment\n");}
        | Input
        ;
        
Input : T_CIN T_INS IDENTIFIER ';' 
        ;

Output : T_COUT T_EXT T_STRING_VAL ';'
        ;

exp : exp '+' TERM
    | exp '-' TERM
    | TERM
    ;
TERM : TERM '*' FACTOR
    | TERM '/' FACTOR
    | FACTOR
    ;
FACTOR : Literal
    | Literal T_INC
    | Literal T_DEC
    ;
Literal : IDENTIFIER
    | NUMBER
    ;

NUMBER : T_INTEGER_VAL
        | T_FLOAT_VAL
        ;

consttype: T_INTEGER_VAL 
	| T_FLOAT_VAL 
    | T_CHAR_VAL 
    | T_STRING_VAL 
;


increment : IDENTIFIER T_INC ';' {check($1,scope, @1.first_line);}
    | T_INC IDENTIFIER ';' {check($2,scope, @2.first_line);}
    ;
decrement : IDENTIFIER T_DEC ';' {check($1,scope, @1.first_line);}
    | T_DEC IDENTIFIER {check($2,scope, @2.first_line);}
    ;

Type : T_INT {$$ = 1;}
	| T_DOUBLE {$$ = 2;}
	| T_VOID {$$ = 3;}
    | T_CHAR  {$$ = 4;}
    | T_STRING {$$ = 5;}
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


Switch : T_SWITCH '(' exp ')' '{' Cases '}' {printf("switch\n");}
;

Cases : Case
    | Case Default
;

Case : C {printf("inside2\n");}
    | Case C {printf("inside\n");}
;

break : T_BREAK ';'
    | 
    ;
C : T_CASE consttype ':' S break {printf("case\n");}
    | T_CASE consttype ':' ';' break {printf("case\n");}
    ;

Default : T_DEFAULT ':' S ';'
    ;

%%

int main(){
    // init();
    yylloc.first_line=yylloc.last_line=1;
    yylloc.first_column=yylloc.last_column=0;
    yyparse();
    
}

int yywrap()
{
  return(1);
}



                    /*Statements : Statements Decleration 
                            | CompoundStatement   
                            | Statements While     {printf("while\n");}
                            | Statements Assignment 
                            | Statements Switch
                            | ';'
                            | Statements Return {printf("returned\n");}
                            | Statements Print
                            | Statements Output
                            | Statements Input
                            | Statements increment
                            | Statements decrement
                            ;

                    // just ; inside case doesn't work
                    S : Decleration S 
                            | While S     {printf("while\n");}
                            | Assignment S
                            | Return  S{printf("returned\n");}
                            | Print S{printf("called\n");}
                            | Switch S {printf("second\n");}
                            |
                            ;


                    Print : T_PRINT '(' T_STRING_VAL ')' ';'
                            
                    Decleration : Type IDENTIFIER '=' exp ';' {lookup($2,scope, $1, @2.first_line); check($2,scope,@2.first_line);}  
                            | Type IDENTIFIER ';' {lookup($2,scope, $1, @2.first_line);} 
                            | Type IDENTIFIER '[' exp ']' ';'
                            
                            ;
                    Assignment : IDENTIFIER '=' exp ';' {check($1,scope, @1.first_line); printf("assignment\n");}
                            ;
                    Assignment : IDENTIFIER '=' exp ';' {check($1,scope, @1.first_line); printf("assignment\n");}
                            | Input
                            ;
                            
                    Input : T_CIN T_INS IDENTIFIER ';'
                            ;

                    Output : T_COUT T_EXT T_STRING_VAL ';'

                    exp : '(' exp ')'
                        | exp '+' exp
                        | exp '-' exp
                        | exp '*' exp
                        | exp '/' exp
                        | IDENTIFIER T_INC {check($1,scope, @1.first_line);}
                        | IDENTIFIER T_DEC {check($1,scope, @1.first_line);}
                        | T_INC IDENTIFIER {check($2,scope, @2.first_line);}
                        | T_DEC IDENTIFIER {check($2,scope, @2.first_line);}
                        | IDENTIFIER {check($1,scope, @1.first_line); printf("hi\n");}
                        | consttype
                         /*exp : '(' exp ')'
	| exp '+' exp
	| exp '-' exp
	| exp '*' exp
	| exp '/' exp
    | IDENTIFIER {check($1,scope, @1.first_line);}
    | consttype
	;*/