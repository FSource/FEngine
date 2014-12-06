#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "FsMacros.h"
#include "fsys/FsVFS.h"
#include "loader/FsGeometryLoader.h"
#include "model/FsGeometry.h"

NS_FS_USE

int main(int argc,char** argv)
{
	if(argc!=3)
	{
		printf("usage:%s <input file> <output file>\n",argv[0]);
		exit(-1);
	}
	FsFile* infile=NULL;
	FsFile* outfile=NULL;
	Geometry* g=NULL;

	if(strcmp(argv[1],"stdin")==0)
	{
		infile=VFS::getStdin();
	}
	else 
	{
		infile=VFS::open(argv[1]);
		if(infile==NULL)
		{
			goto error;
		}
	}

	if(strcmp(argv[2],"stdout")==0)
	{
		outfile=VFS::getStdout();
	}
	else 
	{
		outfile=VFS::open(argv[2],VFS::FS_IO_TRUNC);
		if(outfile==NULL)
		{
			goto error;
		}
	}

	g=GeometryLoader::create(argv[1]);
	if(g==NULL)
	{
		printf("create Geometry Failed\n");
		goto error;
	}
	GeometryLoader::saveGeometryWithScript(g,outfile);

error:
	if(infile) infile->decRef();
	if(outfile) outfile->decRef();
	if(g) g->decRef();
	return 0;
}

