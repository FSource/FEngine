#include <assert.h>
#include "stage/entity/FsParticle2DEffect.h"
#include "stage/entity/FsParticle2DEmitter.h"
#include "math/FsMathUtil.h"
#include "math/FsVertices.h"
#include "graphics/FsRenderDevice.h"
#include "graphics/shader/FsStreamMap.h"
#include "graphics/shader/FsProgram.h"

#include "FsGlobal.h"
#include "mgr/FsProgramSourceMgr.h"

NS_FS_BEGIN


const char* Particle2DEffect::className()
{
	return FS_PARTICLE2D_EFFECT_CLASS_NAME;
}


Particle2DEffect* Particle2DEffect::create(const char* filename)
{
	Particle2DEmitter* emit=Particle2DEmitter::create(filename);
	if( emit==NULL) 
	{
		FS_TRACE_WARN("Create Emitter For File(%s) Failed",filename);
		return NULL;
    }

	Particle2DEffect* ret=Particle2DEffect::create(emit);
	emit->autoDestroy();
	return ret;
}

Particle2DEffect* Particle2DEffect::create(FsFile* file)
{
	Particle2DEmitter* emit=Particle2DEmitter::create(file);
	if(emit==NULL)
	{
		FS_TRACE_WARN("create Emiit for Failed");
		return NULL;
	}

	Particle2DEffect* ret=Particle2DEffect::create(emit);
	emit->autoDestroy();
	return ret;
}


Particle2DEffect* Particle2DEffect::create(Particle2DEmitter* emitter)
{
	Particle2DEffect* ret=new Particle2DEffect;
	if(!ret->init(emitter))
	{
		delete ret;
	}
	return ret;
}


Particle2DEffect* Particle2DEffect::create()
{
	Particle2DEffect* ret=new Particle2DEffect;
	if(!ret->init(NULL))
	{
		delete ret;
	}
	return ret;
}



Particle2DEffect::Particle2DEffect()
{
	m_maxParticles=0;
	m_emitSpeed=0;
	m_lifeTime=0;
	m_elapseTime=0;
	m_opacity=1.0;

	m_emitter=NULL;

	m_stop=true;
	m_pause=false;
	m_autoRemove=true;

	m_material=Material2D::create();
	m_material->addRef();

	static ProgramSource* S_programSource=NULL;
	if(S_programSource==NULL)
	{
		S_programSource=(ProgramSource*)Global::programSourceMgr()->load(FS_PRE_PROGRAM_SOURCE_PARTICLE);
	}

	setProgramSource(S_programSource);
}


Particle2DEffect::~Particle2DEffect()
{
	destruct();
}

bool Particle2DEffect::init(Particle2DEmitter* emitter)
{
	FS_SAFE_ASSIGN(m_emitter,emitter);
	return true;
}

void Particle2DEffect::destruct()
{
	FS_SAFE_DEC_REF(m_emitter);
	m_emitter=NULL;

}

void Particle2DEffect::start(bool restart)
{
	if(!m_emitter)
	{
		m_stop=true;
		FS_TRACE_WARN("no emitter find, start faild");
		return;
	}
	if(restart||m_stop)
	{
		m_lifeTime=m_emitter->getDurationTime()+m_emitter->getDurationTimeVar()*Math::random(0.0f,1.0f);
		m_emitSpeed=m_emitter->getEmitSpeed();
		m_maxParticles=m_emitter->getMaxParticleNu();
		m_particles.clear();
		m_elapseTime=0.0f;
		m_generateParticle=0.0f;
	}
	m_stop=false;
	m_pause=false;
}

void Particle2DEffect::refresh()
{
	if(!m_emitter)
	{
		return;
	}
	m_lifeTime=m_emitter->getDurationTime()+m_emitter->getDurationTimeVar()*Math::random(0.0f,1.0f);
	m_emitSpeed=m_emitter->getEmitSpeed();
	m_maxParticles=m_emitter->getMaxParticleNu();
}

void Particle2DEffect::stop()
{
	m_stop=true;
}


void Particle2DEffect::setPause(bool pause)
{
	m_pause=pause;
}


bool Particle2DEffect::isPause()
{
	return m_pause;
}

bool Particle2DEffect::isStop()
{
	return m_stop;
}


float Particle2DEffect::getLifeTime()
{
	return m_lifeTime;
}



float Particle2DEffect::getElapseTime()
{
	return m_elapseTime;
}


int Particle2DEffect::getMaxParticleNu()
{
	return m_maxParticles;
}




void Particle2DEffect::setEmitter(Particle2DEmitter* emit)
{
	FS_SAFE_ASSIGN(m_emitter,emit);
	m_stop=true;
	m_pause=false;
}

Particle2DEmitter* Particle2DEffect::getEmitter()
{
	return m_emitter;
}

void Particle2DEffect::setAutoRemoveOnStop(bool remove)
{
	m_autoRemove=remove;
}

void Particle2DEffect::finish()
{

}



void Particle2DEffect::update(float dt)
{
	updateWorldMatrix();

	if(m_stop||m_pause)
	{
		return ;
	}

	/* update particle */
	int size=m_particles.size();
	unsigned int i=0;
	int pos=0;
	Particle* p=NULL;

	while(pos<size)
	{
		p=&m_particles[i];

		float d=dt;
		float  finish=false;
		if(p->m_timeElapse+d>p->m_lifeTime)
		{
			d=p->m_lifeTime-p->m_timeElapse;
			finish=true;
		}

		updateParticle(p,d);

		if(finish)
		{

			if(m_particles.size()-1>i)
			{
				m_particles[i]=m_particles[m_particles.size()-1];
			}
			m_particles.pop_back();
		}
		else 
		{
			i++;
		}
		pos++;
	}

	/* generate particle */
	generateParticle(dt);

	
	/* check particle stop */
	if ( ( m_lifeTime > 0 ) && (m_elapseTime > m_lifeTime ))
	{
		/* no particle exist,so will set the state to stop */
		if (m_particles.size()==0) 
		{
			m_stop=true;
			finish();
			if(m_autoRemove)
			{
				Entity::detach();
			}
		}
	}
}


void Particle2DEffect::updateParticle(Particle* p,float dt)
{
	p->m_timeElapse+=dt;

	p->m_size+=p->m_sizeDt*dt;
	if(p->m_size<0 )
	{
		p->m_size=0.0f;
	}

	p->m_colorRed+=p->m_colorRedDt*dt;
	p->m_colorGreen+=p->m_colorGreenDt*dt;
	p->m_colorBlue+=p->m_colorBlueDt*dt;
	p->m_colorAlpha+=p->m_colorAlphaDt*dt;


	p->m_rotation+=p->m_rotationDt*dt;


	/* gravity mode */
	if(p->m_envMode==Particle2DEmitter::ENV_GRAVITY)
	{
		Vector2 radial=Vector2(0,0);
		if(p->m_position.x || p->m_position.y) 
		{
			radial=p->m_position;
			radial.normalize();
		}

		Vector2 tangent=Vector2(-radial.y,radial.x);

		p->m_gravityMode.m_direction+=
						tangent*p->m_gravityMode.m_tangentialAcceleration*dt+
					    radial *p->m_gravityMode.m_radialAcceleration*dt+ 
					    p->m_gravityMode.m_gravity*dt;

		p->m_position+=p->m_gravityMode.m_direction*dt;
	}

	/* radial mode */
	else if (p->m_envMode==Particle2DEmitter::ENV_RADIAL)
	{
		p->m_radialMode.m_radius+=p->m_radialMode.m_radiusDt*dt;
		p->m_radialMode.m_angle+=p->m_radialMode.m_angleDt*dt;

		p->m_position=Vector2(-Math::cosa(p->m_radialMode.m_angle),
							   -Math::sina(p->m_radialMode.m_angle))*p->m_radialMode.m_radius;

	}
	else 
	{
		FS_TRACE_WARN("Error Env Mode");
	}
}

void Particle2DEffect::generateParticle(float dt)
{
	if(m_elapseTime>m_lifeTime)
	{
		return;
	}

	float diff;
	if(m_lifeTime>0)
	{
		if(m_elapseTime+dt>m_lifeTime)
		{
			diff=m_lifeTime-m_elapseTime;
		}
		else 
		{
			diff=dt;
		}
	}
	else 
	{
		diff=dt;
	}

	assert(diff>=0);

	m_generateParticle+=m_emitSpeed*diff;

    int generate_nu=(int)floor(m_generateParticle);
    m_generateParticle-=generate_nu;


    float per_diff=1.0f/(float)m_emitSpeed;
    int particle_size=m_particles.size();


	if(generate_nu+particle_size>m_maxParticles)
	{
        generate_nu=m_maxParticles-particle_size;

    }
	if(generate_nu<0)	
    {
        generate_nu=0;
    }
	
	int new_size=generate_nu+particle_size;

	m_particles.resize(new_size);
	FS_TRACE_ERROR_ON(m_particles.size()!=(unsigned int)new_size,"std::vector.resize Error ");

	/* FIXME: this is a bug, when engine build in debug mode and used as a static library 
	 *        for other application, if the application build with debug mode, std::vector.size() 
	 *        function will work Ok, but if application build with release mode, std::vector size()
	 *        function will not work, I don't kown how to solve it 
	 */


	Vector2 start_pos=Vector2(m_worldMatrix.m03,m_worldMatrix.m13);

	for(int i=0;i<generate_nu;i++)
	{
		Particle* p=&m_particles[i+particle_size];
		m_emitter->generateParticle(p);
		p->m_startPos=start_pos;
		updateParticle(p,per_diff*i);
	}
	

	m_elapseTime+=dt;


}
void Particle2DEffect::draw(RenderDevice* rd,bool update_world_matrix)
{
	Program* prog=getProgram(NULL);
	if(!m_emitter||!m_material||!prog)
	{
		return;
	}
	if(m_stop||m_particles.size()==0)
	{
		return;
	}

	Texture2D* texture=m_emitter->getTexture();
	if(texture==NULL)
	{
		return;
	}
	if(update_world_matrix)
	{
		updateWorldMatrix();
	}


	rd->setWorldMatrix(&m_worldMatrix);

	rd->setProgram(prog);

	m_material->configRenderDevice(rd);

	rd->bindTexture(texture,0);
	rd->setBlend(E_BlendEquation::ADD,m_emitter->getBlendSrc(),m_emitter->getBlendDst());


	static TexCoord2 t[4]={
		TexCoord2(0.0f,0.0f),
		TexCoord2(0.0f,1.0f),
		TexCoord2(1.0f,1.0f),
		TexCoord2(1.0f,0.0f),
	};

	int particle_nu=m_particles.size();
	m_vertics.resize(particle_nu*4);

	int face_nu=m_faces.size();
	int face_need_nu=particle_nu*2;
	m_faces.resize(face_need_nu);
	if(face_nu<face_need_nu)
	{
		int f_start=face_nu/2;
		int f_end=particle_nu;

		for(int i=f_start;i<f_end;i++)
		{
			int p_index=i*4;
			m_faces[i*2].set(p_index,p_index+1,p_index+2);
			m_faces[i*2+1].set(p_index+2,p_index+3,p_index);
		}
	}


	for(int i=0;i<particle_nu;i++)
	{
		Particle&  p=m_particles[i];

		float x,y;

		if( m_particles[i].m_moveMode== Particle2DEmitter::MOVE_FREE)
		{
			Vector2 cur_pos=Vector2(m_worldMatrix.m03,m_worldMatrix.m13);
			x=p.m_position.x-(cur_pos.x-p.m_startPos.x);
			y=p.m_position.y-(cur_pos.y-p.m_startPos.y);
		}
		else 
		{
			x=p.m_position.x;
			y=p.m_position.y;
		}

		float hsize=p.m_size/2;
		float dx=hsize,dy=hsize;
		float angle=p.m_rotation;

		for(int j=0;j<4;j++)
		{
			m_vertics[i*4+j].c4.set(p.m_colorRed,p.m_colorGreen,p.m_colorBlue,p.m_colorAlpha);
			m_vertics[i*4+j].t2=t[j];
		}

		if(!Math::floatEqual(angle,0))
		{

			float cos_o=Math::cosa(angle);
			float sin_o=Math::sina(angle);
			dx=(cos_o-sin_o)*hsize;
			dy=(cos_o+sin_o)*hsize;
		}

		m_vertics[i*4+0].v2.set( x-dy,y+dx);
		m_vertics[i*4+1].v2.set( x-dx,y-dy);
		m_vertics[i*4+2].v2.set( x+dy,y-dx);
		m_vertics[i*4+3].v2.set( x+dx,y+dy);
	}

	rd->disableAllAttrArray();

	StreamMap* map_v=prog->getStreamMap(E_StreamType::VERTICES);
	StreamMap* map_u=prog->getStreamMap(E_StreamType::UVS);
	StreamMap* map_c=prog->getStreamMap(E_StreamType::COLORS);

	int count=particle_nu*4;

	if(map_v)
	{
		rd->setAndEnableVertexAttrPointer(map_v->m_location,2,FS_FLOAT,
									count,sizeof(Fs_V2F_T2F_C4F),m_vertics[0].v2.v);
	}
	if(map_u)
	{
		rd->setAndEnableVertexAttrPointer(map_u->m_location,2,FS_FLOAT,
									count,sizeof(Fs_V2F_T2F_C4F),m_vertics[0].t2.v);
	}
	if(map_c)
	{
		rd->setAndEnableVertexAttrPointer(map_c->m_location,4,FS_FLOAT,
									count,sizeof(Fs_V2F_T2F_C4F),m_vertics[0].c4.v);
	}

	/*
	for(int i=0;i<particle_nu;i++)
	{
		rd->drawArray(E_DrawMode::TRIANGLE_STRIP,i*4,4);
	}
	*/


	rd->drawFace3(&m_faces[0],m_faces.size());

}


NS_FS_END 


















