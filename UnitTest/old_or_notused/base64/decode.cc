#include <string.h>
#include <stdio.h>
#include "FsBase64.h"


int main()
{
	unsigned char src_buf[1024*8];
	unsigned char* dst_buf=NULL;

	unsigned int src_length;
	unsigned int dst_length;

	while(1)
	{
		printf("input:");
		scanf("%s",src_buf);
		src_length=strlen((char*)src_buf);

		printf("src_length=%d\n",src_length);
		int ret=FsBase64_Decode(src_buf,src_length,&dst_buf,&dst_length);
		if(ret==0)
		{

			dst_buf[dst_length]=0;
			printf("out(%d):%s\n",dst_length,dst_buf);
			delete[] dst_buf;
		}
		else 
		{
			printf("decode error\n");
		}
	}
}











