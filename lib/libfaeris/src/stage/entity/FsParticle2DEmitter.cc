#include "string.h"

#include "stage/entity/FsParticle2DEmitter.h"
#include "stage/entity/FsParticle2DEffect.h"
#include "sys/io/FsVFS.h"
#include "graphics/FsTexture2D.h"
#include "graphics/FsRenderDevice.h"
#include "support/util/FsDict.h"
#include "support/util/FsScriptUtil.h"
#include "support/util/FsArray.h"
#include "support/util/FsString.h"
#include "FsGlobal.h"


NS_FS_BEGIN

E_BlendFactor S_StrToBlendFactor(const char* factor)
{
	if(strcmp(factor,"Zero")==0)
	{
		return E_BlendFactor::ONE;
	}
	else if(strcmp(factor,"One")==0)
	{
		return E_BlendFactor::ONE;
	}
	else if(strcmp(factor,"SrcColor")==0)
	{
		return E_BlendFactor::SRC_COLOR;
	}
	else if(strcmp(factor,"OneMinusSrcColor")==0)
	{
		return E_BlendFactor::ONE_MINUS_SRC_COLOR;
	}
	else if(strcmp(factor,"DstColor")==0)
	{
		return E_BlendFactor::DST_COLOR;
	}
	else if(strcmp(factor,"OneMinusDstColor")==0)
	{
		return E_BlendFactor::ONE_MINUS_DST_COLOR;
	}
	else if(strcmp(factor,"SrcAlpha")==0)
	{
		return E_BlendFactor::SRC_ALPHA;
	}
	else if(strcmp(factor,"OneMinusSrcAlpha")==0)
	{
		return E_BlendFactor::ONE_MINUS_SRC_ALPHA;
	}
	else if(strcmp(factor,"DstAlpha")==0)
	{
		return E_BlendFactor::DST_ALPHA;
	}
	else if(strcmp(factor,"OneMinusDstAlpha")==0)
	{
		return E_BlendFactor::ONE_MINUS_DST_ALPHA;
	}
	else if(strcmp(factor,"SrcAlphaSaturate")==0)
	{
		return E_BlendFactor::SRC_ALPHA_SATURATE;
	}


	FS_TRACE_WARN("Unkown Factor Str(%s)",factor);
	return E_BlendFactor::ONE;

}


const char* Particle2DEmitter::className()
{
	return FS_PARTICLE2D_EMITTER_CLASS_NAME;
}





Particle2DEmitter* Particle2DEmitter::create()
{
	Particle2DEmitter* ret=new Particle2DEmitter;
	if(!ret->init())
	{
		delete ret;
		return NULL;
	}
	return ret;
}

Particle2DEmitter* Particle2DEmitter::create(const char* filename)
{
	Particle2DEmitter* ret=new Particle2DEmitter;
	if(!ret->init(filename))
	{
		delete ret;
		return NULL;
	}
	return ret;
}

Particle2DEmitter* Particle2DEmitter::create(FsFile* file)
{
	Particle2DEmitter* ret=new Particle2DEmitter;
	if(!ret->init(file))
	{
		delete ret;
		return NULL;
	}
	return ret;
}

Particle2DEmitter* Particle2DEmitter::create(FsDict* dict)
{
	Particle2DEmitter* ret= new Particle2DEmitter;
	if(!ret->init(dict))
	{
		delete ret;
		return NULL;
	}
	return ret;
}

void Particle2DEmitter::generateParticle(Particle* p)
{
	float fbegin,fend;

	memset(p,0,sizeof(*p));

	float lifetime=m_lifeTime+m_lifeTimeVar*Math::random(0.0f,1.0f);

	p->m_timeElapse=0;
	p->m_lifeTime=lifetime;

	if(lifetime==0)
	{
		return ;
	}
	
	fbegin=m_startSize+m_startSizeVar*Math::random(0.0f,1.0f);
	fend=m_endSize+m_endSizeVar*Math::random(0.0f,1.0f);

	p->m_size=fbegin;
	p->m_sizeDt=(fend-fbegin)/lifetime;

	fbegin=m_startColor.r+m_startColorVar.r*Math::random(0.0f,1.0f);
	fend=m_endColor.r+m_endColorVar.r*Math::random(0.0f,1.0f);
	p->m_colorRed=Math::clampf(fbegin/255.0f,0,1.0f);
	p->m_colorRedDt=(Math::clampf(fend/255.0f,0,1.0f)-p->m_colorRed)/lifetime;

	fbegin=m_startColor.g+m_startColorVar.g*Math::random(0.0f,1.0f);
	fend=m_endColor.g+m_endColorVar.g*Math::random(0.0f,1.0f);
	p->m_colorGreen=Math::clampf(fbegin/255.0f,0,1.0f);
	p->m_colorGreenDt=(Math::clampf(fend/255.0f,0,1.0f)-p->m_colorGreen)/lifetime;

	fbegin=m_startColor.b+m_startColorVar.b*Math::random(0.0f,1.0f);
	fend=m_endColor.b+m_endColorVar.b*Math::random(0.0f,1.0f);
	p->m_colorBlue=Math::clampf(fbegin/255.0f,0,1.0f);
	p->m_colorBlueDt=(Math::clampf(fend/255.0f,0,1.0f)-p->m_colorBlue)/lifetime;

	fbegin=m_startColor.a+m_startColorVar.a*Math::random(0.0f,1.0f);
	fend=m_endColor.a+m_endColorVar.a*Math::random(0.0f,1.0f);
	p->m_colorAlpha=Math::clampf(fbegin/255.0f,0,1.0f);
	p->m_colorAlphaDt=(Math::clampf(fend/255.0f,0,1.0f)-p->m_colorAlpha)/lifetime;



	fbegin=m_startRotation+m_startRotationVar*Math::random(0.0f,1.0f);
	fend=m_endRotation+m_endRotationVar*Math::random(0.0f,1.0f);

	p->m_rotation=fbegin;
	p->m_rotationDt=(fend-fbegin)/lifetime;

	p->m_position.x=m_position.x+m_positionVar.x*Math::random(0.0f,1.0f);
	p->m_position.y=m_position.y+m_positionVar.y*Math::random(0.0f,1.0f);
	

	p->m_startPos=p->m_position;


	p->m_envMode=m_enviromentMode;
	p->m_moveMode=m_moveMode;

	p->m_gravityMode.m_gravity=m_gravity;

	p->m_gravityMode.m_radialAcceleration=m_radialAcceleration+m_radialAccelerationVar*Math::random(0.0f,1.0f);
	p->m_gravityMode.m_tangentialAcceleration=m_tangentialAcceleration+m_tangentialAccelerationVar*Math::random(0.0f,1.0f);

	float speed=m_speed+m_speedVar*Math::random(0.0f,1.0f);
	float angle=m_angle+m_angleVar*Math::random(0.0f,1.0f);
	p->m_gravityMode.m_direction=Vector2(Math::cosa(angle)*speed,Math::sina(angle)*speed);


	fbegin=m_startRadius+m_startRadiusVar*Math::random(0.0f,1.0f);
	fend=m_endRadius+m_endRadiusVar*Math::random(0.0f,1.0f);

	p->m_radialMode.m_radius=fbegin;
	p->m_radialMode.m_radiusDt=(fend-fbegin)/m_lifeTime;
	p->m_radialMode.m_angleDt=m_rotateSpeed+m_rotateSpeedVar*Math::random(0.0f,1.0f);
	p->m_radialMode.m_angle=angle;
}



Particle2DEmitter::Particle2DEmitter()
	:m_durationTime(0),
	m_durationTimeVar(0),
	m_maxParticleNu(0),
	m_emitSpeed(0),
	m_lifeTime(0),
	m_lifeTimeVar(0),
	m_startSize(0),
	m_startSizeVar(0),
	m_endSize(0),
	m_endSizeVar(0),
	m_startColor(255,255,255,255),
	m_startColorVar(0,0,0,0),
	m_endColor(255,255,255,255),
	m_endColorVar(0,0,0,0),
	m_angle(0),
	m_angleVar(0),
	m_startRotation(0),
	m_startRotationVar(0),
	m_endRotation(0),
	m_endRotationVar(0),
	m_position(0,0),
	m_positionVar(0,0),
	m_moveMode(MOVE_GROUP),
	m_blendSrc(E_BlendFactor::SRC_ALPHA),
	m_blendDst(E_BlendFactor::ONE_MINUS_SRC_ALPHA),
	m_texture(NULL),
	m_enviromentMode(ENV_GRAVITY),
	m_speed(0),
	m_speedVar(0),
	m_gravity(0,0),
	m_radialAcceleration(0),
	m_radialAccelerationVar(0),
	m_tangentialAcceleration(0),
	m_tangentialAccelerationVar(0),
	m_startRadius(0),
	m_startRadiusVar(0),
	m_endRadius(0),
	m_endRadiusVar(0),
	m_rotateSpeed(0),
	m_rotateSpeedVar(0)
{
}

Particle2DEmitter::~Particle2DEmitter()
{
}


bool Particle2DEmitter::init()
{
	return true;
}

bool Particle2DEmitter::init(const char* filename)
{
	FsFile* file=VFS::createFile(filename);
	if(file==NULL)
	{
		FS_TRACE_WARN("can't open file:%s for particle",filename);
		return NULL;
	}
	bool ret=init(file);
	file->decRef();
	return ret;
}

bool Particle2DEmitter::init(FsFile* file)
{
	bool ret=false;
	FsDict* dict=ScriptUtil::parseScript(file);
	if(dict)
	{
		ret=init(dict);
		dict->decRef();

	}
	return ret;

}
bool Particle2DEmitter::init(FsDict* dict)
{

	if(dict==NULL)
	{
		FS_TRACE_WARN("Parse file for particle Failed");
		return false;
	}


	/* ---- emittor ------- */
	FsDict* emittor=ScriptUtil::getDict(dict,"emitter");
	if (!emittor) 
	{
		FS_TRACE_WARN("Can't Get Emmitor Infoamtion");
	}
	else 
	{
		if(!ScriptUtil::getFloat(emittor,"durationTime",&m_durationTime))
		{
			FS_TRACE_WARN("Can't Get emitter:durationTime Info");
		}
		if(!ScriptUtil::getFloat(emittor,"durationTimeVar",&m_durationTimeVar))
		{
			FS_TRACE_WARN("Can't Get emitter:durationTimeVar Info");
		}
		if(!ScriptUtil::getInteger(emittor,"emitSpeed",&m_emitSpeed))
		{
			FS_TRACE_WARN("Can't Get emitter:emitSpeed Info");
		}

		if(!ScriptUtil::getInteger(emittor,"maxParticleNu",&m_maxParticleNu))
		{
			FS_TRACE_WARN("Can't Get emittor:maxParticleNu Info");
		}
	}


	/* --- particle ----- */
	FsDict* particle=ScriptUtil::getDict(dict,"particle");
	if(!particle)
	{
		FS_TRACE_WARN("Can't Get Particle Information");
	}
	else 
	{
		if(!ScriptUtil::getFloat(particle,"lifeTime",&m_lifeTime))
		{
			FS_TRACE_WARN("Can't Get particle:lifeTime Info");
		}
		if(!ScriptUtil::getFloat(particle,"lifeTimeVar",&m_lifeTimeVar))
		{
			FS_TRACE_WARN("Can't Get particle:lifeTimeVar Info");
		}
		if(!ScriptUtil::getFloat(particle,"startSize",&m_startSize))
		{
			FS_TRACE_WARN("Can't Get particle:startSize Info");
		}
		if(!ScriptUtil::getFloat(particle,"startSizeVar",&m_startSizeVar))
		{
			FS_TRACE_WARN("Can't Get particle:startSizeVar Info");
		}
		if(!ScriptUtil::getFloat(particle,"endSize",&m_endSize))
		{
			FS_TRACE_WARN("Can't Get particle:endSize Info");
		}
		if(!ScriptUtil::getFloat(particle,"endSizeVar",&m_endSizeVar))
		{
			FS_TRACE_WARN("Can't Get particle:endSizeVar Info");
		}

		FsArray* start_color=ScriptUtil::getArray(particle,"startColor");
		if(start_color)
		{
			int r=255,g=255,b=255,a=255;
			ScriptUtil::getInteger(start_color,0,&r);
			ScriptUtil::getInteger(start_color,1,&g);
			ScriptUtil::getInteger(start_color,2,&b);
			ScriptUtil::getInteger(start_color,3,&a);
			m_startColor=Color(r,g,b,a);
		}
		else 
		{
			FS_TRACE_WARN("Can't Get particle:StartColor Info");
		}

		FsArray* start_color_var=ScriptUtil::getArray(particle,"startColorVar");
		if (start_color_var)
		{
			int r=255,g=255,b=255,a=255;
			ScriptUtil::getInteger(start_color_var,0,&r);
			ScriptUtil::getInteger(start_color_var,1,&g);
			ScriptUtil::getInteger(start_color_var,2,&b);
			ScriptUtil::getInteger(start_color_var,3,&a);
			m_startColorVar=Color(r,g,b,a);
		}
		else 
		{
			FS_TRACE_WARN("Can't Get particle:StartColrVar Info");
		}


		FsArray* end_color=ScriptUtil::getArray(particle,"endColor");
		if(end_color)
		{
			int r=255,g=255,b=255,a=255;
			ScriptUtil::getInteger(end_color,0,&r);
			ScriptUtil::getInteger(end_color,1,&g);
			ScriptUtil::getInteger(end_color,2,&b);
			ScriptUtil::getInteger(end_color,3,&a);
			m_endColor=Color(r,g,b,a);

		}
		else 
		{
			FS_TRACE_WARN("Can't Get particle:EndColor Info");
		}


		FsArray* end_color_var=ScriptUtil::getArray(particle,"endColorVar");
		if(end_color_var)
		{
			int r=255,g=255,b=255,a=255;
			ScriptUtil::getInteger(end_color_var,0,&r);
			ScriptUtil::getInteger(end_color_var,1,&g);
			ScriptUtil::getInteger(end_color_var,2,&b);
			ScriptUtil::getInteger(end_color_var,3,&a);
			m_endColorVar=Color(r,g,b,a);
		}
		else 
		{
			FS_TRACE_WARN("Can't Get particle:EndColorVar");
		}


		if(!ScriptUtil::getFloat(particle,"angle",&m_angle))
		{
			FS_TRACE_WARN("Can't Get particle:angle Info");
		}

		if(!ScriptUtil::getFloat(particle,"angleVar",&m_angleVar))
		{
			FS_TRACE_WARN("Can't Get particle:angleVar Info");
		}
		if(!ScriptUtil::getFloat(particle,"startRotation",&m_startRotation))
		{
			FS_TRACE_WARN("Can't Get particle:startRotate Info");
		}

		if(!ScriptUtil::getFloat(particle,"startRotationVar",&m_startRotationVar))
		{
			FS_TRACE_WARN("Can't Get particle:startRotationVar Info");
		}

		if(!ScriptUtil::getFloat(particle,"endRotation",&m_endRotation)) 
		{
			FS_TRACE_WARN("Can't Get particle:endRotation Info");
		}

		if(!ScriptUtil::getFloat(particle,"endRotationVar",&m_endRotationVar))
		{
			FS_TRACE_WARN("Can't Get particle:endRotationVar Info");
		}



		FsArray* position=ScriptUtil::getArray(particle,"position");
		if(position)
		{
			ScriptUtil::getFloat(position,0,&m_position.x);
			ScriptUtil::getFloat(position,1,&m_position.y);
		}
		else 
		{
			FS_TRACE_WARN("Can't Get particle:position Info");
		}

		FsArray* position_var=ScriptUtil::getArray(particle,"positionVar");
		if(position_var)
		{
			ScriptUtil::getFloat(position_var,0,&m_positionVar.x);
			ScriptUtil::getFloat(position_var,1,&m_positionVar.y);
		}
		else 
		{
			FS_TRACE_WARN("Can't Get particle:positionVar Info");
		}


		FsString* move_mode=ScriptUtil::getString(particle,"moveMode");
		if(move_mode)
		{
			if(move_mode->equal("free"))
			{
				m_moveMode=MOVE_FREE;
			}
			else if(move_mode->equal("group"))
			{
				m_moveMode=MOVE_GROUP;
			}
			else 
			{
				FS_TRACE_WARN("Error particle:moveMode Value");
			}
		}
		else 
		{
			FS_TRACE_WARN("Can't Get particle:moveMode Info");
		}
	}


	/* --- texture --- */
	FsDict* texture=ScriptUtil::getDict(dict,"texture");
	if(texture)
	{
		FsString* blendSrc=ScriptUtil::getString(texture,"blendSrc");
		if(blendSrc)
		{
			m_blendSrc=S_StrToBlendFactor(blendSrc->cstr());
		}
		else 
		{
			FS_TRACE_WARN("Can't Get blendSrc Info");
		}


		FsString* blendDst=ScriptUtil::getString(texture,"blendDst");
		if(blendDst)
		{
			m_blendDst=S_StrToBlendFactor(blendDst->cstr());
		}
		else 
		{
			FS_TRACE_WARN("Can't Get blendDst Info");
		}

		FsString* url=ScriptUtil::getString(texture,"url");
		if(url)
		{
			Texture2D* t=Global::textureMgr()->loadTexture(url->cstr());
			m_texture=t;
		}
		else 
		{
			FS_TRACE_WARN("Can't Get Texture Url");
		}


	}
	else 
	{
		FS_TRACE_WARN("Can't Find Texture Info");
	}
	

	/* ---- enviroment ----- */
	FsDict* environment=ScriptUtil::getDict(dict,"environment");
	if(environment)
	{
		FsString* mode=ScriptUtil::getString(environment,"mode");
		if(mode)
		{
			if(mode->equal("gravity"))
			{
				m_enviromentMode=ENV_GRAVITY;
			}
			else if(mode->equal("radial"))
			{
				m_enviromentMode=ENV_RADIAL;
			}
			else 
			{
				FS_TRACE_WARN("Error environment:mode value");
			}
		}
		else 
		{
			FS_TRACE_WARN("Can't Get environment:mode Info");
		}

		FsDict* gravity=ScriptUtil::getDict(environment,"gravity");
		if(gravity)
		{
			if(!ScriptUtil::getFloat(gravity,"speed",&m_speed))
			{
				FS_TRACE_WARN("Can't Get gravity:speed Info");
			}

			if(!ScriptUtil::getFloat(gravity,"speedVar",&m_speedVar))
			{
				FS_TRACE_WARN("Can't get gravity:speedVar Info");
			}

			FsArray* g=ScriptUtil::getArray(gravity,"gravity");
			if(g)
			{
				ScriptUtil::getFloat(g,0,&m_gravity.x);
				ScriptUtil::getFloat(g,1,&m_gravity.y);
			}
			else 
			{
				FS_TRACE_WARN("Can't Get gravity:gravity Info");
			}

			if(!ScriptUtil::getFloat(gravity,"radialAcceleration",&m_radialAcceleration))
			{
				FS_TRACE_WARN("Can't Get gravity:radialAcceleration Info");
			}
			if(!ScriptUtil::getFloat(gravity,"radialAccelerationVar",&m_radialAccelerationVar))
			{
				FS_TRACE_WARN("Can't Get gravity:radialAccelerationVar Info");
			}
			if(!ScriptUtil::getFloat(gravity,"tangentialAcceleration",&m_tangentialAcceleration))
			{
				FS_TRACE_WARN("Can't Get gravity::tangentialAcceleration Info");
			}
			if(!ScriptUtil::getFloat(gravity,"tangentialAccelerationVar",&m_tangentialAccelerationVar))
			{
				FS_TRACE_WARN("Can't Get gravity::tangentialAccelerationVar Info");
			}
		}
		else 
		{
			FS_TRACE_WARN("Can't Get gravity Info");
		}


		FsDict* radial=ScriptUtil::getDict(environment,"radial");
		if(radial)
		{
			if(!ScriptUtil::getFloat(radial,"startRadius",&m_startRadius))
			{
				FS_TRACE_WARN("Can't Get radial:startRadius Info");
			}
			if(!ScriptUtil::getFloat(radial,"startRadiusVar",&m_startRadiusVar))
			{
				FS_TRACE_WARN("Can't Get radial:startRadiusVar Info");
			}
			if(!ScriptUtil::getFloat(radial,"endRadius",&m_endRadius))
			{
				FS_TRACE_WARN("Can't Get radial:endRadius Info");
			}
			if(!ScriptUtil::getFloat(radial,"endRadiusVar",&m_endRadiusVar))
			{
				FS_TRACE_WARN("Can't Get radial:endRadiusVar Info");
			}
		
			if(!ScriptUtil::getFloat(radial,"rotateSpeed",&m_rotateSpeed))
			{
				FS_TRACE_WARN("Can't Get radial:rotateSpeed Info");
			}
			if(!ScriptUtil::getFloat(radial,"rotateSpeedVar",&m_rotateSpeedVar))
			{
				FS_TRACE_WARN("Can't Get radial:rotateSpeedVar Info");
			}
		}
		else 
		{
			FS_TRACE_WARN("Can't Get radial Info");
		}

	}
	else 
	{

		FS_TRACE_WARN("Can't Find Environment Info");
	}

	return true;
}

NS_FS_END
















