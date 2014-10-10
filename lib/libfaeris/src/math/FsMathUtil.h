#ifndef _FS_MATH_UTIL_H_
#define _FS_MATH_UTIL_H_

#include <math.h>
#include "FsMacros.h"
#include "math/FsVector2.h"
#include "math/FsRect2D.h"
#include "math/FsMatrix4.h"

NS_FS_BEGIN
FS_BEGIN_NAMESPACE(Math)

bool pointInTriangle2D(const Vector2& point,const Vector2& a,const Vector2& b,const Vector2& c);
bool pointInRect2D(const Vector2& point,const Matrix4& mat,const Rect2D& rect);

FS_END_NAMESPACE(Math)
NS_FS_END

#endif 

