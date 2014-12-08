#ifndef _FS_PANEL_H_
#define _FS_PANEL_H_ 

#include "FsMacros.h"
#include "stage/entity/FsEntity.h"
#include "graphics/FsColor.h"



NS_FS_BEGIN

class RenderDevice;
class Panel:public Entity 
{
	public:
		static Panel* create();
		static Panel* create(float width,float height);

	public:
		void setSize(float width,float height);
		void getSize(float* width,float* height);

		void setAnchor(float x,float y);
		void getAnchor(float* x,float* y);

		void setScissorEnabled(bool enabled);
		bool getScissorEnabled();

	public:
		virtual void draws(RenderDevice* r,bool updateMatrix=true);
		virtual const char* className();
		virtual bool hit2D(float x,float y);

	protected:
		bool init(float width,float height);
		Panel();
		virtual ~Panel();


	private:
		bool m_scissorEnabled;
		float m_width;
		float m_height;
		float m_anchorX;
		float m_anchorY;
};




NS_FS_END


#endif /*_FS_PANEL_H_*/

