#ifndef _FS_SINE_EASE_H_
#define _FS_SINE_EASE_H_ 

#include "FsMacros.h"
#include "FsEaseExpr.h"

NS_FS_BEGIN

class SineEase:public EaseExpr 
{
	public:
		static SineEase* create();

	public:
		virtual float getEaseIn(float t);
		virtual const char* className();

	protected:
		SineEase();
		virtual ~SineEase();

};


NS_FS_END



#endif /*_FS_SINE_EASE_H_*/



