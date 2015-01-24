/*************************************************************************/
/*  FsBox3D.cc                                                           */
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


#include "FsBox3D.h"

NS_FS_BEGIN


Box3D::Box3D()
{
	min.set(0,0,0);
	max.set(0,0,0);
}

Box3D::Box3D(const Vector3f& _min,const Vector3f& _max)
{
	min=_min;
	max=_max;
}

void Box3D::set(const Vector3f& _min,const Vector3f& _max)
{
	min=_min; max=_max;
}
void Box3D::setFromCenterAndSize( const Vector3f& center,const Vector3f& size)
{
	Vector3f half_size=size.scale(0.5);

	min=center.sub(half_size);
	max=center.add(half_size);
}


Vector3f Box3D::center()
{
	return min.add(max).scale(0.5);
}

bool Box3D::contain(const Box3D& box)
{

	if ( ( min.x <= box.min.x ) && ( box.max.x <= max.x ) &&
			( min.y <= box.min.y ) && ( box.max.y <= max.y ) &&
			( min.z <= box.min.z ) && ( box.max.z <=max.z ) ) 
	{

		return true;

	}

	return false;

}

bool Box3D::intersection(const Box3D& box)
{
	if ( box.max.x < min.x || box.min.x > max.x ||
			box.max.y < min.y || box.min.y > max.y ||
			box.max.z < min.z || box.min.z > max.z ) 
	{

		return false;

	}

	return true;
}

NS_FS_END 

