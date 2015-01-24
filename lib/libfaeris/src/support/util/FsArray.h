/*************************************************************************/
/*  FsArray.h                                                            */
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


#ifndef _FS_UTIL_ARRAY_H_
#define _FS_UTIL_ARRAY_H_ 

#include "FsMacros.h"
#include "FsObject.h"

NS_FS_BEGIN

class FsArray;
class FsDict;
class FsString;


class FsArray:public FsObject
{
	public:
		class Iterator
		{
			FS_FEATURE:
				FS_MAKE_NO_COPYABLE(Iterator);
			public:
				bool done()
				{
					return m_curPos>=m_host->m_size;
				}
				bool next()
				{
					return ++m_curPos>=m_host->m_size;
				}
				FsObject* getValue()
				{
					FsObject* ret=m_host->m_obs[m_curPos];
					return ret;
				}
				Iterator(FsArray* ay)
				{
					m_host=ay;
					m_host->addRef();
					m_curPos=0;
				}
				~Iterator()
				{
					m_host->decRef();
				}

			private:
				FsArray* m_host;
				ulong m_curPos;
		};
	public:
		static FsArray* create();
	public:
		void push(FsObject* item);
		void pop();

		bool set(ulong index,FsObject*  item);
		FsObject* get(ulong index);
		FsObject* top();
		bool insert(ulong index,FsObject* item);
		bool remove(ulong index);
		bool remove(FsObject* ob);
		void clear();
		void resize(ulong new_size);
		ulong size() { return m_size; }

	public:
		FsDict* getDict(ulong index);
		FsString* getString(ulong index);
		FsArray* getArray(ulong index);

	public:
		FsArray();
		FsArray(ulong size);
		virtual ~FsArray();
		virtual const char* className();
		static bool checkType(FsObject* ob);

	protected:
		void enlarge(ulong new_size);
		int itemPos(FsObject* ob);
	private:
		ulong m_size;
		ulong m_cap;
		FsObject** m_obs;

};

NS_FS_END 
#endif /*_FS_UTIL_ARRAY_H_*/

