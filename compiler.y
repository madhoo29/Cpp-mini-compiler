%{
    #include<stdio.h>
    #include<stdlib.h>
    #include "symboltable.c"

    int yylex();
    extern int yylineno;
    extern char* yytext;
    int scope = 0;
    int err;
    int type;
    int idx = 0;
    char* id;

void yyerror(const char *str)
{
    fprintf(stderr,"Error at line: %d %s %s\n",yylineno,str,yytext);
}



%}
%locations
%token T_MAIN T_WHILE T_IF T_ELSE T_INCLUDE T_HEADER T_SWITCH T_CASE T_PRINT
%token T_INT T_DOUBLE T_BOOL T_CHAR T_STRING T_VOID  STRING_TERMINATE
%token T_COUT T_CIN T_EXT T_INS T_BREAK T_DEFAULT
%token T_GE T_LE T_EQ T_NE T_OR T_AND T_NEWLINE
%token T_CHAR_VAL T_FLOAT_VAL T_INTEGER_VAL T_STRING_VAL IDENTIFIER
%token NOT_STRING

// %error-verbose


%right '='
%left T_LOGICAL_OR
%left T_LOGICAL_AND
%left T_EQ T_NOT_EQ
%left '<' '>' T_LS_EQ T_GR_EQ
%left '+' '-'
%left '*' '/' '%'
%right '!'


%token T_INC T_DEC
%token T_TRUE T_FALSE
%token T_RETURN T_CONST T_AUTO T_CLASS T_PRIVATE T_PUBLIC T_PROTECTED

%start BEGIN
%type <intval> T_INT T_STRING T_DOUBLE T_VOID T_BOOL T_CHAR 
%type <strval> T_FLOAT_VAL T_INTEGER_VAL T_CHAR_VAL T_STRING_VAL IDENTIFIER exp consttype Listvariables Arraytype Term Factor Literal
%type <intval> Type
// %type <strval> preproc

%union {int intval; char* strval;};
%%
 
BEGIN: preproc 
	;

preproc: T_INCLUDE  T_HEADER   preproc
      | T_INCLUDE  T_HEADER Functions
      ;
      
Functions : cf main ;

cf : cf Function_Dec
    | cf Class
    | cf Decleration
    |
            ;      

 /* BEGIN: T_INCLUDE T_HEADER  preproc 
        ;
preproc :main
    ; */

main: T_INT T_MAIN compound_stmt 
      | T_VOID T_MAIN compound_stmt 
      | 
      ;

statements:statements stmt
    |
    ;
    
stmt:compound_stmt
    |single_stmt
    ;

 /* The function body is covered in braces and has multiple statements. */
compound_stmt :'{' {scope++;enter_scope(scope); } statements '}'  {exit_scope(scope + 1); scope--;} 
    ;



 /* Grammar for what constitutes every individual statement */
single_stmt: While
    | Decleration
    | Switch
    | Assignment
    | Print
    | Return
    | Input
    | Output 
    | increment
    | decrement
    | T_BREAK ';'
    | Class
    | access
    | Function_call
    |';'
    ;

Class : T_CLASS IDENTIFIER compound_stmt ';'
    ;

access : T_PUBLIC ':'
    | T_PRIVATE ':'
    | T_PROTECTED ':'
    ;

Function_Dec : Type IDENTIFIER '(' Parameters ')' compound_stmt;

Parameters :  Type IDENTIFIER Parameters 
            |',' Parameters
            |
            ;

Function_call : IDENTIFIER '(' Arguments ')' ';'

Arguments : Arguments ',' exp
        | exp   
        ;

Print : T_PRINT '(' T_STRING_VAL ')' ';'
        
Decleration : Type IDENTIFIER '=' exp ';' { 
                                            err = lookup($2,scope, $1, @2.first_line); 
                                            if(!err) printf("Redeclaration error : %s has already been declared in this scope.\n",$2);
                                            else{
                                            err = check($2,scope,@2.first_line,$4);  
                                            if(!err) printf("Undefined error : %s has not been declared in this scope.\n",$2);
                                            }
                                            }  
        
        | Type Listvariables ';' {$1 = $2;}
        | ArrayDec 
        ;

ArrayDec : Type IDENTIFIER '[' exp ']' ';' { err = lookup_arr($2,scope, $1, @2.first_line, $4); 
                                            if(!err) printf("Redeclaration error : %s has already been declared in this scope.\n",$2);
                                           }
            | Type IDENTIFIER '[' exp ']' { err = lookup_arr($2,scope, $1, @2.first_line, $4); 
            
                                            if(!err) printf("Redeclaration error : %s has already been declared in this scope.\n",$2);
                                            id = $2;
                                            idx = 0;
                                            

                                           } '=' '{' ArrayObj '}' ';' 


ArrayObj : ArrayObj ',' Arraytype {check_arr(id,scope,@3.first_line,$3,idx++);  }
        | Arraytype  {check_arr(id,scope,@1.first_line,$1,idx++);  }
        | 
        ;

Arraytype : T_INTEGER_VAL 
    | T_CHAR_VAL 
    ;


Listvariables : Listvariables ',' IDENTIFIER {err = lookup($3,scope, type, @3.first_line);
                                                if(!err) printf("Redeclaration error : %s has already been declared in this scope.\n",$3);
                                                else{
                                                err = check($3,scope,@3.first_line,"0");
                                                if(!err) printf("Undefined error : %s has not been declared in this scope.\n",$3); }}
        | IDENTIFIER {
                        err = lookup($1,scope, type, @1.first_line);
                        if(!err) printf("Redeclaration error : %s has already been declared in this scope.\n",$1);
                        else{
                        err = check($1,scope,@1.first_line,"0");
                        if(!err) printf("Undefined error : %s has not been declared in this scope.\n",$1); }}
        ;
Assignment : IDENTIFIER '=' exp ';' {err = check($1,scope, @1.first_line, $3); 
                                    if(!err) printf("Undefined error : %s has not been declared in this scope.\n",$1);}
        | IDENTIFIER '[' T_INTEGER_VAL ']' '=' consttype ';' {err = check_arr($1,scope, @1.first_line, $6, atoi($3)); 
                                                if(!err) printf("Undefined error : %s has not been declared in this scope.\n",$1);}
        ;
        
Input : T_CIN T_INS IDENTIFIER ';'
        ;

Output : T_COUT T_EXT T_STRING_VAL ';'
        ;

exp : exp '+' Term {$$ = $1 + $3;}
    | exp '-' Term {$$ = $1 - $3;}
    | Term {$$ = $1;}
    ;

Term : Term '*' Factor {$$ = $1 * $3;}
    | Term '/' Factor {$$ = $1 / $3;}
    | Factor {$$ = $1;}
    ;
Factor : Literal {$$ = $1;}
    ;
Literal : IDENTIFIER  {err = check($1,scope,@1.first_line,"0"); if(!err) printf("Undefined error : %s has not been declared in this scope.\n",$1); $$ = $1;}
    | consttype  {$$ = $1;}
    ;

consttype : T_INTEGER_VAL 
	| T_FLOAT_VAL 
    | T_CHAR_VAL 
    | T_STRING_VAL 
    ;

Type : T_INT {$$ = 1; type = 1;}
	| T_DOUBLE {$$ = 2; type = 2;}
	| T_VOID {$$ = 3; type = 3;}
    | T_CHAR  {$$ = 4; type = 4;}
    | T_STRING {$$ = 5; type = 5;}
;

increment : IDENTIFIER T_INC ';' {check($1,scope, @1.first_line,0);}
    | T_INC IDENTIFIER ';' {check($2,scope, @2.first_line,0);}
    ;
decrement : IDENTIFIER T_DEC ';' {check($1,scope, @1.first_line,0);}
    | T_DEC IDENTIFIER {check($2,scope, @2.first_line,0);}
    ;



Return : T_RETURN IDENTIFIER ';'
    | T_RETURN consttype ';' 
    | T_RETURN ';' 
    ;


While : T_WHILE '(' check ')' compound_stmt 
	;
    
check : consttype 
    | IDENTIFIER
    | exp relop exp
    | T_TRUE
    | T_FALSE
    ;


relop : '<' | '>' | T_NE | T_EQ ; 


Switch : T_SWITCH '(' exp ')' '{' Cases '}' 
;

Cases : Case
    | Case Default
;

Case : C 
    | Case C 
;

C : T_CASE consttype ':' statements T_BREAK ';'
    ;


Default : T_DEFAULT ':' statements 
    ;


%%

int main(){
    init();
    yylloc.first_line=yylloc.last_line=1;
    yylloc.first_column=yylloc.last_column=0;
    yyparse();

    display();
}


int yywrap()
{
  return(1);
}




/*
break : T_BREAK ';'
    | 
    ;
C : T_CASE consttype ':' statements 
    | T_CASE consttype ':' ';' break 
    ;*/
/*
exp : '(' exp ')' {$$ = $2;}
	| exp '+' exp {}
	| exp '-' exp {}
	| exp '*' exp {}
	| exp '/' exp {}
    | IDENTIFIER {err = check($1,scope,@1.first_line,"0");
                        if(!err) printf("Undefined error : %s has not been declared in this scope.\n",$1); $$ = $1;}
    | consttype {$$ = $1;}
	;
*/
