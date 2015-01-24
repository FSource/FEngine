/*************************************************************************/
/*  FsFmodPlayer.h                                                       */
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















