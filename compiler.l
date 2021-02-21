%{
    #include<string.h>
    #include<stdio.h>
    #include "compiler.tab.h"

    extern void yyerror(const char *); 

    unsigned int lineno = 0;

    #define YY_USER_ACTION yylloc.first_line = yylloc.last_line = yylineno;
    
%}

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
DOUBLE      ({DIGIT}+(\.{DIGIT}+){EXP})
OPEN_MULTICOMMENT \/\* 
CLOSE_MULTICOMMENT \*\/

%option yylineno

%%

[ \t] {}

{SINGLE_COMMENT}[^ \n]* { printf("comment %d\t",lineno);};

{OPEN_MULTICOMMENT}(.*\n)*.*{CLOSE_MULTICOMMENT} {
                          printf("comment %d\t",lineno);};

{OPEN_MULTICOMMENT}.* {yyerror("Unterminated Comment\n ");}

 /* Regex to truncate identifiers exceeding length 31 */


[\n]            {
                }

"main()"          { 
                  return T_MAIN; }

"printf"          { 
                  return T_PRINT; }


"while" { 
                  return T_WHILE; }

"switch"  { return T_SWITCH; }
"default" { return T_DEFAULT; }
"case"    { return T_CASE; }                  
                          
"if"    { return T_IF; }

"else"  { return T_ELSE; }

"#include" { return T_INCLUDE; }

"int"     { return T_INT; }
        
"double"  { return T_DOUBLE;}
           
"bool"    { return T_BOOL; }
         
"char"    { return T_CHAR; } 

"string" { return T_STRING;}

"void" {  return T_VOID; 
}

"return" { return T_RETURN;
      }
"break"    { return T_BREAK; }
            
"cout"  { return T_COUT;} 

"cin" { return T_CIN;}

"//".*?\n {}
">="    { return T_GE;}

"<="    { return T_LE;}
        
"=="    { return T_EQ;}
            
"!="    { return T_NE;}

"||"    { return T_OR;
        }

"&&"    { return T_AND;}

">>"  { return T_INS;}

"<<"  { return T_EXT;}

"++"  { return T_INC;}
"--"  { return T_DEC;}


{SINGLE_CHAR_OPERATORS} { 
                          return *yytext; }


{CCONST}        {
                          yylval.strval = strdup(yytext);
                        return T_CHAR_VAL;}

{LETTER}({LETTER}|{DIGIT})*"\.h"  { 
                          yylval.strval = strdup(yytext);
                          return T_HEADER;} 
                    
{IDENTIFIER}    { yylval.strval = strdup(yytext);
              return IDENTIFIER;}

                          
{STRING}          { 
                          yylval.strval = strdup(yytext);
                          return T_STRING_VAL;}

{ICONST}            { 
                          yylval.strval = strdup(yytext);
                          return T_INTEGER_VAL;}

{DOUBLE}        {
                          yylval.strval = strdup(yytext);
                          return T_FLOAT_VAL;}
                          


 /* Regex to remove comments */
^{IDENTIFIER}{1,31}$ { yyerror("Identifier length exceeded 31, truncated ");} 

 /* .                       { yyerror("Invalid character "); } */

%%