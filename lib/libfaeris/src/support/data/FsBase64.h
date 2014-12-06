#ifndef _FS_BASE_64_H_
#define _FS_BASE_64_H_ 
#include "FsMacros.h"


NS_FS_BEGIN
/* Note:
 * 	decode/encode  base64  from memory 
 * 	when success return 0,else return -1
 */

int FsBase64_Decode(uint8_t* src_buf,uint src_length,uint8_t** dst_buf,uint* dst_length);


/* Note:
 * 	dst_buf will be end with '/0', buf dst_length is only the not include '/0' 
 */

int FsBase64_Encode(uint8_t* src_buf,uint src_length,uint8_t** dst_buf,uint* dst_length);

NS_FS_END

#endif /*_FS_BASE_64_H_*/


