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

#ifndef YY_MD5ANIM_MD5ANIM_GRAMMER_H_INCLUDED
# define YY_MD5ANIM_MD5ANIM_GRAMMER_H_INCLUDED
/* Debug traces.  */
#ifndef MD5ANIM_DEBUG
# if defined YYDEBUG
#if YYDEBUG
#   define MD5ANIM_DEBUG 1
#  else
#   define MD5ANIM_DEBUG 0
#  endif
# else /* ! defined YYDEBUG */
#  define MD5ANIM_DEBUG 0
# endif /* ! defined YYDEBUG */
#endif  /* ! defined MD5ANIM_DEBUG */
#if MD5ANIM_DEBUG
extern int md5anim_debug;
#endif

/* Token type.  */
#ifndef MD5ANIM_TOKENTYPE
# define MD5ANIM_TOKENTYPE
  enum md5anim_tokentype
  {
    INTEGER = 258,
    FLOAT = 259,
    VERSIONID = 260,
    CMDLINEID = 261,
    STRING = 262,
    NUMJOINTSID = 263,
    NUMFRAMESID = 264,
    JOINTSID = 265,
    FRAMERATEID = 266,
    LCURLY = 267,
    RCURLY = 268,
    LBRACKET = 269,
    RBRACKET = 270,
    NUMANICOMPSID = 271,
    HIERARCHYID = 272,
    BOUNDSID = 273,
    BASEFRAMEID = 274,
    FRAMEID = 275
  };
#endif

/* Value type.  */
#if ! defined MD5ANIM_STYPE && ! defined MD5ANIM_STYPE_IS_DECLARED
typedef union MD5ANIM_STYPE MD5ANIM_STYPE;
union MD5ANIM_STYPE
{
#line 42 "md5anim_grammer.y" /* yacc.c:1909  */

	int itype;
	float ftype;
	std::string* ctype;

#line 89 "../md5anim_grammer.h" /* yacc.c:1909  */
};
# define MD5ANIM_STYPE_IS_TRIVIAL 1
# define MD5ANIM_STYPE_IS_DECLARED 1
#endif



int md5anim_parse (Md5Parser* param);

#endif /* !YY_MD5ANIM_MD5ANIM_GRAMMER_H_INCLUDED  */
