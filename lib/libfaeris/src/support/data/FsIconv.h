#ifndef _FS_ICONV_H_
#define _FS_ICONV_H_
#include "FsMacros.h"

NS_FS_BEGIN

/* if success a utf text is return, user must call delete to free the memory 
 * else NULL will return ;
 */

uint16_t*  FsIconv_UTF8_to_UNICODE(const char* text);
uint16_t*  FsIconv_LATIN1_to_UNICODE(const char* text);

NS_FS_END 

#endif /*_FS_ICONV_H_*/


