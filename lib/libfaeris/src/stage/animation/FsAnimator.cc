#include "FsAnimator.h"

NS_FS_BEGIN 

void FsAnimator::addAnimation(const char* name,FsAnimation* anim)
{
	FsString* f_name=FsString::create(name);
	m_animations->insert(name,anim);
}

void FsAnimator::removeAnimation(const char* name)
{
	FsString* f_name=FsString::create(name);
	m_animations->remove(f_name);
	f_name->autoDestroy();
}

void FsAnimator::startAnimation(const char* name,E_AnimPlayMode mode)
{
	FsAnimation* anim=(FsAnimation*)m_animations->lookup(name)
	if(m_defaultPlayer&&anim)
	{
		m_defaultPlayer->start(anim,mode);
	}
}

void FsAnimator::startAnimation(FsAnimation* animation,E_AnimPlayMode mode)
{
	if(m_defaultPlayer)
	{
		m_defaultPlayer->start(animation,mode);
	}
}

void FsAnimator::stopAniamtion()
{
	if(m_defaultPlayer)
	{
		m_defaultPlayer->stop();
	}
}
void FsAnimator::pauseAniamtion()
{
	if(m_defaultPlayer)
	{
		m_defaultPlayer->pause();
	}
}

void FsAnimator::playAnimation()
{
	if(m_defaultPlayer)
	{
		m_defaultPlayer->play();

	}
}

bool FsAnimator::isAnimationStop()
{
	if(m_defaultPlayer)
	{
		return m_defaultPlayer->isStop();
	}
	return true;
}

bool FsAnimator::isAnimationPause()
{
	if(m_defaultPlayer)
	{
		return m_defaultPlayer->isPause();
	}

	return true;
}

void FsAnimator::setDefaultPlayer(FsAnimationPlayer* player)
{
	FS_SAFE_ASSIGN(m_defaultPlayer,player);
}

void FsAnimator::getDefaultPlayer()
{
	return m_defaultPlayer;
}

int FsAnimator::getPlayerNu()
{
	return m_players->size();
}

FsAnimationPlayer* FsAnimator::getPlayer(int index)
{
	return (FsAnimationPlayer*)m_players->get(index)
}

void FsAnimator::addPlayer(FsAnimationPlayer* player)
{
	m_players->push(player);
}

void FsAnimator::removePlayer(FsAnimationPlayer* player)
{
	m_players->remove(player);
}

void FsAnimator::removePlayer(int index)
{
	m_players->remove(index);
}

void FsAnimator::updateAnimation(float dt)
{
	int size=m_players->size();

	for(int i=0;i<size;i++)
	{
		FsAnimationPlayer* player=(FsAnimationPlayer*)m_players->get(i);
		player->update(dt);
	}
}




FsAnimator::FsAnimator()
{
	m_animations=FsDict::create();
	FS_NO_REF_DESTORY(m_animations);

	m_players=FsArray::create();
	FS_NO_REF_DESTORY(m_players);

	m_defaultPlayer=FsAnimationPlayer::create();
	m_defaultPlayer->addRef();
}

FsAnimator::~FsAnimator()
{
	FS_DESTORY(m_animations);
	FS_DESTORY(m_players);
	m_defaultPlayer->decRef();
}










NS_FS_END 

