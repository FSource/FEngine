/*************************************************************************/
/*  FsSlowDict.h                                                         */
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


#ifndef _FS_UTIL_SLOW_DICT_H_
#define _FS_UTIL_SLOW_DICT_H_
 
#include <vector>

#include "FsMacros.h"
#include "FsObject.h"
#include "support/util/FsDict.h"


NS_FS_BEGIN
class FsSlowDict:public FsObject 
{

	public:
		static FsSlowDict* create();

	public:
		virtual const char* className();


	public:
		void lock();
		void unlock();
		void flush();


		FsObject* lookup(FsObject* key);
		FsObject* lookup(const char* key);
		void insert(FsObject* key,FsObject* value);
		void remove(FsObject* key);
		void clear();
		ulong size();

		FS_FEATURE_NEW_OBJECT(FsDict::Iterator*) takeIterator();

	protected:
		FsSlowDict();
		virtual ~FsSlowDict();

	private:
		enum 
		{
			CM_INSERT,
			CM_REMOVE,
			CM_CLEAR,
		};

		class PendingCommand
		{
			public:
				PendingCommand(int type,FsObject* key,FsObject* value)
				{
					m_type=type;
					m_key=key;
					m_value=value;
					FS_SAFE_ADD_REF(key);
					FS_SAFE_ADD_REF(value);
				}

				~PendingCommand()
				{
					FS_SAFE_DEC_REF(m_key);
					FS_SAFE_DEC_REF(m_value);
				}

			public:
				int m_type;
				FsObject* m_key;
				FsObject* m_value;
		};

	private:
		bool m_lock;
		FsDict* m_dict;
		std::vector<PendingCommand*> m_pendingCommand;
};

NS_FS_END 

#endif /*_FS_UTIL_SLOW_DICT_H_*/


