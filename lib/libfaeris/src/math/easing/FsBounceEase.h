#ifndef _FS_BOUNCE_EASE_H
#define _FS_BOUNCE_EASE_H

#include "FsMacros.h"
#include "FsEaseExpr.h"

NS_FS_BEGIN

class BounceEase:public EaseExpr
{
	public:
		static BounceEase* create();
		static BounceEase* create(int mode);

	public:
		/*inherit EaseExpr*/
		virtual float getEaseIn(float t);
		virtual float getEaseOut(float t);
		virtual float getEaseInOut(float t);
		virtual float getEaseOutIn(float t);

		/*inherit FsObject*/
		virtual const char* className();

	protected:
		BounceEase();
		BounceEase(int mode);
		virtual ~BounceEase();
}
