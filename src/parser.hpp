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
    VOID = 272,
    INT = 273,
    DOB = 274,
    CHAR = 275,
    BOOL = 276,
    CONST = 277,
    RETURN = 278,
    CONTINUE = 279,
    BREAK = 280,
    IFX = 281,
    ELSE = 282,
    PLUS_EQ = 283,
    MINUS_EQ = 284,
    MUL_EQ = 285,
    DIV_EQ = 286,
    MOD_EQ = 287,
    SH_LE_EQ = 288,
    SH_RI_EQ = 289,
    AND_EQ = 290,
    XOR_EQ = 291,
    OR_EQ = 292,
    OR = 293,
    AND = 294,
    GE = 295,
    LE = 296,
    EQ = 297,
    NE = 298,
    SHIFT_LEFT = 299,
    SHIFT_RIGHT = 300,
    UMINUS = 301,
    UPLUS = 302
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
#define VOID 272
#define INT 273
#define DOB 274
#define CHAR 275
#define BOOL 276
#define CONST 277
#define RETURN 278
#define CONTINUE 279
#define BREAK 280
#define IFX 281
#define ELSE 282
#define PLUS_EQ 283
#define MINUS_EQ 284
#define MUL_EQ 285
#define DIV_EQ 286
#define MOD_EQ 287
#define SH_LE_EQ 288
#define SH_RI_EQ 289
#define AND_EQ 290
#define XOR_EQ 291
#define OR_EQ 292
#define OR 293
#define AND 294
#define GE 295
#define LE 296
#define EQ 297
#define NE 298
#define SHIFT_LEFT 299
#define SHIFT_RIGHT 300
#define UMINUS 301
#define UPLUS 302

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 25 "parser.y"

    int iValue;                         /* integer value */
    double dValue;                      /* double value */
    char cValue;                        /* char value */
    bool bValue;                        /* boolean value */
    char sIndex;                        /* symbol table index */
    nodeType *nPtr;                     /* node pointer */
    switchstatement *swtch;  

#line 161 "parser.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_HPP_INCLUDED  */
