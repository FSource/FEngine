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

#ifndef YY_LIBOBJMESH_LIBOBJMESHGRAMMER_H_INCLUDED
# define YY_LIBOBJMESH_LIBOBJMESHGRAMMER_H_INCLUDED
/* Debug traces.  */
#ifndef LIBOBJMESH_DEBUG
# if defined YYDEBUG
#if YYDEBUG
#   define LIBOBJMESH_DEBUG 1
#  else
#   define LIBOBJMESH_DEBUG 0
#  endif
# else /* ! defined YYDEBUG */
#  define LIBOBJMESH_DEBUG 0
# endif /* ! defined YYDEBUG */
#endif  /* ! defined LIBOBJMESH_DEBUG */
#if LIBOBJMESH_DEBUG
extern int libobjmesh_debug;
#endif

/* Token type.  */
#ifndef LIBOBJMESH_TOKENTYPE
# define LIBOBJMESH_TOKENTYPE
  enum libobjmesh_tokentype
  {
    ERR = 258,
    EOL = 259,
    DECIMAL = 260,
    INTEGER = 261,
    WORD = 262,
    MATERIALLIB_MARKER = 263,
    MTLFILEPATH = 264,
    USEMATERIAL_MARKER = 265,
    NULL_MARKER = 266,
    VERTEX_MARKER = 267,
    TEXEL_MARKER = 268,
    NORMAL_MARKER = 269,
    LINE_MARKER = 270,
    FACE_MARKER = 271,
    GROUP_MARKER = 272,
    OBJECT_MARKER = 273,
    SMOOTHINGGROUP_MARKER = 274,
    CAMERA_MARKER = 275,
    OFF_WORD = 276
  };
#endif

/* Value type.  */
#if ! defined LIBOBJMESH_STYPE && ! defined LIBOBJMESH_STYPE_IS_DECLARED
typedef union LIBOBJMESH_STYPE LIBOBJMESH_STYPE;
union LIBOBJMESH_STYPE
{
#line 40 "meshgrammer.y" /* yacc.c:1909  */

	int itype;    		/* integer */
	float ftype;    	/* float value */
	std::string* ctype;  /* ctype */

#line 90 "../LibObjMeshGrammer.h" /* yacc.c:1909  */
};
# define LIBOBJMESH_STYPE_IS_TRIVIAL 1
# define LIBOBJMESH_STYPE_IS_DECLARED 1
#endif



int libobjmesh_parse (LibObjParserContext* param);

#endif /* !YY_LIBOBJMESH_LIBOBJMESHGRAMMER_H_INCLUDED  */
