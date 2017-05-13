/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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
    VARLIST = 258,
    FUNCT = 259,
    VALUE = 260,
    REFERENCE = 261,
    ID_REF = 262,
    ID_ARRAY_REF = 263,
    MAIN = 264,
    BODY = 265,
    BEG = 266,
    RETURN = 267,
    END = 268,
    NUM = 269,
    ID = 270,
    WRITE = 271,
    READ = 272,
    IF = 273,
    THEN = 274,
    ELSE = 275,
    ENDIF = 276,
    WHILE = 277,
    DO = 278,
    ENDWHILE = 279,
    BOOLEAN = 280,
    INTEGER = 281,
    VOID = 282,
    DECL = 283,
    ENDDECL = 284,
    TRUE = 285,
    FALSE = 286,
    AND = 287,
    OR = 288,
    NOT = 289,
    LT = 290,
    LE = 291,
    GT = 292,
    GE = 293,
    EQ = 294,
    NE = 295
  };
#endif
/* Tokens.  */
#define VARLIST 258
#define FUNCT 259
#define VALUE 260
#define REFERENCE 261
#define ID_REF 262
#define ID_ARRAY_REF 263
#define MAIN 264
#define BODY 265
#define BEG 266
#define RETURN 267
#define END 268
#define NUM 269
#define ID 270
#define WRITE 271
#define READ 272
#define IF 273
#define THEN 274
#define ELSE 275
#define ENDIF 276
#define WHILE 277
#define DO 278
#define ENDWHILE 279
#define BOOLEAN 280
#define INTEGER 281
#define VOID 282
#define DECL 283
#define ENDDECL 284
#define TRUE 285
#define FALSE 286
#define AND 287
#define OR 288
#define NOT 289
#define LT 290
#define LE 291
#define GT 292
#define GE 293
#define EQ 294
#define NE 295

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 29 "stage10.y" /* yacc.c:1909  */

	int val;
	char* identifier;
	struct tree_node *ptr;

#line 140 "y.tab.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
