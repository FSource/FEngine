/*************************************************************************/
/*  FsProgramSourceMgr.h                                                 */
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


#ifndef _FS_PROGRAM_SOURCE_MGR_H_
#define _FS_PROGRAM_SOURCE_MGR_H_

#include "FsMacros.h"
#include "mgr/FsResourceMgr.h"

NS_FS_BEGIN


/* 2d party */
#define FS_PRE_PROGRAM_SOURCE_V4F "__V4F__.fshader"
#define FS_PRE_PROGRAM_SOURCE_V4F_T2F "__V4F_T2F__.fshader"
#define FS_PRE_PROGRAM_SOURCE_V4F_T2F_A1F "__V4F_T2F_A1F__.fshader"
#define FS_PRE_PROGRAM_SOURCE_V4F_T2F_C4F "__V4F_T2F_C4F__.fshader"
#define FS_PRE_PROGRAM_SOURCE_PARTICLE "__PARTICLE__.fshader"


/* 3d party */
#define FS_PRE_PROGRAM_SOURCE_COLOR  "__COLOR__.fshader" 
#define FS_PRE_PROGRAM_SOURCE_TEXTURE "__TEXTURE__.fshader"
#define FS_PRE_PROGRAM_SOURCE_CONSTANT "__CONSTANT__.fshader"
#define FS_PRE_PROGRAM_SOURCE_LAMBERT  "__LAMBERT__.fshader"
#define FS_PRE_PROGRAM_SOURCE_PHONG "__PHONG__.fshader"


/* filter party */
#define FS_PRE_PROGRAM_SOURCE_FILTER_OPACITY "__FILTER_OPACIYT__.fshader"
#define FS_PRE_PROGRAM_SOURCE_FILTER_GRAY  "__FILTER_GRAY__.fshader"
#define FS_PRE_PROGRAM_SOURCE_FILTER_BRIGHTNESS "__FILTER_BRIGHTNESS__.fshader"
#define FS_PRE_PROGRAM_SOURCE_FILTER_COLOR_MATRIX  "__FILTER_COLOR_MATRIX__.fshader"




//#define FS_PRE_PROGRAM_SOURCE_V4F_C4F "__V4F_C4F__.fshader"

#define FS_MAX_PRE_PROGRAM_SOURCE_NU 10


class ProgramSource;
class ProgramSourceMgr:public ResourceMgr 
{
	public:
		static ProgramSourceMgr* create();

	public:
		void loadPreDefineShader();

	public:
		Resource* load(const char* name);



	public:
		virtual const char* className();

	protected:
		ProgramSourceMgr();
		~ProgramSourceMgr();


};

NS_FS_END


#endif /*_FS_PROGRAM_SOURCE_MGR_H_*/



