#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "support/image/FsImageJpeg.h"
#include "jpeglib.h"
#include "graphics/FsImage2D.h"
#include "sys/io/FsVFS.h"

NS_FS_BEGIN

uint8_t S_JpegBeginMagicNu[2]={0xFF,0xD8};
uint8_t S_JpegEndMagicNu[2]={0xFF,0xD9};


bool FsUtil_CheckJpeg(FsFile* file)
{
	int file_length=file->getLength();
	if (file_length< 8 )
	{
		return false;
	}

	uint8_t data[2];
	file->read(data,2);
	file->seek(0,E_FileSeek::SET);

	if(memcmp(data,S_JpegBeginMagicNu,2)!=0)
	{
		return false;
	}

	file->seek(file_length-2,E_FileSeek::SET);
	file->read(data,2);
	file->seek(0,E_FileSeek::SET);

	if(memcmp(data,S_JpegEndMagicNu,2)!=0)
	{
		return false;
	}

	return true;
}

FS_FEATURE_NEW_OBJECT(Image2D*) FsUtil_JpegReader(const char* filename)
{
	FsFile* file=VFS::createFile(filename);
	if(file==NULL)
	{
		FS_TRACE_WARN("Can't Open File(%s) For Image2D",filename);
		return NULL;
	}
	Image2D* ret=FsUtil_JpegReader(file);
	file->decRef();
	return ret;
}

FS_FEATURE_NEW_OBJECT(Image2D*) FsUtil_JpegReader(FsFile* file)
{
	bool is_jpeg=FsUtil_CheckJpeg(file);
	if(!is_jpeg)
	{
		return NULL;
	}

	int file_length=file->getLength();
	uint8_t* data=new uint8_t[file_length];
	file->read(data,file_length);


	/* these are standard libjpeg structures for reading(decompression) */
    struct jpeg_decompress_struct cinfo;
    struct jpeg_error_mgr jerr;

    /* libjpeg data structure for storing one row, that is, scanline of an image */
    JSAMPROW row_pointer[1] = {0};

    unsigned long location = 0;
    unsigned int i = 0;

	Image2D* ret=NULL;
    do 
    {
        /* here we set up the standard libjpeg error handler */
        cinfo.err = jpeg_std_error( &jerr );

        /* setup decompression process and source, then read JPEG header */
        jpeg_create_decompress( &cinfo );

        jpeg_mem_src( &cinfo, (unsigned char *) data, file_length);

        /* reading the image header which contains image information */
        jpeg_read_header( &cinfo, true );

        // we only support RGB or grayscale
        if (cinfo.jpeg_color_space != JCS_RGB)
        {
		
            if (cinfo.jpeg_color_space == JCS_GRAYSCALE || cinfo.jpeg_color_space == JCS_YCbCr)
            {
				cinfo.out_color_space = JCS_RGB;
            }


        }
        else
        {
            break;
        }


        /* Start decompression jpeg here */
        jpeg_start_decompress( &cinfo );
		int width,height;

        /* init image info */
        width= (short)(cinfo.image_width);
        height= (short)(cinfo.image_height);

     	row_pointer[0] = new uint8_t[cinfo.output_width*cinfo.output_components];
		if(cinfo.out_color_components==3)
		{
			ret=Image2D::create(width,height,E_PixelFormat::RGB888);
		}
		else 
		{
			ret=Image2D::create(width,height,E_PixelFormat::RGBA8888);
		}

		uint8_t* pixel_data=(uint8_t*)ret->getPixelData();

        /* now actually read the jpeg into the raw buffer */
        /* read one scan line at a time */

        while( cinfo.output_scanline < cinfo.image_height )
        {
            jpeg_read_scanlines( &cinfo, row_pointer, 1 );

            for( i=0; i<cinfo.image_width*cinfo.output_components;i++) 
            {
                pixel_data[location++] = row_pointer[0][i];
            }
        }

        jpeg_finish_decompress( &cinfo );
        jpeg_destroy_decompress( &cinfo );
        /* wrap up decompression, destroy objects, free pointers and close open files */        
    } while (0);


    FS_SAFE_DELETES(row_pointer[0]);
	FS_DELETES(data);
    return ret;

}

int FsUtil_JpegWriter(FsFile* file,Image2D* image)
{
	FS_TRACE_WARN("Not Support Now");
	return -1;
}

NS_FS_END






