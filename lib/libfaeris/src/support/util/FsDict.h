/*************************************************************************/
/*  FsDict.h                                                             */
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


#ifndef _FS_UTIL_DICT_H_
#define _FS_UTIL_DICT_H_

#include <vector>
#include "FsMacros.h"
#include "FsObject.h"

NS_FS_BEGIN

class FsArray;
class FsDict;
class FsString;


class  FsDict:public FsObject
{
	public:
		class DictEntry
		{
			public:
				long m_code;
				FsObject* m_key;
				FsObject* m_value;

				DictEntry* m_prev;
				DictEntry* m_next;
		};
	public:
		class Iterator
		{
			FS_FEATURE:
				FS_MAKE_NO_COPYABLE(Iterator);
			public:
				Iterator(FsDict* dict)
				{
					m_dict=dict;
					dict->addRef();
					m_curPos=-1;
					if(dict->m_entryListHead!=NULL)
					{
						DictEntry* p=dict->m_entryListHead;
						while(p)
						{
							DictEntry* entry=new DictEntry;
							entry->m_key=p->m_key;
							entry->m_key->addRef();

							entry->m_value=p->m_value;
							entry->m_value->addRef();

							entry->m_code=0;
							entry->m_prev=NULL;
							entry->m_next=NULL;

							m_entries.push_back(entry);
							p=p->m_next;
						}
					}
					findNext();
				}
				~Iterator()
				{
					int size=m_entries.size();

					for(int i=0;i<size;i++)
					{
						DictEntry* entry=m_entries[i];
						entry->m_key->decRef();
						entry->m_value->decRef();
						delete entry;
					}
					m_entries.clear();


					m_dict->decRef();
				}
			public:
				FsObject* getKey()
				{
					if(m_curPos>=(int)m_entries.size())
					{
						return NULL;
					}
					FsObject* ret= m_entries[m_curPos]->m_key;
					return ret;
				}
				FsObject* getValue()
				{
					if(m_curPos>=(int)m_entries.size())
					{
						return NULL;
					}

					FsObject* ret=m_entries[m_curPos]->m_value;
					return ret;
				}
				bool done()
				{
					return m_curPos>=(int)m_entries.size();
				}
				bool next()
				{
					if(m_curPos>=(int)m_entries.size())
					{
						return false;
					}
					return findNext();
				}
			protected:
				bool findNext()
				{
					int size=m_entries.size();
					++m_curPos;
					if(m_curPos<size)
					{
						return true;
					}
					return false ;
				}
			private:
				FsDict* m_dict;
				int m_curPos;
				std::vector<DictEntry*> m_entries;
		};
	public:
		static FsDict* create();

	public:
		FsDict();
		~FsDict();
		virtual const char* className();
		static bool checkType(FsObject* ob);
	public:
		FsObject* lookup(FsObject* key);
		FsObject* lookup(const char* key);
		bool insert(FsObject* key,FsObject* value);
		//bool insertWithNewKey(FsObject* key,FsObject* value);
		bool remove(FsObject* key);
		void clear();
		FS_FEATURE_NEW_OBJECT(Iterator*) takeIterator();
		ulong size(){return m_used;}

	public:
		FsDict* lookupDict(const char* key);
		FsString* lookupString(const char* key);
		FsArray* lookupArray(const char* key);

	protected:
		DictEntry* getEntry(FsObject* key);
		DictEntry* lookupEntry(FsObject* key,long code);
		void resize(long minisize);
		void simpleInsert(FsObject* key,long hcode,FsObject* value);
		bool validEntry(DictEntry* entry);

		void addEntryToList(DictEntry* en);
		void removeEntryFromList(DictEntry* en);

	private:
		long m_fill;  /* slot already filled include dummy */
		long m_used;  /* real key num */
		ulong m_mask;
		DictEntry* m_table;

		DictEntry* m_entryListHead;
		DictEntry* m_entryListTail;

};

NS_FS_END 

#endif /*_FS_UTIL_DICT_H_*/

