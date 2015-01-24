/*************************************************************************/
/*  FsBase64.cc                                                          */
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


#include <stdio.h>
#include "FsBase64.h"

#define FS_BASE64_VALID_VALUE 255 

NS_FS_BEGIN
static uint8_t s_detable[256]={
	64,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,255,255,255, 62,255,255,255, 63,
	52, 53, 54, 55, 56, 57, 58, 59, 60, 61,255,255,255,255,255,255,
	255,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14,
	15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25,255,255,255,255,255,
	255, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
	41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51,255,255,255,255,255,
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
};

static uint8_t s_entable[64]={
	'A','B','C','D','E','F','G','H','I','J',
	'K','L','M','N','O','P','Q','R','S','T',
	'U','V','W','X','Y','Z','a','b','c','d',
	'e','f','g','h','i','j','k','l','m','n',
	'o','p','q','r','s','t','u','v','w','x',
	'y','z','0','1','2','3','4','5','6','7',
	'8','9','+','/',
};

int _FsBase64_Decode(uint8_t* src_buf,uint src_length, uint8_t* dst_buf,uint* dst_length)
{
	uint src_idx=0,dst_idx=0;
	uint errors=0;
	uint  v,bits=0;
	uint8_t c;
	uint char_nu=0;
	for(src_idx=0;src_idx<src_length;src_idx++)
	{
		c=src_buf[src_idx];
		if(c=='=')
		{
			break;
		}

		v=s_detable[c];
		if(v==FS_BASE64_VALID_VALUE)
		{
			continue;
		}
		bits+=v;
		char_nu++;
		if(char_nu==4)
		{
			dst_buf[dst_idx++]=(bits>>16);
			dst_buf[dst_idx++]=(bits>>8)&0xff;
			dst_buf[dst_idx++]=(bits&0xff);
			bits=0;
			char_nu=0;
		}
		else 
		{
			bits<<=6;
		}
	}
	if(c=='=')
	{
		switch(char_nu)
		{
			case 1:
				errors++;
				break;
			case 2:
				dst_buf[dst_idx++]=(bits>>10);
				break;
			case 3:
				dst_buf[dst_idx++]=(bits>>16);
				dst_buf[dst_idx++]=(bits>>8)&0xff;
				break;
		}
	}
	else if(src_idx<src_length)
	{
		if(char_nu)
		{
			errors++;
		}
	}
	*dst_length=dst_idx;
	return errors;
}

int FsBase64_Decode(uint8_t* src_buf,uint src_length,
		uint8_t** dst_buf,uint* dst_length)
{
	uint ret=-1;
	uint8_t* out=new uint8_t[(ulong )(src_length*3.0/4.0f+1)];
	uint out_length=0;
	if(out!=0)
	{
		uint errors=_FsBase64_Decode(src_buf,src_length,out,&out_length);
		if(errors)
		{
			delete[] out;
			out=0;
			out_length=0;
			ret=-1;
		}
		else 
		{
			*dst_buf=out;
			*dst_length=out_length;
			ret=0;
		}
	}
	*dst_buf=out;
	*dst_length=out_length;
	return ret;
}


int FsBase64_Encode(uint8_t* src_buf,uint src_length,uint8_t** dst_buf,uint* dst_length)
{
	uint bit24_nu=src_length/3;
	bool has_padding=src_length>bit24_nu*3;
	bool has_padding2=src_length==(bit24_nu*3+2);

	uint num_bret=4*(bit24_nu+has_padding);

	uint8_t* result=new uint8_t[num_bret+1]; /*allow for trailing '/0' */
	uint i;
	for(i=0;i<bit24_nu;i++)
	{
		result[4*i+0]=s_entable[(src_buf[3*i]>>2)&0x3f];
		result[4*i+1]=s_entable[(((src_buf[3*i]&0x3)<<4)
								|(src_buf[3*i+1]>>4))&0x3f];
		result[4*i+2]=s_entable[((src_buf[3*i+1]<<2)
				    			|(src_buf[3*i+2]>>6))&0x3f];
		result[4*i+3]=s_entable[src_buf[3*i+2]&0x3f];
	}
	if(has_padding)
	{
		result[4*i+0]=s_entable[(src_buf[3*i]>>2)&0x3f];
		if(has_padding2)
		{
			result[4*i+1]=s_entable[(((src_buf[3*i]&0x3)<<4)
									|(src_buf[3*i+1]>>4))&0x3f];
			result[4*i+2]=s_entable[((src_buf[3*i+1]<<2)
									|(src_buf[3*i+2]>>6))&0x3f];
		}
		else 
		{
			result[4*i+1]=s_entable[(((src_buf[3*i]&0x3)<<4)
									|(src_buf[3*i+1]>>4))&0x3f];
			result[4*i+2]='=';
		}
		result[4*i+3]='=';
	}
	result[num_bret]='\0';
	*dst_buf=result;
	*dst_length=num_bret;
	return 0;
}




NS_FS_END






























