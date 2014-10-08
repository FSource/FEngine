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

#include "libmd5model.h"
#include "stdlib.h"
#include <stdio.h>
#include <string.h>

extern FILE* MD5MESH_in;
extern FILE* MD5ANIM_in;
extern FILE* MD5CAMERA_in;
extern int MD5MESH_parse();
extern int MD5ANIM_parse();
extern int MD5CAMERA_parse();
extern int md5_perror;
extern MD5MESH_JOINT* mesh_joints;
extern MD5_MESH* meshes;
extern MD5ANIM_JOINT* baseframe;
extern MD5_BOUND* bounds;
extern MD5MESH_HEADER mesh_header;
extern MD5ANIM_HEADER anim_header;
extern MD5CAMERA_HEADER camera_header;
extern MD5CAMERA_FRAME* frames;
extern int* cuts;
int md5_parsed = MD5_PARSED_FAIL;

MD5IO_FUNC _libmd5_iofunc;

int libmd5_input(void* buf,int size)
{
	/*now parse the model data */	
	if (md5_parsed == MD5_PARSED_MESH)
	{
		return _libmd5_iofunc(MD5MESH_in,buf,size);
	}
	else if (md5_parsed == MD5_PARSED_ANIM)
	{
		return _libmd5_iofunc(MD5ANIM_in,buf,size);
	}
	else if (md5_parsed == MD5_PARSED_CAMERA)
	{
		return _libmd5_iofunc(MD5CAMERA_in,buf,size);
	}

	return 0;
}



int MD5_parse(const char* md5_filename,MD5IO_FUNC io)
{


	if (strstr(md5_filename, ".md5mesh")) 
	{
		if ((MD5MESH_in=fopen(md5_filename, "r")) == NULL)
			return MD5_PARSED_FAIL;
		md5_parsed = MD5_PARSED_MESH;
	}
	else if (strstr(md5_filename, ".md5anim"))
	{	
		if ((MD5ANIM_in=fopen(md5_filename, "r")) == NULL)
			return MD5_PARSED_FAIL;
		md5_parsed = MD5_PARSED_ANIM;
	}
	else if (strstr(md5_filename, ".md5camera"))
	{	
		if ((MD5CAMERA_in=fopen(md5_filename, "r")) == NULL)
			return MD5_PARSED_FAIL;
		md5_parsed = MD5_PARSED_CAMERA;
	}
	else
	{
		return MD5_PARSED_FAIL;
	}

	/*free data of earlier read model */
	MD5_free();
	_libmd5_iofunc=io;

	/*now parse the model data */	
	if (md5_parsed == MD5_PARSED_MESH)
		MD5MESH_parse();
	else if (md5_parsed == MD5_PARSED_ANIM)
		MD5ANIM_parse();
	else if (md5_parsed == MD5_PARSED_CAMERA)
		MD5CAMERA_parse();

	if (md5_perror == 1)
	{
		MD5_free();
		md5_parsed = MD5_PARSED_FAIL;
		return MD5_PARSED_FAIL;
	}
	else	
		return md5_parsed;
}

void MD5_free()
{
	_libmd5_iofunc=0;
	if (md5_parsed == MD5_PARSED_MESH)
	{
		free((char*)mesh_header.commandline);
		mesh_header.commandline = (char*)NULL;

		free((MD5MESH_JOINT*)mesh_joints);
		mesh_joints = (MD5MESH_JOINT*)NULL;
			
		free((MD5_MESH*)meshes);
		meshes = (MD5_MESH*)NULL;
	}
	else if (md5_parsed == MD5_PARSED_ANIM)
	{
		int i;

		free((char*)anim_header.commandline);
		anim_header.commandline = (char*)NULL;

		free((MD5_BOUND*)bounds);
		bounds = (MD5_BOUND*)NULL;
		
		for (i=0; i < anim_header.num_joints; ++i)
		{
			free((MD5ANIM_FRAME*)baseframe[i].frames);
			baseframe[i].frames = (MD5ANIM_FRAME*)NULL;
		}

		free((MD5ANIM_JOINT*)baseframe);
		baseframe = (MD5ANIM_JOINT*)NULL;
	}
	else if (md5_parsed == MD5_PARSED_CAMERA)
	{
		free((char*)camera_header.commandline);
		camera_header.commandline = (char*)NULL;
		
		free((int*)cuts);
		cuts = (int*)NULL;

		free((MD5CAMERA_FRAME*)frames);
		frames = (MD5CAMERA_FRAME*)NULL;
	}
}

MD5MESH_HEADER* MD5Mesh_get_header()
{
	return &mesh_header;
}

MD5MESH_JOINT* MD5Mesh_get_joint(int idx)
{
	return mesh_joints + idx;
}

MD5MESH_JOINT** MD5Mesh_get_joints()
{
	return &mesh_joints;
}

MD5_MESH* MD5Mesh_get_mesh(int idx)
{
	return meshes + idx;
}

MD5_MESH** MD5Mesh_get_meshes()
{
	return &meshes;
}

MD5_VERTEX* MD5Mesh_get_vertex(int mesh_id, int vertex_id)
{
	return (MD5_VERTEX*)(((MD5_MESH*)(meshes + mesh_id))->verts + vertex_id);
}

MD5_TRIANGLE* MD5Mesh_get_triangle(int mesh_id, int triangle_id)
{
	return (MD5_TRIANGLE*)(((MD5_MESH*)(meshes + mesh_id))->tris + triangle_id);
}

MD5_WEIGHT* MD5Mesh_get_weight(int mesh_id, int weight_id)
{
	return (MD5_WEIGHT*)(((MD5_MESH*)(meshes + mesh_id))->weights + weight_id);
}

MD5_VERTEX** MD5Mesh_get_vertices(int mesh_id)
{
	return &((MD5_MESH*)(meshes + mesh_id))->verts;
}

MD5_TRIANGLE** MD5Mesh_get_triangles(int mesh_id)
{
	return &((MD5_MESH*)(meshes + mesh_id))->tris;
}

MD5_WEIGHT** MD5Mesh_get_weights(int mesh_id)
{
	return &((MD5_MESH*)(meshes + mesh_id))->weights;
}

MD5ANIM_HEADER* MD5Anim_get_header()
{
	return &anim_header;
}

MD5ANIM_JOINT* MD5Anim_get_joint(int idx)
{
	return (MD5ANIM_JOINT*)(baseframe + idx);
}

MD5ANIM_JOINT** MD5Anim_get_joints()
{
	return &baseframe;

}

MD5_BOUND* MD5Anim_get_bound(int idx)
{
	return (MD5_BOUND*)(bounds + idx);
}

MD5_BOUND** MD5Anim_get_bounds()
{
	return &bounds;
}

MD5ANIM_FRAME* MD5Anim_get_joint_frame(int joint, int idx)
{
	if (baseframe[joint].frames == (MD5ANIM_FRAME*)NULL)
		return (MD5ANIM_FRAME*)NULL;
	else
		return (MD5ANIM_FRAME*)(baseframe[joint].frames + idx);
}

MD5ANIM_FRAME** MD5Anim_get_joint_frames(int joint)
{
	return &baseframe[joint].frames;
}

MD5CAMERA_HEADER* MD5Camera_get_header()
{
	return &camera_header;
}

MD5CAMERA_FRAME* MD5Camera_get_frame(int idx)
{
	return (MD5CAMERA_FRAME*)(frames + idx);
}

MD5CAMERA_FRAME** MD5Camera_get_frames()
{
	return &frames;
}

int* MD5Camera_get_cut(int idx)
{
	return (int*)(cuts + idx);
}

int** MD5Camera_get_cuts()
{
	return &cuts;
}
