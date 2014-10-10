/* Copyright (C) 2004 W.P. van Paassen - peter@paassen.tmfweb.nl

   This file is part of libmd5model
   
   libmd5model will attempt to parse ID's Doom3 mesh, animation and camera model formats
   
   libmd5model is free software; you can redistribute it and/or modify it under
   the terms of the GNU General Public License as published by the Free
   Software Foundation; either version 2 of the License, or (at your
   option) any later version.

   libmd5model is distributed in the hope that it will be useful, but WITHOUT
   ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
   FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
   for more details.

   You should have received a copy of the GNU General Public License
   along with libmd5model; see the file COPYING.  If not, write to the Free
   Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA  */
%{
#include <stdio.h>
#include "md5anim_defines.h"
#include "md5anim_parser.h"
#include "libmd5modelext.h"
%}
%option nounput
%option noyywrap
%option prefix="MD5ANIM_"

digit			[0-9]

%%

MD5Version		return VERSIONID;
commandline		return CMDLINEID;
numJoints		return NUMJOINTSID;
numFrames		return NUMFRAMESID;
frameRate		return FRAMERATEID;
numAnimatedComponents	return NUMANICOMPSID;
hierarchy		return HIERARCHYID;
bounds			return BOUNDSID;
baseframe		return BASEFRAMEID;
frame			return FRAMEID;
"\"".*"\""		yytext[yyleng-1]='\0'; MD5ANIM_lval.ctype = yytext + 1; return STRING;
"{"			return LCURLY;
"}"			return RCURLY;
"("			return LBRACKET;
")"			return RBRACKET;
"-"?{digit}*"."{digit}+	MD5ANIM_lval.ftype = (float)atof(yytext); return NUMBER;
"-"?{digit}+		MD5ANIM_lval.itype = atoi(yytext); return NUMBER;
"//".*\n		/* eating up comments */
[ \t\n]+		/* eating up whitespace */
.			/* nada */	

%%
