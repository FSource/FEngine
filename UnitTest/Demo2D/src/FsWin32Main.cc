#include "FsFaeris.h"
#include "FsLuaEngine.h"

#include "demoStart/DemoStartLayer.h"

FS_USE_MAIN_ENTRY 


NS_FS_BEGIN
void FsMain_Entry(int argc,char** argv)
{
	FsFaeris_LoadConfig((const char*) NULL);

	

	LuaEngine* engine=LuaEngine::create();
	FS_NO_REF_DESTROY(engine);
	Global::setScriptEngine(engine);


	Scene *scene= Scene::create();
	DemoStartLayer* layer = DemoStartLayer::create();
	scene->push(layer);


	Global::director()->run(scene);
	Global::scheduler()->setFps(0);




}
NS_FS_END




