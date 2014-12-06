#include "fsys/FsSysFile.h"
#include "util/FsScriptUtil.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace Faeris;
int main(int argc,char** argv)
{
	if(argc!=4)
	{
		printf("usage: %s <-indent|-noindent> <infile|stdin>  <outfile|stdout>\n",argv[0]);
		exit(-1);
	}

	int indent=-1;
	char* filename=NULL;
	char* outfile=NULL;


	if(strcmp(argv[1],"-indent")==0)
	{
		indent=0;
	}
	filename=argv[2];
	outfile=argv[3];

	SysFile* f=NULL;
	SysFile* o=NULL;
	FsDict* dict=NULL;
	if(strcmp(filename,"stdin")==0)
	{
		f=SysFile::getStdin();
	}  
	else 
	{
		f=SysFile::open(filename);
	}

	if(strcmp(outfile,"stdout")==0)
	{
		o=SysFile::getStdout();
	}
	else 
	{
		o=SysFile::open(outfile,FsFile::FS_IO_WRONLY|FsFile::FS_IO_TRUNC);
	}

	if(f==NULL)
	{
		printf("Open File(%s) For Read Failed\n",argv[2]);
		goto over;
	}
	if(o==NULL)
	{
		printf("Open File(%s) For Write Failed\n",argv[3]);
		goto over;
	}

	dict=ScriptUtil::parseScript(f);
	if(dict==NULL)
	{
		printf("parseScript Failed\n");
	}
	else 
	{
		printf("dict size=%d\n",dict->size());
		printf("parseScript Success\n");
		ScriptUtil::saveScript(o,dict,indent);
	}

over:
	if(dict) dict->decRef();
	if(o) o->decRef();
	if(f) f->decRef();
	return 0;
}


