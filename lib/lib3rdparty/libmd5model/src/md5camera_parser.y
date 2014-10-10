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
#include "md5camera_defines.h"
#include "libmd5modelext.h"
#define    yylex   MD5CAMERA_lex
MD5CAMERA_HEADER camera_header;
MD5CAMERA_FRAME* frames = (MD5CAMERA_FRAME*)NULL;
extern int md5_perror;
int* cuts;
int count;

extern int MD5CAMERA_lex(void);

void MD5CAMERA_error(char const* s)
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
%token <itype> NUMCUTSID
%token <itype> NUMFRAMESID
%token <itype> FRAMERATEID
%token <itype> LCURLY
%token <itype> RCURLY
%token <itype> LBRACKET
%token <itype> RBRACKET
%token <itype> CAMERAID
%token <itype> CUTSID

%%

md5camera_file: md5camera_header md5camera_cutspart md5camera_camerapart
	;

md5camera_header:	md5camera_version md5camera_cmdline md5camera_numframes md5camera_framerate md5camera_numcuts
		;

md5camera_version:	VERSIONID NUMBER
		{
			camera_header.version = $<itype>2;
 		}
		;

md5camera_cmdline:	CMDLINEID STRING
		{
			camera_header.commandline = (const char*)libmd5_strdup($2);
		}
		;

md5camera_numframes:	NUMFRAMESID NUMBER
		{
			camera_header.num_frames = $<itype>2;
			frames = (MD5CAMERA_FRAME*)malloc(camera_header.num_frames * sizeof (MD5CAMERA_FRAME));	
		}
		;

md5camera_framerate:	FRAMERATEID NUMBER
		{
			camera_header.frame_rate = $<itype>2;
		}
		;

md5camera_numcuts:	NUMCUTSID NUMBER
		{
			camera_header.num_cuts = $<itype>2;
			cuts = (int*)malloc(camera_header.num_cuts * sizeof (int));	
			count = 0;
		}
		;
md5camera_cutspart:	CUTSID LCURLY md5camera_cuts RCURLY
		|	CUTSID LCURLY RCURLY
		{
			if (count != camera_header.num_cuts)
				MD5CAMERA_error("Error: Incorrect number of cuts");	
			count = 0;
		}
		;

md5camera_cuts:		md5camera_cut
		|	md5camera_cuts md5camera_cut
		;

md5camera_cut:	NUMBER
		{
			cuts[count++] = $<itype>1;
		}
		;

md5camera_camerapart:	CAMERAID LCURLY md5camera_frames RCURLY
		|	CAMERAID LCURLY RCURLY
		{
			if (count != camera_header.num_frames)
				MD5CAMERA_error("Error: Incorrect number of frames");	
		}
		;

md5camera_frames:	md5camera_frame
		|	md5camera_frames md5camera_frame
		;

md5camera_frame:	LBRACKET NUMBER NUMBER NUMBER RBRACKET LBRACKET NUMBER NUMBER NUMBER RBRACKET NUMBER	
		{
			float tmp,q1,q2,q3;

			frames[count].position.x = $<ftype>2;
			frames[count].position.y = $<ftype>3;
			frames[count].position.z = $<ftype>4;

			q1 = $<ftype>7;
			q2 = $<ftype>8;
			q3 = $<ftype>9;

			frames[count].orientation.x = q1;
			frames[count].orientation.y = q2;
			frames[count].orientation.z = q3;

			tmp = 1.0f - ( q1 * q1 + q2 * q2 + q3 * q3 );
			if(tmp > 0.0f)
				frames[count].orientation.w = -sqrtf( tmp );
			else
				frames[count].orientation.w = 0.0f;

			frames[count].field_of_view = $<ftype>11;

			count++;
		}
		;

%%


