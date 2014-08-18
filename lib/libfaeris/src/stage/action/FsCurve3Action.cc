#include "FsCurve3Action.h"

NS_FS_BEGIN

const char* Curve3Action::className()
{
	return FS_CURVE3_ACTION_CLASS_NAME;
}

Curve3Action::Curve3Action()
{
	m_curve=NULL;
	m_markBit=CurveUsedMarkBit::USED_XYZ;
}

void Curve3Action::init(Curve3* curve,float time)
{
	FixTimeAction::setTotalTime(time);
	FS_SAFE_ASSIGN(m_curve,curve);
}


Curve3Action::~Curve3Action()
{
	FS_SAFE_DEC_REF(m_curve);
}

Vector3 Curve3Action::getCurveValue(float t)
{
	return m_curve->getValue(t);
}
















NS_FS_END 

