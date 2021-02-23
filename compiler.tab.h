
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     T_MAIN = 258,
     T_WHILE = 259,
     T_IF = 260,
     T_ELSE = 261,
     T_INCLUDE = 262,
     T_HEADER = 263,
     T_SWITCH = 264,
     T_CASE = 265,
     T_PRINT = 266,
     T_INT = 267,
     T_DOUBLE = 268,
     T_BOOL = 269,
     T_CHAR = 270,
     T_STRING = 271,
     T_VOID = 272,
     T_COUT = 273,
     T_CIN = 274,
     T_EXT = 275,
     T_INS = 276,
     T_BREAK = 277,
     T_DEFAULT = 278,
     T_GE = 279,
     T_LE = 280,
     T_EQ = 281,
     T_NE = 282,
     T_OR = 283,
     T_AND = 284,
     T_NEWLINE = 285,
     T_CHAR_VAL = 286,
     T_FLOAT_VAL = 287,
     T_INTEGER_VAL = 288,
     T_STRING_VAL = 289,
     IDENTIFIER = 290,
     T_LOGICAL_OR = 291,
     T_LOGICAL_AND = 292,
     T_NOT_EQ = 293,
     T_GR_EQ = 294,
     T_LS_EQ = 295,
     T_INC = 296,
     T_DEC = 297,
     T_TRUE = 298,
     T_FALSE = 299,
     T_RETURN = 300,
     T_CONST = 301,
     T_AUTO = 302
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 50 ".\\compiler.y"
int intval; char* strval;


/* Line 1676 of yacc.c  */
#line 103 "compiler.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif

extern YYLTYPE yylloc;

