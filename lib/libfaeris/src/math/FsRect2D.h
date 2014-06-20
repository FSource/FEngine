#ifndef _FS_RECT_2D_H_
#define _FS_RECT_2D_H_
#include "FsMacros.h"
#include "math/FsVector2.h"

NS_FS_BEGIN

class Rect2D
{
	public:
		Rect2D(float _x,float _y,float _width,float _height);
		Rect2D(const Vector2& _start,float _width,float _height);
		Rect2D();
	public:
		void set(float _x,float _y,float _width,float _height);

	public:
		float x;
		float y;
		float width;
		float height;
};

NS_FS_END

#endif /*_FS_RECT_2D_H_*/


