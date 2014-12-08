#ifndef _FMOD_PLAYER_H_
#define _FMOD_PLAYER_H_ 

#include <vector>
#include "fmod/fmod.hpp"

#include "FsMacros.h"
#include "media/FsAudioPlayer.h"


NS_FS_BEGIN

class FmodPlayer:public AudioPlayer 
{
	public:
		static FmodPlayer* create(int channel_nu);

	public:   
		virtual Music* createMusic(const char* filename);
		virtual void releaseMusic(Music* m);
		virtual void playMusic(Music* m,bool loop);
		virtual void stopMusic(Music* m);
		virtual bool isMusicPlaying(Music* m);

		virtual void pauseMusic(Music* m);
		virtual void resumeMusic(Music* m);
		virtual bool isMusicPaused(Music* m);

		virtual void setMusicLooping(Music* m,bool loop);
		virtual bool isMusicLooping(Music* m);
		virtual void setMusicVolume(Music* m,float value);
		virtual float getMusicVolume(Music* m);


	public:
		virtual Sound* createSound(const char* filename);
		virtual void releaseSound(Sound* s);
		virtual Channel* playSound(Sound* s,int loop,int priority);

	public:
		virtual void pauseChannel(Channel* c);
		virtual void resumeChannel(Channel* c);
		virtual void stopChannel(Channel* c);
		virtual void setChannelVolume(Channel* c,float value);
		virtual float getChannelVolume(Channel* c);

	public:
		virtual void pauseChannels();
		virtual void resumeChannels();
		virtual void stopChannnels();
		virtual void setVolume(float value);

	protected:
		FmodPlayer();
		virtual ~FmodPlayer();
		bool init(int channel_nu);
		void destory();

		int getFreeMusicId();
		void update();

	private:
		FMOD::System* m_sounds;  /* used for sound */
		FMOD::ChannelGroup* m_channelGroup;
		int m_channelNu;

		FMOD::System* m_musics;  /* used for music */
		std::vector<bool> m_musicChannelUsed;

};

NS_FS_END

#endif /*_FMOD_PLAYER_H_*/















