#ifndef _DM_SLIDE_BAR_H_
#define _DM_SLIDE_BAR_H_

#include "demo3D.h"

NS_FS_BEGIN

class DmSlideBar:public Quad2D
{
	public:
		static DmSlideBar* create(const Vector2& bg_size, const Color4f& bg_color,
									const Vector2& fg_size,const Color4f& fg_color
										);

	public:
		bool touchBegin(float x,float y) FS_OVERRIDE;
		bool touchMove(float x,float y) FS_OVERRIDE;
		bool touchEnd(float x,float y) FS_OVERRIDE;
		bool hit2D(float x,float y) FS_OVERRIDE;

	public:
		void setPercent(float percent,bool call_back=false);
		float getPercent();

	public:
		std::function<void(DmSlideBar*,float)> onPercentChange;


	protected:
		DmSlideBar();
		void init(const Vector2& bg_size, const Color4f& bg_color,
				const Vector2& fg_size,const Color4f& fg_color
				);

		Vector2f getMoveRange();

	private:
		Quad2D* m_slide;

		Vector2f m_bgSize;
		Vector2f m_fgSize;

		float m_percent;



		float m_lastTouchPosX;

};


NS_FS_END 


#endif /* _DM_SLIDE_BAR_H_ */

