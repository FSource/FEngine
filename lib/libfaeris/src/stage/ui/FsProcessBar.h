#ifndef _FS_PROCESS_BAR_H_
#define _FS_PROCESS_BAR_H_

#include "FsMacros.h"
#include "FsUiWidget.h"


NS_FS_BEGIN 

class ProcessBar:public UiWidget
{
	public:
		static ProcessBar* create();
		static ProcessBar* create(const char* fg,const char* bg,float width,float height);
		static ProcessBar* create(Texture2D* fg,Texture2D* bg,float width,float height);

	public:
		void setPercent(float value);
		float getPercent();

		void setDirection(E_AxisDirection dr);
		E_AxisDirection getDirection();

	public:
		void draw(RenderDevice* rd,bool update_matrix) FS_OVERRIDE;

	protected:
		ProcessBar();
		~ProcessBar();
		void initWithTexture(const char* fg,const char* fg,float width,float height);

};


NS_FS_END 



#endif /*_FS_PROCESS_BAR_H_*/



