/*************************************************************************/
/*  FsArcCurve.h                                                         */
/*************************************************************************/
/* Copyright (C) 2012-2014 nosiclin@foxmail.com                          */
/* Copyright (C) 2014-2015 www.fsource.cn                                */
/*                                                                       */
/* http://www.fsource.cn                                                 */
/*                                                                       */
/* Permission is hereby granted, free of charge, to any person obtaining */
/* a copy of this software and associated documentation files (the       */
/* "Software"), to deal in the Software without restriction, including   */
/* without limitation the rights to use, copy, modify, merge, publish,   */
/* distribute, sublicense, and/or sell copies of the Software, and to    */
/* permit persons to whom the Software is furnished to do so, subject to */
/* the following conditions:                                             */
/*                                                                       */
/* The above copyright notice and this permission notice shall be        */
/* included in all copies or substantial portions of the Software.       */
/*                                                                       */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,       */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF    */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.*/
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY  */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,  */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE     */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                */
/*************************************************************************/


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

