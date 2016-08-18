/*************************************************************************/
/*  FsSprite2D.cc                                                        */
/*************************************************************************/
/* Copyright (C) 2012-2014 nosiclin@foxmail.com                          */
/* Copyright (C) 2014-2015 www.fsource.cn                                */
/*                                                                       */
/* http://www.fsource.cn                                                 */
/*                                                                       */
/* Permission is hereby granted, free of charge, to any person obtaining */
/* a copy of this software and associated documentation files (the       */
/* "Software"), to deal in the Software without restriction, including   */
/* without limitation the rights to use, copy, modify, merge, publish,   */
/* distribute, sublicense, and/or sell copies of the Software, and to    */
/* permit persons to whom the Software is furnished to do so, subject to */
/* the following conditions:                                             */
/*                                                                       */
/* The above copyright notice and this permission notice shall be        */
/* included in all copies or substantial portions of the Software.       */
/*                                                                       */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,       */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF    */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.*/
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY  */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,  */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE     */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                */
/*************************************************************************/


#include "stage/entity/FsSprite2D.h"
#include "stage/entity/FsSprite2DData.h"

#include "graphics/FsTexture2D.h"
#include "graphics/shader/FsProgram.h"
#include "graphics/shader/FsStreamMap.h"

#include "support/util/FsArray.h"
#include "support/util/FsDict.h"
#include "support/util/FsInteger.h"
#include "FsGlobal.h"
#include "mgr/FsProgramSourceMgr.h"



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


void Sprite2D::setAnimation(const char*  name)
{

	Sprite2DAnimation* anim=m_data->getAnimation(name);
	FS_TRACE_WARN_ON(anim==NULL,"Can't Find Anim(%s)",name);

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
	
	if(m_curFrame<0)
	{
		m_curFrame=0;
	}

	if(m_curFrame>=total_frame)
	{
		switch(m_mode)
		{
			case E_AnimPlayMode::LOOP:
				m_curFrame=m_curFrame%total_frame;
				break;

		}
	}
}

void Sprite2D::playAnimation(E_AnimPlayMode mode)
{
	m_mode=mode;
	m_stop=false;
}


void Sprite2D::startAnimation(E_AnimPlayMode mode)
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
	updateAnimation(dt);
}


void Sprite2D::draw(RenderDevice* rd,bool update_matrix)
{
	Program* prog=getProgram(NULL);
	if(!m_curAnimation||!prog)
	{
		return ;
	}

	if(update_matrix)
	{
		updateWorldMatrix();
	}

	rd->setWorldMatrix(&m_worldMatrix);

	if(m_curAnimationCacheData) 
	{
		if(m_curAnimationCacheData->m_offsetx||m_curAnimationCacheData->m_offsety)
		{
			rd->translateWorldMatrix(Vector3(m_curAnimationCacheData->m_offsetx,
								m_curAnimationCacheData->m_offsety,0));
		}
	}

	rd->setProgram(prog);
	m_material->configRenderDevice(rd);



	rd->disableAllAttrArray();

	Sprite2DKeyFrame* frame=m_curAnimation->getKeyFrame(m_curFrame);

	static Face3 faces[2]=
	{
		Face3(0,3,2),
		Face3(2,1,0),
	};

	StreamMap* map_v=prog->getStreamMap(E_StreamType::VERTICES);
	StreamMap* map_u=prog->getStreamMap(E_StreamType::UVS);
	StreamMap* map_a=prog->getStreamMap(E_StreamType::USER_DEFINE1);


	for(int i=0;i<frame->getQuadNu();i++)
	{
		Sprite2DQuad* quad=frame->getQuad(i);
		Texture2D* tex=(Texture2D*)m_textures->get(quad->texture);
		rd->bindTexture(tex,0);
		if(map_v)
		{
			rd->setAndEnableVertexAttrPointer(map_v->m_location,2,FS_FLOAT,4,0,quad->vertex);
		}

		if(map_u)
		{
			rd->setAndEnableVertexAttrPointer(map_u->m_location,2,FS_FLOAT,4,0,quad->texcoord);
		}
		if(map_a)
		{
			rd->setAndEnableVertexAttrPointer(map_a->m_location,1,FS_FLOAT,4,0,quad->alpha);
		}
		rd->drawFace3(faces,2);
	}

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
		m_curAnimation=NULL;
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
	m_curFrame=0;
	m_elapseTime=0.0f;

	m_mode=E_AnimPlayMode::LOOP;
	m_stop=true;
	m_curFps=0;


	m_data=NULL;
	m_curAnimation=NULL;
	m_curAnimationCacheData=NULL;


	m_textures=NULL;
	m_animationCacheData=NULL;

	static ProgramSource* S_programSource=NULL;
	if(S_programSource==NULL)
	{
		S_programSource=(ProgramSource*)Global::programSourceMgr()->load(FS_PRE_PROGRAM_SOURCE_V4F_T2F_A1F);
	}
	setProgramSource(S_programSource);
}

Sprite2D::~Sprite2D()
{
	FS_SAFE_DEC_REF(m_data);
	FS_SAFE_DEC_REF(m_curAnimation);
	FS_SAFE_DEC_REF(m_textures);
	FS_DESTROY(m_animationCacheData);
}


NS_FS_END
























