#include "FsSpineSprite.h"
#include "FsTextureAttachment.h"
#include "graphics/FsRender.h"

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


void SpineSprite::setColor(Color c)
{
	m_color=c;
}

Color SpineSprite::getColor()
{
	return m_color;
}


void SpineSprite::setOpacity(float opacity)
{
	m_opacity=opacity;
}

float SpineSprite::getOpacity()
{
	return m_opacity;
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


void SpineSprite::playAnimation(int mode)
{
	m_stop=false;
	m_mode=mode;
}

void SpineSprite::startAnimation(int mode)
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
			case ANIM_LOOP:
				break;
			case ANIM_START:
				m_elapseTime=0;
				m_stop=true;
				break;
			case ANIM_END:
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



void SpineSprite::draw(Render* render,bool update_matrix)
{
	if(!m_material||!m_curAnimation)
	{
		return;
	}

	if(update_matrix)
	{
		updateWorldMatrix();
	}



	m_skeleton->r=(float)m_color.r/255.0f;
	m_skeleton->g=(float)m_color.g/255.0f;
	m_skeleton->b=(float)m_color.b/255.0f;
	m_skeleton->a=(float)m_color.a/255.0f;

	Animation_apply(m_curAnimation,m_skeleton,m_elapseTime,true);
	//FS_TRACE_WARN("Time is %f",m_elapseTime/1000);

	Skeleton_updateWorldTransform(m_skeleton);

	render->pushMatrix();
	render->mulMatrix(&m_worldMatrix);
	render->setActiveTexture(1);
	render->disableAllAttrArray();

	TexCoord2 vc[4]=
	{
		TexCoord2(0,1),
		TexCoord2(0,0),
		TexCoord2(1,0),
		TexCoord2(1,1),
	};

	Face3 faces[2]=
	{
		Face3(0,3,1),
		Face3(3,2,1),
	};



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

		uint8_t red=   (uint8_t)(slot->skeleton->r*slot->r*255);
		uint8_t green= (uint8_t)(slot->skeleton->g*slot->g*255);
		uint8_t blue=  (uint8_t)(slot->skeleton->b*slot->b*255);
		uint8_t alpha= (uint8_t)(slot->skeleton->a*slot->a*255);

		m_material->setOpacity(m_opacity);
		m_material->setColor(Color(red,green,blue,alpha));
		render->setMaterial(m_material);
		render->bindTexture(texture,0);

		int pos_loc=m_material->getV4FLocation();
		int pos_tex=m_material->getT2FLocation();


		render->setAndEnableVertexAttrPointer(pos_loc,2,FS_FLOAT,4,0,vv);
		render->setAndEnableVertexAttrPointer(pos_tex,2,FS_FLOAT,4,0,vc);
		

		render->drawFace3(faces,2);
	}
	render->popMatrix();
}



SpineSprite::SpineSprite()
{
	m_color=Color::WHITE;
	m_opacity=1.0f;
	m_elapseTime=0.0f;
	m_stop=true;
	m_skeleton=NULL;

	m_curAnimation=NULL;
	m_duration=0.0f;

	m_data=NULL;
	m_material=NULL;
	m_mode=ANIM_START;
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
	m_material=Mat_V4F_T2F::shareMaterial();
	FS_SAFE_ADD_REF(m_material);
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
	FS_SAFE_DEC_REF(m_material);
}



















NS_FS_END




























