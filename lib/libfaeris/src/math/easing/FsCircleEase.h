#ifndef _FS_CIRCLE_EASE_H_
#define _FS_CIRCLE_EASE_H_

#include "FsEaseExpr.h"
NS_FS_BEGIN

class CircleEase:EaseExpr 
{
	public:
		static CircleEase* create();

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




#endif /*_FS_CIRCLE_EASE_H_*/

