#ifndef _FS_CURVE3_ACTION_H_
#define _FS_CURVE3_ACTION_H_

#include "FsMacros.h"
#include "FsFixTimeAction.h"
#include "math/curve/FsCurve.h"

NS_FS_BEGIN
enum CurveUsedMarkBit
{
	USED_X=0x1,
	USED_Y=0x2,
	USED_Z=0x4,
	USED_W=0x8,
	USED_XYZ=USED_X|USED_Y|USED_Z,
};


class Curve3Action:public FixTimeAction 
{
	public:
		virtual const char* className();

	public:
		void setCurveMarkBit(uint32 bit){m_markBit=bit;}
		uint32 getCurveMarkBit(){return m_markBit;}

		void setCurve(Curve3* curve){FS_SAFE_ASSIGN(m_curve,curve);}
		Curve3* getCurve(){return m_curve;}

	protected:
		Curve3Action(Curve3* curve,float time);
		~Curve3Action();

		Vector3 getCurveValue(float t);

	protected:
		Curve3* m_curve;
		uint32 m_markBit;
};



NS_FS_END 


#endif /*_FS_CURVE3_ACTION_H_*/

