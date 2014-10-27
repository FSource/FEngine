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
#include "libmd5model.h"
#include "md5anim_grammer.h"
#include "md5anim_scanner.h"


#define ANIM_DATA ((Md5Anim*) param->m_data)
#define param_scanner param->m_scanner


void md5anim_error(void* param,char const* s)
{
	fprintf(stderr, "%s\n", s);
}

%}

%union{
	int itype;
	float ftype;
	std::string* ctype;
}

%token <itype> INTEGER
%token <ftype> FLOAT 
%token <itype> VERSIONID
%token <itype> CMDLINEID
%token <ctype> STRING
%token <itype> NUMJOINTSID
%token <itype> NUMFRAMESID
%token <itype> JOINTSID
%token <itype> FRAMERATEID
%token <itype> LCURLY
%token <itype> RCURLY
%token <itype> LBRACKET
%token <itype> RBRACKET
%token <itype> NUMANICOMPSID
%token <itype> HIERARCHYID
%token <itype> BOUNDSID
%token <itype> BASEFRAMEID 
%token <itype> FRAMEID 

%type <ftype> value


%error-verbose
%parse-param{Md5Parser* param}
%lex-param{Md5Parser* param_scanner}
%define api.pure
%define api.prefix{md5anim_}

%start md5anim_file 


%%


md5anim_file:	md5anim_header md5anim_jointspart md5anim_boundspart md5anim_baseframe_part md5anim_framepart ;

md5anim_header:	md5anim_version md5anim_cmdline md5anim_numframes md5anim_numjoints md5anim_framerate md5anim_numanimated_comps ;

md5anim_version:	VERSIONID INTEGER
{
	ANIM_DATA->m_header.m_version=$2;
}
;

md5anim_cmdline:	CMDLINEID STRING  
{
	ANIM_DATA->m_header.m_commandLine=*$2;
	delete $2;
}
;

md5anim_numframes:	NUMFRAMESID INTEGER
{
	ANIM_DATA->m_header.m_numFrames =$2;
}
;

md5anim_numjoints:	NUMJOINTSID INTEGER
{
	ANIM_DATA->m_header.m_numJoints =$2;
}
;

md5anim_framerate:	FRAMERATEID INTEGER
{
	ANIM_DATA->m_header.m_frameRate=$2;
}
;

md5anim_numanimated_comps:	NUMANICOMPSID INTEGER
{
	ANIM_DATA->m_header.m_numAnimatedComponent=$2;
}
;

md5anim_jointspart:	HIERARCHYID LCURLY md5anim_joints RCURLY ;

md5anim_joints:		md5anim_joint |	md5anim_joints md5anim_joint ;

md5anim_joint:		STRING INTEGER INTEGER INTEGER 
{
	ANIM_DATA->appendJoint($1->c_str(),$2,$3,$4);
	delete $1;
}
;


md5anim_boundspart:		BOUNDSID LCURLY md5anim_bounds RCURLY ; 

md5anim_bounds:		md5anim_bound |	md5anim_bounds md5anim_bound;


md5anim_bound:		LBRACKET value value value RBRACKET LBRACKET value value value RBRACKET 
{
		ANIM_DATA->appendBound(Md5Point($2,$3,$4),Md5Point($7,$8,$9));
}
;


md5anim_baseframe_part:	BASEFRAMEID LCURLY md5anim_baseframe_items RCURLY ;


md5anim_baseframe_items: md5anim_baseframe_item | md5anim_baseframe_items	md5anim_baseframe_item ; 

md5anim_baseframe_item:	LBRACKET value value value RBRACKET LBRACKET value value value RBRACKET 
{
	ANIM_DATA->appendBaseFrame($2,$3,$4,$7,$8,$9);
}
;




md5anim_framepart: 	md5anim_frame |	md5anim_framepart md5anim_frame ;

md5anim_frame: FRAMEID INTEGER LCURLY md5anim_framenumbers RCURLY
{
	ANIM_DATA->commitAnimFrame();
}
| FRAMEID INTEGER LCURLY RCURLY
{
	ANIM_DATA->getCurrentAnimFrame();
	ANIM_DATA->commitAnimFrame();
}
;


md5anim_framenumbers:md5anim_framenumber | md5anim_framenumbers md5anim_framenumber ;

md5anim_framenumber: value 
{  
	ANIM_DATA->getCurrentAnimFrame()->m_data.push_back($1);
}
;

value : FLOAT 
{
	$$=$1;
}
| INTEGER 
{
	$$=(float) $1;
}
;

%%
Md5Anim* LibMd5Anim_Parse(void* file,LibMd5_ReadIo io)
{
	Md5Anim* anim=new Md5Anim;
	yyscan_t scanner=NULL; 
	md5anim_lex_init(&scanner);
	Md5Parser* parser=new Md5Parser(scanner,anim,file,io);
	md5anim_set_extra(parser,scanner);

	if(md5anim_parse(parser)!=0)
	{
		delete anim;
		anim=NULL;
	}

	md5anim_lex_destroy(scanner);
	delete parser;

	return anim;
}
