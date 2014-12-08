#ifndef _FS_ENCRYPT_H_
#define _FS_ENCRYPT_H_

#include "FsMacros.h"

NS_FS_BEGIN 

int FsEncrypt_Xor(uint8_t* src,uint src_len,
	   			  uint8_t** dst,uint* dst_len,
				  uint8_t* key,uint key_len);

int FsEncrypt_Crc32(uint8_t* data,uint8_t length,uint32_t crc);

NS_FS_END 



#endif  /* _FS_ENCRYPT_H_ */

