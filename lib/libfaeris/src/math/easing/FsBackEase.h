#ifndef _FS_BACK_EASE_H
#define _FS_BACK_EASE_H

#include "FsMacros.h"
#include "FsEaseExpr.h"

NS_FS_BEGIN

class BackEase:public EaseExpr
{
	public:
		static BackEase* create();
		static BackEase* create(int mode);
		
	public:
		/*	inherit EaseExpr*/
		virtual float getEaseIn(float t);
		virtual float getEaseOut(float t);
		virtual float getEaseInOut(float t);
		virtual float getEaseOutIn(float t);

	
		/* inherit FsObject*/
		virtual const char* className();
		
	protected:
		BackEase();
		BackEase(int mode);
		virtual ~BackEase();

};

NS_FS_END

#endif /*_FS_BACK_EASE_H*/
