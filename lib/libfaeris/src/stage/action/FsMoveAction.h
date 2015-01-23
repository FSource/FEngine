/*************************************************************************/
/*  FsMoveAction.h                                                       */
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


#ifndef _FS_MOVE_ACTION_H_
#define _FS_MOVE_ACTION_H_

#include "FsCurve3Action.h"

NS_FS_BEGIN

class MoveAction:public Curve3Action 
{
	public:
		/* from to */
		static MoveAction* createFromTo(const Vector3& from,const Vector3& to,float time);
		static MoveAction* createXYFromTo(float xfrom,float yfrom,float xto,float yto,float time);
		static MoveAction* createXFromTo(float from,float to,float time);
		static MoveAction* createYFromTo(float from,float to,float time);
		static MoveAction* createZFromTo(float from,float to,float time);


		static MoveAction* createBy(const Vector3& from,const Vector3& by,float time);
		static MoveAction* createXYBy(float xfrom,float yfrom,float xby,float yby,float time);
		static MoveAction* createXBy(float from,float by,float time);
		static MoveAction* createYBy(float from,float by,float time);
		static MoveAction* createZBy(float from,float by,float time);


		static MoveAction* create(Curve3* curve,float time);
	public:
		/* inherit FixTimeAction */
		virtual void step(ActionTarget* target,float percent);

		/* inherit FsObject */
		virtual const char* className();

	protected:
		MoveAction();

		void initWithFromTo(const Vector3& from,const Vector3& to,float time);
		void initWithBy(const Vector3& from,const Vector3& by,float time);
		void initWithCurve(Curve3* curve,float time);
};





NS_FS_END



#endif /*_FS_MOVE_ACTION_H_*/

