%{
    #include<string.h>
    #include<stdio.h>
    #include "y.tab.h"

    int yylval;
    void yyerror(char *);
	unsigned int lineno = 0;

    extern YYLTYPE yyloc;
    #define YY_USER_INIT yylloc.first_line = 1;
    
%}

SINGLE_CHAR_OPERATORS "+"|"-"|"&"|"!"|"^"|"*"|","|"~"|";"|"/"|"="|"%"|">"|"<"|"."|"["|"]"|":"|"?"|"("|")"|"{"|"}"
SINGLE_COMMENT	\/\/(.*)
MULTI_COMMENT	\/\*(.*\n)*.*\*\/
DIGIT 			[0-9]
FRAC			(\.{DIGIT}+)?
EXP				([Ee][+-]?{DIGIT}+)?
NUMBER 			({DIGIT}+{FRAC}{EXP})
LETTER			[a-zA-Z]
IDENTIFIER		[a-zA-Z_][a-zA-Z_0-9]*
PRINT			[ -~]
CCONST			(\'{PRINT}\')|(\'\\[nftrbv]\')
STRING			\"[ -~]*\"
ICONST			{DIGIT}+
DOUBLE			({DIGIT}+(\.{DIGIT}+){EXP})
OPEN_MULTICOMMENT \/\*
CLOSE_MULTICOMMENT \*\/



%%


SINGLE_COMMENT ;

{OPEN_MULTICOMMENT}.*{CLOSE_MULTICOMMENT} ;

{OPEN_MULTICOMMENT}.* {yyerror("Unterminated Comment\n");}

 /* Regex to truncate identifiers exceeding length 31 */


[\n]            { yylloc.first_line = yylloc.last_line;
                          yylloc.first_column = ++yylloc.last_column;
                          yylloc.last_column = 0; 
                          yyloc.first_line = lineno++;
                          return T_NEWLINE;}

"main()"	        { yylloc.first_line = yylloc.last_line;
                  yylloc.first_column = ++yylloc.last_column; 
                  yylloc.last_column += yyleng - 1; 
                  return T_MAIN; }

"T_WHILE"	{ 
                  yylloc.first_line = yylloc.last_line;
                  yylloc.first_column = ++yylloc.last_column; 
                  yylloc.last_column += yyleng - 1; 
                  return T_T_WHILE; }
                          
                          
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

"include" { 
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
            
"cout"  {   yylloc.first_line = yylloc.last_line;
            yylloc.first_column = ++yylloc.last_column;
            yylloc.last_column += yyleng -1;
            return T_COUT;} 

"cin"	{   
            yylloc.first_line = yylloc.last_line;
            yylloc.first_column = ++yylloc.last_column;
            yylloc.last_column += yyleng -1;
			return T_CIN;}

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
            return T__EQ;}
            
"!="    {   yylloc.first_line = yylloc.last_line;
            yylloc.first_column = ++yylloc.last_column;
            yylloc.last_column += yyleng -1;
            return T_NE;}

"||"    {   yylloc.first_line = yylloc.last_line;
            yylloc.first_column = ++yylloc.last_column;
            yylloc.last_column += yyleng -1;
            return T__OR;
        }

"&&"    {   yylloc.first_line = yylloc.last_line;
            yylloc.first_column = ++yylloc.last_column;
            yylloc.last_column += yyleng -1;
            return T__AND;}


{SINGLE_CHAR_OPERATORS} { yylloc.first_line = yylloc.last_line;
                          yylloc.first_column = ++yylloc.last_column;
                          yylloc.last_column += yyleng -1; 
                          return atoi(*yytext); }


{CCONST}		 		{ yylloc.first_line = yylloc.last_line;
                          yylloc.first_column = ++yylloc.last_column;
                          yylloc.last_column += yyleng -1; 
                          yylval.strval = strdup(yytext);
                          return T_CHAR_VAL;}

{LETTER}({LETTER}|{DIGIT})*"\.h"?  { yylloc.first_line = yylloc.last_line;
                          yylloc.first_column = ++yylloc.last_column;
                          yylloc.last_column += yyleng -1;
                          yylval.strval = strdup(yytext);
                          return T_HEADER;} 

                          
{STRING}          { yylloc.first_line = yylloc.last_line;
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
                          


{IDENTIFIER}		{ yylval.strval = strdup(yytext);
						  return T_IDENTIFIER;}

 /* Regex to remove comments */
^{IDENTIFIER}{1,31}$ { yyerror("Identifier length exceeded 31, truncated");} 

.                       { yyerror("Invalid character"); }

%%

int main(){
    yylex();
    return 0;
}