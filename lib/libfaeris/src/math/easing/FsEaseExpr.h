/*************************************************************************/
/*  FsEaseExpr.h                                                         */
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


#ifndef _FS_EASE_EXPR_H_
#define _FS_EASE_EXPR_H_

#include "FsObject.h"
#include "FsMacros.h"

NS_FS_BEGIN

enum 
{
	FS_EASE_IN=0,
	FS_EASE_OUT=1,
	FS_EASE_INOUT=2,
	FS_EASE_OUTIN=3,
};


class EaseExpr:public FsObject 
{
	public:
		float getValue(float t);
		float getValue(float t,int mode);
		void setMode(int mode);
		int getMode();

	public:
		virtual float getEaseIn(float t)=0;
		virtual float getEaseOut(float t);
		virtual float getEaseInOut(float t);
		virtual float getEaseOutIn(float t);


		/* inherit FsObject */
		const char* className();

	protected:
		EaseExpr(int mode);
		EaseExpr();
		virtual ~EaseExpr();

	private:
		int m_easeMode;

};

NS_FS_END 
#endif /*_FS_EASE_EXPR_H_*/


