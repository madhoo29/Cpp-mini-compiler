/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_COMPILER_TAB_H_INCLUDED
# define YY_YY_COMPILER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
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
    STRING_TERMINATE = 273,
    T_COUT = 274,
    T_CIN = 275,
    T_EXT = 276,
    T_INS = 277,
    T_BREAK = 278,
    T_DEFAULT = 279,
    T_GE = 280,
    T_LE = 281,
    T_EQ = 282,
    T_NE = 283,
    T_OR = 284,
    T_AND = 285,
    T_NEWLINE = 286,
    T_CHAR_VAL = 287,
    T_FLOAT_VAL = 288,
    T_INTEGER_VAL = 289,
    T_STRING_VAL = 290,
    IDENTIFIER = 291,
    NOT_STRING = 292,
    T_LOGICAL_OR = 293,
    T_LOGICAL_AND = 294,
    T_NOT_EQ = 295,
    T_LS_EQ = 296,
    T_GR_EQ = 297,
    T_INC = 298,
    T_DEC = 299,
    T_TRUE = 300,
    T_FALSE = 301,
    T_RETURN = 302,
    T_CONST = 303,
    T_AUTO = 304,
    T_CLASS = 305,
    T_PRIVATE = 306,
    T_PUBLIC = 307,
    T_PROTECTED = 308
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 54 "compiler.y"
int intval; char* strval;

#line 114 "compiler.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_COMPILER_TAB_H_INCLUDED  */
