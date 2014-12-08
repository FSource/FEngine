#ifndef _FS_UNICODE_H_
#define _FS_UNICODE_H_
#include "FsMacros.h"

NS_FS_BEGIN 

/* utf-8 */
int FsUtf8_StrLen(const char* str_utf8);
uint16_t* FsUtf8_ToUtf16(const char* str_utf8);
char* FsUtf8_NextChar(const char* str_utf8);
uint16_t FsUtf8_GetUtf16Char(const char* str_utf8);


/* utf-16 */
int FsUtf16_StrLen(uint16_t* str_utf16);
int FsUtf16_GetUtf8Char(uint16_t value,char* buf);
char* FsUtf16_ToUtf8(uint16_t* str_utf16);
char* FsUtf16_ToUtf8(uint16_t* str_utf16,int len);


NS_FS_END 



#endif /*_FS_UNICODE_H_ */
