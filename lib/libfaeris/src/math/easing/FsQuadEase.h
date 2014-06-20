#ifndef _FS_QUAD_EASE_H_
#define _FS_QUAD_EASE_H_

#include "FsEaseExpr.h"
NS_FS_BEGIN

class QuadEase:EaseExpr 
{
	public:
		static QuadEase* create();

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


#endif /*_FS_QUAD_EASE_H_*/

