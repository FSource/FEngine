#include "FsMacros.h"
#include "FsAudioEngine.h"


NS_FS_BEGIN

const char* AudioEngine::className()
{
	return "AudioEngine";
}

AudioEngine* AudioEngine::create(int channel_nu)
{
	AudioEngine* ret=new AudioEngine;
	if(!ret->init(channel_nu))
	{
		delete ret;
		return NULL;
	}
	return ret;
}

/* load and unload sound */
int AudioEngine::loadSound(const char* name)
{
	SoundSet::iterator iter=m_sounds.find(name);
	if(iter==m_sounds.end())
	{
		Sound* sound=m_player->createSound(name);
		if(!sound)
		{
			return -1;
		}
		else 
		{
			m_sounds[name]=sound;
			return 0;
		}
	}
	return 0;
}

int AudioEngine::unloadSound(const char* name)
{
	SoundSet::iterator iter=m_sounds.find(name);
	if(iter==m_sounds.end())
	{
		FS_TRACE_WARN("Sound (%s) Not Load",name);
		return -1;
	}
	m_player->releaseSound(iter->second);
	m_sounds.erase(name);
	return 0;
}


int AudioEngine::unloadSounds()
{
	SoundSet::iterator iter;
	for(iter=m_sounds.begin();iter!=m_sounds.end();++iter)
	{
		m_player->releaseSound(iter->second);
	}
	m_sounds.clear();
	return 0;
}


Channel* AudioEngine::playSound(const char* name,int loop,int priority)
{
	SoundSet::iterator iter=m_sounds.find(name);
	if(iter==m_sounds.end())
	{
		FS_TRACE_WARN("Sound(%s) Not Load",name);
		return NULL;
	}

	return m_player->playSound(iter->second,loop,priority);
}
void AudioEngine::pauseChannel(Channel* c)
{
	m_player->pauseChannel(c);
}
void AudioEngine::resumeChannel(Channel* c)
{
	m_player->resumeChannel(c);
}
void AudioEngine::stopChannel(Channel* c)
{
	m_player->stopChannel(c);
}

void AudioEngine::setChannelVolume(Channel* c,float value)
{
	m_player->setChannelVolume(c,value);
}

float AudioEngine::getChannelVolume(Channel* c)
{
	return m_player->getChannelVolume(c);
}

void AudioEngine::pauseChannels()
{
	m_player->pauseChannels();
}
void AudioEngine::resumeChannels()
{
	m_player->resumeChannels();
}
void AudioEngine::stopChannnels()
{
	m_player->stopChannnels();
}

void AudioEngine::setVolume(float value)
{
	m_player->setVolume(value);
}


AudioEngine::AudioEngine()
{
	m_player=0;
	m_bgm=NULL;
	m_bgmName=std::string("");
	m_bgmLoop=true;
}





AudioEngine::~AudioEngine()
{
	destory();
}

bool AudioEngine::init(int channel_nu)
{
	m_player=AudioPlayer::create(channel_nu);

	if(m_player)
	{
		return true;
	}
	else 
	{
		return false;
	}
}


void AudioEngine::destory()
{
	if(m_player)
	{
		unloadSounds();
		if(m_bgm)
		{
			m_player->releaseMusic(m_bgm);
			m_player=NULL;
		}
		delete m_player;
		m_player=NULL;
	}
}

void AudioEngine::playBackgroundMusic(const char* name,bool loop)
{
	if(m_bgm&&(std::string(name)==m_bgmName))
	{
		m_player->playMusic(m_bgm,loop);
	}
	else 
	{
		if(m_bgm)
		{
			m_player->releaseMusic(m_bgm);
			m_bgm=NULL;
			m_bgmName="";
		}
		Music* music=m_player->createMusic(name);
		if(music)
		{
			m_player->playMusic(music,loop);
			m_bgmName=std::string(name);
			m_bgm=music;
		}
	}
	m_bgmLoop=loop;
	
}

void AudioEngine::stopBackgroundMusic()
{
	if(m_bgm)
	{
		m_player->stopMusic(m_bgm);
	}

}

void AudioEngine::pauseBackgroundMusic()
{
	if(m_bgm)
	{
		m_player->pauseMusic(m_bgm);
	}

}

void AudioEngine::resumeBackgroundMusic()
{
	if(m_bgm)
	{
		m_player->resumeMusic(m_bgm);
	}
}

void AudioEngine::rewindBackgroundMusic()
{
	if(m_bgm)
	{
		m_player->playMusic(m_bgm,m_bgmLoop);
	}
}



NS_FS_END


































