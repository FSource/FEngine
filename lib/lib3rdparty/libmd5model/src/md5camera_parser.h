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
     NUMCUTSID = 262,
     NUMFRAMESID = 263,
     FRAMERATEID = 264,
     LCURLY = 265,
     RCURLY = 266,
     LBRACKET = 267,
     RBRACKET = 268,
     CAMERAID = 269,
     CUTSID = 270
   };
#endif
#define NUMBER 258
#define VERSIONID 259
#define CMDLINEID 260
#define STRING 261
#define NUMCUTSID 262
#define NUMFRAMESID 263
#define FRAMERATEID 264
#define LCURLY 265
#define RCURLY 266
#define LBRACKET 267
#define RBRACKET 268
#define CAMERAID 269
#define CUTSID 270




#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
#line 47 "md5camera_parser.y"
typedef union YYSTYPE {
	int itype;
	float ftype;
	const char* ctype;
} YYSTYPE;
/* Line 1275 of yacc.c.  */
#line 73 "md5camera_parser.h"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;



