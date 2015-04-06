#include "zlib.h"
#include "support/data/FsDeflate.h"

#define FS_DEFAULT_COMPRESS_LEVEL 6

NS_FS_BEGIN
uint FsDeflate_CompressBound(uint value)
{
	return compressBound(value);
}

int FsDeflate_Compress(const uint8_t* src_buf,uint32_t src_length,
		uint8_t* dst_buf,uint32_t* dst_length)
{
	return FsDeflate_Compress(src_buf,src_length,dst_buf,dst_length,FS_DEFAULT_COMPRESS_LEVEL);
}

int FsDeflate_Compress(const uint8_t* src_buf,uint32_t src_length,
		uint8_t* dst_buf,uint32_t* dst_length,int level)
{
	int ret=compress2((Bytef*) dst_buf,(uLongf*) dst_length,(Bytef*) src_buf,(uLong) src_length,level);
	if(ret!=Z_OK)
	{
		return -1;
	}
	return 0;
}



int FsDeflate_UnCompress(const uint8_t* src_buf,uint32_t src_length,
		uint8_t* dst_buf,uint32_t* dst_length)
{
    uLongf dst_l=*dst_length;
	int ret=uncompress((Bytef*) dst_buf,(uLongf*) &dst_l,(const Bytef*) src_buf,(uLong) src_length);
	if(ret!=Z_OK)
	{
		return -1;
	}
    *dst_length=dst_l;
	return 0;
}

NS_FS_END
