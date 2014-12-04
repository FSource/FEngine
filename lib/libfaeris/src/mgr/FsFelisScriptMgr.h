#ifndef _FS_FELIS_SCRIPT_MGR_H_
#define _FS_FELIS_SCRIPT_MGR_H_

#include "FsMacros.h"
#include "mgr/FsResourceMgr.h"
#include "mgr/FsResource.h"



NS_FS_BEGIN
class FsDict;
class FsFile;
class FelisScriptMgr: public ResourceMgr
{
	public:
		class FelisResource:public Resource
		{
			public:
				static FelisResource* create(FsFile* file);

			public:
				FsDict* getDict()
				{
					return m_dict;
				}

			protected:
				bool init(FsFile* file);

				FelisResource();
				~FelisResource();

			private:
				FsDict* m_dict;
		};

	public:
		static FelisScriptMgr* create();

	public:

		/* please not call "load" */
		virtual Resource* load(const char* name);  

		FsDict* loadDict(const char* name);

	protected:
		FelisScriptMgr();
};

NS_FS_END 

#endif /*_FS_FELIS_SCRIPT_MGR_H_*/



