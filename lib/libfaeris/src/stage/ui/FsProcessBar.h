#ifndef _FS_PROCESS_BAR_H_
#define _FS_PROCESS_BAR_H_

#include "FsMacros.h"
#include "stage/entity/FsEntity2D.h"
//#include "FsUiWidget.h"


NS_FS_BEGIN 

class ProcessBar:public Entity2D
{
	public:
		FS_CLASS_DECLARE(ProcessBar);

	public:
		static ProcessBar* create();
		static ProcessBar* create(const char* bg,const char* fg);
		static ProcessBar* create(Texture2D* bg,Texture2D* fg);

	public:
		void setPercent(float value);
		float getPercent();

		void setDirection(E_AxisDirection dr);
		E_AxisDirection getDirection();

	public:
		void setBackgroundTexture(const char* filename);
		void setBackgroundTexture(Texture2D* tex);
		Texture2D* getBackgroundTexture();

		void setForegroundTexture(const char* filename);
		void setForegroundTexture(Texture2D* tex);
		Texture2D* getForegroundTexture();

		void setReverseDirection(bool value);
		bool getReverseDirection();


	public:
		void draw(RenderDevice* rd,bool update_matrix) FS_OVERRIDE;

	protected:
		ProcessBar();
		~ProcessBar();

		void initWithTexture(const char* bg,const char* fg);
		void initWithTexture(Texture2D* bg,Texture2D* fg);

	protected:
		Texture2D* m_backgroundTexture;
		Texture2D* m_foregroundTexture;
		float m_percent;
		E_AxisDirection m_direction;
		bool m_reverseDirection;

};


NS_FS_END 


#endif /*_FS_PROCESS_BAR_H_*/



