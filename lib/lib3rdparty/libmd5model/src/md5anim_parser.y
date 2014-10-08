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
#include "md5anim_defines.h"
#include "libmd5modelext.h"
#define    yylex   MD5ANIM_lex
#define MD5ANIM_TRANSLATION_X	1
#define MD5ANIM_TRANSLATION_Y	2
#define MD5ANIM_TRANSLATION_Z	4
#define MD5ANIM_ORIENTATION_X	8
#define MD5ANIM_ORIENTATION_Y	16
#define MD5ANIM_ORIENTATION_Z	32
MD5ANIM_HEADER anim_header;
MD5ANIM_JOINT* baseframe = (MD5ANIM_JOINT*)NULL;
MD5_BOUND* bounds = (MD5_BOUND*)NULL;
extern int md5_perror;
float* frames;
int frame_index;
int frame_number;
int count;
typedef struct h_joint
{
	int flag;
	int start_index;
} H_JOINT;
H_JOINT* h_joints;

extern int MD5ANIM_lex(void);

void MD5ANIM_error(char const* s)
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

%%
md5anim_file:	md5anim_header md5anim_jointspart md5anim_boundspart md5anim_baseframe_part md5anim_framepart
		{
			/* post-processing */
			
			int i,j;

			if (frame_index != anim_header.num_frames)
				MD5ANIM_error("Error: Incorrect number of frames");	

			for (i = 0; i < anim_header.num_joints; ++i)
			{
				if (h_joints[i].flag)
				{
					baseframe[i].frames = (MD5ANIM_FRAME*)malloc(anim_header.num_frames * sizeof(MD5ANIM_FRAME));

					/*TODO optimize, remove bit tests from loop */
					for (j = 0; j < anim_header.num_frames; ++j)
					{
						int flag_count = 0;
						if (h_joints[i].flag & MD5ANIM_TRANSLATION_X)
						{
							baseframe[i].frames[j].position.x = frames[j * anim_header.num_joints + h_joints[i].start_index];	
							flag_count++;
						}
						else
						{
							baseframe[i].frames[j].position.x = baseframe[i].position.x;
						}
						if (h_joints[i].flag & MD5ANIM_TRANSLATION_Y)
						{
							baseframe[i].frames[j].position.y = frames[j * anim_header.num_joints + h_joints[i].start_index + flag_count];	
							flag_count++;
						}
						else
						{
							baseframe[i].frames[j].position.y = baseframe[i].position.y;
						}
						if (h_joints[i].flag & MD5ANIM_TRANSLATION_Z)
						{
							baseframe[i].frames[j].position.z = frames[j * anim_header.num_joints + h_joints[i].start_index + flag_count];	
							flag_count++;
						}
						else
						{
							baseframe[i].frames[j].position.z = baseframe[i].position.z;
						}

						if (h_joints[i].flag & MD5ANIM_ORIENTATION_X)
						{
							baseframe[i].frames[j].orientation.x = frames[j * anim_header.num_joints + h_joints[i].start_index + flag_count];	
							flag_count++;
						}
						else
						{
							baseframe[i].frames[j].orientation.x = baseframe[i].orientation.x;
						}
						if (h_joints[i].flag & MD5ANIM_ORIENTATION_Y)
						{
							baseframe[i].frames[j].orientation.y = frames[j * anim_header.num_joints + h_joints[i].start_index + flag_count];	
							flag_count++;
						}
						else
						{
							baseframe[i].frames[j].orientation.y = baseframe[i].orientation.y;
						}
						if (h_joints[i].flag & MD5ANIM_ORIENTATION_Z)
						{
							baseframe[i].frames[j].orientation.z = frames[j * anim_header.num_joints + h_joints[i].start_index + flag_count];	
							flag_count++;
						}
						else
						{
							baseframe[i].frames[j].orientation.z = baseframe[i].orientation.z;
						}
						
						/*compute and set w component of quateration */

						if (h_joints[i].flag & 56)
						{
							float tmp;
							tmp = 1.0f - ( baseframe[i].frames[j].orientation.x * baseframe[i].frames[j].orientation.x + baseframe[i].frames[j].orientation.y * baseframe[i].frames[j].orientation.y + baseframe[i].frames[j].orientation.z * baseframe[i].frames[j].orientation.z );
							if(tmp > 0.0f)
								baseframe[i].frames[j].orientation.w = -sqrtf( tmp );
							else
								baseframe[i].frames[j].orientation.w = 0.0f;
						}
						else
						{
								baseframe[i].frames[j].orientation.w = baseframe[i].orientation.w;
						}
					}		
				}
				else
				{
					baseframe[i].frames = (MD5ANIM_FRAME*)NULL;
				}
			}	

			free(h_joints);
			free(frames);
		
			md5_perror = 0;
		}
		;

md5anim_header:	md5anim_version md5anim_cmdline md5anim_numframes md5anim_numjoints md5anim_framerate md5anim_numanimated_comps
		;

md5anim_version:	VERSIONID NUMBER
		{
			anim_header.version = $<itype>2;
 		}
		;

md5anim_cmdline:	CMDLINEID STRING
		{
			anim_header.commandline = (const char*)libmd5_strdup($2);
		}
		;

md5anim_numframes:	NUMFRAMESID NUMBER
		{
			anim_header.num_frames = $<itype>2;
			bounds = (MD5_BOUND*)malloc(anim_header.num_frames * sizeof(MD5_BOUND));
		}
		;

md5anim_numjoints:	NUMJOINTSID NUMBER
		{
			anim_header.num_joints = $<itype>2;
			baseframe = (MD5ANIM_JOINT*)malloc(anim_header.num_joints * sizeof(MD5ANIM_JOINT));
			h_joints = (H_JOINT*)malloc(anim_header.num_joints * sizeof(H_JOINT));
			frames = (float*)malloc(anim_header.num_joints * 6 * anim_header.num_frames * sizeof(float));
			count = 0;
		}
		;

md5anim_framerate:	FRAMERATEID NUMBER
		{
			anim_header.frame_rate = $<itype>2;
		}
		;

md5anim_numanimated_comps:	NUMANICOMPSID NUMBER
		{
			anim_header.num_animated_components = $<itype>2;
		}
		;

md5anim_jointspart:	HIERARCHYID LCURLY md5anim_joints RCURLY
		{
			if (count != anim_header.num_joints)
				MD5ANIM_error("Error: Incorrect number of joints");	
			count = 0;
		}
		;

md5anim_joints:		md5anim_joint
		|	md5anim_joints md5anim_joint
		;

md5anim_joint:		STRING NUMBER NUMBER NUMBER
		{
			int idx = $<itype>2;
			baseframe[count].name = (const char*)libmd5_strdup($1);

			if (idx == -1)
				baseframe[count].parent = (MD5ANIM_JOINT*)NULL;
			else
				baseframe[count].parent = (MD5ANIM_JOINT*)(baseframe + idx);

			h_joints[count].flag = $<itype>3;
			h_joints[count].start_index = $<itype>4;
			count++;
		}
		;

md5anim_boundspart:		BOUNDSID LCURLY md5anim_bounds RCURLY
		{
			if (count != anim_header.num_frames)
				MD5ANIM_error("Error: Incorrect number of bounds");	
			count = 0;	
		}
		; 

md5anim_bounds:		md5anim_bound
		|	md5anim_bounds md5anim_bound	
		;

md5anim_bound:		LBRACKET NUMBER NUMBER NUMBER RBRACKET LBRACKET NUMBER NUMBER NUMBER RBRACKET
		{
			bounds[count].min.x = $<ftype>2;
			bounds[count].min.y = $<ftype>3;
			bounds[count].min.z = $<ftype>4;
 
			bounds[count].max.x = $<ftype>7;
			bounds[count].max.y = $<ftype>8;
			bounds[count].max.z = $<ftype>9;
			count++;
		}
		;

md5anim_baseframe_part:	BASEFRAMEID LCURLY md5anim_baseframe_items RCURLY
		{
			if (count != anim_header.num_joints)
				MD5ANIM_error("Error: Incorrect number of baseframe joints");	
			count = 0;
			frame_index = 0;
			frame_number = 0;
		}
		;

md5anim_baseframe_items:	md5anim_baseframe_item
		|	md5anim_baseframe_items	md5anim_baseframe_item
		;

md5anim_baseframe_item:	LBRACKET NUMBER NUMBER NUMBER RBRACKET LBRACKET NUMBER NUMBER NUMBER RBRACKET
		{
			float tmp,q1,q2,q3;

			baseframe[count].position.x = $<ftype>2;			
			baseframe[count].position.y = $<ftype>3;			
			baseframe[count].position.z = $<ftype>4;			

			q1 = $<ftype>7;
			q2 = $<ftype>8;
			q3 = $<ftype>9;
			baseframe[count].orientation.x = q1;
			baseframe[count].orientation.y = q2;
			baseframe[count].orientation.z = q3;

			tmp = 1.0f - ( q1 * q1 + q2 * q2 + q3 * q3 );
			if(tmp > 0.0f)
				baseframe[count].orientation.w = -sqrtf( tmp );
			else
				baseframe[count].orientation.w = 0.0f;

			count++;
		}
		;

md5anim_framepart: 	md5anim_frame
		|	md5anim_framepart md5anim_frame
		;

md5anim_frame: 	FRAMEID NUMBER LCURLY md5anim_framenumbers RCURLY
		{
			frame_index++;
		}
		| FRAMEID NUMBER LCURLY RCURLY
		{
			frame_index++;
		}
		;

md5anim_framenumbers:		md5anim_framenumber	
		|		md5anim_framenumbers md5anim_framenumber
		;

md5anim_framenumber:	NUMBER
		{
			frames[frame_index * anim_header.num_joints + frame_number] = $<ftype>1;
			frame_number++;
		}
		;

%%


