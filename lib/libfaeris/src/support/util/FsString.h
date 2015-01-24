/*************************************************************************/
/*  FsString.h                                                           */
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


#ifndef _FS_REFCONT_STRING_H_
#define _FS_REFCONT_STRING_H_
#include <string>

#include "FsMacros.h"
#include "FsObject.h"

NS_FS_BEGIN
class FsString:public FsObject
{
	private:
		std::string m_string;
		long m_hash_code;
	public:
		static FsString* create();
		static FsString* create(const char* str);
		static bool checkType(FsObject* ob);

	public: 
		FsString();
		FsString(const char* str);
		FsString(int value);

	public:
		int toIntValue();
		float toFloatValue();

	public:
		const char* className() FS_OVERRIDE;
		long getHashCode() FS_OVERRIDE;
		bool equal(FsObject* ob) FS_OVERRIDE;

		bool equal(const char* str) ;
	public:
		FsString& append(const char* str);
		FsString& append(const char* str,long n);
		FsString& append(const FsString& str);
		FsString& append(const FsString& str,long n);

		FsString& assign(const FsString& str);
		FsString& assign(const FsString& str,long n);
		FsString& assign(const char* str);
		FsString& assign(const char* str,long n);

		void clear();
		int compare(const FsString& str) const;
		int compare(const char* str)const;
		const char* cstr()const;
		bool empty()const; 
		ulong length()const;
		FsString& erase(long pos,long num=1);
		char operator[](ulong n)const ;
	private:
		inline void mCalHashCode();
};
NS_FS_END 

#include "FsString.inl"

#endif  /*_FS_REFCONT_STRING_H_*/
	





	
