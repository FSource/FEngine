#ifndef _DM_FILTER_SCENE_H_
#define _DM_FILTER_SCENE_H_ 

#include "demo3D.h"

#include "Common/DmColorSlider.h"

NS_FS_USE;

class DmListView;
class DmFilterScene:public Scene 
{
	public:
		static DmFilterScene* create();

	protected:
		DmFilterScene();
		void init();

		void initCfg();
		void initLayer2D();
		void initShaderWidget();
		void initFilterWidget();
		void initCenterWidget();

		void setShaderListIndex(int index);
		void setCurrentFilter(int index);


private:
	Layer2D* m_layer2D;
	UiWidget* m_centerWidget;
	Quad2D* m_quad;

	FsArray* m_shaderList;
	FsArray* m_filterList;

	DmListView* m_shaderListView;
	DmListView* m_filterListView;


};




#endif /*_DM_FILTER_SCENE_H_*/


