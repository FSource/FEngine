/*************************************************************************/
/*  FsMd5.h                                                              */
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


/*  
*  $Id: md5.h,v 1.2 2006/03/03 15:04:49 tomas Exp $
*  Cryptographic module for Lua.
*  @author  Roberto Ierusalimschy
*/

#ifndef _FS_CRYPTO_MD5_H_
#define _FS_CRYPTO_MD5_H_



#include "FsMacros.h"

#define FS_MD5_HASHSIZE       16

NS_FS_BEGIN

/**
*  md5 hash function.
*  @param message: aribtary string.
*  @param len: message length.
*  @param output: buffer to receive the hash value. Its size must be
*  (at least) HASHSIZE.
*/



void FsMd5_ToBinaryBit(const char* message,long len,char* output);



/**
*  md5 hash function.
*  @param message: aribtary string.
*  @param len: message length.
*  @param output: buffer to receive the string value. Its size must be
*  (at least) HASHSIZE*2+1.
*/

void FsMd5_ToString(const char* message,long len,char* output);

NS_FS_END



#endif /*_FS_CRYPTO_MD5_H_*/


