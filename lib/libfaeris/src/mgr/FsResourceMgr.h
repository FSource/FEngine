/*************************************************************************/
/*  FsResourceMgr.h                                                      */
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



