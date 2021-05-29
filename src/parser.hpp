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

#ifndef YY_YY_PARSER_HPP_INCLUDED
# define YY_YY_PARSER_HPP_INCLUDED
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
    DOUBLE = 259,
    CHARACTER = 260,
    BOOLEAN = 261,
    VARIABLE = 262,
    WHILE = 263,
    IF = 264,
    PRINT = 265,
    FOR = 266,
    REPEAT = 267,
    UNTIL = 268,
    SWITCH = 269,
    CASE = 270,
    DEFAULT = 271,
    INT = 272,
    DOB = 273,
    CHAR = 274,
    BOOL = 275,
    IFX = 276,
    ELSE = 277,
    PLUS_EQ = 278,
    MINUS_EQ = 279,
    MUL_EQ = 280,
    DIV_EQ = 281,
    MOD_EQ = 282,
    SH_LE_EQ = 283,
    SH_RI_EQ = 284,
    AND_EQ = 285,
    XOR_EQ = 286,
    OR_EQ = 287,
    OR = 288,
    AND = 289,
    GE = 290,
    LE = 291,
    EQ = 292,
    NE = 293,
    SHIFT_LEFT = 294,
    SHIFT_RIGHT = 295,
    UMINUS = 296,
    UPLUS = 297
  };
#endif
/* Tokens.  */
#define INTEGER 258
#define DOUBLE 259
#define CHARACTER 260
#define BOOLEAN 261
#define VARIABLE 262
#define WHILE 263
#define IF 264
#define PRINT 265
#define FOR 266
#define REPEAT 267
#define UNTIL 268
#define SWITCH 269
#define CASE 270
#define DEFAULT 271
#define INT 272
#define DOB 273
#define CHAR 274
#define BOOL 275
#define IFX 276
#define ELSE 277
#define PLUS_EQ 278
#define MINUS_EQ 279
#define MUL_EQ 280
#define DIV_EQ 281
#define MOD_EQ 282
#define SH_LE_EQ 283
#define SH_RI_EQ 284
#define AND_EQ 285
#define XOR_EQ 286
#define OR_EQ 287
#define OR 288
#define AND 289
#define GE 290
#define LE 291
#define EQ 292
#define NE 293
#define SHIFT_LEFT 294
#define SHIFT_RIGHT 295
#define UMINUS 296
#define UPLUS 297

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 25 "calc3.y" /* yacc.c:1909  */

    int iValue;                         /* integer value */
    double dValue;                      /* double value */
    char cValue;                        /* char value */
    bool bValue;                        /* boolean value */
    char sIndex;                        /* symbol table index */
    nodeType *nPtr;                     /* node pointer */
    switchstatement *swtch;  

#line 148 "parser.hpp" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_HPP_INCLUDED  */
