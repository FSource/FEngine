/*************************************************************************/
/*  FsAudioEngine.h                                                      */
/*************************************************************************/
/* Copyright (C) 2012-2014 nosiclin@foxmail.com                          */
/* Copyright (C) 2014-2015 www.fsource.cn                                */
/*                                                                       */
/* http://www.fsource.cn                                                 */
/*                                                                       */
/* Permission is hereby granted, free of charge, to any person obtaining */
/* a copy of this software and associated documentation files (the       */
/* "Software"), to deal in the Software without restriction, including   */
/* without limitation the rights to use, copy, modify, merge, publish,   */
/* distribute, sublicense, and/or sell copies of the Software, and to    */
/* permit persons to whom the Software is furnished to do so, subject to */
/* the following conditions:                                             */
/*                                                                       */
/* The above copyright notice and this permission notice shall be        */
/* included in all copies or substantial portions of the Software.       */
/*                                                                       */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,       */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF    */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.*/
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY  */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,  */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE     */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                */
/*************************************************************************/


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

















