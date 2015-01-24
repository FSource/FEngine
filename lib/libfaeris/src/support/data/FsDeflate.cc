/*************************************************************************/
/*  FsDeflate.cc                                                         */
/*************************************************************************/
/* Copyright (C) 2012-2014 nosiclin@foxmail.com                          */
/* Copyright (C) 2014-2015 www.fsource.cn                                */
/*                                                                       */
/* http://www.fsource.cn                                                 */
/*                                                                       */
/* Permission is hereby granted, free of charge, to any person obtaining */
/* a copy of this software and associated documentation files (the       */
/* "Software"), to deal in the Software without restriction, including   */
/* without limitation the rights to use, copy, modify, merge, publish,   */
/* distribute, sublicense, and/or sell copies of the Software, and to    */
/* permit persons to whom the Software is furnished to do so, subject to */
/* the following conditions:                                             */
/*                                                                       */
/* The above copyright notice and this permission notice shall be        */
/* included in all copies or substantial portions of the Software.       */
/*                                                                       */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,       */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF    */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.*/
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY  */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,  */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE     */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                */
/*************************************************************************/


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
	int ret=uncompress((Bytef*) dst_buf,(uLongf*) dst_length,(const Bytef*) src_buf,(uLong) src_length);
	if(ret!=Z_OK)
	{
		return -1;
	}
	return 0;
}

NS_FS_END
