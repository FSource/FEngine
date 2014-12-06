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

#ifndef YY_LIBOBJMTL_LIBOBJMTLGRAMMER_H_INCLUDED
# define YY_LIBOBJMTL_LIBOBJMTLGRAMMER_H_INCLUDED
/* Debug traces.  */
#ifndef LIBOBJMTL_DEBUG
# if defined YYDEBUG
#if YYDEBUG
#   define LIBOBJMTL_DEBUG 1
#  else
#   define LIBOBJMTL_DEBUG 0
#  endif
# else /* ! defined YYDEBUG */
#  define LIBOBJMTL_DEBUG 0
# endif /* ! defined YYDEBUG */
#endif  /* ! defined LIBOBJMTL_DEBUG */
#if LIBOBJMTL_DEBUG
extern int libobjmtl_debug;
#endif

/* Token type.  */
#ifndef LIBOBJMTL_TOKENTYPE
# define LIBOBJMTL_TOKENTYPE
  enum libobjmtl_tokentype
  {
    ERR = 258,
    EOL = 259,
    DECIMAL = 260,
    INTEGER = 261,
    WORD = 262,
    FILEPATH = 263,
    NEWMTL_MARKER = 264,
    KA_MARKER = 265,
    KD_MARKER = 266,
    KS_MARKER = 267,
    D_MARKER = 268,
    NS_MARKER = 269,
    NI_MARKER = 270,
    ILLUM_MARKER = 271,
    MAPKA_MARKER = 272,
    MAPKD_MARKER = 273,
    MAPKS_MARKER = 274,
    MAPD_MARKER = 275,
    MAPBUMP_MARKER = 276
  };
#endif

/* Value type.  */
#if ! defined LIBOBJMTL_STYPE && ! defined LIBOBJMTL_STYPE_IS_DECLARED
typedef union LIBOBJMTL_STYPE LIBOBJMTL_STYPE;
union LIBOBJMTL_STYPE
{
#line 38 "mtlgrammer.y" /* yacc.c:1909  */

  int itype;    			/* integer */
  float ftype;    			/* float value */
  std::string* ctype;    	/* character string */

#line 90 "../LibObjMtlGrammer.h" /* yacc.c:1909  */
};
# define LIBOBJMTL_STYPE_IS_TRIVIAL 1
# define LIBOBJMTL_STYPE_IS_DECLARED 1
#endif



int libobjmtl_parse (LibObjParserContext* param);

#endif /* !YY_LIBOBJMTL_LIBOBJMTLGRAMMER_H_INCLUDED  */
