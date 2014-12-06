#ifndef _FAERY_VFS_H_
#define _FAERY_VFS_H_

#include "FsFile.h" 
#include "FsMacros.h"
NS_FS_BEGIN
class FsDir;

FS_BEGIN_NAMESPACE(VFS)
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

bool moduleInit();
bool moduleExit();

FsFile* open(const char* name,uint mode=FS_IO_RDONLY);
FsFile* create(const char* name);
int remove(const char* name);
int copy(const char* src,const char* dst);
bool exist(const char* name);
FsDir* openDir(const char* name);
bool isDir(const char* name);
bool mapPackage(const char* name);

FsFile* getStdout(); 
FsFile* getStdin(); 
FsFile* getStderr(); 

FS_END_NAMESPACE(VFS)
NS_FS_END

#endif 

