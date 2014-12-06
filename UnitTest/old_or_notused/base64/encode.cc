#include <string.h>
#include <stdio.h>
#include "FsBase64.h"
#include <iostream>
#include <string>


int main()
{
	std::string src_buf;
	unsigned char* dst_buf=NULL;

	unsigned int src_length;
	unsigned int dst_length;

	while(1)
	{
		printf("input:");
		std::getline(std::cin,src_buf);

		src_length=strlen(src_buf.c_str());

		printf("src_length=%d\n",src_length);
		int ret=FsBase64_Encode((unsigned char*)(src_buf.c_str()),src_length,&dst_buf,&dst_length);
		if(ret==0)
		{

			dst_buf[dst_length]=0;
			printf("out(%d):%s\n",dst_length,dst_buf);
			delete[] dst_buf;
		}
		else 
		{
			printf("Encode error\n");
		}
	}
}











