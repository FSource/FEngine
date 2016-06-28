#include "FsParallelAnimation.h"
#include "FsClass.h"
#include "support/util/FsArray.h"
#include "mgr/FsClassMgr.h"
#include "FsGlobal.h"

NS_FS_BEGIN 
ParallelAnimation* ParallelAnimation::create()
{
	ParallelAnimation* ret=new ParallelAnimation();
	return ret;
}

void ParallelAnimation::update(Animator* at,float time,float dt)
{
	if(time>m_totalTime)
	{
		return;
	}

	float now=time+dt;

	int size=m_animations->size();
	for(int i=0;i<size;i++)
	{
		Animation* anim=(Animation*)m_animations->get(i);
		if(time<=anim->getTimeLength())
		{
			anim->update(at,time,dt);
		}
	}
}

float ParallelAnimation::getTimeLength()
{
	return m_totalTime;
}

void ParallelAnimation::addAnimation(Animation* anim)
{
	m_animations->push(anim);
	calTotalTime();
}
void ParallelAnimation::removeAnimation(Animation* anim)
{
	m_animations->remove(anim);
	calTotalTime();
}

int ParallelAnimation::getAnimationNu()
{
	return m_animations->size();
}

Animation* ParallelAnimation::getAnimation(int index)
{
	return (Animation*) m_animations->get(index);
}

void ParallelAnimation::calTotalTime()
{
	m_totalTime=0;
	int size=m_animations->size();
	for(int i=0;i<size;i++)
	{
		Animation* anim=(Animation*)m_animations->get(i);
		float anim_time=anim->getTimeLength();
		if(anim_time>m_totalTime)
		{
			m_totalTime=anim_time;
		}
	}
}

ParallelAnimation::ParallelAnimation()
{
	m_animations=FsArray::create();
	FS_NO_REF_DESTROY(m_animations);
	m_totalTime=0;
}

ParallelAnimation::~ParallelAnimation()
{
	m_animations->destroy();
}



/** Used For ParallelAnimation Attribute **/

static ParallelAnimation* S_ParallelAnimation_NewInstance(FsDict* attr)
{
	ParallelAnimation* ret=ParallelAnimation::create();
	if(ret)
	{
		ret->setAttributes(attr);
	}
	return ret;
}

static  void S_ParallelAnimation_setSubAnimation(ParallelAnimation* at,FsArray* attr)
{
	int size=attr->size();

	for(int i=0;i<size;i++)
	{
		FsDict* dict=attr->getDict(i);
		if(dict)
		{
			FsObject* ob=Global::classMgr()->newInstance(dict);
			if(ob)
			{
				Animation* anim=dynamic_cast<Animation*>(ob);
				if(anim)
				{
					at->addAnimation(anim);
				}
				else 
				{
					FS_TRACE_WARN("Not SubClass Of Animation,type is (%s) Ingore Item(%d)",ob->className(),i);
					ob->destroy();
				}
			}
		}
		else 
		{
			FS_TRACE_WARN("Not Dict,Ingore Item(%d)",i);
		}
	}
}

static FsClass::FsAttributeDeclare S_ParallelAnimation_Main_Attr[]={
	FS_CLASS_ATTR_DECLARE("subAnimations",E_FsType::FT_ARRAY,NULL,S_ParallelAnimation_setSubAnimation,0),
	FS_CLASS_ATTR_DECLARE(NULL,E_FsType::FT_IN_VALID,NULL,0,0)
};

FS_CLASS_IMPLEMENT_WITH_BASE(ParallelAnimation,Animation,S_ParallelAnimation_NewInstance,S_ParallelAnimation_Main_Attr);

NS_FS_END 














