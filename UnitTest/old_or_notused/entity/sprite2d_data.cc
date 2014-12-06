#include <stdio.h>
#include <stdlib.h>
#include "mgr/FsTextureMgr.h"
#include "graphics/FsTexture2D.h"
#include "common/FsGlobal.h"
#include "scene/FsLayer2D.h"
#include "scene/FsScene.h"
#include "entity/FsColorQuad2D.h"
#include "entity/FsQuad2D.h"
#include "graphics/FsFontTTF.h"
#include "entity/FsLabelTTF.h"
#include "entity/FsSprite2DData.h"
#include "entity/FsSprite2D.h"

NS_FS_USE
int main(int argc,char** argv)
{
	if(argc!=3)
	{
		printf("useage:%s <file> <animtion>\n",argv[0]);
		exit(-1);
	}

	Global::moduleInit();

	Sprite2D* sprite=Sprite2D::create(argv[1]);

	if(sprite==NULL)
	{
		FS_TRACE_WARN("create Sprite2D Failed");
	}
	else 
	{
		//sprite->setAnimation(argv[2]);
		sprite->decRef();
	}

	Global::moduleExit();
	return 0;
}
