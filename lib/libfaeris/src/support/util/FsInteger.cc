/*************************************************************************/
/*  FsInteger.cc                                                         */
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


#include "support/util/FsInteger.h"

static const char* s_FsIntegerName=FS_INTEGER_CLASS_NAME;

NS_FS_BEGIN

FsInteger* FsInteger::create(int value)
{
	return new FsInteger(value);

}

bool FsInteger::checkType(FsObject* ob)
{
	return ob->className()==s_FsIntegerName;
}

const char* FsInteger::className()
{
	return s_FsIntegerName;
}

bool FsInteger::equal(FsObject* ob)
{
	if(!FsInteger::checkType(ob))
	{
		return false;
	}
	return ((FsInteger*)ob)->m_value==m_value;
}
long FsInteger::getHashCode()
{
	if(m_value==FS_INVALID_HASH_CODE)
	{
		return m_value+1;
	}
	return m_value;
}

FsInteger::FsInteger()
	:m_value(0)
{}

FsInteger::FsInteger(int value)
	:m_value(value)
{}



NS_FS_END










