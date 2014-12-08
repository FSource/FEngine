#include "support/data/FsEncrypt.h"

NS_FS_BEGIN
int FsEncrypt_Xor(uint8_t* src,uint src_len,
	   			  uint8_t** dst,uint* dst_len,
				  uint8_t* key,uint key_len)
{

	uint8_t* out_buf=new uint8_t[src_len];

	for(uint i=0;i<src_len;i++)
	{
		out_buf[i]=src[i]^key[i%key_len];
	}

	*dst=out_buf;
	*dst_len=src_len;
	return 0;
}

NS_FS_END 


