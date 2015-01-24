/*************************************************************************/
/*  FsDeflate.h                                                          */
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


#ifndef _FS_DEFLATE_H_
#define _FS_DEFLATE_H_
#include "FsMacros.h"

NS_FS_BEGIN
/* description:
 * 		FSDeflate_Compress() return an upper bound on the compressed size 
 * 	after FsDeflate_Compress on src_length bytes. It would be used before 
 * 	a FsDeflate_Compress call to allocate the destination buffer 
 */
uint FsDeflate_CompressBound(uint value);

/* description:
 * 		Compress the source buffer into the destination buffer,sourcelen is 
 * 	the byte length of the source buffer, upon entry, dst_length is the 
 * 	total by FsDeflate_CompressBound(src_length), Upon exit,dst_length is 
 * 	the actual size of the compressed buffer 
 * 		if success 0 will return, -1 if there was not falied 
 */
int FsDeflate_Compress(const uint8_t* src_buf,uint32_t src_length,
		uint8_t* dst_buf,uint32_t* dst_length);

int FsDeflate_Compress(const uint8_t* src_buf,uint32_t src_length,
						uint8_t* dst_buf,uint32_t* dst_length,
						int level);


/* description:
 * 		Decompresses the source buffer into the destination buffer.
 * 	src_length is the byte length of the source buffer. Upon entry,
 * 	dst_length is the total size of the destination buffer, which must 
 * 	be large enough to hold the entire uncompressed data,(the size of the 
 * 	uncompressed data must have been saved previously by the compressor and
 * 	trnasmitted to the decompressor by some mechanism outside the scope of
 * 	the compressed library,Upon exit,src_length is the actual size of the 
 * 	compressed buffer.
 * 		uncompressed returns 0 if success, -1 if falied
 */
int FsDeflate_UnCompress(const uint8_t* src_buf,uint32_t src_length,
		uint8_t* dst_buf,uint32_t* dst_length);

NS_FS_END

#endif /*_FS_DEFLATE_H_*/















