#include <stdlib.h>
#include "io/FsZipPackage.h"
#include "io/FsFile.h"
#include "io/FsVFS.h"

NS_FS_USE

int main(int argc,char** argv)
{
	if(argc!=3)
	{
		printf("useage:%s <zipfile> <file>\n",argv[0]);
		exit(0);
	}
	VFS::moduleInit();

	Package* package=Package::create(argv[1],Package::PACKAGE_ZIP);
	if(package==NULL)
	{
		FS_TRACE_WARN("Create Package Failed");
		return 0;
	}

	VFS::mapPackage("",package);
	package->decRef();

	VFS::PrefixNameFilter* filter=VFS::PrefixNameFilter::create("asset/");
	VFS::addFilter(filter);

	FsFile* file=VFS::open(argv[2]);


	filter->decRef();

	if(file==NULL)
	{
		printf("Open File %s Failed\n",argv[2]);
		package->decRef();
		return 0;
	}
	printf("Open File %s Success\n",argv[2]);

	int size=file->getLength();
	char* buf=new char[size+1];
	int readbyte=file->read(buf,size);
	buf[readbyte]=0;

	if(readbyte!=size)
	{
		printf("file length is %d, but only %d byte read",size,readbyte);
	}

	printf("content:\n%s\n",buf);
	delete[] buf;
	file->decRef();
	VFS::moduleExit();
}
