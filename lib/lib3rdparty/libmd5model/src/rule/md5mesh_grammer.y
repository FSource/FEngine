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
#include "md5mesh_grammer.h"
#include "md5mesh_scanner.h"


#define MESH_DATA ((Md5Mesh*) param->m_data)
#define param_scanner param->m_scanner


void md5mesh_error(void* param,char const* s)
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
%token <itype> NUMMESHESID
%token <itype> JOINTSID
%token <itype> MESHID
%token <itype> LCURLY
%token <itype> RCURLY
%token <itype> LBRACKET
%token <itype> RBRACKET
%token <itype> SHADERID
%token <itype> WEIGHTID
%token <itype> TRIID
%token <itype> VERTID
%token <itype> NUMVERTSID
%token <itype> NUMTRISID
%token <itype> NUMWEIGHTSID

%type <ftype> number



%error-verbose
%parse-param{Md5Parser* param}
%lex-param{Md5Parser* param_scanner}

%define api.pure
%define api.prefix{md5mesh_}

%start md5mesh_file


%%

md5mesh_file:	md5mesh_header md5mesh_jointspart md5mesh_meshpart
{
	if(MESH_DATA->m_header.m_jointsNu!=(int)MESH_DATA->m_joints.size())
	{
		printf("Header JointNu Is(%d),But Only (%d) Find",
				MESH_DATA->m_header.m_jointsNu,(int)MESH_DATA->m_joints.size());
	}
	if(MESH_DATA->m_header.m_meshNu != (int) MESH_DATA->m_subMeshs.size())
	{
		printf("Header MeshNu Is(%d),But Only(%d) Find",
				MESH_DATA->m_header.m_meshNu,(int) MESH_DATA->m_subMeshs.size());
	}
}
;



md5mesh_header:	md5mesh_version md5mesh_cmdline md5mesh_numjoints md5mesh_nummeshes ;

md5mesh_version:	VERSIONID INTEGER
{
	MESH_DATA->m_header.m_version=$2;
}
;

md5mesh_cmdline:	CMDLINEID STRING
{
	MESH_DATA->m_header.m_commandLine=*($2);
	delete $2;
}

;

md5mesh_numjoints:	NUMJOINTSID INTEGER 
{
	MESH_DATA->m_header.m_jointsNu=$2;
}

;

md5mesh_nummeshes:	NUMMESHESID INTEGER 
{
	MESH_DATA->m_header.m_meshNu=$2;
}
;

md5mesh_jointspart:	JOINTSID LCURLY md5mesh_joints RCURLY ;


md5mesh_joints:	md5mesh_joint | md5mesh_joints md5mesh_joint ;

md5mesh_joint:	STRING INTEGER LBRACKET number number number RBRACKET LBRACKET number number number RBRACKET
{
	Md5Point p($4,$5,$6);
	Md5Quat q($9,$10,$11);
	MESH_DATA->appendJoint(*($1),$2,p,q);
	delete $1;
}
;

md5mesh_meshpart:	md5mesh_mesh | md5mesh_meshpart md5mesh_mesh ;



md5mesh_mesh:	MESHID LCURLY md5mesh_shader md5mesh_numverts md5mesh_verts md5mesh_numtris md5mesh_tris md5mesh_numweights md5mesh_weights RCURLY 
{
	MESH_DATA->commitSubMesh();
}
;

md5mesh_shader:	SHADERID STRING
{
	MESH_DATA->getCurrentSubMesh()->setTextureUrl($2->c_str());
	delete $2;
}
;

md5mesh_numverts:	NUMVERTSID INTEGER
{
	MESH_DATA->getCurrentSubMesh()->setVertexNu($2);
}

;

md5mesh_verts:	md5mesh_vert | md5mesh_verts md5mesh_vert ;

md5mesh_vert:	VERTID INTEGER LBRACKET number number RBRACKET INTEGER INTEGER  
{
	MESH_DATA->getCurrentSubMesh()->setVertex($2,Md5Vertex($4,$5,$7,$8));
}
;

md5mesh_numtris:	NUMTRISID INTEGER 
{
	MESH_DATA->getCurrentSubMesh()->setTriangleNu($2);
}			   
;

md5mesh_tris:	md5mesh_tri | md5mesh_tris md5mesh_tri ;

md5mesh_tri:	TRIID INTEGER INTEGER INTEGER INTEGER
{
	MESH_DATA->getCurrentSubMesh()->setTriangle($2,Md5Triangle($3,$4,$5));
}
;

md5mesh_numweights:	NUMWEIGHTSID INTEGER
{
	MESH_DATA->getCurrentSubMesh()->setWeightNu($2);
		
}
;

md5mesh_weights:	md5mesh_weight | md5mesh_weights md5mesh_weight ;


md5mesh_weight:	WEIGHTID INTEGER INTEGER number LBRACKET number number number RBRACKET
{
	Md5Weight  w($3,$4,$6,$7,$8);
	MESH_DATA->getCurrentSubMesh()->setWeight($2,w);
};

number: INTEGER 
{
		$$=float($1);
}
| FLOAT 
{
		$$=$1;
} ;
%%

Md5Mesh* LibMd5Mesh_Parse(void* file,LibMd5_ReadIo io)
{
	Md5Mesh* mesh=new Md5Mesh;
	yyscan_t scanner=NULL; 
	md5mesh_lex_init(&scanner);
	Md5Parser* parser=new Md5Parser(scanner,mesh,file,io);
	md5mesh_set_extra(parser,scanner);

	if(md5mesh_parse(parser)!=0)
	{
		delete mesh;
		mesh=NULL;
	}

	md5mesh_lex_destroy(scanner);
	delete parser;

	return mesh;
}


