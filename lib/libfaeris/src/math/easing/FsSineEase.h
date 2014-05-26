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
		/* inherit EaseExpr */
		virtual float getEaseIn(float t);
		virtual float getEaseOut(float t);
		virtual float getEaseInOut(float t);
		virtual float getEaseOutIn(float t);

		/* inherit FsObject */
		virtual const char* className();


};


NS_FS_END



#endif /*_FS_SINE_EASE_H_*/



