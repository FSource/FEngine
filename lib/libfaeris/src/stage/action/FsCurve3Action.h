/*************************************************************************/
/*  FsCurve3Action.h                                                     */
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


#ifndef _FS_CURVE3_ACTION_H_
#define _FS_CURVE3_ACTION_H_

#include "FsMacros.h"
#include "FsFixTimeAction.h"
#include "math/curve/FsCurve.h"

NS_FS_BEGIN
namespace CurveUsedMarkBit
{
	enum{
		USED_X=0x1,
		USED_Y=0x2,
		USED_Z=0x4,
		USED_W=0x8,
		USED_XYZ=USED_X|USED_Y|USED_Z,
	};
};


class Curve3Action:public FixTimeAction 
{
	public:
		virtual const char* className();

	public:
		void setCurveMarkBit(uint32_t bit){m_markBit=bit;}
		uint32_t getCurveMarkBit(){return m_markBit;}

		void setCurve(Curve3* curve){FS_SAFE_ASSIGN(m_curve,curve);}
		Curve3* getCurve(){return m_curve;}

	protected:
		Curve3Action();
		~Curve3Action();

		Vector3 getCurveValue(float t);
		void init(Curve3* curve,float time);
		void destruct();

	protected:
		Curve3* m_curve;
		uint32_t m_markBit;
};



NS_FS_END 


#endif /*_FS_CURVE3_ACTION_H_*/

