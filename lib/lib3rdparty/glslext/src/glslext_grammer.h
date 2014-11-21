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

#ifndef YY_GLSLEXT_SRC_GLSLEXT_GRAMMER_H_INCLUDED
# define YY_GLSLEXT_SRC_GLSLEXT_GRAMMER_H_INCLUDED
/* Debug traces.  */
#ifndef GLSLEXT_DEBUG
# if defined YYDEBUG
#if YYDEBUG
#   define GLSLEXT_DEBUG 1
#  else
#   define GLSLEXT_DEBUG 0
#  endif
# else /* ! defined YYDEBUG */
#  define GLSLEXT_DEBUG 0
# endif /* ! defined YYDEBUG */
#endif  /* ! defined GLSLEXT_DEBUG */
#if GLSLEXT_DEBUG
extern int Glslext_debug;
#endif

/* Token type.  */
#ifndef GLSLEXT_TOKENTYPE
# define GLSLEXT_TOKENTYPE
  enum Glslext_tokentype
  {
    tFeature = 258,
    tVERTEX_SHADER = 259,
    tFRAGMENT_SHADER = 260,
    tL_RB = 261,
    tR_RB = 262,
    tDOLLAR = 263,
    tCOLON = 264,
    tL_SB = 265,
    tR_SB = 266,
    tL_CB = 267,
    tR_CB = 268,
    tATTRIBUTE = 269,
    tUNIFROM = 270,
    tU_TYPE = 271,
    tFLOAT = 272,
    tINTEGER = 273,
    tNEW_LINE = 274,
    tCOMMA = 275,
    tASSIGN = 276,
    tOPERATOR = 277,
    tWORD = 278,
    tPRECISION = 279,
    tSEMICOLON = 280,
    tOP_EQUAL = 281
  };
#endif

/* Value type.  */
#if ! defined GLSLEXT_STYPE && ! defined GLSLEXT_STYPE_IS_DECLARED
typedef union GLSLEXT_STYPE GLSLEXT_STYPE;
union GLSLEXT_STYPE
{
#line 18 "../src/rule/glslext_grammer.y" /* yacc.c:1909  */

	std::string* istring;
	std::vector<float>* ivec;
	float inumber;

#line 95 "../src/glslext_grammer.h" /* yacc.c:1909  */
};
# define GLSLEXT_STYPE_IS_TRIVIAL 1
# define GLSLEXT_STYPE_IS_DECLARED 1
#endif



int Glslext_parse (GlslextParser* param);

#endif /* !YY_GLSLEXT_SRC_GLSLEXT_GRAMMER_H_INCLUDED  */
