#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "FsMacros.h"
#include "fsys/FsVFS.h"
#include "fsys/FsWindow.h"
#include "fsys/FsFrame.h"
#include "loader/FsMaterialLoader.h"
#include "material/FsMaterial.h"
#include "material/FsShaderMaterial.h"

NS_FS_USE

int main(int argc,char** argv)
{
	if(argc!=3)
	{
		printf("usage:%s <input file> <output file>\n",argv[0]);
		exit(-1);
	}
	Window::shareWindow();
	FsFile* infile=NULL;
	FsFile* outfile=NULL;
	Material* g=NULL;

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

	g=MaterialLoader::create(argv[1]);
	if(g==NULL)
	{
		printf("create Geometry Failed\n");
		goto error;
	}
	MaterialLoader::saveShaderMaterialWithScript((ShaderMaterial*)g,outfile);

error:
	if(infile) infile->decRef();
	if(outfile) outfile->decRef();
	if(g) g->decRef();
	Window::purgeShareWindow();
	Frame::purgeShareFrame();
	return 0;
}

