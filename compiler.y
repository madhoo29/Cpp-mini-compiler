%{
    #include<stdio.h>
    #include<stdlib.h>
    #include<string.h>
    #include "symboltable.c"

    int yylex();
    extern int yylineno;
    extern char* yytext;
    int scope = 0;
    int err;
    int type;
    int idx = 0;
    FILE * fp;
    FILE * qptr;
    char* id;
    int top=-1;
    int top2 = -1;
    void while1();
    void while2();
    void while3();
    void switch1();
    void test();
    void next();
    void casestart();
    void caseend();
    void push_t();
    void push_op(char*);
    void codegen();
    void codegen_assign();
    void codegen_assigna();
    void arg1();
    void funcall();
    void fun1();
    void fun2();
    int num_cases = 0;
    char cases[20];
    int arg_count = 0;

    typedef struct quadruples
    {
        char* op;
        sym* arg1;
        sym* arg2;
        sym* res;
    } quad;

    int quadlen = 0;
    quad q[100];
    sym* case_var;
 
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

//%define parse.error verbose
%error-verbose

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

statements:statements stmt {$<structure.intval>$ = $<structure.intval>2;}
    |
    ;
    
stmt:compound_stmt {$<structure.intval>$ = $<structure.intval>1;}
    |single_stmt {$<structure.intval>$ = $<structure.intval>1; }
    ;

 /* The function body is covered in braces and has multiple statements. */
compound_stmt : '{' {scope++;enter_scope(scope); } statements   '}'  {exit_scope(scope + 1); scope--;}  {$<structure.intval>$ = $<structure.intval>3;}
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

Function_Dec : Type IDENTIFIER {
                err = lookup($<structure.strval>2, scope, $<structure.intval>1, @2.first_line); 
                if(!err) printf("Redeclaration error : %s has already been declared in this scope.\n",$<structure.strval>2);
                push_t();
                fun1();
                }

                '(' Parameters ')' compound_stmt  {int t1 = $<structure.intval>1;
                                                                  int t2 = $<structure.intval>6;
                                                                  if (t1!=t2)
                                                                 printf("return type does not match function");
                                                                 fun2();
                                                                 }
            ;

Parameters :  Type IDENTIFIER Parameters 
            |',' Parameters
            |
            ;

Function_call : IDENTIFIER { err = check($<structure.strval>1,scope,@1.first_line,"0"); 
                        if(!err){
                            printf("Undefined error : %s has not been declared in this scope.\n",$<structure.strval>1); 
                        }
                        else
                            push_t();}
                        '(' Arguments {if(arg_count == 1) arg1();} ')' ';'  {if(err) funcall();}

Arguments : Arguments ',' exp {arg_count++; arg1();}
        | exp   {arg_count++;}
        |
        ;

Print : T_PRINT '(' T_STRING_VAL ')' ';'
        
Decleration : Type IDENTIFIER '=' {push_op("=");} exp ';' { 
                                            if($<structure.intval>1 != $<structure.intval>5)
                                                printf("Error at line: %d WARNING : Type mismatch\n",@1.first_line);
                                            err = lookup($<structure.strval>2,scope, $<structure.intval>1, @2.first_line); 
                                            if(!err) printf("Redeclaration error : %s has already been declared in this scope.\n",$<structure.strval>2);
                                            else{
                                            
                                            err = check($<structure.strval>2,scope,@2.first_line,$<structure.strval>5);  
                                            if(!err) printf("Undefined error : %s has not been declared in this scope.\n",$<structure.strval>2);
                                            }
                                            push_t();
                                            codegen_assign(); 
                                            }  
        
        | Type Listvariables ';' 
        | ArrayDec 
        ;

ArrayDec : Type IDENTIFIER '[' exp ']' ';' { 

                                            err = lookup_arr($<structure.strval>2,scope, $<structure.intval>1, @2.first_line, $<structure.strval>4); 
                                            if(!err) printf("Redeclaration error : %s has already been declared in this scope.\n",$<structure.strval>2);
                                           }
            | Type IDENTIFIER '[' exp ']' { err = lookup_arr($<structure.strval>2,scope, $<structure.intval>1, @2.first_line, $<structure.strval>4); 
            
                                            if(!err) printf("Redeclaration error : %s has already been declared in this scope.\n",$<structure.strval>2);
                                            id = $<structure.strval>2;
                                            idx = 0;
                                            

                                           } '=' '{' ArrayObj '}' ';' {
                                                if($<structure.intval>1 != $<structure.intval>9)
                                                printf("Error at line: %d WARNING : Type mismatch\n",@1.first_line); }


ArrayObj : ArrayObj ',' Arraytype {check_arr(id,scope,@3.first_line,$<structure.strval>3,idx++);   }
        | Arraytype  {check_arr(id,scope,@1.first_line,$<structure.strval>1,idx++);  }
        | 
        ;

Arraytype : T_INTEGER_VAL 
    | T_CHAR_VAL 
    ;


Listvariables : Listvariables ',' IDENTIFIER {  err = lookup($<structure.strval>3,scope, type, @3.first_line);
                                                if(!err) printf("Redeclaration error : %s has already been declared in this scope.\n",$<structure.strval>3);
                                                else{
                                                err = check($<structure.strval>3,scope,@3.first_line,"0");
                                                if(!err) printf("Undefined error : %s has not been declared in this scope.\n",$<structure.strval>3); }
                                            }
        | IDENTIFIER {
                        err = lookup($<structure.strval>1,scope, type, @1.first_line);
                        if(!err) printf("Redeclaration error : %s has already been declared in this scope.\n",$<structure.strval>1);
                        else{
                        err = check($<structure.strval>1,scope,@1.first_line,"0");
                        if(!err) printf("Undefined error : %s has not been declared in this scope.\n",$<structure.strval>1); }
}
        ;
Assignment : IDENTIFIER '=' {push_op("=");} exp ';' { 
                                    if($<structure.intval>1 != $<structure.intval>4)
                                        printf("Error at line: %d WARNING : Type mismatch\n",@1.first_line);
                                    err = check($<structure.strval>1,scope, @1.first_line, "0"); 
                                    if(!err) printf("Undefined error : %s has not been declared in this scope.\n",$<structure.strval>1);
                                    push_t();
                                    codegen_assign(); 
}
        | IDENTIFIER '[' T_INTEGER_VAL ']' '=' consttype ';' {err = check_arr($<structure.strval>1,scope, @1.first_line, $<structure.strval>6, atoi($<structure.strval>3)); 
                                                if(!err) printf("Undefined error : %s has not been declared in this scope.\n",$<structure.strval>1);
}
        ;
        
Input : T_CIN T_INS IDENTIFIER ';'
        ;

Output : T_COUT T_EXT T_STRING_VAL ';'
        ;

exp : exp {if(link->arr != NULL) yyerror("Invalid operation on given data type\n"); } '+' {push_op("+");} Term { 
                    codegen(); 
                    int t1 = $<structure.intval>1;
                    int t2 = $<structure.intval>5;
                    if(((t1 == 1) || (t1 == 2) || (t1 == 4)) && ((t2 != 1) || (t2 != 2) || (t2 != 4)))
                    yyerror("Type mismatch\n");
                    if(((t1 != 1) || (t1 != 2) || (t1 != 4)) && ((t2 == 1) || (t2 == 2) || (t2 == 5)))
                    yyerror("Type mismatch\n");   
                    }
    | exp {if(link->arr != NULL) yyerror("Invalid operation on given data type\n"); } '-' {push_op("-");} Term { codegen();  }
    | Term 
    ;

Term : Term {if(link->arr != NULL) yyerror("Invalid operation on given data type\n");} '*' {push_op("*");} Factor { codegen();  }
    | Term {if(link->arr != NULL) yyerror("Invalid operation on given data type\n");} '/' {push_op("/");} Factor  { codegen();  }
    | Factor 
    ;
Factor : Literal 
    ;
Literal : IDENTIFIER  {
                        err = check($<structure.strval>1,scope,@1.first_line,"0"); if(!err) printf("Undefined error : %s has not been declared in this scope.\n",$<structure.strval>1); $<structure.strval>$ = $<structure.strval>1;
                        push_t(); 
                        }
    | consttype  { link = create_var($<structure.strval>1,-1,$<structure.intval>1,-1);
        push_t();}
    ;

consttype : T_INTEGER_VAL 
	| T_FLOAT_VAL 
    | T_CHAR_VAL 
    | T_STRING_VAL 
    ;

    
Type : T_INT {type = 1; }
	| T_DOUBLE {type = 2;}
	| T_VOID {type = 3;}
    | T_CHAR {type = 4;}
    | T_STRING {type = 5;}
    ;

increment : IDENTIFIER T_INC ';' {check($<structure.strval>1,scope, @1.first_line,0); }
    | T_INC IDENTIFIER ';' {check($<structure.strval>2,scope, @2.first_line,0); }
    ;
decrement : IDENTIFIER T_DEC ';' {check($<structure.strval>1,scope, @1.first_line,0); }
    | T_DEC IDENTIFIER {check($<structure.strval>2,scope, @2.first_line,0); }
    ;

Return : T_RETURN IDENTIFIER ';' {$<structure.intval>$ = $<structure.intval>2;}
    | T_RETURN consttype ';' {$<structure.intval>$ = $<structure.intval>2;}
    | T_RETURN ';' 
    ;

While : T_WHILE {while1();} '(' global_check ')' {while2();} compound_stmt {while3();}
	;
    
global_check : consttype 
    | IDENTIFIER
    | exp relop exp {codegen_assigna();}
    | T_TRUE
    | T_FALSE
    ;

relop : '<' {push_op("<");push_op(" ");} 
        | '>' {push_op(">");push_op(" ");}
        | T_NE {push_op("!");push_op("=");}
        | T_EQ {push_op("=");push_op("=");}; 
        | T_LE {push_op("<"); push_op("=");};
        | T_GE {push_op(">"); push_op("=");};

constcases : T_INTEGER_VAL
    | T_CHAR_VAL
    ;
Switch : T_SWITCH {switch1();} '(' exp {case_var = link;} ')' '{' Cases '}' {test(); next();} 
;

Cases : Case
    | Case Default
;

Case : C    //count number of cases;
    | Case C 
;

C : T_CASE  constcases {cases[num_cases] = $<structure.strval>2[0]; num_cases++; casestart();} ':' statements  T_BREAK ';'   {caseend();}
    ;


Default : T_DEFAULT ':' statements 
    ;


%%
#include<ctype.h>
char st1[100][7];
sym* st2[100];

char i_[2]="0";
int temp_i=0;
char tmp_i[3];
char temp[5]="t";

int lnum=0;
int ltop=0;
int abcd=0;
int l_while=0;
int l_switch=0;
int label = 0;
int l_for=0;
int flag_set = 1;
int snum = 0;
int nnum = 0;


int main(){
    init();
    fp = fopen("ICG.txt","w");
    qptr = fopen("Quadruples.txt","w");
       
    if(!yyparse()) 
    {
        printf("Parsing Complete\n");
        printf("---------------------Quadruples-------------------------\n\n");
        fprintf(qptr,"Quadruples\n\n");
        printf("Operator \t Arg1 \t\t Arg2 \t\t Result \n");
        fprintf(qptr,"Operator \t Arg1 \t\t Arg2 \t\t Result \n");
        int i;
        for(i=0;i<quadlen;i++)
        {
            char *a1, *a2, *r;
            if(q[i].arg1 != NULL) 
                a1 = q[i].arg1->name;
            else
                a1 = (char*)q[i].arg1;
            if(q[i].arg2 != NULL) 
                a2 = q[i].arg2->name;
            else
                a2 = (char*)q[i].arg2;
            if(q[i].res != NULL) 
                r = q[i].res->name;
            else
                r = (char*)q[i].res;

            printf("%-8s \t %-8s \t %-8s \t %-6s \n",q[i].op,a1,a2,r);
            fprintf(qptr,"%-8s \t %-8s \t %-8s \t %-6s \n",q[i].op,a1,a2,r);
        }
    }
    display();
    fclose(qptr);
    fclose(fp);
}


int yywrap()
{
  return(1);
}

void test()
{
    fprintf(fp,"test%d:\n",snum-1);

    q[quadlen].op = (char*)malloc(sizeof(char)*6);
    q[quadlen].arg1 = NULL;
    q[quadlen].arg2 = NULL;   
    strcpy(q[quadlen].op,"Label");
    char x1[10];
    sprintf(x1,"%d",snum-1);
    char l1[11]="test";
    strcat(l1,x1);
    err = lookup(l1,scope,type,quadlen);
    q[quadlen].res = link;
    quadlen++;

    int i;
    sym* t = case_var;
    for(i=0;i<num_cases;i++)
    {
        strcpy(temp,"T");
        sprintf(tmp_i, "%d", temp_i);
        strcat(temp,tmp_i);
        fprintf(fp, "%s = %s == %c\n",temp,t->name,cases[i]);        
        q[quadlen].op = (char*)malloc(sizeof(char)*3);
        strcpy(q[quadlen].op,"==");
        q[quadlen].arg1 = t;
        char x[10];
        sprintf(x,"%c",cases[i]);
        err = lookup(x,scope,type,quadlen);
        q[quadlen].arg2 = link;
        err = lookup(temp,scope,type,quadlen);
        q[quadlen].res = link;        
        quadlen++;

        fprintf(fp,"if %s goto L%d\n",temp,lnum - num_cases + i);
        q[quadlen].op = (char*)malloc(sizeof(char)*3);
        q[quadlen].arg1 = link;
        q[quadlen].arg2 = NULL;        
        strcpy(q[quadlen].op,"if");
        sprintf(x,"%d",lnum - num_cases + i);
        char l[11]="L";
        strcat(l,x);
        err = lookup(l,scope,type,quadlen);
        q[quadlen].res = link;
        st2[top2] = link;
        quadlen++;
        temp_i++;
    }   
}

void next()
{
    fprintf(fp,"next%d:\n",nnum++);
    q[quadlen].op = (char*)malloc(sizeof(char)*6);
    q[quadlen].arg1 = NULL;
    q[quadlen].arg2 = NULL;
    strcpy(q[quadlen].op,"Label");
    char x1[10];
    sprintf(x1,"%d",nnum-1);
    char l1[11]="next";
    strcat(l1,x1);
    err = lookup(l1,scope,type,quadlen);
    q[quadlen].res = link;
    quadlen++;
    num_cases = 0;
}

void casestart()
{
    l_switch = lnum;
    fprintf(fp, "L%d :\n",lnum++);
    q[quadlen].op = (char*)malloc(sizeof(char)*6);
    q[quadlen].arg1 = NULL;
    q[quadlen].arg2 = NULL;   
    strcpy(q[quadlen].op,"Label");
    char x1[10];
    sprintf(x1,"%d",lnum-1);
    char l1[11]="L";
    strcat(l1,x1);
    err = lookup(l1,scope,type,quadlen);
    q[quadlen].res = link;
    quadlen++;   
}

void caseend()
{
    fprintf(fp,"goto next%d\n",nnum);
    q[quadlen].op = (char*)malloc(sizeof(char)*5);
    q[quadlen].arg1 = NULL;
    q[quadlen].arg2 = NULL;
    strcpy(q[quadlen].op,"goto");
    char x[10];
    sprintf(x,"%d",nnum);
    char l[11]="next";
    strcat(l,x);
    err = lookup(l,scope,type,quadlen);
    q[quadlen].res = link;
    quadlen++;
}

void switch1()
{
    fprintf(fp,"goto test%d\n",snum++);
    q[quadlen].op = (char*)malloc(sizeof(char)*5);
    q[quadlen].arg1 = NULL;
    q[quadlen].arg2 = NULL;
    strcpy(q[quadlen].op,"goto");
    char x[10];
    sprintf(x,"%d",snum-1);
    char l[11]="test";
    strcat(l,x);
    err = lookup(l,scope,type,quadlen);
    q[quadlen].res = link;
    quadlen++;
}

void while1()
{
    l_while = lnum;
    fprintf(fp, "L%d :\n",lnum++);
    q[quadlen].op = (char*)malloc(sizeof(char)*6);
    q[quadlen].arg1 = NULL;
    q[quadlen].arg2 = NULL;
    strcpy(q[quadlen].op,"Label");
    char x[10];
    sprintf(x,"%d",lnum-1);
    char l[11]="L";
    strcat(l,x);
    err = lookup(l,scope,type,quadlen);
    q[quadlen].res = link;
    quadlen++;
}

void while2()
{
    strcpy(temp,"T");
    sprintf(tmp_i, "%d", temp_i);
    strcat(temp,tmp_i);
    fprintf(fp,"%s = not %s\n",temp,st2[top2]->name);
    q[quadlen].op = (char*)malloc(sizeof(char)*4);
    q[quadlen].arg2 = NULL;
    strcpy(q[quadlen].op,"not");
    q[quadlen].arg1 = st2[top2];
    err = lookup(temp,scope,type,quadlen);
    q[quadlen].res = link;
    quadlen++;
    fprintf(fp, "if %s goto L%d\n",temp,lnum);
    q[quadlen].op = (char*)malloc(sizeof(char)*3);
    q[quadlen].arg1 = link;
    q[quadlen].arg2 = NULL; 
    strcpy(q[quadlen].op,"if");
    char x[10];
    sprintf(x,"%d",lnum);char l[11]="L";
    strcat(l,x);
    err = lookup(l,scope,type,quadlen);
    q[quadlen].res = link;
    st2[top2] = link;
    quadlen++;
    temp_i++;
}

void while3()
{
    fprintf(fp,"goto L%d\n",l_while);
    q[quadlen].op = (char*)malloc(sizeof(char)*5);
    q[quadlen].arg1 = NULL;
    q[quadlen].arg2 = NULL;
    strcpy(q[quadlen].op,"goto");
    char x[10];
    sprintf(x,"%d",l_while);
    char l[11]="L";
    strcat(l,x);
    err = lookup(l,scope,type,quadlen);
    q[quadlen].res = link;
    quadlen++;
    fprintf(fp,"L%d: \n",lnum++); 
    q[quadlen].op = (char*)malloc(sizeof(char)*6);
    q[quadlen].arg1 = NULL;
    q[quadlen].arg2 = NULL;    
    strcpy(q[quadlen].op,"Label");
    char x1[10];
    sprintf(x1,"%d",lnum-1);
    char l1[11]="L";
    strcat(l1,x1);
    err = lookup(l1,scope,type,quadlen);
    q[quadlen].res = link;
    quadlen++;
}

void codegen()
{
    strcpy(temp,"T");
    sprintf(tmp_i, "%d", temp_i);
    strcat(temp,tmp_i);
    fprintf(fp,"%s = %s %s %s\n",temp,st2[top2-1]->name,st1[top],st2[top2]->name);
    q[quadlen].op = (char*)malloc(sizeof(char)*strlen(st1[top]));
    strcpy(q[quadlen].op,st1[top]);
    q[quadlen].arg1 = st2[top2-1];
    q[quadlen].arg2 = st2[top2];
    err = lookup(temp,scope,type,quadlen);
    q[quadlen].res = link;
    quadlen++;
    top2-=1;
    top-=1;
    st2[top2] = link;
    temp_i++;
}

void push_t()
{
    st2[++top2] = link; 
}

void push_op(char* text)
{
    strcpy(st1[++top],text);  
}

void codegen_assigna()
{
    strcpy(temp,"T");
    sprintf(tmp_i, "%d", temp_i);
    strcat(temp,tmp_i);
    fprintf(fp,"%s = %s %s %s %s\n",temp,st2[top2-1]->name,st1[top-1],st1[top],st2[top2]->name);
    if(strlen(st1[top])==1)
    {        
        char t[120];
        strcpy(t,st1[top-1]);
        strcat(t,st1[top]);
        q[quadlen].op = (char*)malloc(sizeof(char)*strlen(t));
        strcpy(q[quadlen].op,t);
        q[quadlen].arg1 = st2[top2-1];
        q[quadlen].arg2 = st2[top2];
        err = lookup(temp,scope,type,quadlen);
        q[quadlen].res = link;
        quadlen++;  
    }
    else
    {
        q[quadlen].op = (char*)malloc(sizeof(char)*strlen(st1[top]));
        strcpy(q[quadlen].op,st1[top]);
        q[quadlen].arg1 = st2[top2-1];
        q[quadlen].arg2 = st2[top2];
        err = lookup(temp,scope,type,quadlen);
        q[quadlen].res = link;
        quadlen++;
    }
    top2-=2;
    top-=2;
    temp_i++;
    st2[++top2] = link;
}

void codegen_assign()
{
    fprintf(fp,"%s = %s\n",st2[top2]->name,st2[top2-1]->name);
    q[quadlen].op = (char*)malloc(sizeof(char));
    q[quadlen].arg2 = NULL;
    strcpy(q[quadlen].op,"=");
    q[quadlen].arg1 = st2[top2-1];
    q[quadlen].res = st2[top2];
    quadlen++;
    top2-=2;
    top-=1;
}

void arg1()
{
    int rem = arg_count % 3;
    int m = arg_count / 3;

    for(int i = 0; i < m; ++i){
        fprintf(fp,"param %s, %s, %s\n",st2[top2]->name,st2[top2-1]->name,st2[top2-2]->name);
        q[quadlen].op = (char*)malloc(sizeof(char) * 6);
        strcpy(q[quadlen].op,"param");
        q[quadlen].arg1 = st2[top2];
        q[quadlen].arg2 = st2[top2-1];
        q[quadlen].res = st2[top2-2];
        quadlen++;
        top2-=3;
    }
    
    if(rem == 1){
        fprintf(fp,"param %s\n",st2[top2]->name);
        q[quadlen].op = (char*)malloc(sizeof(char) * 6);
        strcpy(q[quadlen].op,"param");
        q[quadlen].arg1 = st2[top2];
        q[quadlen].arg2 = NULL;
        q[quadlen].res = NULL;
        quadlen++;
        top2-=1;        
    }
    if(rem == 2){
        fprintf(fp,"param %s, %s\n",st2[top2]->name,st2[top2-1]->name);
        q[quadlen].op = (char*)malloc(sizeof(char) * 6);
        strcpy(q[quadlen].op,"param");
        q[quadlen].arg1 = st2[top2];
        q[quadlen].arg2 = st2[top2-1];
        q[quadlen].res = NULL;
        quadlen++;
        top2-=2;
    }
}

void funcall()
{
    fprintf(fp,"call %s, %d\n",st2[top2]->name,arg_count);
    q[quadlen].op = (char*)malloc(sizeof(char) * 5);
    strcpy(q[quadlen].op,"call");
    q[quadlen].arg1 = st2[top2];
    char x[2];
    sprintf(x,"%d",arg_count);
    err = lookup(x,scope,type,quadlen);
    q[quadlen].arg2 = link;
    q[quadlen].res = NULL;
    quadlen++;
    top2-=1;    
}

void fun1()
{
    fprintf(fp,"func begin %s\n",st2[top2]->name);
    q[quadlen].op = (char*)malloc(sizeof(char) * 5);
    strcpy(q[quadlen].op,"func");
    q[quadlen].arg2 = link;
    err = lookup("begin",scope,type,quadlen);
    q[quadlen].arg1 = link;
    q[quadlen].res = NULL;
    quadlen++;
    top2-=1;      
}

void fun2()
{
    fprintf(fp,"func end\n");
    q[quadlen].op = (char*)malloc(sizeof(char) * 5);
    strcpy(q[quadlen].op,"func");
    q[quadlen].arg2 = NULL;
    err = lookup("end",scope,type,quadlen);
    q[quadlen].arg1 = link;
    q[quadlen].res = NULL;
    quadlen++;     
}
