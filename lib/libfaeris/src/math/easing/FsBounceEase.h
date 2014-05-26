#ifndef _FS_BOUNCE_EASE_H
#define _FS_BOUNCE_EASE_H

#include "FsMacros.h"
#include "FsEaseExpr.h"

NS_FS_BEGIN

class BounceEase:public EaseExpr
{
	public:
		static BounceEase* create();
		static BounceEase* create(float amplitude);

	public:
		/*inherit EaseExpr*/
		virtual float getEaseIn(float t);
		virtual float getEaseOut(float t);
		virtual float getEaseInOut(float t);
		virtual float getEaseOutIn(float t);


		/*inherit FsObject*/
		virtual const char* className();

	public:
		void setAmplitude(float a){m_amplitude=a;}
		float getAmplitude(){return m_amplitude;}

	protected:
		BounceEase(float amplitude);

	private:
		float m_amplitude;
};

NS_FS_END 

#endif /*_FS_BOUNCE_EASE_H_*/

