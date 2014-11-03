#include "stdio.h"
#include "FsImageTga.h"
#include "tga.h"


NS_FS_BEGIN

static  size_t S_Tga_Read(TGA* tga,void* data,size_t size,size_t count)
{
	FsFile* file=(FsFile*)tga->fd;
	int read_count=file->read(data,size*count);
	return read_count/size;
}

static int S_Tga_Getc(TGA* tga)
{
	FsFile* file=(FsFile*)tga->fd;
	int read=0;

	file->read(&read,1);
	return read;
}

static size_t S_Tga_Write(TGA* tga,const void* data,size_t size,size_t count)
{
	FsFile* file=(FsFile*)tga->fd;
	int write_count=file->write(data,size*count);
	return write_count/size;
}

static int S_Tga_Putc(TGA* tga,int c)
{
	FsFile* file=(FsFile*)tga->fd;
	char v=c;

	return file->write(&v,1);
}

static void S_Tga_Seek(TGA* tga,long off,int where)
{

	FsFile* file=(FsFile*)tga->fd;
	E_FileSeek w=E_FileSeek::SET;
	if(where==SEEK_SET)
	{
		w=E_FileSeek::SET;
	}
	else if (where==SEEK_CUR)
	{
		w=E_FileSeek::CUR;
	}
	else if (where==SEEK_END)
	{
		w=E_FileSeek::END;
	}

	file->seek(off,w);
}

static long S_Tga_Tell(TGA* tga)
{
	FsFile* file=(FsFile*) tga->fd;
	return file->tell();
}





FS_FEATURE_NEW_OBJECT(Image2D*) FsUtil_TgaReader(const char* filename)
{
	FsFile* file=VFS::createFile(filename);
	if(!file)
	{
		return NULL;
	}
	Image2D* ret=FsUtil_TgaReader(file);
	file->autoDestroy();
	return ret;
}


FS_FEATURE_NEW_OBJECT(Image2D*) FsUtil_TgaReader(FsFile* file)
{
	TGA* tga=TGAOpenUserDef(file,S_Tga_Getc,S_Tga_Read,S_Tga_Putc,S_Tga_Write,S_Tga_Seek,S_Tga_Tell);
	Image2D* ret=NULL;
	if(!tga)
	{
		FS_TRACE_WARN("File(%s) Is Not Tga File Format",file->getFileName());
		return NULL;
	}

	TGAData image_data;
	image_data.flags=TGA_IMAGE_DATA;

	int tga_ret=TGAReadImage(tga,&image_data);


	if(tga_ret!=TGA_OK)
	{
		FS_TRACE_WARN("Read Tga Image Data Failed From File(%s)",file->getFileName());
		TGAClose(tga);
		return NULL;
	}


	int mode =tga->hdr.depth /8 ;
	int width=tga->hdr.width;
	int height=tga->hdr.height;



	if (mode == 3 )
	{
		ret=Image2D::create(width,height,image_data.img_data,E_PixelFormat::RGB888);
	}
	else if(mode == 4)
	{
		ret=Image2D::create(width,height,image_data.img_data,E_PixelFormat::RGBA8888);
	}

	/* handle image_data */
	TGAClose(tga);

	if(image_data.flags & TGA_IMAGE_DATA) 
	{
		free(image_data.img_data);
	}

	return ret;

}


int FsUtil_TgaWriter(FsFile* file,Image2D* img)
{
	FS_ASSERT(false); /*TODO(Not Implement)*/
	return -1;
}

bool FsUtil_CheckTga(FsFile* file)
{
	bool ret=true;

	TGA* tga=TGAOpenUserDef(file,S_Tga_Getc,S_Tga_Read,S_Tga_Putc,S_Tga_Write,S_Tga_Seek,S_Tga_Tell);
	if(!tga)
	{
		return false;
	}

	int tga_ret=TGAReadHeader(tga);

	if(tga_ret!=TGA_OK)
	{
		goto error ;
	}

	if(tga->hdr.img_t!=2)
	{
		goto error;
	}

	TGAClose(tga);

	return true;
error:
	return false;
}


NS_FS_END

