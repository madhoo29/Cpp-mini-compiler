%{
    #include<string.h>
    #include<stdio.h>

    // int yylex();

// typedef struct YYLTYPE
// {
//     int first_line;
//     int first_column;
//     int last_line;
//     int last_column;
//     char *filename; /* use to keep track of which file we're currently in */
//     int hel;    /* no errors = 0, warning = 1, error = 2, fatal = 3 */
// } YYLTYPE;


    #include "compiler.tab.h"
    extern void yyerror(const char *); 

    // int yylval;
    // void yyerror(char *);
	unsigned int lineno = 0;

   // extern YYLTYPE yylloc;
  //#define YYLTYPE * yylloc;
   //#define YYSTYPE char * ;
  //  #define YYSTYPE char*
   
    // #define YY_USER_INIT yylloc.first_line = 1;
    
%}

SINGLE_CHAR_OPERATORS "+"|"-"|"&"|"!"|"^"|"*"|","|"~"|";"|"/"|"="|"%"|">"|"<"|"."|"["|"]"|":"|"?"|"("|")"|"{"|"}"|"\""
SINGLE_COMMENT	\/\/(.*)
MULTI_COMMENT	\/\*(.*\n)*.*\*\/
DIGIT 			[0-9]
FRAC			(\.{DIGIT}+)?
EXP				([Ee][+-]?{DIGIT}+)?
NUMBER 			({DIGIT}+{FRAC}{EXP})
LETTER			[a-zA-Z_]
IDENTIFIER		[a-zA-Z_][a-zA-Z0-9_]*
PRINT			[ -~]
CCONST			(\'{PRINT}\')|(\'\\[nftrbv]\')
STRING			\"[ -~]*\"
ICONST			{DIGIT}+
DOUBLE			({DIGIT}+(\.{DIGIT}+){EXP})
OPEN_MULTICOMMENT \/\* 
CLOSE_MULTICOMMENT \*\/



%%

[ \t] {}

SINGLE_COMMENT ;

{OPEN_MULTICOMMENT}(.*\n)*.*{CLOSE_MULTICOMMENT} ;

{OPEN_MULTICOMMENT}.* {yyerror("Unterminated Comment\n");}

 /* Regex to truncate identifiers exceeding length 31 */


[\n]            { yylloc.first_line = yylloc.last_line;
                          yylloc.first_column = ++yylloc.last_column;
                          yylloc.last_column = 0; 
                          yylloc.first_line = lineno++;
                }

"main()"	        { yylloc.first_line = yylloc.last_line;
                  yylloc.first_column = ++yylloc.last_column; 
                  yylloc.last_column += yyleng - 1; 
                  return T_MAIN; }

"printf"	        { yylloc.first_line = yylloc.last_line;
                  yylloc.first_column = ++yylloc.last_column; 
                  yylloc.last_column += yyleng - 1; 
                  return T_PRINT; }


"while"	{ 
                  yylloc.first_line = yylloc.last_line;
                  yylloc.first_column = ++yylloc.last_column; 
                  yylloc.last_column += yyleng - 1; 
                  return T_WHILE; }

"switch"	{ 
                  yylloc.first_line = yylloc.last_line;
                  yylloc.first_column = ++yylloc.last_column; 
                  yylloc.last_column += yyleng - 1; 
                  return T_SWITCH; }
"default"	{ 
                  yylloc.first_line = yylloc.last_line;
                  yylloc.first_column = ++yylloc.last_column; 
                  yylloc.last_column += yyleng - 1; 
                  return T_DEFAULT; }
"case"    { 
                  yylloc.first_line = yylloc.last_line;
                  yylloc.first_column = ++yylloc.last_column; 
                  yylloc.last_column += yyleng - 1; 
                  return T_CASE; }                  
                          
"if"    { 
                  yylloc.first_line = yylloc.last_line;
                  yylloc.first_column = ++yylloc.last_column; 
                  yylloc.last_column += yyleng - 1; 
                  return T_IF; }

"else"	{ 
                  yylloc.first_line = yylloc.last_line;
                  yylloc.first_column = ++yylloc.last_column; 
                  yylloc.last_column += yyleng - 1; 
                  return T_ELSE; }

"#include" { 
                  yylloc.first_line = yylloc.last_line;
                  yylloc.first_column = ++yylloc.last_column; 
                  yylloc.last_column += yyleng - 1; 
                  return T_INCLUDE; }

"int"     { 
                          yylloc.first_line = yylloc.last_line;
                          yylloc.first_column = ++yylloc.last_column;
                          yylloc.last_column += yyleng -1; 
                          yylval.intval = T_INT;
                          return T_INT; }
        
"double"  { 
                          yylloc.first_line = yylloc.last_line;
                          yylloc.first_column = ++yylloc.last_column;
                          yylloc.last_column += yyleng -1; 
                          yylval.intval = T_DOUBLE;
                          return T_DOUBLE;}
           
"bool"    { 
                          yylloc.first_line = yylloc.last_line;
                          yylloc.first_column = ++yylloc.last_column;
                          yylloc.last_column += yyleng -1; 
                          yylval.intval = T_BOOL;
                          return T_BOOL; }
         
"char"    { 
                          yylloc.first_line = yylloc.last_line;
                          yylloc.first_column = ++yylloc.last_column;
                          yylloc.last_column += yyleng -1; 
                          yylval.intval = T_CHAR;
                          return T_CHAR; } 

"string" { 	
              yylloc.first_line = yylloc.last_line;
            	yylloc.first_column = ++yylloc.last_column;
           	  yylloc.last_column += yyleng -1; 
                 yylval.intval = T_STRING;
           	  return T_STRING;}

"void" { 	
          yylloc.first_line = yylloc.last_line;
          yylloc.first_column = ++yylloc.last_column;
         	yylloc.last_column += yyleng -1; 
             yylval.intval = T_VOID;
         	return T_VOID; 
}

"return" {  yylloc.first_line = yylloc.last_line;
            yylloc.first_column = ++yylloc.last_column;
            yylloc.last_column += yyleng -1;
      		   return T_RETURN;
	    }
"break"    { 
                  yylloc.first_line = yylloc.last_line;
                  yylloc.first_column = ++yylloc.last_column; 
                  yylloc.last_column += yyleng - 1; 
                  return T_BREAK; }
            
"cout"  {   yylloc.first_line = yylloc.last_line;
            yylloc.first_column = ++yylloc.last_column;
            yylloc.last_column += yyleng -1;
            return T_COUT;} 




"cin"	{   
            yylloc.first_line = yylloc.last_line;
            yylloc.first_column = ++yylloc.last_column;
            yylloc.last_column += yyleng -1;
			return T_CIN;}

"//".*?\n {}
">="    {   yylloc.first_line = yylloc.last_line;
            yylloc.first_column = ++yylloc.last_column;
            yylloc.last_column += yyleng -1;
			return T_GE;}

"<="    {   yylloc.first_line = yylloc.last_line;
            yylloc.first_column = ++yylloc.last_column;
            yylloc.last_column += yyleng -1;
            return T_LE;}
        
"=="    {   yylloc.first_line = yylloc.last_line;
            yylloc.first_column = ++yylloc.last_column;
            yylloc.last_column += yyleng -1;
            return T_EQ;}
            
"!="    {   yylloc.first_line = yylloc.last_line;
            yylloc.first_column = ++yylloc.last_column;
            yylloc.last_column += yyleng -1;
            return T_NE;}

"||"    {   yylloc.first_line = yylloc.last_line;
            yylloc.first_column = ++yylloc.last_column;
            yylloc.last_column += yyleng -1;
            return T_OR;
        }

"&&"    {   yylloc.first_line = yylloc.last_line;
            yylloc.first_column = ++yylloc.last_column;
            yylloc.last_column += yyleng -1;
            return T_AND;}

">>"  {     yylloc.first_line = yylloc.last_line;
            yylloc.first_column = ++yylloc.last_column;
            yylloc.last_column += yyleng -1;
            return T_INS;}

"<<"  {     yylloc.first_line = yylloc.last_line;
            yylloc.first_column = ++yylloc.last_column;
            yylloc.last_column += yyleng -1;
            return T_EXT;}

"++"  {     yylloc.first_line = yylloc.last_line;
            yylloc.first_column = ++yylloc.last_column;
            yylloc.last_column += yyleng -1;
            return T_INC;}
"--"  {     yylloc.first_line = yylloc.last_line;
            yylloc.first_column = ++yylloc.last_column;
            yylloc.last_column += yyleng -1;
            return T_DEC;}


{SINGLE_CHAR_OPERATORS} { yylloc.first_line = yylloc.last_line;
                          yylloc.first_column = ++yylloc.last_column;
                          yylloc.last_column += yyleng -1; 
                          return *yytext; }


{CCONST}		 		{ yylloc.first_line = yylloc.last_line;
                          yylloc.first_column = ++yylloc.last_column;
                          yylloc.last_column += yyleng -1; 
                          yylval.strval = strdup(yytext);
                          return T_CHAR_VAL;}

{LETTER}({LETTER}|{DIGIT})*"\.h"  { yylloc.first_line = yylloc.last_line;
                          yylloc.first_column = ++yylloc.last_column;
                          yylloc.last_column += yyleng -1;
                          yylval.strval = strdup(yytext);
                          return T_HEADER;} 
                    
{IDENTIFIER}		{   yylval.strval = strdup(yytext);
						  return IDENTIFIER;}

                          
{STRING}          {       yylloc.first_line = yylloc.last_line;
                          yylloc.first_column = ++yylloc.last_column; 
                          yylloc.last_column += yyleng - 1; 
                          yylval.strval = strdup(yytext);
                          return T_STRING_VAL;}

{ICONST}            { yylloc.first_line = yylloc.last_line;
                     yylloc.first_column = ++yylloc.last_column; 
                          yylloc.last_column += yyleng - 1; 
                          yylval.strval = strdup(yytext);
                          return T_INTEGER_VAL;}

{DOUBLE}        { yylloc.first_line = yylloc.last_line;
                          yylloc.first_column = ++yylloc.last_column; 
                          yylloc.last_column += yyleng - 1; 
                          yylval.strval = strdup(yytext);
                          return T_FLOAT_VAL;}
                          




 /* Regex to remove comments */
^{IDENTIFIER}{1,31}$ { yyerror("Identifier length exceeded 31, truncated");} 

 /* .                       { yyerror("Invalid character"); } */

%%