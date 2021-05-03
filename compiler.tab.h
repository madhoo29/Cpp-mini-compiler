/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
     T_GR_EQ = 296,
     T_LS_EQ = 297,
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
/* Tokens.  */
#define T_MAIN 258
#define T_WHILE 259
#define T_IF 260
#define T_ELSE 261
#define T_INCLUDE 262
#define T_HEADER 263
#define T_SWITCH 264
#define T_CASE 265
#define T_PRINT 266
#define T_INT 267
#define T_DOUBLE 268
#define T_BOOL 269
#define T_CHAR 270
#define T_STRING 271
#define T_VOID 272
#define STRING_TERMINATE 273
#define T_COUT 274
#define T_CIN 275
#define T_EXT 276
#define T_INS 277
#define T_BREAK 278
#define T_DEFAULT 279
#define T_GE 280
#define T_LE 281
#define T_EQ 282
#define T_NE 283
#define T_OR 284
#define T_AND 285
#define T_NEWLINE 286
#define T_CHAR_VAL 287
#define T_FLOAT_VAL 288
#define T_INTEGER_VAL 289
#define T_STRING_VAL 290
#define IDENTIFIER 291
#define NOT_STRING 292
#define T_LOGICAL_OR 293
#define T_LOGICAL_AND 294
#define T_NOT_EQ 295
#define T_GR_EQ 296
#define T_LS_EQ 297
#define T_INC 298
#define T_DEC 299
#define T_TRUE 300
#define T_FALSE 301
#define T_RETURN 302
#define T_CONST 303
#define T_AUTO 304
#define T_CLASS 305
#define T_PRIVATE 306
#define T_PUBLIC 307
#define T_PROTECTED 308




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 96 "compiler.y"
{  
  struct {
     char* strval;
     int  intval;
  } structure;
}
/* Line 1529 of yacc.c.  */
#line 162 "compiler.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
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
