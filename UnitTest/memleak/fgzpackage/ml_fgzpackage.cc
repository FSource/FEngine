#include <stdio.h>
#include <assert.h>
#include "sys/io/FsPackage.h"
#include "sys/io/FsVFS.h"
#include "FsFaerisModule.h"

NS_FS_USE

int main(int argc,char** argv)
{
	if (argc!=2)
	{
		printf("usage:%s <package>\n",argv[0]);
		return 0;
	}

	VFS::moduleInit();


	Package* package=Package::create(argv[1],Package::PACKAGE_FGZ);
	assert(package);
	FsFile* file1=package->takeBlock("simsun1.ttc");
	FsFile* file2=package->takeBlock("textures/background.png");
	assert(file1);
	assert(file2);


	package->decRef();
	file1->decRef();
	file2->decRef();

	VFS::moduleExit();
	return 0;

}


