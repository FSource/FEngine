#include <stdio.h>

static unsigned char s_entable[65]="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/" ;
static unsigned char s_detable[256]={};


int main()
{

	for(int i=0;i<256;i++)
	{
		s_detable[i]=255;
	}
	for(int i=0;i<65;i++)
	{
		s_detable[s_entable[i]]=i;
	}

	for(int i=0;i<256;i++)
	{
		if(i%16==0)
		{
			printf("\n");
		}
		printf("%3d,",s_detable[i]);
	}


	printf("\n\n\n\n");

	for(int i=0;i<64;i++)
	{

		if(i%10==0)
		{
			printf("\n");
		}
		printf("\'%c\',",s_entable[i]);
	}
	return 0;
}
