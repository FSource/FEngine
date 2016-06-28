#include "FsAnimator.h"
#include "FsAnimation.h"
#include "FsAnimationEvent.h"
#include "FsAnimationPlayer.h"
#include "support/util/FsArray.h"
#include "support/util/FsDict.h"
#include "support/util/FsString.h"
#include "FsGlobal.h"
#include "mgr/FsClassMgr.h"
#include "FsClass.h"


NS_FS_BEGIN 

void Animator::addAnimation(const char* name,Animation* anim)
{
	FsString* f_name=FsString::create(name);
	m_animations->insert(f_name,anim);
}

void Animator::removeAnimation(const char* name)
{
	FsString* f_name=FsString::create(name);
	m_animations->remove(f_name);
	f_name->autoDestroy();
}

void Animator::clearAnimation()
{
	m_animations->clear();
}

Animation* Animator::getAnimation(const char* name)
{
	return (Animation*) m_animations->lookup(name);
}


FsDict* Animator::getAnimations()
{
	return m_animations;
}


void Animator::startAnimation(const char* name,E_AnimPlayMode mode)
{
	Animation* anim=(Animation*)m_animations->lookup(name);
	if(m_defaultPlayer)
	{
		if(anim)
		{
			m_defaultPlayer->start(anim,mode);
		}
		else 
		{
			m_defaultPlayer->stop();
		}
	}
}

void Animator::startAnimation(Animation* animation,E_AnimPlayMode mode)
{
	if(m_defaultPlayer)
	{
		m_defaultPlayer->start(animation,mode);
	}
}

void Animator::stopAniamtion()
{
	if(m_defaultPlayer)
	{
		m_defaultPlayer->stop();
	}
}
void Animator::pauseAniamtion()
{
	if(m_defaultPlayer)
	{
		m_defaultPlayer->pause();
	}
}

void Animator::playAnimation()
{
	if(m_defaultPlayer)
	{
		m_defaultPlayer->play();

	}
}

bool Animator::isAnimationStop()
{
	if(m_defaultPlayer)
	{
		return m_defaultPlayer->isStop();
	}
	return true;
}

bool Animator::isAnimationPause()
{
	if(m_defaultPlayer)
	{
		return m_defaultPlayer->isPause();
	}

	return true;
}

void Animator::setDefaultPlayer(AnimationPlayer* player)
{
	FS_SAFE_ASSIGN(m_defaultPlayer,player);
}

AnimationPlayer* Animator::getDefaultPlayer()
{
	return m_defaultPlayer;
}

int Animator::getPlayerNu()
{
	return m_players->size();
}

AnimationPlayer* Animator::getPlayer(int index)
{
	return (AnimationPlayer*)m_players->get(index);
}

void Animator::addPlayer(AnimationPlayer* player)
{
	m_players->push(player);
}

void Animator::removePlayer(AnimationPlayer* player)
{
	m_players->remove(player);
}

void Animator::removePlayer(int index)
{
	m_players->remove(index);
}


bool Animator::animationEvent(AnimationEvent* event)
{
	E_AnimEventType type=event->getEventType();

	if(type==E_AnimEventType::ATTRIBUTE)
	{
		const FsVariant& value=((AttributeAnimationEvent*)event)->getValue();
		const char* attr_name= ((AttributeAnimationEvent*)event)->getAttributeName();
		setAttribute(attr_name,value);
		return true;
	}
	return false;
}


void Animator::updateAnimation(float dt)
{
	int size=m_players->size();

	for(int i=0;i<size;i++)
	{
		AnimationPlayer* player=(AnimationPlayer*)m_players->get(i);
		player->update(this,dt);
	}
}



Animator::Animator()
{
	m_animations=FsDict::create();
	FS_NO_REF_DESTROY(m_animations);

	m_players=FsArray::create();
	FS_NO_REF_DESTROY(m_players);

	m_defaultPlayer=AnimationPlayer::create();
	m_defaultPlayer->addRef();

	m_players->push(m_defaultPlayer);

	onAnimationEvent=nullptr;

}

Animator::~Animator()
{
	FS_DESTROY(m_animations);
	FS_DESTROY(m_players);
	m_defaultPlayer->decRef();
}


/** Used For  Animator Attribute **/

static void Animator_setAnimations(Animator* at,FsDict* attr)
{
	at->clearAnimation();

	FsDict::Iterator* iter=attr->takeIterator();
	while(!iter->done())
	{
		FsObject* key=iter->getKey();
		FsObject* value=iter->getValue();
		if(!FsString::checkType(key)||!FsDict::checkType(value))
		{
			FS_TRACE_WARN("Error Type For Key(%s),Value(%s)",key->className(),value->className());
			iter->next();
			continue;
		}

		FsString* name=(FsString*) key;
		FsDict* dict=(FsDict*) value;

		FsObject* ob_an =Global::classMgr()->newInstance(dict);
		if(ob_an)
		{
			Animation* anim=dynamic_cast<Animation*>(ob_an);
			if(anim)
			{
				at->addAnimation(name->cstr(),anim);
			}
			else 
			{
				FS_TRACE_WARN("Can't Cast Type(%s) To Animation",ob_an->className());
			}
		}
		iter->next();
	}
	delete iter;
}


static FsClass::FsAttributeDeclare S_Animator_Main_Attr[]={
	FS_CLASS_ATTR_DECLARE("animations",E_FsType::FT_DICT,NULL,Animator_setAnimations,0),

	FS_CLASS_ATTR_DECLARE(NULL,E_FsType::FT_IN_VALID,NULL,0,0)
};

FS_CLASS_IMPLEMENT_WITH_BASE(Animator,FsObject,0,S_Animator_Main_Attr);


NS_FS_END 

