#ifndef _FS_POINT_CURVE_H_
#define _FS_POINT_CURVE_H_

#include <vector>
#include "FsMacros.h"
#include "FsTCurve.h"



NS_FS_BEGIN
template<typename T_Vector>
class TPercentPoint
{
	float percent;
	T_Vector value;
};

template<typename T_Vector>
class TPointCurve:public TCurve<T_Vector>
{
	public:
		void addPoint(float pos,const T_Vector& v)
		{
		}

	private:
		std::vector<TPercentPoint<T_Vector>> m_points;
};



NS_FS_END


#endif /*_FS_POINT_CURVE_H_*/


