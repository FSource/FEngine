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


