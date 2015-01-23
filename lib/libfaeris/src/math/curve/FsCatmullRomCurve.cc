/*************************************************************************/
/*  FsCatmullRomCurve.cc                                                 */
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


#include "FsCatmullRomCurve.h"

NS_FS_BEGIN

/* CatmullRomCurve2 */
CatmullRomCurve2* CatmullRomCurve2::create()
{
	return new CatmullRomCurve2();
}

const char* CatmullRomCurve2::className()
{
	return FS_CATMULL_ROM_CURVE_2;
}


/* CatmullRomCurve3 */
CatmullRomCurve3* CatmullRomCurve3::create()
{
	return new CatmullRomCurve3();
}

const char* CatmullRomCurve3::className()
{
	return FS_CATMULL_ROM_CURVE_3;
}

/* CatmullRomCurve4 */
CatmullRomCurve4* CatmullRomCurve4::create()
{
	return new CatmullRomCurve4();
}

const char* CatmullRomCurve4::className()
{
	return FS_CATMULL_ROM_CURVE_4;
}



NS_FS_END 




