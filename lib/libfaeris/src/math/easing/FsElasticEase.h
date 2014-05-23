#ifndef _FS_ELASTIC_EASE_H_
#define _FS_ELASTIC_EASE_H_

#include "FsMacros.h"
#include "FsEaseExpr.h"

NS_FS_BEGIN
class ElasticEase:public EaseExpr 
{
	public:
		static ElasticEase* create();
		static ElasticEase* create(float amplitude,float period);

	public:
		/*inherit EaseExpr*/
		virtual float getEaseIn(float t);
		virtual float getEaseOut(float t);
		virtual float getEaseInOut(float t);
		virtual float getEaseOutIn(float t);

		/* inherit FsObject */
		virtual const char* className();

	public:
		void setAmplitude(float amplitude){m_amplitude=amplitude;}
		float getAmplitude(){return m_amplitude;}
		void setPeriod(float period){m_period=period;}
		float getPeriod(){return m_period;}

	protected:
		ElasticEase();

	private:
		float m_amplitude;
		float m_period;
};




NS_FS_END


#endif /*_FS_ELASTIC_EASE_H_*/

