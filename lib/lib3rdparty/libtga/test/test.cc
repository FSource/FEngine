#include "tga.h"
#include <stdio.h>

static int S_Read(void* file,void* data,int length)
{
	return fread(data,1,length,(FILE*)file);
}

static int S_Write(void* file,const void* data,int length)
{
	return fwrite(data,1,length,(FILE*)file);
}

static int S_Seek(void* file,tlong off,int whence)
{
	return fseek((FILE*)file,off,whence);
}
static int S_Tell(void* file)
{
	return ftell((FILE*)file);
}




int main(int argc,char** argv)
{
	if(argc<2)
	{
		printf("usage %s <tga image>\n",argv[0]);
		return 0;
	}

	FILE* file=fopen(argv[1],"rb");
	if(file==NULL)
	{
		printf("Open %s failed\n",argv[1]);
		return 0;
	}


	TGA* tga=TGAOpen(file,S_Read,S_Write,S_Seek,S_Tell);

	int ret;
	TGAData image_data;

	ret=TGAReadImage(tga,&image_data);
	if(ret!=TGA_OK)
	{
		printf("Read Image Data Failed\n");
		return 0;
	}
	printf("Read Image Data OK\n");

	printf("file Header size=%d,%d\n",tga->hdr.width,tga->hdr.height);

	return 0;

}



