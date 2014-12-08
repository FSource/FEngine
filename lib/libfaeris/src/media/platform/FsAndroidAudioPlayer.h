#ifndef _FS_ANDROID_AUDIO_PLAYER_H_
#define _FS_ANDROID_AUDIO_PLAYER_H_
#include <jni.h>

#include "FsMacros.h"

NS_FS_BEGIN

class AndroidAudioPlayer:public AudioPlayer
{
	public:
		static AndroidAudioPlayer* create(int channel_nu);

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
		bool init(int channel_nu);
		void destory();
		AndroidAudioPlayer();
		virtual ~AndroidAudioPlayer();

	private:
		jobject m_audioPlayer;
};

NS_FS_END 

#endif /*_FS_ANDROID_AUDIO_PLAYER_H_*/

















