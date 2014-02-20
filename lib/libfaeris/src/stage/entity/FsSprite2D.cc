#include "stage/entity/FsSprite2D.h"
#include "FsGlobal.h"
#include "stage/entity/FsSprite2DData.h"
#include "graphics/FsTexture2D.h"
#include "support/util/FsArray.h"
#include "support/util/FsDict.h"
#include "support/util/FsInteger.h"
#include "graphics/material/FsMat_V4F_T2F_A1F.h"

NS_FS_BEGIN

class AnimationCacheData: public FsObject 
{
	public:
		static AnimationCacheData* create(Sprite2DAnimation* anim)
		{
			AnimationCacheData* ret=new AnimationCacheData();
			ret->init(anim);
			return ret;
		}

	protected:
		AnimationCacheData()
		{
			m_fps=0;
			m_offsetx=0;
			m_offsety=0;
		}
		bool init(Sprite2DAnimation* anim)
		{
			m_fps=anim->getFps();
			return true;
		}

	public:
		const char* className() 
		{
			return "AnimationCacheData";
		}

	public:
		int m_fps;
		float m_offsetx,m_offsety;
};

Sprite2D* Sprite2D::create(const char* name)
{

	Sprite2D* ret=new Sprite2D;
	if(!ret->init(name))
	{
		FS_TRACE_WARN("init Sprite Data Failed");
		delete ret;
		ret=NULL;
	}

	return ret;
}


Sprite2D* Sprite2D::create()
{
	Sprite2D* ret=new Sprite2D;
	if(!ret->init())
	{
		delete ret;
		ret=NULL;
	}
	return ret;
}


void Sprite2D::setColor(Color  color)
{
	m_color=color;
}
Color Sprite2D::getColor()
{
	return m_color;
}
void Sprite2D::setOpacity(float opacity)
{
	m_opacity=opacity;
}

float Sprite2D::getOpacity()
{
	return m_opacity;
}

void Sprite2D::setAnimation(const char*  name)
{
	Sprite2DAnimation* anim=m_data->getAnimation(name);
	setAnimation(anim);
}
const char* Sprite2D::getAnimation()
{
	if(m_curAnimation)
	{
		return NULL;
	}

	FsString* name=m_curAnimation->getName();
	return name->cstr();
}

bool Sprite2D::hasAnimation(const char* name)
{
	Sprite2DAnimation* anim=m_data->getAnimation(name);
	bool ret=(anim!=NULL);
	return ret;
}

void Sprite2D::updateAnimation(float dt)
{
	if(!m_curAnimation||m_stop)
	{
		return ;
	}

	int fps=m_curFps;
	float frame_time=1.0f/(float)fps;
	int total_frame=m_curAnimation->getKeyFrameNu();


	m_elapseTime+=dt;

	int forward_frame=(int)floor(m_elapseTime/frame_time);
	m_elapseTime-=forward_frame*frame_time;
	
	m_curFrame+=forward_frame;

	if(m_curFrame>=total_frame)
	{
		switch(m_mode)
		{
			case ANIM_LOOP:
				m_curFrame=m_curFrame%total_frame;
				break;
			case ANIM_START:
				m_curFrame=0;
				m_stop=true;
				break;
			case ANIM_END:
				m_curFrame=total_frame-1;
				m_stop=true;
				break;
		}
	}
}

void Sprite2D::playAnimation(int mode)
{
	m_mode=mode;
	m_stop=false;
}


void Sprite2D::startAnimation(int mode)
{
	m_mode=mode;
	m_stop=false;
	m_elapseTime=0;
	m_curFrame=0;
}

void Sprite2D::stopAnimation()
{
	m_stop=true;
}

bool Sprite2D::isAnimationPlaying()
{
	return !m_stop;
}

void Sprite2D::setBlendMode(int blendsrc,int blenddst)
{
	m_blendSrc=blendsrc;
	m_blendDst=blenddst;
}



void Sprite2D::setCurFrame(int frame)
{
	m_curFrame=frame;
	if(m_curAnimation)
	{
		int total_frame=m_curAnimation->getKeyFrameNu();
		m_curFrame=m_curFrame%total_frame;
	}
}


int Sprite2D::getCurFrame()
{
	return m_curFrame;
}

int Sprite2D::getTotalFrame()
{
	if(!m_curAnimation)
	{
		return 0;
	}
	return m_curAnimation->getKeyFrameNu();
}



void Sprite2D::update(float dt)
{
	updateAction(dt);
	updateAnimation(dt);
}


void Sprite2D::draw(Render* render,bool update_matrix)
{
	if(!m_curAnimation)
	{
		return ;
	}

	if(update_matrix)
	{
		updateWorldMatrix();
	}
	render->pushMatrix();
	render->mulMatrix(&m_worldMatrix);
	if(m_curAnimationCacheData) 
	{
		if(m_curAnimationCacheData->m_offsetx||m_curAnimationCacheData->m_offsety)
		{
			render->translate(Vector3(m_curAnimationCacheData->m_offsetx,
								m_curAnimationCacheData->m_offsety,0));
		}
	}

	m_material->setOpacity(m_opacity);
	m_material->setColor(m_color);
	render->setMaterial(m_material);

	render->setBlend(Render::EQUATION_ADD,m_blendSrc,m_blendDst);

	render->setActiveTexture(1);
	render->disableAllAttrArray();



	Sprite2DKeyFrame* frame=m_curAnimation->getKeyFrame(m_curFrame);

	static Face3 faces[2]=
	{
		Face3(0,3,2),
		Face3(2,1,0),
	};
	int pos_loc=m_material->getV4FLocation();
	int alpha_loc=m_material->getA1FLocation();
	int tex_loc=m_material->getT2FLocation();

	for(int i=0;i<frame->getQuadNu();i++)
	{
		Sprite2DQuad* quad=frame->getQuad(i);
		Texture2D* tex=(Texture2D*)m_textures->get(quad->texture);
		render->bindTexture(tex,0);
		render->setAndEnableVertexAttrPointer(pos_loc,2,FS_FLOAT,4,0,quad->vertex);
		render->setAndEnableVertexAttrPointer(tex_loc,2,FS_FLOAT,4,0,quad->texcoord);
		render->setAndEnableVertexAttrPointer(alpha_loc,1,FS_FLOAT,4,0,quad->alpha);
		render->drawFace3(faces,2);
	}
	render->popMatrix();
}

const char* Sprite2D::className()
{
	return FS_SPRITE2D_CLASS_NAME;
}

bool Sprite2D::init(const char* name)
{
	setResourceUrl(name);
	return true;
}
bool Sprite2D::init()
{
	return true;
}

void Sprite2D::setResourceUrl(const char* name)
{
	if(m_data)
	{
		FS_SAFE_DEC_REF(m_data);
		m_data=NULL;
	}
	if(m_textures)
	{
		FS_SAFE_DEC_REF(m_textures);
		m_textures=NULL;
	}

	if(m_animationCacheData)
	{
		FS_DESTROY(m_animationCacheData);
		m_animationCacheData=NULL;
	}

	if(m_curAnimation)
	{
		FS_SAFE_DEC_REF(m_curAnimation);
	}

	m_curFrame=0;
	m_elapseTime=0.0f;
	m_stop=true;
	m_curFps=0;


	Sprite2DData* data=Global::sprite2DDataMgr()->loadSprite2DData(name);
	if(data==NULL)
	{
		FS_TRACE_WARN("Can't Find Sprite2DData(%s)",name);
		return;
	}

	FS_SAFE_ASSIGN(m_data,data);

	FS_SAFE_ASSIGN(m_textures,data->getTextures());

	m_animationCacheData=FsDict::create();

	FS_NO_REF_DESTROY(m_animationCacheData);
}



void Sprite2D::setAnimation(Sprite2DAnimation* anim)
{
	FS_SAFE_ASSIGN(m_curAnimation,anim);

	if(m_curAnimation)
	{
		FsString* anim_name=m_curAnimation->getName();
		m_curFrame=0;
		m_curAnimationCacheData=(AnimationCacheData*)m_animationCacheData->lookup(anim_name);
		if(m_curAnimationCacheData)
		{
			m_curFps=m_curAnimationCacheData->m_fps;
		}
		else
		{
			m_curFps=m_curAnimation->getFps();
		}
		m_elapseTime=0.0f;
	}
	else 
	{
		m_curFps=0;
	}
}

int Sprite2D::getFps()
{
	return m_curFps;
}

void Sprite2D::setFps(int fps)
{
	if(m_curAnimation)
	{
		if(!m_curAnimationCacheData) 
		{
			FsString* anim_name=m_curAnimation->getName();
			m_curAnimationCacheData =AnimationCacheData::create(m_curAnimation);
			m_animationCacheData->insert(anim_name,m_curAnimationCacheData);
			m_curFps=fps;
		}
		m_curAnimationCacheData->m_fps=fps;
		m_curFps=fps;
	}
}
void Sprite2D::setAnimationOffset(float x,float y)
{
	if(m_curAnimation) 
	{
		if(!m_curAnimationCacheData) 
		{
			FsString* anim_name=m_curAnimation->getName();
			m_curAnimationCacheData =AnimationCacheData::create(m_curAnimation);
			m_animationCacheData->insert(anim_name,m_curAnimationCacheData);
		}
		m_curAnimationCacheData->m_offsetx=x;
		m_curAnimationCacheData->m_offsety=y;
	}

}

void Sprite2D::getAnimationOffset(float* x,float* y)
{
	if(!m_curAnimation)
	{
		*x=0;
		*y=0;
		return ;
	}
	if(m_curAnimationCacheData)
	{
		*x=m_curAnimationCacheData->m_offsetx;
		*y=m_curAnimationCacheData->m_offsety;
	}
	else 
	{
		*x=0;
		*y=0;
	}
}


Sprite2D::Sprite2D()
{
	m_color=Color::WHITE;
	m_opacity=1.0f;
	m_curFrame=0;
	m_elapseTime=0.0f;

	m_mode=ANIM_LOOP;
	m_stop=true;
	m_curFps=0;


	m_data=NULL;
	m_curAnimation=NULL;
	m_curAnimationCacheData=NULL;

	m_blendSrc=Render::FACTOR_SRC_ALPHA;
	m_blendDst=Render::FACTOR_ONE_MINUS_SRC_ALPHA;

	m_textures=NULL;
	m_animationCacheData=NULL;
	m_material=Mat_V4F_T2F_A1F::shareMaterial();
}

Sprite2D::~Sprite2D()
{
	FS_SAFE_DEC_REF(m_data);
	FS_SAFE_DEC_REF(m_curAnimation);

	FS_SAFE_DEC_REF(m_textures);
	FS_SAFE_DEC_REF(m_material);

	FS_DESTROY(m_animationCacheData);
}


NS_FS_END
























