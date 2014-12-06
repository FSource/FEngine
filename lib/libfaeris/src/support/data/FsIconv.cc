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


