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
     T_MAIN = 259,
     T_WHILE = 260,
     T_IF = 261,
     T_ELSE = 262,
     T_INCLUDE = 263,
     T_HEADER = 264,
     T_INT = 265,
     T_DOUBLE = 266,
     T_BOOL = 267,
     T_CHAR = 268,
     T_STRING = 269,
     T_VOID = 270,
     T_COUT = 271,
     T_CIN = 272,
     T_GE = 273,
     T_LE = 274,
     T_EQ = 275,
     T_NE = 276,
     T_OR = 277,
     T_AND = 278,
     T_NEWLINE = 279,
     T_CHAR_VAL = 280,
     T_FLOAT_VAL = 281,
     T_INTEGER_VAL = 282,
     T_STRING_VAL = 283,
     IDENTIFIER = 284
   };
#endif
/* Tokens.  */
#define T_MAIN 259
#define T_WHILE 260
#define T_IF 261
#define T_ELSE 262
#define T_INCLUDE 263
#define T_HEADER 264
#define T_INT 265
#define T_DOUBLE 266
#define T_BOOL 267
#define T_CHAR 268
#define T_STRING 269
#define T_VOID 270
#define T_COUT 271
#define T_CIN 272
#define T_GE 273
#define T_LE 274
#define T_EQ 275
#define T_NE 276
#define T_OR 277
#define T_AND 278
#define T_NEWLINE 279
#define T_CHAR_VAL 280
#define T_FLOAT_VAL 281
#define T_INTEGER_VAL 282
#define T_STRING_VAL 283
#define IDENTIFIER 284




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 21 "yacc.y"
{int INT; char* STR; double DOUBLE; char CHAR; }
/* Line 1529 of yacc.c.  */
#line 107 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

