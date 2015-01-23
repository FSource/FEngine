/*************************************************************************/
/*  FsVertices.h                                                         */
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


#ifndef _FS_VERTICES_H_
#define _FS_VERTICES_H_

#include "FsMacros.h"
#include "math/FsVector2.h"
#include "math/FsVector3.h"
#include "math/FsTexCoord2.h"
#include "graphics/FsColor.h"


NS_FS_BEGIN


class Fs_V2F_T2F
{
	
	public:
		Fs_V2F_T2F(){}
		Fs_V2F_T2F(const Vector2& v,const TexCoord2& t)
		{
			v2=v;
			t2=t;
		}
	
	public:

		Vector2 v2;
		TexCoord2 t2;
};


class Fs_V3F_T2F
{
	public:
		Fs_V3F_T2F();
		Fs_V3F_T2F(const Vector3& v,const TexCoord2& t)
		{
			v3=v;
			t2=t;
		}

	public:
		Vector3 v3;
		TexCoord2 t2;
};

class Fs_V2F_T2F_C4F
{
	public:
		Fs_V2F_T2F_C4F(){}
		Fs_V2F_T2F_C4F(const Vector2& v,const TexCoord2& t,const Color4f& c)
		{
			v2=v;
			t2=t;
			c4=c;
		}

	public:
		Vector2 v2;
		TexCoord2 t2;
		Color4f c4;
};


NS_FS_END 



#endif /*_FS_VERTICES_H_*/









