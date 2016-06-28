#include "support/felis/xir_scanner.h"
#include "support/felis/xir_parser.h"
#include "support/felis/xir_token.h"
#include "support/felis/sl_state.h"

#include "sys/io/FsSysFile.h"

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

	SysFile* f=SysFile::create(argv[1]);
	if(f==NULL)
	{
		printf("Open File(%s) Failed\n",argv[1]);
		exit(-1);
	}

	XirScanner* s=new XirScanner(f,&Xir_Top);
	YYParserParm* pm=new YYParserParm(s);
	int ret=yyparse(pm);
	if(ret==0)
	{
		printf("Parse Success\n");
	}
	else
	{
		printf("Parse Failed\n");
	}

	f->autoDestroy();
	delete s;
	delete pm;
	return 0;
}


