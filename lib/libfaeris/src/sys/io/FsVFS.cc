#include <string.h>

#include "FsVFS.h"
#include "sys/io/FsSysFile.h"
#include "sys/io/FsPackage.h"
#include "sys/FsSys.h"
#include "support/util/FsArray.h"
#include "support/util/FsPathUtil.h"

NS_FS_BEGIN
#define FS_ROOT_PATH_SIZE  1024

FS_BEGIN_NAMESPACE(VFS)

/* NameFilter */
NameFilter::~NameFilter()
{

}

const char* NameFilter::className()
{
	return FS_VFS_NAME_FILTER_CLASS_NAME;
}


/* PrefixNameFilter */

PrefixNameFilter* PrefixNameFilter::create(const char* prefix)
{
	return new PrefixNameFilter(prefix);
}

std::string PrefixNameFilter::apply(const char* name)
{
	return m_prefix+name;
}
const char* PrefixNameFilter::className()
{
	return FS_VFS_PREFIX_NAME_FILTER_CLASS_NAME;
}

PrefixNameFilter::PrefixNameFilter(const char* prefix)
{
	m_prefix=prefix;
}
PrefixNameFilter::~PrefixNameFilter()
{
}






/* MapPackage */

MapPackage* MapPackage::create(const char* path,Package* package)
{
	MapPackage* ret=new MapPackage();
	if(!ret->init(path,package))
	{
		delete ret;
		return NULL;
	}
	return ret;
}

FsFile* MapPackage::takeFile(const char* file_name)
{
	int file_name_size=strlen(file_name);
	int path_size=m_path.size();

	if(file_name_size<path_size) 
	{
		return  NULL;
	}


	bool start_with=true;

	for(int i=0;i<path_size;i++)
	{
		if(m_path[i]!=file_name[i])
		{
			start_with=false;
			break;
		}
	}
	if(start_with)
	{
		return m_package->takeBlock(file_name+path_size);
	}
	return NULL;
}

const char* MapPackage::className()
{
	return FS_VFS_MAP_PACKAGE_CLASS_NAME;
}

MapPackage::MapPackage()
{
	m_package=NULL;
}
MapPackage::~MapPackage()
{
	FS_SAFE_DEC_REF(m_package);
}

bool MapPackage::init(const char* path,Package* package)
{
	if(package==NULL) return false;
	m_path=path;
	package->addRef();
	m_package=package;
	return true;
}




/* VFS  Module Data */

static FsArray* s_mapPackage=NULL;
static FsArray* s_nameFilter=NULL;
static char s_root[FS_ROOT_PATH_SIZE];


bool moduleInit()
{
	s_mapPackage=FsArray::create();
	s_nameFilter=FsArray::create();
	//s_root=new std::string(Sys::currentDir())+"/";
	sprintf(s_root,"%s/",Sys::currentDir());

	FS_TRACE_WARN("pwd=%s",s_root);


	return true;
}

bool moduleExit()
{
	FS_SAFE_DEC_REF(s_mapPackage);
	s_mapPackage=NULL;

	FS_SAFE_DEC_REF(s_nameFilter);
	s_nameFilter=NULL;

	return true;
}







void setRoot(const char* path)
{
	strncpy(s_root,path,FS_ROOT_PATH_SIZE);
}
const char* getRoot()
{
	return s_root;
}







FsFile* rawCreate(const char* name,uint mode)
{
	FsFile* ret=NULL;

	/* file is absolutePath */
	if(PathUtil::absolutePath(name))
	{
		ret=SysFile::create(name,mode);
		return ret;
	}

	std::string rel_path=std::string(s_root)+std::string(name);

	/* look with root dir */
	ret=SysFile::create(rel_path.c_str(),mode);
	if(ret!=NULL)
	{
		return ret;
	}


	if(mode!=FS_IO_RDONLY)
	{
		return NULL;
	}

	/* if file is readonly will check it in package */
	int package_nu=s_mapPackage->size();
	for(int i=0;i<package_nu;i++)
	{
		MapPackage* package=(MapPackage*) s_mapPackage->get(i);
		ret=package->takeFile(name);

		if(ret!=NULL)
		{
			return ret;
		}

	}
	return NULL;
}

FsFile* createFile(const char* name,uint mode)
{
	FsFile* ret=NULL;


	/* file is relative path */
	ret=rawCreate(name,mode);
	if(ret!=NULL) return ret;


	/* file not find ,so we apply name fileter to it */

	int fileter_nu=s_nameFilter->size();

	for(int i=0;i<fileter_nu;i++)
	{
		NameFilter* f=(NameFilter*)s_nameFilter->get(i);
		std::string filter_name=f->apply(name);


		ret=rawCreate(filter_name.c_str(),mode);
		if(ret!=NULL)
		{
			return ret;
		}
	}

	/* file not find */
	return NULL;
}




bool addFilter(NameFilter* filter)
{
	s_nameFilter->push(filter);
	return true;
}
bool removeFilter(NameFilter* filter)
{
	s_nameFilter->remove(filter);
	return true;
}

bool mapPackage(const char* path,Package* package,int priority)
{
	MapPackage* map=MapPackage::create(path,package);

	if(!map) return false;

	if (priority == VFS::FS_MAP_HIGH) 
	{
		FS_TRACE_INFO("MapPackage(%s,high)",path);
		s_mapPackage->insert(0,map);
	}
	else 
	{
		FS_TRACE_INFO("MapPackage(%s,low)",path);
		s_mapPackage->push(map);
	}

	return true;

}
bool unmapPackage(const char* path)
{
	/*TODO */
	FS_TRACE_WARN("Not Write Yet");
	return true;
}

FsFile* getStdout()
{
	return SysFile::getStdout();
}
FsFile* getStdin()
{
	return SysFile::getStdin();
}
FsFile* getStderr()
{
	return SysFile::getStderr();
}





int saveFile(const char* filename,const uint8_t* buff,int32_t len)
{
	std::string dir_name=PathUtil::getDirName(filename);
	if(dir_name!="")
	{
		if(!VFS::isDir(dir_name.c_str()))
		{
			if(VFS::mkdir(dir_name.c_str())==-1)
			{
				FS_TRACE_WARN("Can't Create Dir(%s) For File(%s)",dir_name.c_str(),filename);
				return -1;
			}
		}
	}
	
	FsFile* file=VFS::createFile(filename,VFS::FS_IO_CREATE|VFS::FS_IO_TRUNC);
	if(file==NULL)
	{
		FS_TRACE_WARN("Can't Open File(%s) For Write",filename);
		return -1;
	}

	file->write(buff,len);
	file->decRef();
	return 0;
}

int loadFile(const char* filename,uint8_t** buf_out,uint* len_out)
{
	FsFile* file=VFS::createFile(filename);
	if(file==NULL)
	{
		FS_TRACE_WARN("Can't Open File(%s) For Read",filename);
		return -1;
	}
	int32_t length=file->getLength();

	uint8_t* buf=new uint8_t[length];
	file->read(buf,length);
	*buf_out=buf;
	*len_out=length;

	file->decRef();

	return 0;
}




int mkdir(const char* name)
{
	std::string dir_name;
	if(PathUtil::absolutePath(name))
	{
		dir_name=std::string(name);
	}
	else 
	{
		dir_name=std::string(getRoot())+std::string(name);
	}
	return Sys::mkdir(dir_name.c_str());

}

bool isDir(const char* name)
{
	std::string dir_name;
	if(PathUtil::absolutePath(name))
	{
		dir_name=std::string(name);
	}
	else 
	{
		dir_name=std::string(getRoot())+std::string(name);
	}

	return Sys::isDir(dir_name.c_str());
}


FS_END_NAMESPACE(VFS)
NS_FS_END
























