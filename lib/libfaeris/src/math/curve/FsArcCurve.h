#ifndef _FS_ARC_CURVE_H_
#define _FS_ARC_CURVE_H_

#include "FsMacros.h"
#include "FsCurve.h"

NS_FS_BEGIN
/* FIXME: How To Description Arc In 3D Space */ 

class ArcCurve3:public Curve3
{
	public:
		void setStartAngle(float v) { m_startAngle=v; }
		void setEndAngle(float v) { m_endAngle=v; }
		void setAngle(float s,float e){m_startAngle=s;m_endAngle=e;}

		void setStartRadius(float v) {m_startRadius=v;}
		void setEndRadius(float v){m_endRadius=v;}
		void setRadius(float s,float e){m_startRadius=s;m_endRadius=e;}

		void setCenter(Vector3 v){m_center=v;}

	public:
		virtual  Vector3 getValue(float t)
		{
			float angle=m_startAngle+(m_endAngle-m_startAngle)*t;
			float raduis=m_startRadius+(m_endRadius-m_startRadius)*t;

			Matrix4 mat;
			mat.makeRotateAxis(m_rotateAxis,angle);
			Vector3 out=mat.mulVector3(Vector3(0,0,0));


			return 
		}


	private:
		Vector3 m_center;
		Vector3 m_rotateAxis;


		float m_startAngle;
		float m_endAngle;

		float m_startRadius;
		float m_endRadius;

};



NS_FS_END



#endif /*_FS_ARC_CURVE_H_*/

