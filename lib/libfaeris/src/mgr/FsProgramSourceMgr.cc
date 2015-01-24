/*************************************************************************/
/*  FsProgramSourceMgr.cc                                                */
/*************************************************************************/
/* Copyright (C) 2012-2014 nosiclin@foxmail.com                          */
/* Copyright (C) 2014-2015 www.fsource.cn                                */
/*                                                                       */
/* http://www.fsource.cn                                                 */
/*                                                                       */
/* Permission is hereby granted, free of charge, to any person obtaining */
/* a copy of this software and associated documentation files (the       */
/* "Software"), to deal in the Software without restriction, including   */
/* without limitation the rights to use, copy, modify, merge, publish,   */
/* distribute, sublicense, and/or sell copies of the Software, and to    */
/* permit persons to whom the Software is furnished to do so, subject to */
/* the following conditions:                                             */
/*                                                                       */
/* The above copyright notice and this permission notice shall be        */
/* included in all copies or substantial portions of the Software.       */
/*                                                                       */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,       */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF    */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.*/
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY  */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,  */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE     */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                */
/*************************************************************************/


#include "FsProgramSourceMgr.h"
#include "graphics/shader/FsProgramSource.h"
#include "sys/io/FsMemFile.h"

NS_FS_BEGIN

static Resource* S_ProgramSource_Create(FsFile* file)
{
	ProgramSource* ret=ProgramSource::create(file);
	return ret;
}


const char* ProgramSourceMgr::className()
{
	return "ProgramSourceMgr";
}

ProgramSourceMgr* ProgramSourceMgr::create()

{
	ProgramSourceMgr* ret=new ProgramSourceMgr;
	return ret;
}

ProgramSourceMgr::ProgramSourceMgr()
	:ResourceMgr(S_ProgramSource_Create)
{
}


ProgramSourceMgr::~ProgramSourceMgr()
{

}


Resource* ProgramSourceMgr::load(const char* name)
{
	return ResourceMgr::load(name);
}



struct ST_PreDefineShader
{
	const char* key;
	const char* source;
};



static const char* FS_PRE_PROGRAM_SOURCE_V4F_SOURCE=
#include "graphics/shader/buildin/Fs_V4F.fshader"

static const char* FS_PRE_PROGRAM_SOURCE_V4F_T2F_SOURCE=
#include "graphics/shader/buildin/Fs_V4F_T2F.fshader"

static const char* FS_PRE_PROGRAM_SOURCE_V4F_T2F_A1F_SOURCE=
#include "graphics/shader/buildin/Fs_V4F_T2F_A1F.fshader"


static const char* FS_PRE_PROGRAM_SOURCE_V4F_T2F_C4F_SOURCE=
#include "graphics/shader/buildin//Fs_V4F_T2F_C4F.fshader"


static const char* FS_PRE_PROGRAM_SOURCE_PARTICLE_SOURCE=
#include "graphics/shader/buildin/Fs_Particle.fshader"

static const char*  FS_PRE_PROGRAM_SOURCE_COLOR_SOURCE=
#include "graphics/shader/buildin/Fs_Color.fshader"


static const  char* FS_PRE_PROGRAM_SOURCE_TEXTURE_SOURCE=
#include "graphics/shader/buildin/Fs_Texture.fshader"

static const char* FS_PRE_PROGRAM_SOURCE_CONSTANT_SOURCE=
#include "graphics/shader/buildin/Fs_Constant.fshader"

static const char* FS_PRE_PROGRAM_SOURCE_LAMBERT_SOURCE=
#include "graphics/shader/buildin/Fs_Lambert.fshader"

static const char* FS_PRE_PROGRAM_SOURCE_PHONG_SOURCE=
#include "graphics/shader/buildin/Fs_Phong.fshader"

static const char* FS_PRE_PROGRAM_SOURCE_FILTER_OPACITY_SOURCE=
#include "graphics/shader/buildin/Fs_Opacity_Filter.fshader"

static const char* FS_PRE_PROGRAM_SOURCE_FILTER_GRAY_SOURCE=
#include "graphics/shader/buildin/Fs_Gray_Filter.fshader"

static const char* FS_PRE_PROGRAM_SOURCE_FILTER_BRIGHTNESS_SOURCE=
#include "graphics/shader/buildin/Fs_Brightness_Filter.fshader"

static const char* FS_PRE_PROGRAM_SOURCE_FILTER_COLOR_MATRIX_SOURCE=
#include "graphics/shader/buildin/Fs_ColorMatrix_Filter.fshader"


void ProgramSourceMgr::loadPreDefineShader()
{
	ST_PreDefineShader shader[]=
	{
		/* 2d party */
		{
			FS_PRE_PROGRAM_SOURCE_V4F,
			FS_PRE_PROGRAM_SOURCE_V4F_SOURCE,
		},
		{
			FS_PRE_PROGRAM_SOURCE_V4F_T2F,
			FS_PRE_PROGRAM_SOURCE_V4F_T2F_SOURCE,
		},
		{
			FS_PRE_PROGRAM_SOURCE_V4F_T2F_A1F,
			FS_PRE_PROGRAM_SOURCE_V4F_T2F_A1F_SOURCE,
		},
		{
			FS_PRE_PROGRAM_SOURCE_V4F_T2F_C4F,
			FS_PRE_PROGRAM_SOURCE_V4F_T2F_C4F_SOURCE
		},

		{
			FS_PRE_PROGRAM_SOURCE_PARTICLE,
			FS_PRE_PROGRAM_SOURCE_PARTICLE_SOURCE,
		},


		/* 3d party */
		{
			FS_PRE_PROGRAM_SOURCE_COLOR,
			FS_PRE_PROGRAM_SOURCE_COLOR_SOURCE,
		},
		{
			FS_PRE_PROGRAM_SOURCE_TEXTURE,
			FS_PRE_PROGRAM_SOURCE_TEXTURE_SOURCE,
		},
		{
			FS_PRE_PROGRAM_SOURCE_CONSTANT,
			FS_PRE_PROGRAM_SOURCE_CONSTANT_SOURCE,
		},
		{
			FS_PRE_PROGRAM_SOURCE_LAMBERT,
			FS_PRE_PROGRAM_SOURCE_LAMBERT_SOURCE
		},
		{
			FS_PRE_PROGRAM_SOURCE_PHONG,
			FS_PRE_PROGRAM_SOURCE_PHONG_SOURCE
		},

		/* filter party */
		{
			FS_PRE_PROGRAM_SOURCE_FILTER_OPACITY,
			FS_PRE_PROGRAM_SOURCE_FILTER_OPACITY_SOURCE
		},
		{
			FS_PRE_PROGRAM_SOURCE_FILTER_GRAY,
			FS_PRE_PROGRAM_SOURCE_FILTER_GRAY_SOURCE,
		},
		{
			FS_PRE_PROGRAM_SOURCE_FILTER_BRIGHTNESS,
			FS_PRE_PROGRAM_SOURCE_FILTER_BRIGHTNESS_SOURCE,
		},
		{
			FS_PRE_PROGRAM_SOURCE_FILTER_COLOR_MATRIX,
			FS_PRE_PROGRAM_SOURCE_FILTER_COLOR_MATRIX_SOURCE,
		},
		{
			NULL,
			NULL,
		}
		

	};
	
	ST_PreDefineShader* p_shader=shader;

	while(p_shader->key!=NULL)
	{
		int length=strlen(p_shader->source);
		FsFile* file=MemFile::create(p_shader->source,length);
		ProgramSource* ps=ProgramSource::create(file);
		file->autoDestroy();

		if(!ps)
		{
			FS_TRACE_WARN("Can't Load PreDefine Shader(%s)",p_shader->key);
			p_shader++;
			continue;
		}

		FsString* key=FsString::create(p_shader->key);

		addCache(key,ps);
		key->autoDestroy();
		p_shader++;
	}

}


NS_FS_END
