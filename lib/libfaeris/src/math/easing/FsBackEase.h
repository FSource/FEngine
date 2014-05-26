#ifndef _FS_BACK_EASE_H
#define _FS_BACK_EASE_H

#include "FsMacros.h"
#include "FsEaseExpr.h"

NS_FS_BEGIN

class BackEase:public EaseExpr
{
	public:
		static BackEase* create();
		static BackEase* create(float overshoot);
		
	public:
		/*	inherit EaseExpr*/
		virtual float getEaseIn(float t);
		virtual float getEaseOut(float t);
		virtual float getEaseInOut(float t);
		virtual float getEaseOutIn(float t);

		/* inherit FsObject*/
		virtual const char* className();

	public:
		void setOvershoot(float a){m_overshoot=a;}
		float getOvershoot(){return m_overshoot;}
		
	protected:
		BackEase(float overshoot);

	private:
		float m_overshoot;
};

NS_FS_END

#endif /*_FS_BACK_EASE_H*/
