#ifndef _FS_LINEAR_EASE_H_
#define _FS_LINEAR_EASE_H_

#include "FsMacros.h"
#include "FsEaseExpr.h"

NS_FS_BEGIN

class LinearEase:public EaseExpr
{
	public:
		static LinearEase* create();

	public:
		/* inherit EaseExpr */
		virtual float getEaseIn(float t);


		/* inherit FsObject */
		virtual const char* className();


};


NS_FS_END 

#endif /*_FS_LINEAR_EASE_H_*/



