#include "FsFaeris.h"
#include "demoStart/DemoStartLayer.h"

NS_FS_BEGIN

void FsMain_Entry(int argc,char** argv)
{
    FsFaeris_LoadConfig((const char*) NULL);
    
    Scene *scene= Scene::create();
    DemoStartLayer* layer = DemoStartLayer::create();

    
    scene->push(layer);
    Global::director()->run(scene);
    Global::scheduler()->setFps(0);
    
}



NS_FS_END

