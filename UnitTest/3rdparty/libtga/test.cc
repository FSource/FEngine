#include "tga.h"
#include <stdio.h>

static size_t S_Read(TGA* tga,void* data,size_t size,size_t count )
{
	return fread(data,size,count,(FILE*)tga->fd);
}

static size_t S_Write(TGA* tga,const void* data,size_t size,size_t count)
{
	return fwrite(data,size,count,(FILE*)tga->fd);
}

static int S_Putc(TGA* tga, int c)
{
	return fputc(c,(FILE*)tga->fd);
}
static int S_Getc(TGA* tga)
{
	return fgetc((FILE*) tga->fd);
}
static void S_Seek(TGA* tga,long off,int where)
{
	fseek((FILE*)tga->fd,off,where);
}
static long S_Tell(TGA* tga)
{
	return ftell((FILE*) tga->fd);
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


	TGA* tga=TGAOpenUserDef(file,S_Getc,S_Read,S_Putc,S_Write,S_Seek,S_Tell);

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



