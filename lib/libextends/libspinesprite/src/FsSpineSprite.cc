#include "FsSpineSprite.h"
#include "FsTextureAttachment.h"
#include "graphics/FsRenderDevice.h"
#include "FsGlobal.h"
#include "mgr/FsProgramSourceMgr.h"
#include "graphics/shader/FsProgram.h"
#include "graphics/shader/FsStreamMap.h"

NS_FS_BEGIN 

const char* SpineSprite::className()
{
	return "SpineSprite";
}

SpineSprite* SpineSprite::create(const char* filename)
{
	SpineSprite* ret=new SpineSprite;
	if(!ret->init(filename))
	{
		delete ret;
		ret=NULL;
	}

	return ret;
}


bool SpineSprite::setSkin(const char* skin)
{
	bool ret=Skeleton_setSkinByName(m_skeleton,skin)?true:false;
	return ret;
}



void SpineSprite::setAnimation(const char* anim)
{
	m_curAnimation=SkeletonData_findAnimation(m_data->getSkeletonData(),anim);
	m_elapseTime=0.0f;
	if(m_curAnimation)
	{
		m_duration=m_curAnimation->duration;
		Skeleton_setToSetupPose(m_skeleton);
	}
	else 
	{
		m_duration=0;
	}

}



void SpineSprite::updateAnimation(float dt)
{
	if(m_stop||!m_curAnimation)
	{
		return;
	}
	setCurTime(m_elapseTime+dt);
}


void SpineSprite::playAnimation(E_AnimPlayMode mode)
{
	m_stop=false;
	m_mode=mode;
}

void SpineSprite::startAnimation(E_AnimPlayMode mode)
{
	m_elapseTime=0.0f;
	m_stop=false;
	m_mode=mode;
}

void SpineSprite::stopAnimation()
{
	m_stop=true;
}

bool SpineSprite::isAnimationPlaying()
{
	if(m_stop)
	{
		return false;
	}
	return true;
}

void SpineSprite::setCurTime(float time)
{
	m_elapseTime=time;
	if(!m_curAnimation)
	{
		m_elapseTime=0.0f;
		return;
	}

	if(m_elapseTime>m_duration)
	{
		switch(m_mode)
		{
			case E_AnimPlayMode::LOOP:
				break;
			case E_AnimPlayMode::START:
				m_elapseTime=0;
				m_stop=true;
				break;
			case E_AnimPlayMode::END:
				m_elapseTime=m_duration-0.001f;
				m_stop=true;
				break;
		}
	}


}

float SpineSprite::getCurTime()
{
	return m_elapseTime;
}
float SpineSprite::getDurationTime()
{
	return m_duration;
}


void SpineSprite::update(float dt)
{
	Entity::update(dt);
	updateAnimation(dt);
}



void SpineSprite::draw(RenderDevice* rd,bool update_matrix)
{
	Program* prog=getProgram(NULL);

	if(!prog||!m_curAnimation)
	{
		return;
	}

	if(update_matrix)
	{
		updateWorldMatrix();
	}

	m_skeleton->r=1.0f;
	m_skeleton->g=1.0f;
	m_skeleton->b=1.0f;
	m_skeleton->a=1.0f;

	Animation_apply(m_curAnimation,m_skeleton,m_elapseTime,true);
	//FS_TRACE_WARN("Time is %f",m_elapseTime/1000);

	Skeleton_updateWorldTransform(m_skeleton);

	rd->setWorldMatrix(&m_worldMatrix);
	rd->setProgram(prog);
	m_material->configRenderDevice(rd);
	rd->disableAllAttrArray();


	static TexCoord2 vt[4]=
	{
		TexCoord2(0,1),
		TexCoord2(0,0),
		TexCoord2(1,0),
		TexCoord2(1,1),
	};

	static Face3 faces[2]=
	{
		Face3(0,3,1),
		Face3(3,2,1),
	};

	StreamMap* map_v=prog->getStreamMap(E_StreamType::VERTICES);
	StreamMap* map_u=prog->getStreamMap(E_StreamType::UVS);
	StreamMap* map_c=prog->getStreamMap(E_StreamType::COLORS);


	if(map_u)
	{
		rd->setAndEnableVertexAttrPointer(map_u->m_location,2,FS_FLOAT,4,0,vt);
	}





	int slot_nu=m_skeleton->slotCount;

	for(int i=0;i<slot_nu;i++)
	{
		Slot* slot=m_skeleton->slots[i];
		if(!slot->attachment||slot->attachment->type!=ATTACHMENT_REGION)
		{
			continue;
		}
		TextureAttachment* attachment=(TextureAttachment*)slot->attachment;
		Texture2D* texture=attachment->texture;

		if(!texture)
		{
			continue;
		}
		float vv[8];
		RegionAttachment_computeVertices(
				&attachment->super,
				0,
				0,
				slot->bone,
				vv);

		float r= slot->skeleton->r*slot->r;
		float g= slot->skeleton->g*slot->g;
		float b= slot->skeleton->b*slot->b;
		float a= slot->skeleton->a*slot->a;

		Color4f vc[4]={
			Color4f (r,g,b,a),
			Color4f (r,g,b,a),
			Color4f (r,g,b,a),
			Color4f (r,g,b,a),
		};

		rd->bindTexture(texture,0);

		if(map_v)
		{
			rd->setAndEnableVertexAttrPointer(map_v->m_location,2,FS_FLOAT,4,0,vv);
		}

		if(map_c)
		{
			rd->setAndEnableVertexAttrPointer(map_c->m_location,4,FS_FLOAT,4,0,vc);
		}

		rd->drawFace3(faces,2);
	}

}



SpineSprite::SpineSprite()
{

	m_elapseTime=0.0f;
	m_stop=true;
	m_skeleton=NULL;

	m_curAnimation=NULL;
	m_duration=0.0f;

	m_data=NULL;
	m_mode=E_AnimPlayMode::START;

	static ProgramSource* S_programSource=NULL;
	if(S_programSource==NULL)
	{
		S_programSource=(ProgramSource*) Global::programSourceMgr()->load(FS_PRE_PROGRAM_SOURCE_V4F_T2F_C4F);

	}
	setProgramSource(S_programSource);

}

SpineSprite::~SpineSprite()
{
	destruct();
}


bool SpineSprite::init(const char* name)
{
	SpineSpriteData* data=SpineSpriteDataMgr::sharedMgr()->loadSpineSpriteData(name);
	if(data==NULL)
	{
		return false;
	}

	FS_SAFE_ASSIGN(m_data,data);
	SkeletonData* sk_data=m_data->getSkeletonData();

	m_skeleton=Skeleton_create(sk_data);



	return true;

}

void SpineSprite::destruct()
{

	if(m_skeleton)
	{
		Skeleton_dispose(m_skeleton);
		m_skeleton=NULL;
	}

	FS_SAFE_DEC_REF(m_data);
}



















NS_FS_END




























