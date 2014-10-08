/* A Bison parser, made by GNU Bison 1.875c.  */

/* Skeleton parser for Yacc-like parsing with Bison,
   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     NUMBER = 258,
     VERSIONID = 259,
     CMDLINEID = 260,
     STRING = 261,
     NUMJOINTSID = 262,
     NUMFRAMESID = 263,
     JOINTSID = 264,
     FRAMERATEID = 265,
     LCURLY = 266,
     RCURLY = 267,
     LBRACKET = 268,
     RBRACKET = 269,
     NUMANICOMPSID = 270,
     HIERARCHYID = 271,
     BOUNDSID = 272,
     BASEFRAMEID = 273,
     FRAMEID = 274
   };
#endif
#define NUMBER 258
#define VERSIONID 259
#define CMDLINEID 260
#define STRING 261
#define NUMJOINTSID 262
#define NUMFRAMESID 263
#define JOINTSID 264
#define FRAMERATEID 265
#define LCURLY 266
#define RCURLY 267
#define LBRACKET 268
#define RBRACKET 269
#define NUMANICOMPSID 270
#define HIERARCHYID 271
#define BOUNDSID 272
#define BASEFRAMEID 273
#define FRAMEID 274




#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
#line 62 "md5anim_parser.y"
typedef union YYSTYPE {
	int itype;
	float ftype;
	const char* ctype;
} YYSTYPE;
/* Line 1275 of yacc.c.  */
#line 81 "md5anim_parser.h"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;



