#ifndef _FAERY_VFS_H_
#define _FAERY_VFS_H_

#include <string>
#include "FsFile.h" 
#include "FsMacros.h"
#include "FsObject.h"
NS_FS_BEGIN

class FsDir;
class Package;

FS_BEGIN_NAMESPACE(VFS)
class NameFilter:public FsObject
{
	public:
		virtual std::string apply(const char* name)=0;
		virtual const char* className();
	protected:
		virtual ~NameFilter();
};

class PrefixNameFilter:public NameFilter 
{
	public:
		static PrefixNameFilter* create(const char* prefix);
	public:
		std::string apply(const char* name);
		const char* className();
	protected:
		PrefixNameFilter(const char* prefix);
		virtual ~PrefixNameFilter();
	private:
		std::string m_prefix;
};


class MapPackage:public FsObject
{
	public:
		static MapPackage* create(const char* path,Package* package);

	public:
		FsFile* takeFile(const char* path);
	public:
		virtual const char* className();

	protected:
		MapPackage();
		~MapPackage();
		bool init(const char* path,Package* package);
	private:
		std::string m_path;
		Package* m_package;
};

enum
{
	FS_IO_RDONLY=FsFile::FS_IO_RDONLY,
	FS_IO_WRONLY=FsFile::FS_IO_WRONLY,
	FS_IO_RDWR=FsFile::FS_IO_RDWR,
	FS_IO_APPEND=FsFile::FS_IO_APPEND,
	FS_IO_CREATE=FsFile::FS_IO_CREATE,
	FS_IO_TRUNC=FsFile::FS_IO_TRUNC,
};

enum
{
	FS_SEEK_SET=FsFile::FS_SEEK_SET,
	FS_SEEK_CUR=FsFile::FS_SEEK_CUR,
	FS_SEEK_END=FsFile::FS_SEEK_END,
};

enum 
{
	FS_MAP_LOW=0,
	FS_MAP_HIGH,
};


bool moduleInit();
bool moduleExit();

void setRoot(const char* path);
const char* getRoot();

FsFile* createFile(const char* name,uint mode=FS_IO_RDONLY);


bool addFilter(NameFilter* filter);
bool removeFilter(NameFilter* filter);
bool mapPackage(const char* path,Package* package,int priority=VFS::FS_MAP_LOW);
bool unmapPackage(const char* path);

FsFile* getStdout(); 
FsFile* getStdin(); 
FsFile* getStderr(); 


/* aux interface for easy read and write */
int saveFile(const char* filename,const uint8_t* buff,int32_t len);
int loadFile(const char* filename,uint8_t** buff,uint* len);




/* platform independ api */

/* directory */
int mkdir(const char* name);
bool isDir(const char* name);
FsDir* openDir(const char* name);


/* normal file */
int create(const char* name);
int remove(const char* name);
int copy(const char* src,const char* dst);
bool exist(const char* name);


FS_END_NAMESPACE(VFS)

NS_FS_END

#endif 















