#ifndef _FS_DIALOG_H_
#define _FS_DIALOG_H_

#include  "FsMacros.h"
#include  "FsUiWidget.h"
#include  "graphics/FsColor.h"

NS_FS_BEGIN 


class Dialog:public UiWidget 
{
	public:
		FS_CLASS_DECLARE(Dialog);

	public:
		static Dialog* create();
		static Dialog* create(float width,float height);

	public:
		bool hit2D(float x,float y) FS_OVERRIDE;
		bool touchBegin(float x,float y) FS_OVERRIDE;
		bool touchEnd(float x,float y) FS_OVERRIDE;
		void draw(RenderDevice* rd,bool update_matrix) FS_OVERRIDE;

	public:
		void setDarkOutsideColor(const Color4f& c);
		Color4f getDarkOutsideColor();

		void setDarkOutsideEnabled(bool enabled);
		bool getDarkOutsideEnabled();

		void setDetachOnTouchOutside(bool value);
		bool getDetachOnTouchOutside();

	public:
		virtual void touchOutside(float,float);
		std::function<void(Dialog*,float,float)> onTouchOutside;

	protected:
		Dialog();
		~Dialog();
		void drawOutside(RenderDevice* rd,bool update_matrix);

	private:
		bool m_detachOutside;
		bool m_darkOutsideEnabled;
		Material2D* m_outsideMaterial;
};





NS_FS_END 


#endif /*_FS_DIALOG_H_*/


