  
%{
    #include<string.h>
    #include<stdio.h>
    #include "compiler.tab.h"

    extern void yyerror(const char *); 
    #define YY_USER_ACTION yylloc.first_line = yylloc.last_line = yylineno;

    
%}


SINGLE_CHAR_OPERATORS "+"|"-"|"&"|"!"|"^"|"*"|","|";"|"/"|"="|"%"|">"|"<"|"."|"["|"]"|":"|"?"|"("|")"|"{"|"}"|"\""
SINGLE_COMMENT  \/\/(.*)
MULTI_COMMENT \/\*(.*\n)*.*\*\/
DIGIT       [0-9]
FRAC      (\.{DIGIT}+)?
EXP       ([Ee][+-]?{DIGIT}+)?
NUMBER      ({DIGIT}+{FRAC}{EXP})
LETTER      [a-zA-Z_]
IDENTIFIER    (_|{LETTER})({LETTER}|{DIGIT}|_)*
PRINT     [ -~]
CCONST      (\'{PRINT}\')|(\'\\[nftrbv]\')
/* CCONST      \'[a-zA-Z0-9]\'*/
STRING_TERMINATE ('\0')
STRING      \"[^\"\n]*\"
NOT_STRING      \"[^\"]*[\n][^\"]*\"
ICONST      {DIGIT}+
DOUBLE      ({DIGIT}+(\.{DIGIT}+){EXP})
OPEN_MULTICOMMENT \/\* 
CLOSE_MULTICOMMENT \*\/

%option yylineno

%%

[ \t] {}

{SINGLE_COMMENT}[^\n]* {;}

{OPEN_MULTICOMMENT}(.*?\n)*?.*?{CLOSE_MULTICOMMENT}{CLOSE_MULTICOMMENT}+   {yyerror("Unexpected extra closing comment");}


{OPEN_MULTICOMMENT}(.*?\n)*?.*?{CLOSE_MULTICOMMENT} 

{OPEN_MULTICOMMENT}.* {yyerror("Unterminated Comment");}




"main()"        { printf("%s\n","T_MAIN");
                  return T_MAIN; }

"printf"        { printf("%s\n","T_PRINT");
                  return T_PRINT; }


"while"         { printf("%s\n","T_WHILE");
                  return T_WHILE; }

"switch"  { printf("%s\n","T_SWITCH");
            return T_SWITCH; }
"default" { printf("%s\n","T_DEFAULT");
            return T_DEFAULT; }
"case"    { printf("%s\n","T_CASE");
            return T_CASE; }                  
                          
"if"    { printf("%s\n","T_IF");
          return T_IF; }

"else"  { printf("%s\n","T_ELSE");
          return T_ELSE; }

"#include" { printf("%s\n","T_INCLUDE"); return T_INCLUDE; }

"class"   { printf("%s\n","T_CLASS"); return T_CLASS; }

"public"  { printf("%s\n","T_PUBLIC"); return T_PUBLIC; }

"private" { printf("%s\n","T_PRIVATE"); return T_PRIVATE; }

"protected"   { printf("%s\n","T_PROTECTED"); return T_PROTECTED; }

"int"     { printf("%s\n","T_INT"); yylval.structure.intval = 1;return T_INT; }
        
"double"  { printf("%s\n","T_DOUBLE"); yylval.structure.intval = 2; return T_DOUBLE;}
           
"bool"    { printf("%s\n","T_BOOL"); return T_BOOL; }
         
"char"    { printf("%s\n","T_CHAR"); yylval.structure.intval = 4; return T_CHAR; } 

"string" { printf("%s\n","T_STRING"); yylval.structure.intval = 5; return T_STRING;}

"void" {  printf("%s\n","T_VOID"); yylval.structure.intval = 3;return T_VOID; }

"return" { printf("%s\n","T_RETURN"); return T_RETURN;
      }
"break"    { printf("%s\n","T_BREAK"); return T_BREAK; }
            
"cout"  { printf("%s\n","T_COUT"); return T_COUT;} 

"cin" {printf("%s\n","T_CIN"); return T_CIN;}

"//".*?\n {}
">="    { printf("%s\n","T_GE"); return T_GE;}

"<="    { printf("%s\n","T_LE"); return T_LE;}
        
"=="    { printf("%s\n","T_EQ"); return T_EQ;}
            
"!="    { printf("%s\n","T_NE"); return T_NE;}

"||"    { printf("%s\n","T_OR"); return T_OR; }

"&&"    { printf("%s\n","T_AND"); return T_AND;}

">>"  { printf("%s\n","T_INS"); return T_INS;}

"<<"  { printf("%s\n","T_EXT"); return T_EXT;}

"++"  { printf("%s\n","T_INC"); return T_INC;}
"--"  { printf("%s\n","T_DEC"); return T_DEC;}

{IDENTIFIER}    { printf("%s\n","T_IDENTIFIER");
  if (strlen(yytext) > 31){
                  yyerror("Identifier length exceeded 31, truncated.\n ");
                  char* new = (char*)malloc(31 * sizeof(char));
                  for(int i = 0; i < 30; i++){
                    new[i] = yytext[i];
                  }
                  new[30] = '\0';
                  yylval.structure.strval = new;
                  return IDENTIFIER;
                }
                yylval.structure.strval = strdup(yytext);
                return IDENTIFIER;
    }

{CCONST}        {
                  printf("%s\n","T_CHAR_VAL");
                   yylval.structure.intval = 4;
                    yylval.structure.strval = strdup(yytext);                   
                    return T_CHAR_VAL;}

(<|\"){LETTER}({LETTER}|{DIGIT})*"\.h"(>|\")  { 
                          printf("%s\n","T_HEADER");
                          yylval.structure.strval = strdup(yytext);
                          return T_HEADER;} 
                    


{STRING}          {       printf("%s\n","T_STRING_VAL");
                         yylval.structure.intval = 5;
                          yylval.structure.strval = strdup(yytext);                           
                          return T_STRING_VAL;}

{NOT_STRING}      { yyerror("String with erroneous newline") ;
                          yylval.structure.strval = " ";
                          return T_STRING_VAL;}


\"[^\"\n]*$       {yyerror("Unterminated string");}


{ICONST}            { 
                          yylval.structure.intval = 1;
                          yylval.structure.strval = strdup(yytext); 

                          //printf("%s, %d\n","T_INTEGER_VAL", yylval.structure.intval);    
                          return T_INTEGER_VAL;}

{DOUBLE}           {   
                        yylval.structure.intval = 2;   
                          yylval.structure.strval = strdup(yytext);
                          
                          return T_FLOAT_VAL;}
            
{SINGLE_CHAR_OPERATORS} {printf("%c\n",*yytext); return *yytext; }

({DIGIT})+({LETTER}|_)+ {yyerror("Illegal identifier name");}

[\n]            {}
[ \t\r\f\v]+    {}
.                       {ECHO;
            printf("char = %s\n",yytext); yyerror("unexpected character");}


%%