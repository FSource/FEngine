/*************************************************************************/
/*  FsString.inl                                                         */
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


#ifndef _FS_UTIL_STRING_INL_
#define _FS_UTIL_STRING_INL_

#include "FsMacros.h"
#include "support/data/FsHash.h"

NS_FS_BEGIN
inline FsString::FsString():m_string("")
{
	mCalHashCode();
}
inline FsString::FsString(const char* str):m_string(str)
{
	mCalHashCode();
}
inline FsString& FsString::append(const char* str)
{
	m_string.append(str);
	mCalHashCode();
	return *this;
}
inline FsString& FsString::append(const char* str,long n)
{
	m_string.append(str,n);
	mCalHashCode();
	return *this;
}
inline FsString& FsString::append(const FsString& str)
{
	m_string.append(str.m_string);
	mCalHashCode();
	return *this;
}
inline FsString& FsString::append(const FsString& str,long n)
{
	m_string.append(str.m_string,0,n);
	mCalHashCode();
	return *this;
}

inline FsString& FsString::assign(const FsString& str)
{
	m_string.assign(str.m_string);
	m_hash_code=str.m_hash_code;
	return *this;
}
inline FsString& FsString::assign(const FsString& str,long n)
{
	m_string.assign(str.m_string,0,n);
	mCalHashCode();
	return *this;
}
inline FsString& FsString::assign(const char* str)
{
	m_string.assign(str);
	mCalHashCode();
	return *this;
}
inline FsString& FsString::assign(const char* str,long n)
{
	m_string.assign(str,n);
	mCalHashCode();
	return *this;
}
inline void FsString::clear()
{
	m_string.clear();
	mCalHashCode();
}
inline int FsString::compare(const FsString& str)const 
{
	return m_string.compare(str.m_string);
}
inline int FsString::compare(const char* str)const
{
	return m_string.compare(str);
}
inline const char* FsString::cstr()const
{
	return m_string.c_str();
}
inline bool FsString::empty()const 
{
	return m_string.empty();
}
inline ulong FsString::length()const 
{
	return m_string.length();
}
inline FsString& FsString::erase(long pos,long num)
{
	m_string.erase(pos,num);
	return *this;
}
inline void FsString::mCalHashCode()
{
	m_hash_code=FsHash_JCode(m_string.c_str());
	if(m_hash_code==FS_INVALID_HASH_CODE)
	{
		m_hash_code+=1;
	}
}

inline char FsString::operator[](ulong n)const 
{
	FS_ASSERT(n<length());
	return m_string[n];
}

NS_FS_END

#endif /*_FS_UTIL_STRING_INL_*/





