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

#ifndef YY_MD5MESH_MD5MESH_GRAMMER_H_INCLUDED
# define YY_MD5MESH_MD5MESH_GRAMMER_H_INCLUDED
/* Debug traces.  */
#ifndef MD5MESH_DEBUG
# if defined YYDEBUG
#if YYDEBUG
#   define MD5MESH_DEBUG 1
#  else
#   define MD5MESH_DEBUG 0
#  endif
# else /* ! defined YYDEBUG */
#  define MD5MESH_DEBUG 0
# endif /* ! defined YYDEBUG */
#endif  /* ! defined MD5MESH_DEBUG */
#if MD5MESH_DEBUG
extern int md5mesh_debug;
#endif

/* Token type.  */
#ifndef MD5MESH_TOKENTYPE
# define MD5MESH_TOKENTYPE
  enum md5mesh_tokentype
  {
    INTEGER = 258,
    FLOAT = 259,
    VERSIONID = 260,
    CMDLINEID = 261,
    STRING = 262,
    NUMJOINTSID = 263,
    NUMMESHESID = 264,
    JOINTSID = 265,
    MESHID = 266,
    LCURLY = 267,
    RCURLY = 268,
    LBRACKET = 269,
    RBRACKET = 270,
    SHADERID = 271,
    WEIGHTID = 272,
    TRIID = 273,
    VERTID = 274,
    NUMVERTSID = 275,
    NUMTRISID = 276,
    NUMWEIGHTSID = 277
  };
#endif

/* Value type.  */
#if ! defined MD5MESH_STYPE && ! defined MD5MESH_STYPE_IS_DECLARED
typedef union MD5MESH_STYPE MD5MESH_STYPE;
union MD5MESH_STYPE
{
#line 41 "md5mesh_grammer.y" /* yacc.c:1909  */

	int itype;
	float ftype;
	std::string* ctype;

#line 91 "../md5mesh_grammer.h" /* yacc.c:1909  */
};
# define MD5MESH_STYPE_IS_TRIVIAL 1
# define MD5MESH_STYPE_IS_DECLARED 1
#endif



int md5mesh_parse (Md5Parser* param);

#endif /* !YY_MD5MESH_MD5MESH_GRAMMER_H_INCLUDED  */
