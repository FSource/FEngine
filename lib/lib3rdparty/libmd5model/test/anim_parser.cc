#include "stdio.h"
#include "libmd5model.h"

int S_read_io(void* data,void* buf,int length)
{
	return fread(buf,1,length,(FILE*)data);
}


int main(int argc,const char** argv)
{
	if(argc<2)
	{
		printf("useage %s <filename>\n", argv[0]);
		return 0;
	}

	FILE* file=fopen(argv[1],"r");

	if(file==NULL)
	{
		printf("Open File(%s) Failed\n",argv[1]);
		return 0;
	}

	Md5Anim* mesh=LibMd5Anim_Parse(file,S_read_io);

	if(mesh==NULL)
	{
		printf("Parse Failed\n");
	}
	else 
	{
		printf("Parse Success\n");
	}
	return 0;

}



