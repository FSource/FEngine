#include "script/xir_scanner.h"
#include "script/xir_parser.h"
#include "script/xir_token.h"
#include "script/sl_state.h"

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

	delete s;
	delete f;
	delete pm;
	return 0;
}


