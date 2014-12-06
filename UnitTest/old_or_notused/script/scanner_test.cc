#include "support/felis/xir_scanner.h"
#include "support/felis/xir_token.h"
#include "support/felis/sl_state.h"
#include "fsys/FsVFS.h"
#include "fsys/FsSysFile.h"
#include <stdio.h>
#include <stdlib.h>

using namespace Faeris;

int main(int argc,char** argv)
{
	if(argc!=2)
	{
		printf("usage: %s <file>\n",argv[0]);
		exit(-1);
	}

	SysFile* f=SysFile::open(argv[1]);
	if(f==NULL)
	{
		printf("Open File(%s) Failed\n",argv[1]);
		exit(-1);
	}

	XirScanner* s=new XirScanner(f,&Xir_Top);


	while(1)
	{
		s->nextToken();

		if(s->curToken()==XT_EOF)
		{
			break;
		}
		printf("%d:%s:<%s>\n",s->curLine(),s->curTokenName(),s->curString());
	}
	delete s;
	delete f;
	return 0;
}

	

