#ifndef _FS_POWER_EASE_H_
#define _FS_POWER_EASE_H_

#include "FsMacros.h"

NS_FS_BEGIN
class PowerEase:public EaseExpr
{
	public:
		static PowerEase* create(float p);

	public:
		virtual float getEaseIn(float t);
		virtual const char* className();

	protected:
		PowerEase(float p);
		virtual ~PowerEase();

	private:
		float m_exponent;
};




NS_FS_END



#endif /*_FS_POWER_EASE_H_*/

