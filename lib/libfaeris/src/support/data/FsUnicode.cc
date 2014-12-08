#include "support/data/FsUnicode.h"

NS_FS_BEGIN
#define UTF8_LENGTH(Char,len)            \
	do{ \
		len=((Char) < 0x80 ? 1 :                \
				((Char) < 0x800 ? 2 :            \
				 ((Char) < 0x10000 ? 3 :            \
				  ((Char) < 0x200000 ? 4 :            \
				   ((Char) < 0x4000000 ? 5 : 6)))));  \
	}while(0)

#define UTF8_COMPUTE(Char, Mask, Len)        \
	do{   \
		if (Char < 128)                \
		{                        \
			Len = 1;                    \
			Mask = 0x7f;                \
		}                        \
		else if ((Char & 0xe0) == 0xc0)        \
		{                        \
			Len = 2;                    \
			Mask = 0x1f;                \
		}                        \
		else if ((Char & 0xf0) == 0xe0)        \
		{                        \
			Len = 3;                    \
			Mask = 0x0f;                \
		}                        \
		else if ((Char & 0xf8) == 0xf0)        \
		{                        \
			Len = 4;                    \
			Mask = 0x07;                \
		}                        \
		else if ((Char & 0xfc) == 0xf8)        \
		{                        \
			Len = 5;                    \
			Mask = 0x03;                \
		}                        \
		else if ((Char & 0xfe) == 0xfc)        \
		{                        \
			Len = 6;                    \
			Mask = 0x01;                \
		}                        \
		else                        \
		Len = -1;   \
	}while(0) \



#define UTF8_GET(Result, Chars, Count, Mask, Len)    \
	do{ \
		(Result) = (Chars)[0] & (Mask);            \
		for ((Count) = 1; (Count) < (Len); ++(Count))        \
		{                            \
			if (((Chars)[(Count)] & 0xc0) != 0x80)        \
			{                        \
				(Result) = -1;                \
				break;                    \
			}                        \
			(Result) <<= 6;                    \
			(Result) |= ((Chars)[(Count)] & 0x3f);        \
		} \
	}while(0)  \


static const char s_utf8_skip_data[256]=
{
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 1, 1,
	2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
	2, 2, 2, 2, 2, 2, 2,
	3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 5,
	5, 5, 5, 6, 6, 1, 1
};

inline char* FsUtf8_NextChar(const char* str_utf8)
{
	return (char*)str_utf8+s_utf8_skip_data[*(unsigned char*)(str_utf8)];
}


int FsUtf8_StrLen(const char* str_utf8)
{
	int len=0;
	while(*str_utf8)
	{
		str_utf8=FsUtf8_NextChar(str_utf8);
		++len;
	}
	return len;
}


uint16_t FsUtf8_GetUtf16Char(const char* p)
{
	int i, mask = 0, len;
	unsigned int result;
	unsigned char c = (unsigned char) *p;

	UTF8_COMPUTE (c, mask, len);

	if (len == -1)
	{
		return (uint16_t) (-1);
	}

	UTF8_GET (result, p, i, mask, len);

	return result;
}


uint16_t* FsUtf8_ToUtf16(const char* str_utf8)
{
	int len=FsUtf8_StrLen(str_utf8);

	uint16_t* ret=new uint16_t[len+1];
	ret[len]=0;

	for(int i=0;i<len;++i)
	{
		ret[i]=FsUtf8_GetUtf16Char(str_utf8);

		str_utf8=FsUtf8_NextChar(str_utf8);
	}

	return ret;
}




/* utf-16 */
int FsUtf16_GetUtf8Char(uint32_t c,char* outbuf)
{
	unsigned int len = 0;
	int first;
	int i;


	if (c < 0x80)
	{
		first = 0;
		len = 1;
	}
	else if (c < 0x800)
	{
		first = 0xc0;
		len = 2;
	}
	else if (c < 0x10000)
	{
		first = 0xe0;
		len = 3;
	}
	else if (c < 0x200000)
	{
		first = 0xf0;
		len = 4;
	}
	else if (c < 0x4000000)
	{
		first = 0xf8;
		len = 5;
	}
	else
	{
		first = 0xfc;
		len = 6;
	}

	if (outbuf)
	{
		for (i = len - 1; i > 0; --i)
		{
			outbuf[i] = (c & 0x3f) | 0x80;
			c >>= 6;
		}
		outbuf[0] = c | first;
	}

	return len;
}

char* FsUtf16_ToUtf8(uint16_t* str_utf16)
{
	int utf16_len=FsUtf16_StrLen(str_utf16);
	return FsUtf16_ToUtf8(str_utf16,utf16_len);
}


char* FsUtf16_ToUtf8(uint16_t* str_utf16,int utf16_len)
{
	int utf8_len=0;

	for(int i=0;i<utf16_len;i++)
	{
		int s_len;
		UTF8_LENGTH((int32_t)str_utf16[i],s_len);
		utf8_len+=s_len;
	}

	char* utf8_ret= new char[utf8_len+1];
	utf8_ret[utf8_len]='\0';

	char* tmp_utf8=utf8_ret;

	for(int i=0;i<utf16_len;i++)
	{
		int l=FsUtf16_GetUtf8Char((uint32_t)str_utf16[i],tmp_utf8);
		tmp_utf8+=l;
		assert((tmp_utf8-utf8_ret)<=utf8_len);
	}
	assert((tmp_utf8-utf8_ret)==utf8_len);
	return utf8_ret;
}

int FsUtf16_StrLen(uint16_t* str_utf16)
{
	int len=0;
	while(*str_utf16++)
	{
		len++;
	}
	return len;
}


NS_FS_END











