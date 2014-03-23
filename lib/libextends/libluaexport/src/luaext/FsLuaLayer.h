#ifndef _FS_LUA_LAYER_H_
#define _FS_LUA_LAYER_H_

#include "stage/layer/FsLayer2D.h"
#include "stage/layer/FsColorLayer.h"
#include "FsLuaMacros.h"

#include "luaext/FsTLuaLayer.h"


NS_FS_BEGIN


class LuaLayer2D:public TLuaLayer<Layer2D>
{
	public:
		static LuaLayer2D* create()
		{
			return new LuaLayer2D;
		}
	public:
		virtual const char* className()
		{
			return FS_LUA_LAYER2D_CLASS_NAME;
		}
	protected:
		LuaLayer2D(){}
		~LuaLayer2D(){}
};



class LuaColorLayer:public TLuaLayer<ColorLayer>
{
	public:
		static LuaColorLayer* create()
		{
			return new LuaColorLayer;
		}
		static LuaColorLayer* create(Color4f c)
		{
			LuaColorLayer* layer=new LuaColorLayer;
			layer->setColor(c);
			return layer;
		}
	public:
		virtual const char* className()
		{
			return FS_LUA_COLOR_LAYER_CLASS_NAME;
		}

	protected:
		LuaColorLayer(){}
		~LuaColorLayer(){}
};
NS_FS_END 


#endif /*_FS_LUA_LAYER_H_*/
