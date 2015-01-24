/*************************************************************************/
/*  FsIconv.cc                                                           */
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


#include <string.h>
#include "support/data/FsIconv.h"


NS_FS_BEGIN
uint16_t*  FsIconv_UTF8_to_UNICODE(const char* utf8)
{
	uint16_t* unicode;
	int len;
	len=strlen(utf8);

	unicode=new uint16_t[1+len+1];
	if(unicode==NULL) 
	{
		return NULL;
	}

	int i,j;
	uint16_t ch;

	for ( i=0, j=0; i < len; ++i, ++j ) {
		ch = ((const unsigned char *)utf8)[i];
		if ( ch >= 0xF0 ) {
			ch  =  (uint16_t)(utf8[i]&0x07) << 18;
			ch |=  (uint16_t)(utf8[++i]&0x3F) << 12;
			ch |=  (uint16_t)(utf8[++i]&0x3F) << 6;
			ch |=  (uint16_t)(utf8[++i]&0x3F);
		} else
		if ( ch >= 0xE0 ) {
			ch  =  (uint16_t)(utf8[i]&0x0F) << 12;
			ch |=  (uint16_t)(utf8[++i]&0x3F) << 6;
			ch |=  (uint16_t)(utf8[++i]&0x3F);
		} else
		if ( ch >= 0xC0 ) {
			ch  =  (uint16_t)(utf8[i]&0x1F) << 6;
			ch |=  (uint16_t)(utf8[++i]&0x3F);
		}
		unicode[j] = ch;
	}
	unicode[j] = 0;

	return unicode;

}
uint16_t*  FsIconv_LATIN1_to_UNICODE(const char* text) 
{
	uint16_t* unicode;
	int len;
	len=strlen(text);

	unicode=new uint16_t[1+len+1];
	if(unicode==NULL) 
	{
		return NULL;
	}

	int i;
	for ( i=0; i < len; ++i ) {
		unicode[i] = ((const unsigned char *)text)[i];
	}

	unicode[i] = 0;
	return unicode;

}

NS_FS_END 


