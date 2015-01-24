#ifndef _DM_LAYOUT_SCENE_H_
#define _DM_LAYOUT_SCENE_H_ 

#include "demo3D.h"
class DmListView;

NS_FS_USE 

class DmLayoutScene:public Scene 
{
	public:
		static DmLayoutScene* create();

	public:
		void setCurrentSelect(int index);
	protected:
		DmLayoutScene();
		~DmLayoutScene();

		void initUiLayer();
		void initLayoutList();

	private:
		FsArray* m_layoutList;
		Layer2D* m_uiLayer;

		Layer2D* m_layoutLayer;
		DmListView* m_layoutListView;


};




#endif /*_DM_LAYOUT_SCENE_H_*/


