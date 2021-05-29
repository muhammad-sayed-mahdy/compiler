/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    INTEGER = 258,
    VARIABLE = 259,
    WHILE = 260,
    IF = 261,
    PRINT = 262,
    FOR = 263,
    REPEAT = 264,
    UNTIL = 265,
    SWITCH = 266,
    CASE = 267,
    DEFAULT = 268,
    IFX = 269,
    ELSE = 270,
    PLUS_EQ = 271,
    MINUS_EQ = 272,
    MUL_EQ = 273,
    DIV_EQ = 274,
    MOD_EQ = 275,
    SH_LE_EQ = 276,
    SH_RI_EQ = 277,
    AND_EQ = 278,
    XOR_EQ = 279,
    OR_EQ = 280,
    OR = 281,
    AND = 282,
    GE = 283,
    LE = 284,
    EQ = 285,
    NE = 286,
    SHIFT_LEFT = 287,
    SHIFT_RIGHT = 288,
    UMINUS = 289
  };
#endif
/* Tokens.  */
#define INTEGER 258
#define VARIABLE 259
#define WHILE 260
#define IF 261
#define PRINT 262
#define FOR 263
#define REPEAT 264
#define UNTIL 265
#define SWITCH 266
#define CASE 267
#define DEFAULT 268
#define IFX 269
#define ELSE 270
#define PLUS_EQ 271
#define MINUS_EQ 272
#define MUL_EQ 273
#define DIV_EQ 274
#define MOD_EQ 275
#define SH_LE_EQ 276
#define SH_RI_EQ 277
#define AND_EQ 278
#define XOR_EQ 279
#define OR_EQ 280
#define OR 281
#define AND 282
#define GE 283
#define LE 284
#define EQ 285
#define NE 286
#define SHIFT_LEFT 287
#define SHIFT_RIGHT 288
#define UMINUS 289

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 24 "calc3.y" /* yacc.c:1909  */

    int iValue;                         /* integer value */
    char sIndex;                        /* symbol table index */
    nodeType *nPtr;                     /* node pointer */
    switchstatement *swtch;  

#line 129 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
