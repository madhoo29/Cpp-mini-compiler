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
// %type <intval> T_FLOAT_VAL T_INTEGER_VAL T_CHAR_VAL T_STRING_VAL IDENTIFIER exp consttype Listvariables Arraytype Term Factor Literal
%type <intval> Type

%union {  
  struct {
     char* strval;
     int  intval;
  } structure;
}

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
    
stmt:compound_stmt {$<structure.intval>$ = $<structure.intval>1; printf(" cmpd stmt type %d\n",$<structure.intval>$) ;}
    |single_stmt {$<structure.intval>$ = $<structure.intval>1; printf(" single stmt type %d\n",$<structure.intval>$) ;}
    ;

 /* The function body is covered in braces and has multiple statements. */
compound_stmt :'{' {scope++;enter_scope(scope); } statements {$<structure.intval>$ = $<structure.intval>1; printf("function return type %d\n",$<structure.intval>$) ;} '}'  {exit_scope(scope + 1); scope--;} 
    ;



 /* Grammar for what constitutes every individual statement */
single_stmt: While
    | Decleration
    | Switch
    | Assignment
    | Print
    | Return {$<structure.intval>$ = $<structure.intval>1; printf("return type %d\n",$<structure.intval>$) ;}
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

Function_Dec : Type IDENTIFIER '(' Parameters ')' compound_stmt ';' {int t1 = $<structure.intval>1;
                                                                  int t2 = $<structure.intval>6;
                                                                  if (t1!=t2)
                                                                 printf("return type does not match function");}

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
                                            err = lookup($<structure.strval>2,scope, $<structure.intval>1, @2.first_line); 
                                            if(!err) printf("Redeclaration error : %s has already been declared in this scope.\n",$<structure.strval>2);
                                            else{
                                            err = check($<structure.strval>2,scope,@2.first_line,$<structure.strval>4);  
                                            if(!err) printf("Undefined error : %s has not been declared in this scope.\n",$<structure.strval>2);
                                            }
                                            }  
        
        | Type Listvariables ';' 
        | ArrayDec 
        ;

ArrayDec : Type IDENTIFIER '[' exp ']' ';' { err = lookup_arr($<structure.strval>2,scope, $<structure.intval>1, @2.first_line, $<structure.strval>4); 
                                            if(!err) printf("Redeclaration error : %s has already been declared in this scope.\n",$<structure.strval>2);
                                           }
            | Type IDENTIFIER '[' exp ']' { err = lookup_arr($<structure.strval>2,scope, $<structure.intval>1, @2.first_line, $<structure.strval>4); 
            
                                            if(!err) printf("Redeclaration error : %s has already been declared in this scope.\n",$<structure.strval>2);
                                            id = $<structure.strval>2;
                                            idx = 0;
                                            

                                           } '=' '{' ArrayObj '}' ';' 


ArrayObj : ArrayObj ',' Arraytype {check_arr(id,scope,@3.first_line,$<structure.strval>3,idx++);  }
        | Arraytype  {check_arr(id,scope,@1.first_line,$<structure.strval>1,idx++);  }
        | 
        ;

Arraytype : T_INTEGER_VAL 
    | T_CHAR_VAL 
    ;


Listvariables : Listvariables ',' IDENTIFIER {
												err = lookup($<structure.strval>3,scope, type, @3.first_line);
                                                if(!err) printf("Redeclaration error : %s has already been declared in this scope.\n",$<structure.strval>3);
                                                else{
                                                err = check($<structure.strval>3,scope,@3.first_line,"0");
                                                if(!err) printf("Undefined error : %s has not been declared in this scope.\n",$<structure.strval>3); }}
        | IDENTIFIER {
			            
                        err = lookup($<structure.strval>1,scope, type, @1.first_line);
                        if(!err) printf("Redeclaration error : %s has already been declared in this scope.\n",$<structure.strval>1);
                        else{
                        err = check($<structure.strval>1,scope,@1.first_line,"0");
                        if(!err) printf("Undefined error : %s has not been declared in this scope.\n",$<structure.strval>1); }}
        ;
Assignment : IDENTIFIER '=' exp ';' {err = check($<structure.strval>1,scope, @1.first_line, $<structure.strval>3); 
                                    if(!err) printf("Undefined error : %s has not been declared in this scope.\n",$<structure.strval>1);}
        | IDENTIFIER '[' T_INTEGER_VAL ']' '=' consttype ';' {err = check_arr($<structure.strval>1,scope, @1.first_line, $<structure.strval>6, atoi($<structure.strval>3)); 
                                                if(!err) printf("Undefined error : %s has not been declared in this scope.\n",$<structure.strval>1);}
        ;
        
Input : T_CIN T_INS IDENTIFIER ';'
        ;

Output : T_COUT T_EXT T_STRING_VAL ';'
        ;

exp : exp '+' Term { int t1 = $<structure.intval>1;
                     int t2 = $<structure.intval>3;
                     if(((t1 == 1) || (t1 == 2) || (t1 == 4)) && ((t2 != 1) || (t2 != 2) || (t2 != 4)))
                         printf("type mismatch\n");
                     if(((t1 != 1) || (t1 != 2) || (t1 != 4)) && ((t2 == 1) || (t2 == 2) || (t2 == 5)))
                         printf("type mismatch\n");                         
                    }
    | exp '-' Term {  }
    | Term 
    ;

Term : Term '*' Factor 
    | Term '/' Factor 
    | Factor 
    ;
Factor : Literal 
    ;
Literal : IDENTIFIER  {err = check($<structure.strval>1,scope,@1.first_line,"0"); if(!err) printf("Undefined error : %s has not been declared in this scope.\n",$<structure.strval>1); $<structure.strval>$ = $<structure.strval>1;}
    | consttype  
    ;

consttype : T_INTEGER_VAL 
	| T_FLOAT_VAL 
    | T_CHAR_VAL 
    | T_STRING_VAL 
    ;
    
Type : T_INT {printf("Declared type %d\n",$<structure.intval>$); }
	| T_DOUBLE
	| T_VOID 
    | T_CHAR 
    | T_STRING 
    ;

increment : IDENTIFIER T_INC ';' {check($<structure.strval>1,scope, @1.first_line,0);}
    | T_INC IDENTIFIER ';' {check($<structure.strval>2,scope, @2.first_line,0);}
    ;
decrement : IDENTIFIER T_DEC ';' {check($<structure.strval>1,scope, @1.first_line,0);}
    | T_DEC IDENTIFIER {check($<structure.strval>2,scope, @2.first_line,0);}
    ;

Return : T_RETURN IDENTIFIER ';' {$<structure.intval>$ = $<structure.intval>2;}
    | T_RETURN consttype ';' {$<structure.intval>$ = $<structure.intval>2;}
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
    // yylloc.first_line=yylloc.last_line=1;
    // yylloc.first_column=yylloc.last_column=0;
    yyparse();
    
    display();
}


int yywrap()
{
  return(1);
}

// int main() {

//      ptr = fopen("tokens.txt","w");
     
//      yylex();

//      fclose(ptr);
     
//      return 0;
// }
