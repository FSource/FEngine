/**
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


