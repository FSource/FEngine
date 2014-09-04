#ifndef _FS_LUA_ENTITY_H_
#define _FS_LUA_ENTITY_H_

#include "FsMacros.h"
#include "FsLuaMacros.h"
#include "FsObject.h"
#include "luaext/FsTEntity.h"
#include "stage/entity/FsEntity.h"
#include "stage/entity/FsColorQuad2D.h"
#include "stage/entity/FsQuad2D.h"
#include "stage/entity/FsSprite2D.h"
#include "stage/entity/FsLabelTTF.h"
#include "stage/entity/FsLabelBitmap.h"
#include "stage/entity/FsVertexPolygon.h"
#include "stage/entity/FsParticle2DEffect.h"
#include "stage/entity/FsParticle2DEmitter.h"
#include "stage/entity/FsPanel.h"
#include "stage/ui/FsPressButton.h"

#if FS_CONFIG(FS_EXPORT_LIB_SPINE_SPRITE)
#include "FsSpineSprite.h"
#endif 

NS_FS_BEGIN
class LuaEntity:public TEntity<Entity>
{
	public:
		static LuaEntity* create()
		{
			return new LuaEntity;
		}
	public:
		virtual const char* className()
		{
			return FS_LUA_ENTITY_CLASS_NAME;
		}
	protected:
		LuaEntity(){}
		~LuaEntity(){}
};


class LuaColorQuad2D:public TEntity<ColorQuad2D>
{
	public:
		static LuaColorQuad2D* create()
		{
			LuaColorQuad2D* ret=new LuaColorQuad2D();
			ret->init();
			return ret;
		}
		static LuaColorQuad2D* create(const Rect2D& rect,Color4f c)
		{
			LuaColorQuad2D* ret=new LuaColorQuad2D;
			ret->init(rect,c);
			return ret;
		}
		static LuaColorQuad2D* create(float width,float height,Color4f c)
		{
			LuaColorQuad2D* ret=new LuaColorQuad2D;
			ret->init(width,height,c);
			return ret;
		}

	public:
		virtual const char* className()
		{
			return FS_LUA_COLOR_QUAD2D_CLASS_NAME;
		}
	protected:
		LuaColorQuad2D(){}
		~LuaColorQuad2D(){}
};
class LuaQuad2D:public TEntity<Quad2D>
{
	public:
		static LuaQuad2D* create(const char* name)
		{
			LuaQuad2D* ret=new LuaQuad2D();
			if(!ret->init(name))
			{
				delete ret;
				return NULL;
			}
			return ret;
		}
		static LuaQuad2D* create()
		{
			LuaQuad2D* ret=new LuaQuad2D();
			if(!ret->init())
			{
				delete ret;
				return NULL;
			}
			return ret;
		}

		static LuaQuad2D* create(const char* name,const Rect2D& rect)
		{
			LuaQuad2D* ret=new LuaQuad2D();
			if(!ret->init(name))
			{
				delete ret;
				return NULL;
			}
			ret->setRect2D(rect);
			return ret;

		}
		static LuaQuad2D* create(const char* name,float width,float height)
		{
			return create(name,Rect2D(-width/2,-height/2,width,height));
		}

	public:
		virtual const char* className()
		{
			return FS_LUA_QUAD2D_CLASS_NAME;
		}
	protected:
		LuaQuad2D(){}
		~LuaQuad2D(){}
};

class LuaLabelTTF:public TEntity<LabelTTF>
{
	public:
		static LuaLabelTTF* create()
		{
			LuaLabelTTF* ret=new LuaLabelTTF();
			if(!ret->init())
			{
				delete ret;
				return NULL;
			}
			return ret;
		}

		static LuaLabelTTF* create(const char* font,int size)
		{
			LuaLabelTTF* ret=new LuaLabelTTF();
			if(!ret->init(font,size))
			{
				delete ret;
				return NULL;
			}

			return ret;
		}

		static LuaLabelTTF* create(const char* font,int size,const char* text)
		{
			LuaLabelTTF* ret=new LuaLabelTTF();
			if(!ret->init(font,size,text))
			{
				delete ret;
				return NULL;
			}
			return ret;
		}

	public:
		virtual const char* className()
		{
			return FS_LUA_LABEL_TTF_CLASS_NAME;
		}
	protected:
		LuaLabelTTF(){}
		~LuaLabelTTF(){}
};
class LuaLabelBitmap:public TEntity<LabelBitmap>
{
	public:
		static LuaLabelBitmap* create(const char* text,FontBitmap* font)
		{
			LuaLabelBitmap* ret=create(font);
			if(ret)
			{
				ret->setString(text);
			}
			return ret;
		}
		static LuaLabelBitmap* create(FontBitmap* font)
		{
			LuaLabelBitmap* ret=new LuaLabelBitmap();
			if(!ret->init(font))
			{
				ret->decRef();
				ret=NULL;
			}
			return ret;
		}
	public:
		virtual const char* className()
		{
			return FS_LUA_LABEL_BITMAP_CLASS_NAME;
		}
	protected:
		LuaLabelBitmap(){}
		~LuaLabelBitmap(){}

};

class LuaSprite2D:public TEntity<Sprite2D>
{
	public:
		static LuaSprite2D* create(const char* name)
		{
			LuaSprite2D* ret=new LuaSprite2D();
			if(!ret->init(name))
			{
				delete ret;
				return NULL;
			}
			return ret;
		}
		static LuaSprite2D* create()
		{
			LuaSprite2D* ret=new LuaSprite2D();
			if(!ret->init())
			{
				delete ret;
				return NULL;
			}
			return ret;
		}
	public:
		virtual const char* className()
		{
			return FS_LUA_SPRITE2D_CLASS_NAME;
		}
	protected:
		LuaSprite2D(){}
		~LuaSprite2D(){}
};

class LuaParticle2DEffect:public TEntity<Particle2DEffect>
{
	public:
		static LuaParticle2DEffect* create(const char* filename)
		{
			Particle2DEmitter* emit=Particle2DEmitter::create(filename);
			if( emit==NULL) 
			{
				FS_TRACE_WARN("Create Emitter For File(%s) Failed",filename);
				return NULL;
			}
			LuaParticle2DEffect* ret=LuaParticle2DEffect::create(emit);
			emit->autoDestroy();
			return ret;
		}

		static LuaParticle2DEffect* create(FsFile*  file)
		{
			Particle2DEmitter* emit=Particle2DEmitter::create(file);
			if(emit==NULL)
			{
				FS_TRACE_WARN("create Emiit for Failed");
				return NULL;
			}

			LuaParticle2DEffect* ret=LuaParticle2DEffect::create(emit);
			emit->autoDestroy();
			return ret;
		}

		static LuaParticle2DEffect* create(Particle2DEmitter* emitter)
		{
			LuaParticle2DEffect* ret=new LuaParticle2DEffect;
			if(!ret->init(emitter))
			{
				delete ret;
			}
			return ret;
		}

		static LuaParticle2DEffect* create()
		{
			LuaParticle2DEffect* ret=new LuaParticle2DEffect;
			if(!ret->init(NULL))
			{
				delete ret;
			}
			return ret;
		}
	public:
		virtual const char* className()
		{
			return FS_LUA_PARTICLE2D_EFFECT_CLASS_NAME;
		}
};



class LuaVertexPolygon:public TEntity<VertexPolygon> 
{
	public:
		static LuaVertexPolygon* create()
		{
			LuaVertexPolygon* ret=new LuaVertexPolygon();
			if(!ret->init())
			{
				delete ret;
				return NULL;
			}
			return ret;
		}

	public:

		virtual const char* className()
		{
			return FS_LUA_VERTEX_POLYGON_CLASS_NAME;
		}

	protected:
		LuaVertexPolygon(){}
		~LuaVertexPolygon(){}
};

class LuaPressButton:public TEntity<PressButton>
{
	public:
		static LuaPressButton* create()
		{
			LuaPressButton* ret=new LuaPressButton();
			return ret;
		}

		static LuaPressButton* createWithDarkStyle(const char* filename,const Color4f& dark)
		{
			LuaPressButton* ret=new LuaPressButton();
			ret->initWithDarkStyle(filename,dark);
			return ret;
		}

		static LuaPressButton* createWithDarkStyle(Texture2D* tex,const Color4f& dark)
		{
			LuaPressButton* ret=new LuaPressButton();
			ret->initWithDarkStyle(tex,dark);
			return ret;
		}

		static LuaPressButton* createWithScaleStyle(const char* filename,const Vector3& scale)
		{
			LuaPressButton* ret=new LuaPressButton();
			ret->initWithScaleStyle(filename,scale);
			return ret;
		}

		static LuaPressButton* createWithScaleStyle(Texture2D* tex,const Vector3& scale)
		{
			LuaPressButton* ret=new LuaPressButton();
			ret->initWithScaleStyle(tex,scale);
			return ret;
		}



	public:
		/* inherit PressButton */

		virtual void click()
		{
			LuaEngine* se=(LuaEngine*) Global::scriptEngine();
			if(!se->callFunctionInTable(TEntity<PressButton>::m_scriptData,"onClick",1,0,"f",this))
			{
				TEntity<PressButton>::click();
			}
		}
		virtual void cancel()
		{
			LuaEngine* se=(LuaEngine*) Global::scriptEngine();
			if(!se->callFunctionInTable(TEntity<PressButton>::m_scriptData,"onCancel",1,0,"f",this))
			{
				TEntity<PressButton>::cancel();
			}
		}

		virtual void pressDown(float x,float y)
		{
			LuaEngine* se=(LuaEngine*) Global::scriptEngine();
			if(!se->callFunctionInTable(TEntity<PressButton>::m_scriptData,"onPressDown",3,0,"fnn",this,x,y))
			{
				TEntity<PressButton>::pressDown(x,y);
			}
		}
		virtual void pressMoveIn(float x,float y)
		{
			LuaEngine* se=(LuaEngine*) Global::scriptEngine();
			if(!se->callFunctionInTable(TEntity<PressButton>::m_scriptData,"onPressMoveIn",3,0,"fnn",this,x,y))
			{
				TEntity<PressButton>::pressMoveIn(x,y);
			}
		}
		virtual void pressMoveOut(float x,float y)
		{
			LuaEngine* se=(LuaEngine*) Global::scriptEngine();
			if(!se->callFunctionInTable(TEntity<PressButton>::m_scriptData,"onPressMoveOut",3,0,"fnn",this,x,y))
			{
				TEntity<PressButton>::pressMoveOut(x,y);
			}
		}
		virtual void pressUp(float x,float y)
		{
			LuaEngine* se=(LuaEngine*) Global::scriptEngine();
			if(!se->callFunctionInTable(TEntity<PressButton>::m_scriptData,"onPressUp",3,0,"fnn",this,x,y))
			{
				TEntity<PressButton>::pressUp(x,y);
			}
		}


	public:
		virtual void onPressDown(float x,float y)
		{
			TEntity<PressButton>::pressDown(x,y);
		}
		virtual void onPressMoveIn(float x,float y)
		{
			TEntity<PressButton>::pressMoveIn(x,y);
		}
		virtual void onPressMoveOut(float x,float y)
		{
			TEntity<PressButton>::pressMoveOut(x,y);
		}
		virtual void onPressUp(float x,float y)
		{
			TEntity<PressButton>::pressUp(x,y);
		}

		virtual void onClick()
		{
			TEntity<PressButton>::click();
		}
		virtual void onCancel()
		{
			TEntity<PressButton>::cancel();
		}



	public:


		/* inherit FsObject */
		virtual const char* className()
		{
			return FS_LUA_PRESS_BUTTON_CLASS_NAME;
		}


	protected:
		LuaPressButton(){}
		virtual ~LuaPressButton(){}


};


class LuaPanel:public TEntity<Panel>
{
	public:
		static LuaPanel* create()
		{
			return LuaPanel::create(0,0);
		}
		static LuaPanel* create(float width,float height)
		{
			LuaPanel* ret=new LuaPanel();
			if(!ret->init(width,height))
			{
				delete ret;
				return NULL;
			}
			return ret;
		}
	public:
		virtual const char* className()
		{
			return FS_LUA_PANEL_CLASS_NAME;
		}



};


#if FS_CONFIG(FS_EXPORT_LIB_SPINE_SPRITE)


class LuaSpineSprite:public TEntity<SpineSprite>
{
	public:
		static LuaSpineSprite* create(const char* name)
		{
			LuaSpineSprite* ret=new LuaSpineSprite();
			if(!ret->init(name))
			{
				delete ret;
				return NULL;
			}
			return ret;

		}
	public:
		virtual const char* className()
		{
			return FS_LUA_SPINE_SPRITE_CLASS_NAME;
		}
	protected:
		LuaSpineSprite(){}
		~LuaSpineSprite(){}
};


#endif 


NS_FS_END

#endif /*_FS_LUA_ENTITY_H_*/











