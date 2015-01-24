#ifndef _DEMO_START_LAYER_H
#define _DEMO_START_LAYER_H

#include "FsMacros.h"
#include "stage/layer/FsLayer2D.h"

NS_FS_BEGIN

class DemoStartLayer:public Faeris::Layer2D 
{
	public:
		static DemoStartLayer* create();
		virtual bool init();
		void showDemoChooseLayer();
		
	protected:
		DemoStartLayer();
};

NS_FS_END

#endif
