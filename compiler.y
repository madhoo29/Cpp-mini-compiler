%{
    #include<stdio.h>
    #include<stdlib.h>
    #include "symboltable.c"

    int yylex();
    extern int yylineno;
    int scope = 0;
    int err;
    int type;

void yyerror(const char *str)
{
    fprintf(stderr,"Error at line: %d %s\n",yylineno,str);
}



%}
%locations
%token T_MAIN T_WHILE T_IF T_ELSE T_INCLUDE T_HEADER T_SWITCH T_CASE T_PRINT
%token T_INT T_DOUBLE T_BOOL T_CHAR T_STRING T_VOID  
%token T_COUT T_CIN T_EXT T_INS T_BREAK T_DEFAULT
%token T_GE T_LE T_EQ T_NE T_OR T_AND T_NEWLINE
%token T_CHAR_VAL T_FLOAT_VAL T_INTEGER_VAL T_STRING_VAL IDENTIFIER

%error-verbose


%right '='
%left T_LOGICAL_OR
%left T_LOGICAL_AND
%left T_EQ T_NOT_EQ
%left '<' '>' T_LS_EQ T_GR_EQ
%left '+' '-'
%left '*' '/' '%'
%right '!'

 /* ADD THESE */
%token T_INC T_DEC
%token T_TRUE T_FALSE
%token T_RETURN T_CONST T_AUTO

%start BEGIN
%type <intval> T_INT T_STRING T_DOUBLE T_VOID T_BOOL T_CHAR 
%type <strval> T_FLOAT_VAL T_INTEGER_VAL T_CHAR_VAL T_STRING_VAL IDENTIFIER exp consttype Listvariables
%type <intval> Type
// %type <strval> preproc

%union {int intval; char* strval;};
%%
 
BEGIN: preproc 
	;

 /*preproc: T_INCLUDE '<' T_HEADER '>'  preproc
      | T_INCLUDE  "\"" T_HEADER "\""  preproc
      | main
      ;*/
preproc: T_INCLUDE  T_HEADER   preproc
      | main
      ;

main: T_INT T_MAIN compound_stmt 
      | T_VOID T_MAIN compound_stmt 
      | 
      ;
stmt:compound_stmt
    |single_stmt
    ;

 /* The function body is covered in braces and has multiple statements. */
compound_stmt :'{' {scope++;enter_scope(scope); } statements '}'  {exit_scope(scope + 1); scope--;} 
    ;

statements:statements stmt
    |
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
    ;



// just ; inside case doesn't work
S : Decleration S 
        | While S    
        | Assignment S
        | Return  S
        | Print S
        | Switch S 
        | T_BREAK ';' S
        |
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
        
        | Type Listvariables ';'
        | ArrayDec 
        ;

ArrayDec : Type IDENTIFIER '[' exp ']' ';'
            | Type IDENTIFIER '[' exp ']' '=' '{' ArrayObj '}' ';'

ArrayObj : consttype 
        |ArrayObj ',' consttype
        | 
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
Assignment : IDENTIFIER '=' exp ';' {check($1,scope, @1.first_line, $3); }
        | IDENTIFIER '[' T_INTEGER_VAL ']' '=' consttype ';' {check($1,scope, @1.first_line, $6); }
        ;
        
Input : T_CIN T_INS IDENTIFIER ';'
        ;

Output : T_COUT T_EXT T_STRING_VAL ';'
        ;

exp : '(' exp ')' {$$ = $2;}
	| exp '+' exp {}
	| exp '-' exp {}
	| exp '*' exp {}
	| exp '/' exp {}
    | IDENTIFIER {check($1,scope, @1.first_line,"hi"); $$ = $1;}
    | consttype {$$ = $1;}
	;

increment : IDENTIFIER T_INC ';' {check($1,scope, @1.first_line,0);}
    | T_INC IDENTIFIER ';' {check($2,scope, @2.first_line,0);}
    ;
decrement : IDENTIFIER T_DEC ';' {check($1,scope, @1.first_line,0);}
    | T_DEC IDENTIFIER {check($2,scope, @2.first_line,0);}
    ;

Type : T_INT {$$ = 1; type = 1;}
	| T_DOUBLE {$$ = 2; type = 2;}
	| T_VOID {$$ = 3; type = 3;}
    | T_CHAR  {$$ = 4; type = 4;}
    | T_STRING {$$ = 5; type = 5;}
;

consttype : T_INTEGER_VAL 
	| T_FLOAT_VAL 
    | T_CHAR_VAL 
    | T_STRING_VAL 
;


Return : T_RETURN IDENTIFIER ';'
    | T_RETURN consttype ';' 
    | T_RETURN ';' 
    ;


While : T_WHILE '(' check ')' compound_stmt 
	;
    
check : consttype 
    | IDENTIFIER relop exp 
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

break : T_BREAK ';'
    | 
    ;
C : T_CASE consttype ':' S 
    | T_CASE consttype ':' ';' break 
    ;

Default : T_DEFAULT ':' S 
    ;


%%

int main(){
    init();
    yylloc.first_line=yylloc.last_line=1;
    yylloc.first_column=yylloc.last_column=0;
    yyparse();
    
}




int yywrap()
{
  return(1);
}