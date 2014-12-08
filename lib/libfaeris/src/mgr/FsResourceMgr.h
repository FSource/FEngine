#ifndef _FS_RESOURCE_MGR_H_
#define _FS_RESOURCE_MGR_H_ 

#include <string>
#include <vector>
#include <map>
#include "FsMacros.h"
#include "support/util/FsString.h"
#include "support/util/FsDict.h"

NS_FS_BEGIN
class Resource;
class FsFile;

class ResourceMgr:public FsObject
{
	public:
		typedef Resource* (*ResourceCreateFunc)(FsFile* file);

	public:
		ResourceMgr(ResourceCreateFunc func);
		virtual ~ResourceMgr();

	public:
		virtual Resource* load(const char* path);

	public:
		void addSearchPath(const char* path);
		bool existSearchPath(const char* path);
		void removeSearchPath(const char* path);

		bool preloadResource(const char* path);
		bool unload(const char* path,bool force=false);
		void unloadAll(bool force=false);
		int getCacheResourceNu();


		void remove(Resource* res);
		void add(const char* name,Resource* res);

		virtual void dump();


	protected:
		int pathPos(const char* path);

		FsFile* createFile(const char* filename);

		void removeCache(FsString* key);
		void addCache(FsString* name,Resource* res);
		Resource* findFromCache(FsString* name);

		void clearCache();

	protected:
		ResourceCreateFunc m_func;
		std::vector<std::string> m_searchPaths;

		FsDict* m_caches;
};
NS_FS_END

#endif  /*_FS_RESOURCE_MGR_H_*/



