#ifndef _FS_EXPONENTIAL_EASE_H_
#define _FS_EXPONENTIAL_EASE_H_

#include "FsMacros.h"
#include "FsEaseExpr.h"

NS_FS_BEGIN 

class ExponentialEase:public EaseExpr 
{
	public:
		static ExponentialEase* create();

	public:
		virtual float getEaseIn(float t);
		virtual float getEaseOut(float t);
		virtual float getEaseInOut(float t);
		virtual float getEaseOutIn(float t);

		virtual const char* className();

	protected:
		ExponentialEase();

};

NS_FS_END

#endif /*_FS_EXPONENTIAL_EASE_H_*/


