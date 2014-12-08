#ifndef _AUDIO_ENGINE_H_
#define _AUDIO_ENGINE_H_ 

#include <map>
#include <string>

#include "FsMacros.h"
#include "FsObject.h"
#include "FsAudioPlayer.h"

#define FS_DEFAULT_CHANNEL_NU 5

NS_FS_BEGIN 

class Channel;
class Sound;
class Music;
class AudioPlayer;

class AudioEngine:public FsObject
{
	public:
		enum
		{
			PRIORITY_HIGH=AudioPlayer::PRIORITY_HIGH,
			PRIORITY_MIDDLE=AudioPlayer::PRIORITY_MIDDLE,
			PRIORITY_LOW=AudioPlayer::PRIORITY_LOW,
		};

	public:
		typedef std::map<std::string,Sound*> SoundSet;

	public:
		static AudioEngine* create(int channel_nu=FS_DEFAULT_CHANNEL_NU);

	public:
		void playBackgroundMusic(const char* name,bool loop=true);
		void stopBackgroundMusic();
		void pauseBackgroundMusic();
		void resumeBackgroundMusic();
		void rewindBackgroundMusic();


	public:
		/* load and unload sound */
		int loadSound(const char* name);
		int unloadSound(const char* name);
		int unloadSounds();

		Channel* playSound(const char* name,int loop=0,int priority=PRIORITY_MIDDLE);

		/* single channel */
		void pauseChannel(Channel* c);
		void resumeChannel(Channel* c);
		void stopChannel(Channel* c);
		void setChannelVolume(Channel* c,float value);
		float getChannelVolume(Channel* c);

		/* all channel */
		void pauseChannels();
		void resumeChannels();
		void stopChannnels();
		void setVolume(float value);

	public:
		virtual const char* className();
	protected:
		AudioEngine();
		virtual ~AudioEngine();
		bool init(int channel_nu);
		void destory();

	private:
		AudioPlayer* m_player;
		SoundSet m_sounds;

		/* background music */
		Music* m_bgm;
		std::string m_bgmName;
		bool m_bgmLoop;

};

NS_FS_END

#endif /*_AUDIO_ENGINE_H_*/

















