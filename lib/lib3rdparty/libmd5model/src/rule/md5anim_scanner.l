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
#include <string>

#include "libmd5defines.h"
#include "md5anim_grammer.h"
#define YYSTYPE MD5ANIM_STYPE

#define YY_INPUT(buf,result,max_size) \
	Md5Parser* parser=(Md5Parser*) md5anim_get_extra(yyg); \
	result=parser->m_io(parser->m_file,buf,max_size);
	
%}


%option yylineno 
%option reentrant 
%option never-interactive 
%option nounput
%option noyywrap
%option prefix="md5anim_"

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
"\"".*"\""		yytext[yyleng-1]='\0'; yylval_param->ctype = new std::string(yytext + 1); return STRING;
"{"			return LCURLY;
"}"			return RCURLY;
"("			return LBRACKET;
")"			return RBRACKET;
"-"?{digit}*"."{digit}+	yylval_param->ftype = (float)atof(yytext); return FLOAT;
"-"?{digit}+		yylval_param->itype = atoi(yytext); return INTEGER;
"//".*\n		/* eating up comments */
[ \t\n]+		/* eating up whitespace */
.			/* nada */	

%%
