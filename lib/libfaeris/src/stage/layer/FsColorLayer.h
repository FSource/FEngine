#ifndef _FS_COLOR_LAYER_H_
#define _FS_COLOR_LAYER_H_

#include "FsMacros.h"
#include "stage/layer/FsLayer.h"
#include "graphics/FsColor.h"

NS_FS_BEGIN

class Render;
class ColorMaterial;
class Program;
class ColorLayer:public Layer 
{
	public:
		static ColorLayer* create();
		static ColorLayer* create(Color4f c);
	public:
		void setColor(Color4f c);
		Color4f getColor();

	public:
		/* inherit Layer */
		virtual void draw(Render*  r);
		virtual Matrix4 getProjectMatrix();

		/* inherit FsObject */
		virtual const char* className();

	protected:
		ColorLayer();
		~ColorLayer();

	private:
		Color4f m_color;
		ColorMaterial* m_material;
		Program* m_program;
};
NS_FS_END

#endif /*_FS_COLOR_LAYER_H_*/


