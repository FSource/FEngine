/*************************************************************************/
/*  FsUnicode.h                                                          */
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
