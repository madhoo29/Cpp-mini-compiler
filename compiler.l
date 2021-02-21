%{
    #include<string.h>
    #include<stdio.h>

    #include "compiler.tab.h"
    extern void yyerror(const char *); 
    unsigned int lineno = 0;

    
%}

%option yylineno

SINGLE_CHAR_OPERATORS "+"|"-"|"&"|"!"|"^"|"*"|","|"~"|";"|"/"|"="|"%"|">"|"<"|"."|"["|"]"|":"|"?"|"("|")"|"{"|"}"|"\""
SINGLE_COMMENT  \/\/(.*)
MULTI_COMMENT \/\*(.*\n)*.*\*\/
DIGIT       [0-9]
FRAC      (\.{DIGIT}+)?
EXP       ([Ee][+-]?{DIGIT}+)?
NUMBER      ({DIGIT}+{FRAC}{EXP})
LETTER      [a-zA-Z_]
IDENTIFIER    [a-zA-Z_][a-zA-Z0-9_]*
PRINT     [ -~]
CCONST      (\'{PRINT}\')|(\'\\[nftrbv]\')
STRING      \"[ -~]*\"
ICONST      {DIGIT}+
DOUBLE      ({DIGIT}+(\.{DIGIT}+)?{EXP})
OPEN_MULTICOMMENT \/\* 
CLOSE_MULTICOMMENT \*\/



%%

[ \t] {}

SINGLE_COMMENT ;

{OPEN_MULTICOMMENT}(.*\n)*.*{CLOSE_MULTICOMMENT} ;

{OPEN_MULTICOMMENT}.* {yyerror("Unterminated Comment\n ");}

 /* Regex to truncate identifiers exceeding length 31 */


[\n]            {   
                        yylineno ++;
                          
                }

"main()"          {  
                  printf("T_MAIN "); 
                  return T_MAIN; }

"printf"          {   
                  printf("T_PRINT ");
                  return T_PRINT; }


"while" { 
                  printf("T_WHILE ");
                  return T_WHILE; }

"switch"  { 
                  printf("T_SWITCH ");
                  return T_SWITCH; }
"default" { 
                    
                  printf("T_DEFAULT ");
                  return T_DEFAULT; }
"case"    { 
                    
                  printf("T_CASE ");
                  return T_CASE; }                  
                          
"if"    { 
                    
                  printf("T_IF ");
                  return T_IF; }

"else"  { 
                    
                  printf("T_ELSE ");
                  return T_ELSE; }

"#include" { 
                    
                  printf("T_INCLUDE ");
                  return T_INCLUDE; }

"int"     { 
                             
                          yylval.intval = T_INT;
                          printf("T_INT ");
                          return T_INT; }
        
"double"  { 
                             
                          yylval.intval = T_DOUBLE;
                          printf("T_DOUBLE ");
                          return T_DOUBLE;}
           
"bool"    { 
                             
                          yylval.intval = T_BOOL;
                          printf("T_BOOL ");
                          return T_BOOL; }
         
"char"    { 
                             
                          yylval.intval = T_CHAR;
                          printf("T_CHAR ");
                          return T_CHAR; } 

"string" {   
                 yylval.intval = T_STRING;
                 printf("T_STRING ");
              return T_STRING;}

"void" {  
              
             yylval.intval = T_VOID;
             printf("T_VOID ");
          return T_VOID; 
}

"return" {   
             
            printf("T_RETURN ");
             return T_RETURN;
      }
"break"    { 
                    
                  printf("T_BREAK ");
                  return T_BREAK; }
            
"cout"  {    
             
            printf("T_COUT ");
            return T_COUT;} 

"cin" {   
             
             
            printf("T_CIN ");
      return T_CIN;}

"//".*?\n {}
">="    {    
             
            printf("T_GE ");
      return T_GE;}

"<="    {    
             
            printf("T_LE ");
            return T_LE;}
        
"=="    {    
             
            printf("T_EQ ");
            return T_EQ;}
            
"!="    {    
             
            printf("T_NE ");
            return T_NE;}

"||"    {    
             
            printf("T_OR ");
            return T_OR;
        }

"&&"    {    
             
            printf("T_AND ");
            return T_AND;}

">>"  {      
             
            printf("T_INS ");
            return T_INS;}

"<<"  {      
             
            printf("T_EXT ");
            return T_EXT;}

"++"  {      
             
            printf("T_INC ");
            return T_INC;}
"--"  {      
             
            printf("T_DEC ");
            return T_DEC;}


{SINGLE_CHAR_OPERATORS} {    
                          return *yytext; }


{CCONST}        {    
                          yylval.strval = strdup(yytext);
                          printf("T_CHAR_VAL ");
                          return T_CHAR_VAL;}

{LETTER}({LETTER}|{DIGIT})*"\.h"  {   
                          yylval.strval = strdup(yytext);
                          printf("T_HEADER ");
                          return T_HEADER;} 
                    
{IDENTIFIER}    { yylval.strval = strdup(yytext);
                        printf("IDENTIFIER ");
              return IDENTIFIER;}

                          
{STRING}          {  
                            
                          yylval.strval = strdup(yytext);
                          printf("T_STRING_VAL ");
                          return T_STRING_VAL;}

{ICONST}            {  
                       
                          yylval.strval = strdup(yytext);
                          printf("T_INTEGER_VAL ");
                          return T_INTEGER_VAL;}

{DOUBLE}        {  
                            
                          yylval.strval = strdup(yytext);
                          printf("T_FLOAT_VAL ");
                          return T_FLOAT_VAL;}
                          




 /* Regex to remove comments */
^{IDENTIFIER}{1,31}$ { yyerror("Identifier length exceeded 31, truncated ");} 

 /* .                       { yyerror("Invalid character "); } */

%%