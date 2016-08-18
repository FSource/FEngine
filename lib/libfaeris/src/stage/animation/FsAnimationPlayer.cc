#include "FsAnimationPlayer.h"
#include "FsAnimation.h"

NS_FS_BEGIN 

AnimationPlayer* AnimationPlayer::create()
{
	AnimationPlayer* ret=new AnimationPlayer();
	return ret;
}

void AnimationPlayer::start(Animation* animation,E_AnimPlayMode mode)
{
	FS_ASSERT(animation!=NULL);
	FS_SAFE_ASSIGN(m_animation,animation);

	m_mode=mode;

	m_time=0;
	m_animTotalTime=animation->getTimeLength();

	m_isStop=false;
	m_isPause=false;
}

void AnimationPlayer::stop()
{
	m_isStop=true;
	m_isPause=true;
}
void AnimationPlayer::pause()
{
	m_isPause=true;
}

void AnimationPlayer::play()
{
	if(m_isStop)
	{
		return;
	}

	m_isPause=false;
}

bool AnimationPlayer::isPause()
{
	return m_isPause;
}

bool AnimationPlayer::isStop()
{
	return m_isStop;
}

void AnimationPlayer::update(Animator* target,float dt)
{
	if(m_isStop||m_isPause)
	{
		return;
	}

	switch(m_mode)
	{
		case E_AnimPlayMode::NORMAL:
			{
				m_animation->update(target,m_time,dt);
				m_time+=dt;
				if(m_time>=m_animTotalTime)
				{
					m_isStop=true;
					m_isPause=true;
				}

				break;
			}
		case E_AnimPlayMode::LOOP:
			{
				float time=Math::fmod(m_time,m_animTotalTime);
				m_animation->update(target,time,dt);

				if(time+dt>m_animTotalTime)
				{
					m_animation->update(target,0,time+dt-m_animTotalTime);
				}

				m_time+=dt;

			}

	}


}

AnimationPlayer::AnimationPlayer()
{
	m_mode=E_AnimPlayMode::NORMAL;
	m_animation=NULL;
	m_time=0;
	m_animTotalTime=0;
	m_isStop=true;
	m_isPause=true;
}

AnimationPlayer::~AnimationPlayer()
{
	FS_SAFE_DEC_REF(m_animation);
}
















NS_FS_END 
