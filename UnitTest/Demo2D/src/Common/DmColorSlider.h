#ifndef _DM_COLOR_SLIDER_H_
#define _DM_COLOR_SLIDER_H_

#include "demo3D.h"

#include "DmSlideBar.h"

NS_FS_BEGIN

class DmColorSlider:public UiWidget 
{
	public:
		static DmColorSlider* create(const char* title,const Color3f& c);

	public:
		std::function<void(DmColorSlider*,Color3f)> onColorChange ;
		void setColor(const Color3f& c ,bool call_back=false);

	protected:
		DmColorSlider(const char* title,const Color3f& c);
		void setColorTextValue(Color3f c);

	protected:
		LabelTTF* m_title;

		LabelTTF* m_redValue;
		LabelTTF* m_greenValue;

		LabelTTF* m_blueValue;

		LabelTTF* m_redText;
		LabelTTF* m_blueText;
		LabelTTF* m_greenText;

		DmSlideBar* m_slideRed;
		DmSlideBar* m_slideBlue;
		DmSlideBar* m_slideGreen;
};

NS_FS_END

#endif /*_DM_COLOR_SLIDER_H_*/

