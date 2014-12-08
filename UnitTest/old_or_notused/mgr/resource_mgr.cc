
#include "mgr/FsTextureMgr.h"
#include "graphics/FsTexture2D.h"
#include "common/FsGlobal.h"

NS_FS_USE
int main()
{
	Global::moduleInit();

	TextureMgr* mgr=TextureMgr::create();

	Texture2D* tex1=mgr->loadTexture("tree1.png");
	Texture2D* tex2=mgr->loadTexture("tree2.png");

	assert(tex1!=tex2);
	Texture2D* tex3=mgr->loadTexture("tree3.png");
	assert(tex2!=tex3);
	Texture2D* tex4=mgr->loadTexture("tree1.png");


	assert(tex1==tex4);
	tex1->decRef();
	tex2->decRef();
	tex3->decRef();
	tex4->decRef();

	mgr->decRef();
	Global::moduleExit();
	return 0;



}

