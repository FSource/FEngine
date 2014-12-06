#include "math/FsRect2D.h"

NS_FS_BEGIN
Rect2D::Rect2D(float _x,float _y,float _width,float _height)
{
	x=_x;
	y=_y;
	width=_width;
	height=_height;
}

Rect2D::Rect2D(const Vector2& _start,float _width,float _height)
{
	x=_start.x;
	y=_start.y;
	width=_width;
	height=_height;
}
void Rect2D::set(float _x,float _y,float _width,float _height)
{
	x=_x;
	y=_y;
	width=_width;
	height=_height;
}

Rect2D::Rect2D()
{
	x=0;
	y=0;
	width=0;
	height=0;
}

NS_FS_END
