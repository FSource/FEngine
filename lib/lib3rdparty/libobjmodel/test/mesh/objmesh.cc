#include <stdio.h>
#include "LibObjModel.h"


int S_ReadIo(void* file,void* buf,int length)
{
	return fread(buf,1,length,(FILE*)file);
}


int main(int argc,char** argv)
{
	if(argc<2)
	{
		fprintf(stderr,"useage %s <filename>\n",argv[0]);
		return 0;
	}

	FILE* file=fopen(argv[1],"r");
	if(file==NULL)
	{
		fprintf(stderr,"Open %s For Parser Failed\n",argv[1]);
		return 0;
	}


	LibObjMesh* mesh=LibObj_ParseMesh(file,S_ReadIo);
	if(mesh==NULL)
	{
		fprintf(stderr,"Parser Obj(%s) Failed\n",argv[1]);
	}
	else 
	{
		fprintf(stderr,"Parser Obj(%s) Success\n",argv[1]);
	}

	return 0;
}



