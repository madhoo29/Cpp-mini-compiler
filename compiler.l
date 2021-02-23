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
STRING      \"[^\"]*\"
ICONST      {DIGIT}+
DOUBLE      ({DIGIT}+(\.{DIGIT}+){EXP})
OPEN_MULTICOMMENT \/\* 
CLOSE_MULTICOMMENT \*\/

%option yylineno

%%

[ \t] {}

{SINGLE_COMMENT}[^ \n]* {;}

{OPEN_MULTICOMMENT}(.*\n)*.*{CLOSE_MULTICOMMENT} ;

{OPEN_MULTICOMMENT}.* {yyerror("Unterminated Comment");}

 /* Regex to truncate identifiers exceeding length 31 */


[\n]            {}
[ \t\r\f\v]+    {}

"main()"        { fprintf(ptr,T_MAIN);
                  return T_MAIN; }

"printf"        { fprintf(ptr,"T_PRINT");
                  return T_PRINT; }


"while"         { fprintf(ptr,"T_WHILE");
                  return T_WHILE; }

"switch"  { fprintf(ptr,"T_SWITCH");
            return T_SWITCH; }
"default" { fprintf(ptr,"T_DEFAULT");
            return T_DEFAULT; }
"case"    { fprintf(ptr,"T_CASE");
            return T_CASE; }                  
                          
"if"    { fprintf(ptr,"T_IF");
          return T_IF; }

"else"  { fprintf(ptr,"T_ELSE");
          return T_ELSE; }

"#include" { fprintf(ptr,"T_INCLUDE"); return T_INCLUDE; }

"int"     { fprintf(ptr,"T_INT"); return T_INT; }
        
"double"  { fprintf(ptr,"T_DOUBLE"); return T_DOUBLE;}
           
"bool"    { fprintf(ptr,"T_BOOL"); return T_BOOL; }
         
"char"    { fprintf(ptr,"T_CHAR"); return T_CHAR; } 

"string" { fprintf(ptr,"T_STRING"); return T_STRING;}

"void" {  fprintf(ptr,"T_VOID"); return T_VOID; 
}

"return" { fprintf(ptr,"T_RETURN"); return T_RETURN;
      }
"break"    { fprintf(ptr,"T_BREAK"); return T_BREAK; }
            
"cout"  { fprintf(ptr,"T_COUT"); return T_COUT;} 

"cin" {fprintf(ptr,"T_CIN"); return T_CIN;}

"//".*?\n {}
">="    { fprintf(ptr,"T_GE"); return T_GE;}

"<="    { fprintf(ptr,"T_LE"); return T_LE;}
        
"=="    { fprintf(ptr,"T_EQ"); return T_EQ;}
            
"!="    { fprintf(ptr,"T_NE"); return T_NE;}

"||"    { fprintf(ptr,"T_OR"); return T_OR; }

"&&"    { fprintf(ptr,"T_AND"); return T_AND;}

">>"  { fprintf(ptr,"T_INS"); return T_INS;}

"<<"  { fprintf(ptr,"T_EXT"); return T_EXT;}

"++"  { fprintf(ptr,"T_INC"); return T_INC;}
"--"  { fprintf(ptr,"T_DEC"); return T_DEC;}

{IDENTIFIER}    { if (strlen(yytext) > 31){
                  yyerror("Identifier length exceeded 31, truncated.\n ");
                  char* new = (char*)malloc(31 * sizeof(char));
                  for(int i = 0; i < 30; i++){
                    new[i] = yytext[i];
                  }
                  new[30] = '\0';
                  yylval.strval = new;
                  return IDENTIFIER;
                }
                yylval.strval = strdup(yytext);
                return IDENTIFIER;
    }

{CCONST}        {
                  fprintf(ptr,"T_CHAR_VAL");
                    yylval.strval = strdup(yytext);
                    return T_CHAR_VAL;}

(<|\"){LETTER}({LETTER}|{DIGIT})*"\.h"(>|\")  { 
                          fprintf(ptr,"T_HEADER");
                          yylval.strval = strdup(yytext);
                          return T_HEADER;} 
                    


{STRING}          {       fprintf(ptr,"T_STRING_VAL");
                          yylval.strval = strdup(yytext);
                          return T_STRING_VAL;}

\"[^\"\n]*$       {yyerror("Unterminated string");}

 

{ICONST}            { 
                          yylval.strval = strdup(yytext);
                          fprintf(ptr,"T_INTEGER_VAL");    
                          return T_INTEGER_VAL;}

{DOUBLE}            {
                          yylval.strval = strdup(yytext);
                          fprintf(ptr,"T_FLOAT_VAL");
                          return T_FLOAT_VAL;}
            
{SINGLE_CHAR_OPERATORS} { return *yytext; }

({DIGIT})+({LETTER}|_)+ {yyerror("Illegal identifier name");}


.                       {ECHO; yyerror("unexpected character");}


%%

int main()
{
    FILE* ptr= fopen("tokens.txt","w");
}