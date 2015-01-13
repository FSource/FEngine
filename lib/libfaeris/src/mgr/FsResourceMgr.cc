#include "mgr/FsResourceMgr.h"
#include "mgr/FsResource.h"
#include "support/util/FsPathUtil.h"
#include "sys/io/FsVFS.h"

NS_FS_BEGIN
ResourceMgr::ResourceMgr(ResourceCreateFunc func)
{
	m_func=func;
	m_caches=FsDict::create();

	FS_NO_REF_DESTROY(m_caches);
}


ResourceMgr::~ResourceMgr()
{
	unloadAll(true);
	FS_DESTROY(m_caches);
}



void ResourceMgr::addSearchPath(const char* path)
{
	if(existSearchPath(path))
	{
		return ;
	}
	m_searchPaths.push_back(std::string(path));
}

bool ResourceMgr::existSearchPath(const char* path)
{
	if(pathPos(path)==-1)
	{
		return false;
	}
	return true;

}

void ResourceMgr::removeSearchPath(const char* path)
{
	int pos=pathPos(path);
	if(pos==-1)
	{
		FS_TRACE_WARN("path not found");
	}
	m_searchPaths.erase(m_searchPaths.begin()+pos);
}


void ResourceMgr::remove(Resource* res)
{
	if(res->m_mgr!=this)
	{
		FS_TRACE_WARN("Resource Is Not Manager");
		return ;
	}

	FsString* key=res->getResourceName();
	assert(key);
	removeCache(key);
}

void ResourceMgr::add(const char* name,Resource* res)
{
	if(res->m_mgr)
	{
		if(res->m_mgr==this)
		{
			FS_TRACE_WARN("Resource Is Aready Manager");
		}
		else 
		{
			FS_TRACE_WARN("Resource Is Manage By Other Manager");
		}
		return;
	}
	FsString* f_name=FsString::create(name);
	m_caches->insert(f_name,res);

	res->m_mgr=this;
	res->setResourceName(f_name);
}

int ResourceMgr::getCacheResourceNu()
{
	return m_caches->size();
}



/* protected */
int ResourceMgr::pathPos(const char* path)
{
	std::string path_str(path);
	int pos=-1;
	int path_nu=m_searchPaths.size();

	for(int i=0;i<path_nu;i++)
	{
		if(m_searchPaths[i]==path_str)
		{
			pos=i;
			break;
		}
	}
	return pos;
}


void ResourceMgr::removeCache(FsString* key)
{
	Resource* res=(Resource*) m_caches->lookup(key);
	if(res)
	{
		res->setMgr(NULL);
	}
	m_caches->remove(key);
}

Resource* ResourceMgr::findFromCache(FsString* name)
{
	Resource* ret=(Resource*)m_caches->lookup(name);
	return ret;
}



Resource* ResourceMgr::load(const char* filename)
{
	if(filename==NULL)
	{
		return NULL;
	}

	FsString* f_name=FsString::create(filename);
	Resource* ret=findFromCache(f_name);
	if( !ret)
	{
		if(!m_func)
		{
			FS_TRACE_WARN("load Func Not Define");
			return NULL;
		}
		FsFile* file=createFile(filename);
		if(file)
		{
			FS_SAFE_ADD_REF(file);
			ret=m_func(file);
			FS_SAFE_DEC_REF(file);
			if(ret)
			{
				addCache(f_name,ret);
			}
			else
			{
				FS_TRACE_WARN("Can't Load Resource (%s)",filename?filename:"NULL");
			}
		}
	}
	f_name->autoDestroy();
	return ret;
}


FsFile* ResourceMgr::createFile(const char* filename)
{
	FsFile* ret=NULL;

	/* file is absolutePath */
	if(PathUtil::absolutePath(filename)) 
	{
		ret=VFS::createFile(filename);
		return ret;
	}

	/* direct load */
	ret=VFS::createFile(filename);
	if(ret)
	{
		return ret;
	}

	/* load from search path */

	int path_nu=m_searchPaths.size();
	std::string std_filename(filename);

	for(int i=0;i<path_nu;i++)
	{
		std::string load_path=m_searchPaths[i]+std_filename;
		ret=VFS::createFile(load_path.c_str());
		if(ret)
		{
			return ret;
		}

	}
	return NULL;
}





void ResourceMgr::addCache(FsString* name,Resource* res)
{
	res->setMgr(this);
	res->setResourceName(name);
	m_caches->insert(name,res);
}




bool ResourceMgr::preloadResource(const char* path)
{
	Resource* ret=load(path);

	if (ret==NULL)
	{
		return false;
	}
	return true;
}


bool ResourceMgr::unload(const char* path,bool force)
{
	Resource* res=load(path);
	if(res!=NULL)
	{
		if(res->refCnt()==1||force) 
		{
			remove(res);
			return true;
		}
	}
	return false;
}


void ResourceMgr::unloadAll(bool force)
{
	if(force)
	{	
		FsDict::Iterator iter(m_caches);
		while(!iter.done())
		{
			Resource* res=(Resource*)iter.getValue();
			res->setMgr(NULL);
			iter.next();
		}

		m_caches->clear();
	}
	else 
	{
		std::vector<Resource*> need_unload;
		FsDict::Iterator iter(m_caches);
		while(!iter.done())
		{
			Resource* res=(Resource*)iter.getValue();
			if(res->refCnt()==1)
			{
				need_unload.push_back(res);
			}
			iter.next();
		}

		int size=need_unload.size();
		for(int i=0;i<size;i++)
		{
			//FS_TRACE_INFO("remove cache:%s",need_unload[i]->getResourceName()->cstr());
			remove(need_unload[i]);
		}
	}
}


void ResourceMgr::dump()
{

	/*
	   FsDict::Iterator iter(m_caches);
	   while(!iter.done())
	   {
	   FsString* key=(FsString*)iter.getKey();
	//	printf("\t%s\n",key->cstr());
	iter.next();
	}
	//printf("%s Dump Resource End\n",className());
	*/
}


NS_FS_END













