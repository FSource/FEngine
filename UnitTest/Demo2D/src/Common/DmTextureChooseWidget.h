#ifndef _FS_TEXTURE_CHOOSE_WIDGET_H_
#define _FS_TEXTURE_CHOOSE_WIDGET_H_

#include <vector>

#include "demo3D.h"

NS_FS_USE

class DmTextureChooseWidget:public UiWidget 
{
	public:
		static DmTextureChooseWidget* create(FsArray* textures);
		static Layer2D* create(FsArray* textures,float x,float y,std::function<void(const char* )> fn);

	public:
		std::function<void(const char* )> onTextureChoosed;

	public:
		bool touchBegin(float x,float y) FS_OVERRIDE;


	protected:
		DmTextureChooseWidget();

		void init(FsArray* textures);
		
		void initTitle();
		void initSeleteQuad();
		void initListView();
		void initPressButton();

	private:
		ListView* m_textureList;
		FsArray* m_textureNames;
		Quad2D* m_selectQuad;
		FsString* m_selectTexture;
};



#endif /*_FS_TEXTURE_CHOOSE_WIDGET_H_*/


