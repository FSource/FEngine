
#include <string.h>

#include "fmod/fmod.hpp"
#include "fmod/fmod_errors.h"

#include "FsMacros.h"
#include "FsFmodPlayer.h"

#include "sys/io/FsVFS.h"


#define FS_MAX_MUSIC_CHANNEL_NU 1


NS_FS_BEGIN

class Music 
{
	public:
		Music(int id,FMOD::Sound* sound)
		{
			m_id=id;
			m_sound=sound;
		}
	public:
		int m_id;
		FMOD::Sound* m_sound;
		float m_volume;
};

FmodPlayer* FmodPlayer::create(int channel_nu)
{
	FmodPlayer* ret=new FmodPlayer;
	if(!ret->init(channel_nu))
	{
		delete ret;
		return NULL;
	}
	return ret;
}

Sound* FmodPlayer::createSound(const char* filename)
{
	update();
	FMOD_RESULT result;
	FMOD::Sound* sound=NULL;
	FMOD_CREATESOUNDEXINFO exinfo;


	FsFile* file=VFS::createFile(filename);
	if(file==NULL)
	{
		FS_TRACE_WARN("Open File %s For Load Sound Failed",filename);
		return NULL;

	}
	int length=file->getLength();
	if(length<=0)
	{
		FS_TRACE_WARN("No File Content");
		file->decRef();
		return NULL;
	}


	char* buffer=new  char[length];
	int readbyte=file->read(buffer,length);
	file->decRef(); /* file is no used */

	if(readbyte!=length)
	{
		FS_TRACE_WARN("Can't load %d byte For Sound File,Only %d byte Loaded",length,readbyte);
		delete[] buffer;
		return NULL;
	}

	memset(&exinfo, 0, sizeof(FMOD_CREATESOUNDEXINFO));
    exinfo.cbsize = sizeof(FMOD_CREATESOUNDEXINFO);
    exinfo.length = length;    


	result=m_sounds->createSound(buffer,FMOD_LOOP_NORMAL |FMOD_OPENMEMORY,&exinfo,&sound);
	delete[] buffer; /* buffer is no used */


	if(result!=FMOD_OK)
	{
		FS_TRACE_WARN("FMOD error! (%d) %s", result, FMOD_ErrorString(result));
		return NULL;
	}
	return (Sound*) sound;
}

void FmodPlayer::releaseSound(Sound* s)
{
	update();
	FMOD_RESULT result;
	FMOD::Sound* sound=(FMOD::Sound*) s;
	result=sound->release();

	if(result!=FMOD_OK)
	{
		FS_TRACE_WARN("FMOD error! (%d) %s", result, FMOD_ErrorString(result));
	}
}


Channel* FmodPlayer::playSound(Sound* s,int loop,int priority)
{
	update();
	FMOD_RESULT result;
	FMOD::Channel* channel=NULL;
	FMOD::Sound* sound=NULL;

	sound= (FMOD::Sound*) s;
	result=m_sounds->playSound(FMOD_CHANNEL_FREE,sound,true,&channel);


	if(result!=FMOD_OK)
	{
		FS_TRACE_WARN("FMOD error! (%d) %s", result, FMOD_ErrorString(result));
		return NULL;
	}

	channel->setChannelGroup(m_channelGroup);
	channel->setLoopCount(loop);
	switch(priority)
	{
		case PRIORITY_HIGH:
			channel->setPriority(0);
			break;
		case PRIORITY_MIDDLE: 
			channel->setPriority(128);
			break;
		case PRIORITY_LOW:
			channel->setPriority(256);
			break;
	}

	channel->setPaused(false);
	return (Channel*) channel;
}


void FmodPlayer::pauseChannel(Channel* c)
{
	update();
	FMOD::Channel* channel=(FMOD::Channel*) c;
	channel->setPaused(true);
}

void FmodPlayer::resumeChannel(Channel* c)
{
	update();
	FMOD::Channel* channel=(FMOD::Channel*) c;
	channel->setPaused(false);
}

void FmodPlayer::stopChannel(Channel* c)
{
	update();
	FMOD::Channel* channel=(FMOD::Channel*) c;
	channel->stop();
}

void FmodPlayer::setChannelVolume(Channel* c,float value)
{
	update();
	FMOD::Channel* channel=(FMOD::Channel*) c;
	channel->setVolume(value);
}
float FmodPlayer::getChannelVolume(Channel* c)
{
	update();
	FMOD::Channel* channel=(FMOD::Channel*) c;
	float volume;
	channel->getVolume(&volume);
	return volume;
}


void FmodPlayer::pauseChannels()
{
	update();
	m_channelGroup->setPaused(true);
}
void FmodPlayer::resumeChannels()
{
	update();
	m_channelGroup->setPaused(false);
}
void FmodPlayer::stopChannnels()
{
	update();
	m_channelGroup->stop();
}

void FmodPlayer::setVolume(float value)
{
	update();
	m_channelGroup->setVolume(value);
}

FmodPlayer::FmodPlayer()
{
	m_sounds=NULL;
	m_channelGroup=NULL;
	m_channelNu=0;
	m_musics=NULL;
}

FmodPlayer::~FmodPlayer()
{
	destory();
}

bool FmodPlayer::init(int channel_nu)
{
	FMOD_RESULT result;
	FMOD::ChannelGroup* master_grounp;

	do 
	{ /* create m_sounds */
		result=FMOD::System_Create(&m_sounds);

		if(result!=FMOD_OK)
		{
			FS_TRACE_WARN("Init SOUND SYSTEM Failed");
			goto error;
		}


		result=m_sounds->init(channel_nu,FMOD_INIT_NORMAL,0);
		if(result!=FMOD_OK)
		{
			FS_TRACE_WARN("Init Sound Failed");
			goto error;
		}


		result=m_sounds->createChannelGroup("ChannelGroup",&m_channelGroup);
		if(result!=FMOD_OK)
		{
			FS_TRACE_WARN("create ChannelGroup Failed");
			goto error;
		}

		result = m_sounds->getMasterChannelGroup(&master_grounp);
		if(result!=FMOD_OK)
		{
			FS_TRACE_WARN("getMasterChannelGroup Failed");
			goto error;
		}

		result= master_grounp->addGroup(m_channelGroup);
		if(result!=FMOD_OK)
		{
			FS_TRACE_WARN("add to Master Grounp Failed");
			goto error;
		}

		m_channelNu=channel_nu;
	}while(0);

    
    /*
	do
	{
		result=FMOD::System_Create(&m_musics);
		if(result!=FMOD_OK)
		{
			FS_TRACE_WARN("Init MUSIC SYSTEM Failed");
			goto error;
		}
		result=m_musics->init(FS_MAX_MUSIC_CHANNEL_NU,FMOD_INIT_NORMAL,0);
		if(result!=FMOD_OK)
		{
			FS_TRACE_WARN("Init Music Failed");
			goto error;
		}
		m_musicChannelUsed.resize(FS_MAX_MUSIC_CHANNEL_NU);

	}while(0);
     */
    m_musics=m_sounds;




	return true;

error:
	destory();
	FS_TRACE_WARN("FMOD error! (%d) %s", result, FMOD_ErrorString(result));
	return false;
}
void FmodPlayer::destory()
{
	if(m_channelGroup) 
	{
		m_channelGroup->release();
		m_channelGroup=NULL;
	}

	if(m_sounds)
	{
		m_sounds->close();
		m_sounds->release();
		m_sounds=NULL;
	}
    /*
	if(m_musics)
	{
		m_musics->close();
		m_musics->release();
		m_musics=NULL;
	}
     */
}




/* music part */


Music* FmodPlayer::createMusic(const char* filename)
{
	update();
	int music_id=getFreeMusicId();
	if(music_id==-1)
	{
		FS_TRACE_WARN("Max Music Create(%d)",FS_MAX_MUSIC_CHANNEL_NU);
		return NULL;
	}

	FMOD_RESULT result;
	FMOD::Sound* sound=NULL;
	FMOD_CREATESOUNDEXINFO exinfo;


	FsFile* file=VFS::createFile(filename);
	if(file==NULL)
	{
		FS_TRACE_WARN("Open File %s For Load Sound Failed",filename);
		return NULL;

	}
	int length=file->getLength();
	if(length<=0)
	{
		FS_TRACE_WARN("No File Content");
		file->decRef();
		return NULL;
	}


	char* buffer=new  char[length];
	int readbyte=file->read(buffer,length);
	file->decRef(); /* file is no used */

	if(readbyte!=length)
	{
		FS_TRACE_WARN("Can't load %d byte For Sound File,Only %d byte Loaded",length,readbyte);
		delete[] buffer;
		return NULL;
	}

	memset(&exinfo, 0, sizeof(FMOD_CREATESOUNDEXINFO));
    exinfo.cbsize = sizeof(FMOD_CREATESOUNDEXINFO);
    exinfo.length = length;    


	result=m_musics->createSound(buffer,FMOD_LOOP_NORMAL |FMOD_OPENMEMORY,&exinfo,&sound);
	delete[] buffer; /* buffer is no used */


	if(result!=FMOD_OK)
	{
		FS_TRACE_WARN("FMOD error! (%d) %s", result, FMOD_ErrorString(result));
		return NULL;
	}
	m_musicChannelUsed[music_id]=true;

	return new Music(music_id,sound);
}


void FmodPlayer::releaseMusic(Music* m)
{
	update();
	FMOD_RESULT result;
	FMOD::Sound* sound=m->m_sound;
	result=sound->release();
	m_musicChannelUsed[m->m_id]=false;

	if(result!=FMOD_OK)
	{
		FS_TRACE_WARN("FMOD error! (%d) %s", result, FMOD_ErrorString(result));
	}


}

void FmodPlayer::playMusic(Music* m,bool loop)
{
	update();

	FMOD_RESULT result;
	FMOD::Channel* channel=NULL;
	m_musics->getChannel(m->m_id,&channel);

	result=m_musics->playSound(FMOD_CHANNEL_REUSE,m->m_sound,true,&channel);

	if(result!=FMOD_OK)
	{
		FS_TRACE_WARN("FMOD error! (%d) %s", result, FMOD_ErrorString(result));
		return ;
	}

	if(loop)
	{
		channel->setLoopCount(-1);
	}
	else 
	{
		channel->setLoopCount(0);
	}

	channel->setPaused(false);
}


void FmodPlayer::stopMusic(Music* m) 
{
	update();
	FMOD::Channel* channel=NULL;
	m_musics->getChannel(m->m_id,&channel);
	channel->stop();
}


bool FmodPlayer::isMusicPlaying(Music* m)
{
	update();
	FMOD::Channel* channel=NULL;
	m_musics->getChannel(m->m_id,&channel);
	bool is_play;

	channel->isPlaying(&is_play);
	return is_play;
}


void FmodPlayer::pauseMusic(Music* m)
{
	update();
	FMOD::Channel* channel=NULL;
	m_musics->getChannel(m->m_id,&channel);
	channel->setPaused(true);
}


void FmodPlayer::resumeMusic(Music* m)
{
	update();
	FMOD::Channel* channel=NULL;
	m_musics->getChannel(m->m_id,&channel);
	channel->setPaused(false);
}


bool FmodPlayer::isMusicPaused(Music* m) 
{
	update();
	FMOD::Channel* channel=NULL;
	m_musics->getChannel(m->m_id,&channel);

	bool paused;
	channel->getPaused(&paused);
	return paused;
}


void FmodPlayer::setMusicLooping(Music* m,bool loop) 
{
	update();
	FMOD::Channel* channel=NULL;
	m_musics->getChannel(m->m_id,&channel);
	if(loop)
	{
		channel->setLoopCount(-1);
	}
	else 
	{
		channel->setLoopCount(0);
	}
}


bool FmodPlayer::isMusicLooping(Music* m)
{
	update();
	FMOD::Channel* channel=NULL;
	m_musics->getChannel(m->m_id,&channel);
	int loop;
	channel->getLoopCount(&loop);

	if(loop==0)
	{
		return  false;
		
	}
	else 
	{
		return true;
	}


}


void FmodPlayer::setMusicVolume(Music* m,float value)
{
	update();
	FMOD::Channel* channel=NULL;
	m_musics->getChannel(m->m_id,&channel);
	channel->setVolume(value);
}


float FmodPlayer::getMusicVolume(Music* m)
{
	update();
	FMOD::Channel* channel=NULL;
	m_musics->getChannel(m->m_id,&channel);
	float value;
	channel->getVolume(&value);
	return value;
}


int FmodPlayer::getFreeMusicId()
{
	int channel_nu=m_musicChannelUsed.size();
	for(int i=0;i<channel_nu;i++)
	{
		if(m_musicChannelUsed[i]==false)
		{
			return i;
		}
	}
	return -1;

}


void FmodPlayer::update()
{
	m_sounds->update();
	m_musics->update();
}




NS_FS_END




