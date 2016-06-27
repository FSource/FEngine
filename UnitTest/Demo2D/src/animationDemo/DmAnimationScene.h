#ifndef _DM_ANIMAION_SCENE_H_
#define _DM_ANIMAION_SCENE_H_ 

#include "demo3D.h"
class DmListView;

NS_FS_USE

class DmAnimationScene:public Scene 
{
	public:
		static DmAnimationScene* create();

	public:
		void setCurrentSelect(int index);
	protected:
		DmAnimationScene();
		~DmAnimationScene();

		void initUiLayer();
		void initLayoutList();

		void setCurrentAnimaiton(int index);
		void resetAnimatiionView();
		void initAnimationWidget();


	private:
		FsArray* m_layoutList;
		Layer2D* m_uiLayer;

		Layer2D* m_layoutLayer;

		DmListView* m_layoutListView;
		DmListView* m_animationView;

		FsArray* m_animList;
};




#endif /*_DM_ANIMAION_SCENE_H_*/

