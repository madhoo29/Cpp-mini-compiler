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
    FILE * fp;
    char* id;
      int top=-1;
    void while1();
    void while2();
    void while3();
    void push_t();
    void codegen();
    void codegen_assign();
    void codegen_assigna();

      typedef struct quadruples
  {
    char *op;
    char *arg1;
    char *arg2;
    char *res;
  }quad;
  int quadlen = 0;
  quad q[100];

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

%define parse.error verbose
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

statements:statements stmt {$<structure.intval>$ = $<structure.intval>2; printf(" statements type %d\n",$<structure.intval>$) ;}
    |
    ;
    
stmt:compound_stmt {$<structure.intval>$ = $<structure.intval>1; printf(" cmpd stmt type %d\n",$<structure.intval>$) ;}
    |single_stmt {$<structure.intval>$ = $<structure.intval>1; printf(" single stmt type %d\n",$<structure.intval>$) ;}
    ;

 /* The function body is covered in braces and has multiple statements. */
compound_stmt :'{' {scope++;enter_scope(scope); } statements   '}'  {exit_scope(scope + 1); scope--;}  {$<structure.intval>$ = $<structure.intval>3;printf("The compound statemetn in funcdef %d\n",$<structure.intval>$) ;}
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

Function_Dec : Type IDENTIFIER '(' Parameters ')' compound_stmt  {int t1 = $<structure.intval>1;
                                                                  int t2 = $<structure.intval>6;
                                                                  printf("t1 : %d \n t2: %d\n",t1,t2);
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
Assignment : IDENTIFIER {push_t();} '=' {push_t();} exp ';' { codegen_assign(); 
                                    err = check($<structure.strval>1,scope, @1.first_line, $<structure.strval>3); 
                                    if(!err) printf("Undefined error : %s has not been declared in this scope.\n",$<structure.strval>1);}
        | IDENTIFIER '[' T_INTEGER_VAL ']' '=' consttype ';' {err = check_arr($<structure.strval>1,scope, @1.first_line, $<structure.strval>6, atoi($<structure.strval>3)); 
                                                if(!err) printf("Undefined error : %s has not been declared in this scope.\n",$<structure.strval>1);}
        ;
        
Input : T_CIN T_INS IDENTIFIER ';'
        ;

Output : T_COUT T_EXT T_STRING_VAL ';'
        ;

exp : exp '+' {push_t();} Term { codegen(); 
                     int t1 = $<structure.intval>1;
                     int t2 = $<structure.intval>3;
                     if(((t1 == 1) || (t1 == 2) || (t1 == 4)) && ((t2 != 1) || (t2 != 2) || (t2 != 4)))
                         printf("type mismatch\n");
                     if(((t1 != 1) || (t1 != 2) || (t1 != 4)) && ((t2 == 1) || (t2 == 2) || (t2 == 5)))
                         printf("type mismatch\n");                         
                    }
    | exp '-' {push_t();} Term { codegen();  }
    | Term 
    ;

Term : Term '*' {push_t();} Factor { codegen();  }
    | Term '/' {push_t();} Factor  { codegen();  }
    | Factor 
    ;
Factor : Literal 
    ;
Literal : IDENTIFIER  {push_t(); err = check($<structure.strval>1,scope,@1.first_line,"0"); if(!err) printf("Undefined error : %s has not been declared in this scope.\n",$<structure.strval>1); $<structure.strval>$ = $<structure.strval>1;}
    | consttype  {push_t();}
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


While : T_WHILE {while1();} '(' check ')' {while2();} compound_stmt {while3();}
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
#include<ctype.h>
char st[100][100];

char i_[2]="0";
int temp_i=0;
char tmp_i[3];
char temp[2]="t";
int label[20];
int lnum=0;
int ltop=0;
int abcd=0;
int l_while=0;
int l_for=0;
int flag_set = 1;

int main(){
    init();
    fp = fopen("ICG.txt","w");
    
    
    if(!yyparse())  //yyparse-> 0 if success
    {
        printf("Parsing Complete\n");
        printf("---------------------Quadruples-------------------------\n\n");
        printf("Operator \t Arg1 \t\t Arg2 \t\t Result \n");
        int i;
        for(i=0;i<quadlen;i++)
        {
            printf("%-8s \t %-8s \t %-8s \t %-6s \n",q[i].op,q[i].arg1,q[i].arg2,q[i].res);
        }
    }
    
    display();
}


int yywrap()
{
  return(1);
}





void while1()
{

    l_while = lnum;
    printf("L%d: \n",lnum++);
    fprintf(fp, "L%d :\n",lnum++);
    q[quadlen].op = (char*)malloc(sizeof(char)*6);
    q[quadlen].arg1 = NULL;
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*(lnum+2));
    strcpy(q[quadlen].op,"Label");
    char x[10];
    sprintf(x,"%d",lnum-1);
    char l[]="L";
    strcpy(q[quadlen].res,strcat(l,x));
    quadlen++;
}

void while2()
{
 strcpy(temp,"T");
 sprintf(tmp_i, "%d", temp_i);
 strcat(temp,tmp_i);
 printf("%s = not %s\n",temp,st[top]);
    q[quadlen].op = (char*)malloc(sizeof(char)*4);
    q[quadlen].arg1 = (char*)malloc(sizeof(char)*strlen(st[top]));
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*strlen(temp));
    strcpy(q[quadlen].op,"not");
    strcpy(q[quadlen].arg1,st[top]);
    strcpy(q[quadlen].res,temp);
    quadlen++;
    printf("if %s goto L%d\n",temp,lnum);
    fprintf(fp, "if %s = goto L%d\n",temp,lnum);

    q[quadlen].op = (char*)malloc(sizeof(char)*3);
    q[quadlen].arg1 = (char*)malloc(sizeof(char)*strlen(temp));
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*(lnum+2));
    strcpy(q[quadlen].op,"if");
    strcpy(q[quadlen].arg1,temp);
    char x[10];
    sprintf(x,"%d",lnum);char l[]="L";
    strcpy(q[quadlen].res,strcat(l,x));
    quadlen++;

 temp_i++;
 }

void while3()
{

printf("goto L%d \n",l_while);
fprintf(fp,"goto L%d\n",l_while);
q[quadlen].op = (char*)malloc(sizeof(char)*5);
    q[quadlen].arg1 = NULL;
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*(l_while+2));
    strcpy(q[quadlen].op,"goto");
    char x[10];
    sprintf(x,"%d",l_while);
    char l[]="L";
    strcpy(q[quadlen].res,strcat(l,x));
    quadlen++;
    printf("L%d: \n",lnum++);
    fprintf(fp,"L%d: \n",lnum++);
    q[quadlen].op = (char*)malloc(sizeof(char)*6);
    q[quadlen].arg1 = NULL;
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*(lnum+2));
    strcpy(q[quadlen].op,"Label");
    char x1[10];
    sprintf(x1,"%d",lnum-1);
    char l1[]="L";
    strcpy(q[quadlen].res,strcat(l1,x1));
    quadlen++;
}

void codegen()
{
    strcpy(temp,"T");
    sprintf(tmp_i, "%d", temp_i);
    strcat(temp,tmp_i);
    printf("%s = %s %s %s\n",temp,st[top-2],st[top-1],st[top]);
    fprintf(fp,"%s = %s %s %s\n",temp,st[top-2],st[top-1],st[top]);
    q[quadlen].op = (char*)malloc(sizeof(char)*strlen(st[top-1]));
    q[quadlen].arg1 = (char*)malloc(sizeof(char)*strlen(st[top-2]));
    q[quadlen].arg2 = (char*)malloc(sizeof(char)*strlen(st[top]));
    q[quadlen].res = (char*)malloc(sizeof(char)*strlen(temp));
    strcpy(q[quadlen].op,st[top-1]);
    strcpy(q[quadlen].arg1,st[top-2]);
    strcpy(q[quadlen].arg2,st[top]);
    strcpy(q[quadlen].res,temp);
    quadlen++;
    top-=2;
    strcpy(st[top],temp);

temp_i++;
}

void push_t()
{
    strcpy(st[++top],yytext);
}

void codegen_assigna()
{
strcpy(temp,"T");
sprintf(tmp_i, "%d", temp_i);
strcat(temp,tmp_i);
printf("%s = %s %s %s %s\n",temp,st[top-3],st[top-2],st[top-1],st[top]);
fprintf(fp,"%s = %s %s %s %s\n",temp,st[top-3],st[top-2],st[top-1],st[top]);
//printf("%d\n",strlen(st[top]));
if(strlen(st[top])==1)
{
	//printf("hello");
	
    char t[20];
	//printf("hello");
	strcpy(t,st[top-2]);
	strcat(t,st[top-1]);
	q[quadlen].op = (char*)malloc(sizeof(char)*strlen(t));
    q[quadlen].arg1 = (char*)malloc(sizeof(char)*strlen(st[top-3]));
    q[quadlen].arg2 = (char*)malloc(sizeof(char)*strlen(st[top]));
    q[quadlen].res = (char*)malloc(sizeof(char)*strlen(temp));
    strcpy(q[quadlen].op,t);
    strcpy(q[quadlen].arg1,st[top-3]);
    strcpy(q[quadlen].arg2,st[top]);
    strcpy(q[quadlen].res,temp);
    quadlen++;
    
}
else
{
	q[quadlen].op = (char*)malloc(sizeof(char)*strlen(st[top-2]));
    q[quadlen].arg1 = (char*)malloc(sizeof(char)*strlen(st[top-3]));
    q[quadlen].arg2 = (char*)malloc(sizeof(char)*strlen(st[top-1]));
    q[quadlen].res = (char*)malloc(sizeof(char)*strlen(temp));
    strcpy(q[quadlen].op,st[top-2]);
    strcpy(q[quadlen].arg1,st[top-3]);
    strcpy(q[quadlen].arg2,st[top-1]);
    strcpy(q[quadlen].res,temp);
    quadlen++;
}
top-=4;

temp_i++;
strcpy(st[++top],temp);
}

void codegen_assign()
{
    printf("%s = %s\n",st[top-3],st[top]);
    fprintf(fp, "%s = %s",st[top-3],st[top]);
    q[quadlen].op = (char*)malloc(sizeof(char));
    q[quadlen].arg1 = (char*)malloc(sizeof(char)*strlen(st[top]));
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*strlen(st[top-3]));
    strcpy(q[quadlen].op,"=");
    strcpy(q[quadlen].arg1,st[top]);
    strcpy(q[quadlen].res,st[top-3]);
    quadlen++;
    top-=2;
}

