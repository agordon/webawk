/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
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
     FIRSTTOKEN = 258,
     FINAL = 259,
     FATAL = 260,
     LT = 261,
     LE = 262,
     GT = 263,
     GE = 264,
     EQ = 265,
     NE = 266,
     MATCH = 267,
     NOTMATCH = 268,
     APPEND = 269,
     ADD = 270,
     MINUS = 271,
     MULT = 272,
     DIVIDE = 273,
     MOD = 274,
     UMINUS = 275,
     ASSIGN = 276,
     ADDEQ = 277,
     SUBEQ = 278,
     MULTEQ = 279,
     DIVEQ = 280,
     MODEQ = 281,
     JUMP = 282,
     XBEGIN = 283,
     XEND = 284,
     NL = 285,
     PRINT = 286,
     PRINTF = 287,
     SPRINTF = 288,
     SPLIT = 289,
     IF = 290,
     ELSE = 291,
     WHILE = 292,
     FOR = 293,
     IN = 294,
     NEXT = 295,
     EXIT = 296,
     BREAK = 297,
     CONTINUE = 298,
     PROGRAM = 299,
     PASTAT = 300,
     PASTAT2 = 301,
     REGEXPR = 302,
     ASGNOP = 303,
     BOR = 304,
     AND = 305,
     NOT = 306,
     INDEX = 307,
     LSUBSTR = 308,
     SUBSTR = 309,
     FNCN = 310,
     ARRAY = 311,
     VAR = 312,
     NUMBER = 313,
     GETLINE = 314,
     MATCHOP = 315,
     RELOP = 316,
     OR = 317,
     CHAR = 318,
     NCCL = 319,
     CCL = 320,
     DOT = 321,
     STRING = 322,
     CAT = 323,
     QUEST = 324,
     PLUS = 325,
     STAR = 326,
     DECR = 327,
     INCR = 328,
     PREDECR = 329,
     POSTDECR = 330,
     PREINCR = 331,
     POSTINCR = 332,
     INDIRECT = 333,
     FIELD = 334,
     LASTTOKEN = 335
   };
#endif
/* Tokens.  */
#define FIRSTTOKEN 258
#define FINAL 259
#define FATAL 260
#define LT 261
#define LE 262
#define GT 263
#define GE 264
#define EQ 265
#define NE 266
#define MATCH 267
#define NOTMATCH 268
#define APPEND 269
#define ADD 270
#define MINUS 271
#define MULT 272
#define DIVIDE 273
#define MOD 274
#define UMINUS 275
#define ASSIGN 276
#define ADDEQ 277
#define SUBEQ 278
#define MULTEQ 279
#define DIVEQ 280
#define MODEQ 281
#define JUMP 282
#define XBEGIN 283
#define XEND 284
#define NL 285
#define PRINT 286
#define PRINTF 287
#define SPRINTF 288
#define SPLIT 289
#define IF 290
#define ELSE 291
#define WHILE 292
#define FOR 293
#define IN 294
#define NEXT 295
#define EXIT 296
#define BREAK 297
#define CONTINUE 298
#define PROGRAM 299
#define PASTAT 300
#define PASTAT2 301
#define REGEXPR 302
#define ASGNOP 303
#define BOR 304
#define AND 305
#define NOT 306
#define INDEX 307
#define LSUBSTR 308
#define SUBSTR 309
#define FNCN 310
#define ARRAY 311
#define VAR 312
#define NUMBER 313
#define GETLINE 314
#define MATCHOP 315
#define RELOP 316
#define OR 317
#define CHAR 318
#define NCCL 319
#define CCL 320
#define DOT 321
#define STRING 322
#define CAT 323
#define QUEST 324
#define PLUS 325
#define STAR 326
#define DECR 327
#define INCR 328
#define PREDECR 329
#define POSTDECR 330
#define PREINCR 331
#define POSTINCR 332
#define INDIRECT 333
#define FIELD 334
#define LASTTOKEN 335




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


