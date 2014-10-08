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
#include "libmd5model.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#include "md5mesh_defines.h"
#include "libmd5modelext.h"

#define    yylex   MD5MESH_lex
MD5MESH_HEADER mesh_header;
MD5MESH_JOINT* mesh_joints = (MD5MESH_JOINT*)NULL;
MD5_MESH* meshes = (MD5_MESH*)NULL;
int md5_perror = 0;
int count;
int mesh_count;

extern int MD5MESH_lex(void);

void MD5MESH_error(char const* s)
{
	fprintf(stderr, "%s\n", s);
	md5_perror = 1;
}

%}
%error-verbose

%union{
	int itype;
	float ftype;
	const char* ctype;
}

%token NUMBER
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

%%

md5mesh_file:	md5mesh_header md5mesh_jointspart md5mesh_meshpart
		{
			/* post-processing */
			int i,j;

			for (i = 0; i < mesh_header.num_meshes; ++i)
			{
				for (j = 0; j < meshes[i].num_verts; ++j)
				{
					meshes[i].verts[j].weight = (MD5_WEIGHT*)(meshes[i].weights + (int)(meshes[i].verts[j].weight)); 
				}
			}
			md5_perror = 0;
		}
		;

md5mesh_header:	md5mesh_version md5mesh_cmdline md5mesh_numjoints md5mesh_nummeshes
		;

md5mesh_version:	VERSIONID NUMBER
		{
			mesh_header.version = $<itype>2;
		}
		;

md5mesh_cmdline:	CMDLINEID STRING
		{
			mesh_header.commandline = (const char*)libmd5_strdup($2);
		}
		;

md5mesh_numjoints:	NUMJOINTSID NUMBER
		{
			mesh_header.num_joints = $<itype>2;
			mesh_joints = (MD5MESH_JOINT*)malloc(mesh_header.num_joints * sizeof(MD5MESH_JOINT));
			count = 0;
		}
		;

md5mesh_nummeshes:	NUMMESHESID NUMBER
		{
			mesh_header.num_meshes = $<itype>2;
			meshes = (MD5_MESH*)malloc(mesh_header.num_meshes * sizeof(MD5_MESH));
			mesh_count = 0;
		}
		;

md5mesh_jointspart:	JOINTSID LCURLY md5mesh_joints RCURLY 
		{
			if (count != mesh_header.num_joints)
				MD5MESH_error("Error: Incorrect number of joints");	
		}
		;

md5mesh_joints:	md5mesh_joint
		| md5mesh_joints md5mesh_joint
		;

md5mesh_joint:	STRING NUMBER LBRACKET NUMBER NUMBER NUMBER RBRACKET LBRACKET NUMBER NUMBER NUMBER RBRACKET
		{
			if (count < mesh_header.num_joints)
			{
				float tmp,q1,q2,q3;
				int idx;

				mesh_joints[count].name = (const char*)libmd5_strdup($1);
				idx = $<itype>2;
				if (idx != -1)
				{
					mesh_joints[count].parent = (MD5MESH_JOINT*)(mesh_joints + $<itype>2);
				}
				else
				{
					mesh_joints[count].parent = (MD5MESH_JOINT*)NULL;
				}

				mesh_joints[count].position.x = $<ftype>4;
				mesh_joints[count].position.y = $<ftype>5;
				mesh_joints[count].position.z = $<ftype>6;

				q1 = $<ftype>9;
				q2 = $<ftype>10;
				q3 = $<ftype>11;
				
				mesh_joints[count].orientation.x = q1;
				mesh_joints[count].orientation.y = q2;
				mesh_joints[count].orientation.z = q3;
	
				tmp = 1.0f - ( q1 * q1 + q2 * q2 + q3 * q3 );
				if(tmp > 0.0f)
					mesh_joints[count].orientation.w = -sqrtf( tmp );
				else
					mesh_joints[count].orientation.w = 0.0f;
				count++;
			}
		}
		;

md5mesh_meshpart:	md5mesh_mesh
		| md5mesh_meshpart md5mesh_mesh

md5mesh_mesh:	MESHID LCURLY md5mesh_shader md5mesh_numverts md5mesh_verts md5mesh_numtris md5mesh_tris md5mesh_numweights md5mesh_weights RCURLY
		{
			if (count != meshes[mesh_count].num_weights)
				MD5MESH_error("Error: Incorrect number of weights in mesh");
			mesh_count++;
			count = 0;
		}
		;

md5mesh_shader:	SHADERID STRING
		{
			meshes[mesh_count].shader = (const char*)libmd5_strdup($2);	
		}
		;

md5mesh_numverts:	NUMVERTSID NUMBER
		{
			meshes[mesh_count].num_verts = $<itype>2;	
			meshes[mesh_count].verts = (MD5_VERTEX*)malloc($<itype>2 * sizeof(MD5_VERTEX));
			count = 0;
		}
		;

md5mesh_verts:	md5mesh_vert
		| md5mesh_verts md5mesh_vert
		;

md5mesh_vert:	VERTID NUMBER LBRACKET NUMBER NUMBER RBRACKET NUMBER NUMBER
		{
			if (count < meshes[mesh_count].num_verts)
			{
				/*meshes[mesh_count].verts[count].id = $<itype>2;*/	
				meshes[mesh_count].verts[count].texture_u = $<ftype>4;	
				meshes[mesh_count].verts[count].texture_v = $<ftype>5;	
				meshes[mesh_count].verts[count].weight = (MD5_WEIGHT*)$<itype>7;	
					
				meshes[mesh_count].verts[count].num_weights = $<itype>8;	
				count++;
			}
		}
		;

md5mesh_numtris:	NUMTRISID NUMBER 
		{
			if (count != meshes[mesh_count].num_verts)
				MD5MESH_error("Error: Incorrect number of vertices in mesh");
			meshes[mesh_count].num_tris = $<itype>2;	
			meshes[mesh_count].tris = (MD5_TRIANGLE*)malloc($<itype>2 * sizeof(MD5_TRIANGLE));
			count = 0;
		}
		;

md5mesh_tris:	md5mesh_tri
		| md5mesh_tris md5mesh_tri
		;

md5mesh_tri:	TRIID NUMBER NUMBER NUMBER NUMBER
		{
			if (count < meshes[mesh_count].num_tris)
			{
				/*meshes[mesh_count].tris[count].id = $<itype>2;*/	
				meshes[mesh_count].tris[count].vertex1 = (MD5_VERTEX*)(meshes[mesh_count].verts + $<itype>3);	
				meshes[mesh_count].tris[count].vertex2 = (MD5_VERTEX*)(meshes[mesh_count].verts + $<itype>4);	
				meshes[mesh_count].tris[count].vertex3 = (MD5_VERTEX*)(meshes[mesh_count].verts + $<itype>5);	
				count++;
			}
		}
		;

md5mesh_numweights:	NUMWEIGHTSID NUMBER
		{
			if (count != meshes[mesh_count].num_tris)
				MD5MESH_error("Error: Incorrect number of triangles in mesh");
			meshes[mesh_count].num_weights = $<itype>2;	
			meshes[mesh_count].weights = (MD5_WEIGHT*)malloc($<itype>2 * sizeof(MD5_WEIGHT));
			count = 0;
		}
		;

md5mesh_weights:	md5mesh_weight
		| md5mesh_weights md5mesh_weight
		;

md5mesh_weight:	WEIGHTID NUMBER NUMBER NUMBER LBRACKET NUMBER NUMBER NUMBER RBRACKET
		{
			if (count < meshes[mesh_count].num_weights)
			{
				/*meshes[mesh_count].weights[count].id = $<itype>2;*/	
				meshes[mesh_count].weights[count].joint = (MD5MESH_JOINT*)(mesh_joints + $<itype>3);	
				meshes[mesh_count].weights[count].weight = $<ftype>4;	
				meshes[mesh_count].weights[count].offset_x = $<ftype>6;	
				meshes[mesh_count].weights[count].offset_y = $<ftype>7;	
				meshes[mesh_count].weights[count].offset_z = $<ftype>8;	
				count++;
			}
		}
		; 
%%


