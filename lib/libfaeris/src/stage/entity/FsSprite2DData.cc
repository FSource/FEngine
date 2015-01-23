/*************************************************************************/
/*  FsSprite2DData.cc                                                    */
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


#include "stage/entity/FsSprite2DData.h"
#include "support/util/FsDict.h"
#include "support/util/FsArray.h"
#include "support/util/FsScriptUtil.h"
#include "graphics/FsTexture2D.h"
#include "FsGlobal.h"



NS_FS_BEGIN
void Sprite2DKeyFrame::addQuad(Sprite2DQuad* quad)
{
	m_quads.push_back(quad);
}

Sprite2DQuad* Sprite2DKeyFrame::getQuad(int i)
{
	return m_quads[i];
}

int Sprite2DKeyFrame::getQuadNu()
{
	return m_quads.size();
}


void Sprite2DKeyFrame::setBoundingBox(const Rect2D& rect)
{
	m_boundingBox=rect;
}

Rect2D Sprite2DKeyFrame::getBoundingBox()
{
	return m_boundingBox;

}

Sprite2DKeyFrame::Sprite2DKeyFrame()
{
}

Sprite2DKeyFrame::~Sprite2DKeyFrame()
{
	for(unsigned int i=0;i<m_quads.size();i++)
	{
		delete m_quads[i];
	}
	m_quads.clear();
}

Sprite2DAnimation* Sprite2DAnimation::create()
{
	return new Sprite2DAnimation();
}

void Sprite2DAnimation::addKeyFrame(Sprite2DKeyFrame* frame)
{
	m_keys.push_back(frame);
}
Sprite2DKeyFrame* Sprite2DAnimation::getKeyFrame(int i)
{
	return m_keys[i];
}

int Sprite2DAnimation::getKeyFrameNu()
{
	return m_keys.size();
}


void Sprite2DAnimation::setFps(int fps)
{
	m_fps=fps;
}

int Sprite2DAnimation::getFps()
{
	return m_fps;
}

void Sprite2DAnimation::setName(FsString* name)
{
	FS_SAFE_ASSIGN(m_name,name);
}
FsString* Sprite2DAnimation::getName()
{
	return m_name;
}


const char* Sprite2DAnimation::className()
{
	return FS_SPRITE2D_ANIMATION_CLASS_NAME;
}


Sprite2DAnimation::Sprite2DAnimation()
{
	m_fps=0;
	m_name=NULL;
}

Sprite2DAnimation::~Sprite2DAnimation()
{
	for(unsigned int i=0;i<m_keys.size();i++)
	{
		delete m_keys[i];
	}
	m_keys.clear();

	FS_SAFE_DEC_REF(m_name);
}

Sprite2DData* Sprite2DData::create(FsFile* file)
{
	Sprite2DData* ret=new Sprite2DData();
	if(!ret->init(file))
	{
		delete ret;
		return NULL;
	}
	return ret;
}

void Sprite2DData::addAnimation(Sprite2DAnimation* animation)
{
	FsString* name=animation->getName();
	assert(name!=NULL);
	m_animations->insert(name,animation);
}

Sprite2DAnimation* Sprite2DData::getAnimation(const char* name)
{
	Sprite2DAnimation* anim=(Sprite2DAnimation*) m_animations->lookup(name);
	return anim;
}

int Sprite2DData::getAnimationNu()
{
	return m_animations->size();
}


FsArray* Sprite2DData::getTextures()
{
	return m_textures;
}

Texture2D* Sprite2DData::getTexture(int i)
{
	return (Texture2D*) m_textures->get(i);
}


const char* Sprite2DData::className()
{
	return FS_SPRITE2D_DATA_CLASS_NAME;
}


Sprite2DData::Sprite2DData()
{
	m_animations=FsDict::create();
	FS_NO_REF_DESTROY(m_animations);

	m_textures=FsArray::create();
	FS_NO_REF_DESTROY(m_textures);

	m_name=NULL;
}

Sprite2DData::~Sprite2DData()
{
	FS_DESTROY(m_animations);
	FS_DESTROY(m_textures);

	FS_SAFE_DEC_REF(m_name);

}


bool Sprite2DData::init(FsFile* file)
{
	bool ret=false;

	FsDict* dict=ScriptUtil::parseScript(file);

	if(dict==NULL)
	{
		FS_TRACE_WARN("Parse File For Sprite2DData Failed");
		return false;
	}
	FsString* type=ScriptUtil::getString(dict,"type");
	FsString* name=ScriptUtil::getString(dict,"name");
	FsString* version=ScriptUtil::getString(dict,"version");

	int resourceNu=0;

	FsArray* textures=ScriptUtil::getArray(dict,"resources");
	FsArray* animations=ScriptUtil::getArray(dict,"animations");


	if(type==NULL||!type->equal("sprite2d"))
	{
		FS_TRACE_WARN("Type Field Not Find Or Type Error");
		goto  error;
	}

	if(name==NULL)
	{
		FS_TRACE_WARN("Name Filed Not Find");
		goto error;
	}

	if(version==NULL||!version->equal("v1.0"))
	{
		FS_TRACE_WARN("Version Filed Not Find Or Version Error");
		goto error;
	}

	if(!ScriptUtil::getInteger(dict,"resourceNu",&resourceNu))
	{
		FS_TRACE_WARN("Resource Field Not Find Or Error");
		goto error;
	}
	if(textures==NULL)
	{
		FS_TRACE_WARN("Resources Filed  Not Find Or Error");
		goto error;
	}
	if(animations==NULL)
	{
		FS_TRACE_WARN("Animations Filed Not Find Or Error");
		goto error;
	}


	if(resourceNu!=(int)textures->size())
	{
		FS_TRACE_WARN("resources in array not equal resourceNu");
		goto error;
	}


	if(!loadTextures(textures))
	{
		FS_TRACE_WARN("load Resource Error");
		goto error;
	}
	if(!loadAnimations(animations))
	{
		FS_TRACE_WARN("load Animation Error");
		goto error;
	}

	FS_SAFE_ASSIGN(m_name,name);

	ret=true;


error:
	FS_DESTROY(dict);
	return  ret;
}

bool Sprite2DData::loadTextures(FsArray* array)
{
	int texture_nu=array->size();
	for(int i=0;i<texture_nu;i++)
	{
		FsString* name=ScriptUtil::getString(array,i);
		if(name)
		{
			Texture2D* tex=Global::textureMgr()->loadTexture(name->cstr());
			if(!tex)
			{
				FS_TRACE_WARN("Can't Load Resource(%s) For Sprite",name->cstr());
				return false;
			}
			m_textures->push(tex);
		}
		else 
		{
			return false;
		}
	}
	return true;
}

bool Sprite2DData::loadAnimations(FsArray* array)
{
	int anim_nu=array->size();
	for(int i=0;i<anim_nu;i++)
	{
		FsDict* dict=ScriptUtil::getDict(array,i);
		if(!dict)
		{
			FS_TRACE_WARN("load animtion %d failed",i);
			continue;
		}

		Sprite2DAnimation* anim=createAnimation(dict);

		if(!anim)
		{
			FS_TRACE_WARN("load animtion %d failed",i);
			continue;
		}

		addAnimation(anim);
	}
	return true;
}

Sprite2DAnimation* Sprite2DData::createAnimation(FsDict* dict)
{
	FsString* name=ScriptUtil::getString(dict,"name");
	FsArray* keyframes=ScriptUtil::getArray(dict,"keyFrames");

	int fps,frame_nu;
	Sprite2DAnimation* ret=NULL;

	if(name==NULL)
	{
		FS_TRACE_WARN("Can't Find Name Filed");
		return NULL;
	}
	if(keyframes==NULL)
	{
		FS_TRACE_WARN("Can't Find keyFrames Filed");
		return NULL;
	}

	if(!ScriptUtil::getInteger(dict,"fps",&fps))
	{
		FS_TRACE_WARN("Can't Find fps Filed");
		return NULL;
	}
	if(!ScriptUtil::getInteger(dict,"frameNu",&frame_nu))
	{
		FS_TRACE_WARN("Can't Find frameNu Filed");
		return NULL;
	}

	if(frame_nu!=(int)keyframes->size())
	{
		FS_TRACE_WARN("Frame in keyFrames not Equal frameNu");
		return NULL;
	}
	ret=Sprite2DAnimation::create();

	for(int i=0;i<frame_nu;i++)
	{
		FsArray* frame=ScriptUtil::getArray(keyframes,i);
		if(frame)
		{
			Sprite2DKeyFrame* key=createKeyFrame(frame);

			if(key)
			{
				ret->addKeyFrame(key);
			}
			else 
			{
				FS_DESTROY(ret);
				return NULL;
			}
		}
		else 
		{
			FS_DESTROY(ret);
			return NULL;
		}
	}

	ret->setName(name);
	if(fps<=0) fps=1;
	ret->setFps(fps);

	return ret;
}

Sprite2DKeyFrame* Sprite2DData::createKeyFrame(FsArray* frame)
{
	Sprite2DKeyFrame* ret=new Sprite2DKeyFrame;

	int quad_nu=frame->size();

	for(int i=0;i<quad_nu;i++)
	{
		bool error=false;

		FsDict* quad=ScriptUtil::getDict(frame,i);

		if(quad==NULL)
		{
			FS_TRACE_WARN("Can't Get SpriteQuad At %d",i);
			continue;
		}

		Sprite2DQuad* q=new Sprite2DQuad();

		if(!ScriptUtil::getInteger(quad,"texture",&q->texture))
		{
			FS_TRACE_WARN("Can't Get Texture ID");
			error=true;
		}

		/* texture coord */
		{
			FsArray* tex_coord=ScriptUtil::getArray(quad,"texcoord");
			if(tex_coord==NULL)
			{
				FS_TRACE_WARN("Can't Get TexCoord Filed");
				error=true;
			}
			else 
			{
				for(int j=0;j<8;j++)
				{
					if(!ScriptUtil::getFloat(tex_coord,j,&q->texcoord[j]))
					{
						FS_TRACE_WARN("Can't Get Texture Coord  data At %d ",j); 
						error=true;
						break;
					}
				}
			}
		}

		/* vertex */
		{
			FsArray* vertex=ScriptUtil::getArray(quad,"vertex");
			if(vertex==NULL)
			{
				FS_TRACE_WARN("Can't Get Vertex Field");
				error=true;
			}
			else 
			{
				for(int j=0;j<8;j++)
				{
					if(!ScriptUtil::getFloat(vertex,j,&q->vertex[j]))
					{
						FS_TRACE_WARN("Can't Get Vertex data At %d",j);
						error=true;
						break;
					}
				}
			}
		}

		/* alpha */
		{
			FsArray* alpha=ScriptUtil::getArray(quad,"alpha");
			if(alpha==NULL)
			{
				FS_TRACE_WARN("Can't Get Alpha Filed");
				error=true;
			}
			else 
			{
				for(int j=0;j<4;j++)
				{
					if(!ScriptUtil::getFloat(alpha,j,&q->alpha[j]))
					{
						FS_TRACE_WARN("Can't Get alpha data ");
						error=true;
						break;
					}
				}
			}
		}

		if(error)
		{
			FS_TRACE_WARN("Error Quad(%d) Ingore",i);
			delete q;
			q=NULL;
		} 
		else 
		{

			ret->addQuad(q);
		}
	}

	return ret;

}


NS_FS_END














































