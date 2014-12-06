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















