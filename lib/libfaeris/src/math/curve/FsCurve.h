#ifndef _FS_T_CURVE_H_
#define _FS_T_CURVE_H_ 


#include "FsMacros.h"
#include "FsObject.h"

#include "math/FsVector3.h"
#include "math/FsVector2.h"
#include "math/FsVector4.h"

NS_FS_BEGIN

template<typename T_Vector>
class TCurve:public FsObject 
{
	public:
		virtual T_Vector getValue(float t)=0;
};

typedef TCurve<Vector4> Curve4;
typedef TCurve<Vector3> Curve3;
typedef TCurve<Vector2> Curve2;


NS_FS_END

#endif /*_FS_T_CURVE_H_*/

