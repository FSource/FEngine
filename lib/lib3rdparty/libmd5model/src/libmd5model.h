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

#ifndef LIBMD5MODEL_H
#define LIBMD5MODEL_H
#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

/* MD5MESH */


typedef struct
{
	int	version;
	const char* commandline;
	int	num_joints;
	int	num_meshes;
} MD5MESH_HEADER;

typedef struct 
{
	float x,y,z;
} MD5_POINT;

typedef struct
{
	float x,y,z,w;
} MD5_QUAT;

typedef struct md5mesh_joint
{
	const char* name;
	struct md5mesh_joint* parent;
	MD5_POINT position;
	MD5_QUAT orientation;
} MD5MESH_JOINT;

typedef struct md5_weight
{
	/*int id;*/
	MD5MESH_JOINT* joint;
	float weight;
	float offset_x;
	float offset_y;
	float offset_z;
} MD5_WEIGHT;

typedef struct md5_vertex
{
	/*int id;*/
	float texture_u;
	float texture_v;
	MD5_WEIGHT* weight;
	int num_weights;
} MD5_VERTEX;

typedef struct md5_triangle
{
	/*int id;*/
	MD5_VERTEX* vertex1;
	MD5_VERTEX* vertex2;
	MD5_VERTEX* vertex3;
} MD5_TRIANGLE;

typedef struct md5_mesh {
	const char* shader;
	int num_verts;
	MD5_VERTEX* verts;
	int num_tris;
	MD5_TRIANGLE* tris;
	int num_weights;
	MD5_WEIGHT* weights;
} MD5_MESH;

MD5MESH_HEADER* MD5Mesh_get_header();
MD5_MESH* MD5Mesh_get_mesh(int idx);
MD5_MESH** MD5Mesh_get_meshes();
MD5_VERTEX* MD5Mesh_get_vertex(int mesh_id, int vertex_id);
MD5_TRIANGLE* MD5Mesh_get_triangle(int mesh_id, int triangle_id);
MD5_WEIGHT* MD5Mesh_get_weight(int mesh_id, int weight_id);
MD5_VERTEX** MD5Mesh_get_vertices(int mesh_id);
MD5_TRIANGLE** MD5Mesh_get_triangles(int mesh_id);
MD5_WEIGHT** MD5Mesh_get_weights(int mesh_id);
MD5MESH_JOINT* MD5Mesh_get_joint(int idx);
MD5MESH_JOINT** MD5Mesh_get_joints();

/* MD5ANIM */

typedef struct
{
	int	version;
	const char* commandline;
	int	num_frames;
	int	num_joints;
	int	frame_rate;	
	int	num_animated_components;
} MD5ANIM_HEADER;

typedef struct md5_bound
{
	MD5_POINT min;
	MD5_POINT max;	
} MD5_BOUND;

typedef struct md5anim_frame
{
	MD5_POINT position;
	MD5_QUAT orientation;
} MD5ANIM_FRAME;

typedef struct md5anim_joint
{
	const char* name;
	struct md5anim_joint* parent;
	MD5ANIM_FRAME* frames; /* if NULL then baseframe position and orientation for all frames */
	MD5_POINT position;
	MD5_QUAT orientation;
} MD5ANIM_JOINT;

MD5ANIM_HEADER* MD5Anim_get_header();
MD5ANIM_JOINT* MD5Anim_get_joint(int idx);
MD5ANIM_JOINT** MD5Anim_get_joints();
MD5_BOUND* MD5Anim_get_bound(int idx);
MD5_BOUND** MD5Anim_get_bounds();
MD5ANIM_FRAME* MD5Anim_get_joint_frame(int joint, int idx);
MD5ANIM_FRAME** MD5Anim_get_joint_frames(int joint);

/* MD5CAMERA */

typedef struct
{
	int	version;
	const char* commandline;
	int	num_frames;
	int	frame_rate;	
	int	num_cuts;
} MD5CAMERA_HEADER;

typedef struct md5camera_frame
{
	MD5_POINT position;
	MD5_QUAT orientation;
	float field_of_view;
} MD5CAMERA_FRAME;

MD5CAMERA_HEADER* MD5Camera_get_header();
MD5CAMERA_FRAME* MD5Camera_get_frame(int idx);
MD5CAMERA_FRAME** MD5Camera_get_frames();
int* MD5Camera_get_cut(int idx);
int** MD5Camera_get_cuts();

/* MD5 */

//typedef int (*fun_ptr)(int,int);
typedef int (*MD5IO_FUNC)(FILE* ,void* ,int );

int MD5_parse(const char* md5_filename,MD5IO_FUNC io);
void MD5_free();

#define MD5_PARSED_FAIL		1
#define MD5_PARSED_MESH		2
#define MD5_PARSED_ANIM		4
#define MD5_PARSED_CAMERA	8

#ifdef __cplusplus
} /* closing bracket for extern "C" */
#endif

#endif
