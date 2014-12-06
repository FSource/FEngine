#include "sys/io/FsVFS.h"
#include "sys/io/FsPackage.h"
#include "sys/io/FsZipPackage.h"
#include "sys/io/FsFgzPackage.h"

NS_FS_BEGIN

Package* Package::create(const char* filename,int type)
{
	FsFile* file=VFS::createFile(filename);
	if(file==NULL)
	{
		FS_TRACE_WARN("Can't Find File For Package");
		return NULL;
	}

	Package* ret=NULL;
	switch(type)
	{
		case PACKAGE_ZIP:
			ret=ZipPackage::create(file);
			break;
		case PACKAGE_FGZ:
			ret=FgzPackage::create(file);
	}
	file->autoDestroy();
	return ret;
}


Package::~Package()
{
}

const char* Package::className()
{
	return FS_PACKAGE_CLASS_NAME;
}



NS_FS_END




















