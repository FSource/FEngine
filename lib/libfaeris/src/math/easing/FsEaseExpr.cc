#include "FsEaseExpr.h"


NS_FS_BEGIN

const char* EaseExpr::className()
{
	return FS_EASE_EXPR_CLASS_NAME;
}

EaseExpr::EaseExpr(int mode)
{
	m_easeMode=mode;
}

EaseExpr::~EaseExpr()
{
}


float EaseExpr::getValue(float t)
{
	switch(m_easeMode)
	{
		case FS_EASE_IN: return getEaseIn(t);
		case FS_EASE_OUT: return getEaseOut(t);
		case FS_EASE_INOUT:return getEaseInOut(t);
		case FS_EASE_OUTIN: return getEaseOutIn(t);
	}

	FS_TRACE_WARN("Unkown Ease Mode(%d)",m_easeMode);

	return m_easeMode;
}

void EaseExpr::setMode(int mode)
{
	m_easeMode=mode;
}

int EaseExpr::getMode()
{
	return m_easeMode;
}


float EaseExpr::getEaseOut(float t)
{
	return 1.0f-getEaseIn(1.0f-t);
}

float EaseExpr::getEaseInOut(float t)
{
	if (t<=0.5f )
	{
		return 0.5f*getEaseIn(2*t);
	}

	return 0.5f+0.5f*getEaseOut(2*t-1);
}

float EaseExpr::getEaseOutIn()
{
	if (t<=0.5f)
	{
		return 0.5f*getEaseOut(2*t);
	}

	return 0.5f+0.5f*getEaseIn(2*t-1);
}




NS_FS_END








