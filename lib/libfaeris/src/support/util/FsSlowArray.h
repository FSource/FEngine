/*************************************************************************/
/*  FsSlowArray.h                                                        */
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


#ifndef _FS_SLOW_ARRAY_H_
#define _FS_SLOW_ARRAY_H_

#include <vector>

#include "FsMacros.h"
#include "support/util/FsArray.h"
#include "FsObject.h"

NS_FS_BEGIN
class FsSlowArray:public FsObject
{

	public:
		static FsSlowArray* create();

	public:
		virtual const char* className() ;

	public:
		void lock();
		void unlock();
		void flush();

		void push(FsObject* object);
		void pop();
		void remove(FsObject* object);
		void set(int pos,FsObject* object);
		void insert(int pos,FsObject* object);
		void clear();


		FsObject* get(ulong index);
		FsObject* top();
		int size();
		

	protected:
		FsSlowArray();
		virtual ~FsSlowArray();
		void init();
		void destruct();


	private:
		enum
		{
			CM_POP,
			CM_PUSH,
			CM_REMOVE,
			CM_SET,
			CM_INSERT,
			CM_CLEAR,
		};

		class PendingCommand
		{
			public:
				PendingCommand(int type,int pos,FsObject* ob)
				{
					m_type=type;
					m_pos=pos;
					FS_SAFE_ADD_REF(ob);
					m_object=ob;
				}


				~PendingCommand()
				{
					FS_SAFE_DEC_REF(m_object);
				}

				
			public:
				int m_type;
				int m_pos;
				FsObject* m_object;
		};


	private:
		bool m_lock;
		FsArray* m_items;
		std::vector<PendingCommand*> m_pendingCommand;
};
NS_FS_END

#endif /*_FS_SLOW_ARRAY_H_*/

















