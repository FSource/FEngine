/*************************************************************************/
/*  FsFace3.h                                                            */
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


#ifndef _FAERY_FACE3_H_
#define _FAERY_FACE3_H_

#include "FsMacros.h"

NS_FS_BEGIN
class Face3 
{
	public:
		union
		{
			struct
			{
				uint16_t a;
				uint16_t b;
				uint16_t c;
			};
			uint16_t v[3];
		};
	public:
		void set(uint16_t _a,uint16_t _b,uint16_t _c)
		{
			a=_a;
			b=_b;
			c=_c;
		}

	public:
		Face3(uint16_t _a,uint16_t _b,uint16_t _c)
			:a(_a),b(_b),c(_c)
		{}
		Face3(){}
};
typedef Face3 Face3i;


NS_FS_END

#endif 

