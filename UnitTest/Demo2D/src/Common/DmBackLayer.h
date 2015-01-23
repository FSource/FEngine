#ifndef _DM_BACK_LAYER_H_
#define _DM_BACK_LAYER_H_


#include "demo3D.h"

NS_FS_BEGIN

class DmBackLayer:public Layer2D 
{
	public:
		static 	DmBackLayer* create();


	public:
		void goBack();
		void  update(float dt) FS_OVERRIDE;

	protected:
		DmBackLayer();
		void initButtons();
		void initFps();


	private:
		int m_fpsNu;
		float m_time;
		LabelTTF* m_fpsLabel;

};



NS_FS_END

#endif /*_DM_BACK_LAYER_H_*/


