#ifndef _FS_UTIL_DICT_H_
#define _FS_UTIL_DICT_H_

#include "FsMacros.h"
#include "FsObject.h"

NS_FS_BEGIN
class  FsDict:public FsObject
{
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
					findNext();
				}
				~Iterator()
				{
					m_dict->decRef();
				}
			public:
				FsObject* getKey()
				{
					FsObject* ret= m_dict->m_table[m_curPos].m_key;
					return ret;
				}
				FsObject* getValue()
				{
					FsObject* ret=m_dict->m_table[m_curPos].m_value;
					return ret;
				}
				bool done()
				{
					return m_curPos>(long)m_dict->m_mask;
				}
				bool next()
				{
					if(m_curPos>(long)m_dict->m_mask)
					{
						return false;
					}
					return findNext();
				}
			protected:
				bool findNext()
				{
					if(m_curPos>(long)m_dict->m_mask)
					{
						return false;
					}
					while(++m_curPos<(long)((m_dict->m_mask+1)))
					{
						if(m_dict->validEntry(m_dict->m_table+m_curPos))
						{
							return true;
						}
					}
					return false ;
				}
			private:
				FsDict* m_dict;
				long m_curPos;
				//long m_iterNu;
		};
		class DictEntry
		{
			public:
				long m_code;
				FsObject* m_key;
				FsObject* m_value;
			public:
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
		bool insertWithNewKey(FsObject* key,FsObject* value);
		bool remove(FsObject* key);
		void clear();
		FS_FEATURE_NEW_OBJECT(Iterator*) takeIterator();
		ulong size(){return m_used;}
	protected:
		DictEntry* getEntry(FsObject* key);
		DictEntry* lookupEntry(FsObject* key,long code);
		void resize(long minisize);
		void simpleInsert(FsObject* key,long hcode,FsObject* value);
		bool validEntry(DictEntry* entry);
	private:
		long m_fill;  /* slot already filled include dummy */
		long m_used;  /* real key num */
		ulong m_mask;
		DictEntry* m_table;
};
NS_FS_END 

#endif /*_FS_UTIL_DICT_H_*/

