/*************************************************************************/
/*  FsBox3D.h                                                            */
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


#ifndef _FS_BOX3_H_
#define _FS_BOX3_H_

#include "FsMacros.h"
#include "math/FsVector3.h"



NS_FS_BEGIN 

class Box3D
{
	public:
		Box3D();
		Box3D(const Vector3f& _min,const Vector3f& _max);

	public:
		void set(const Vector3f& _min,const Vector3f& _max);
		void setFromCenterAndSize(const Vector3f& center,const Vector3f& size);
		Vector3f center();
		Vector3f size() { return max.sub(min); }
		bool contain(const Box3D& box);
		bool intersection(const Box3D&  box ) ;


		/*
		Box3D intersect( const Box3D& box ) 
		{
			Vector3f t_min=Math::max(min,box.min);
			Vector3f t_max=Math::min(max,box.max);

			return Box3D(t_min,t_max);

		}

		Box3D union( const Box3D& box ) 
		{
			Vector3f t_min=Math::min(min,box.min);
			Vector3f t_max=Math::max(max,box.max);
			return Box3D(t_min,t_max);
		}
		*/


	public:
		Vector3f min;
		Vector3f max;
};



NS_FS_END 


#endif /*_FS_BOX3_H_*/



