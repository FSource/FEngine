/*************************************************************************/
/*  FsAudioPlayer.h                                                      */
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


#ifndef _AUDIO_PLAYER_H_
#define _AUDIO_PLAYER_H_

NS_FS_BEGIN
class Sound;
class Channel;
class Music;

class AudioPlayer
{
	public:
		enum
		{
			PRIORITY_HIGH,
			PRIORITY_MIDDLE,
			PRIORITY_LOW,
		};

	public:
		static AudioPlayer* create(int channel_nu);

	public:   
		virtual Music* createMusic(const char* filename)=0;
		virtual void releaseMusic(Music* m)=0;
		virtual void playMusic(Music* m,bool loop)=0;
		virtual void stopMusic(Music* m)=0;
		virtual bool isMusicPlaying(Music* m)=0;

		virtual void pauseMusic(Music* m)=0;
		virtual void resumeMusic(Music* m)=0;
		virtual bool isMusicPaused(Music* m)=0;


		virtual void setMusicLooping(Music* m,bool loop)=0;
		virtual bool isMusicLooping(Music* m)=0;
		virtual void setMusicVolume(Music* m,float value)=0;
		virtual float getMusicVolume(Music* m)=0;



	public:
		virtual Sound* createSound(const char* filename)=0;
		virtual void releaseSound(Sound* s)=0;
		virtual Channel* playSound(Sound* s,int loop,int priority)=0;

	public:
		virtual void pauseChannel(Channel* c)=0;
		virtual void resumeChannel(Channel* c)=0;
		virtual void stopChannel(Channel* c)=0;
		virtual void setChannelVolume(Channel* c,float value)=0;
		virtual float getChannelVolume(Channel* c)=0;


	public:
		virtual void pauseChannels()=0;
		virtual void resumeChannels()=0;
		virtual void stopChannnels()=0;
		virtual void setVolume(float value)=0;

	public:
		virtual ~AudioPlayer();


};

NS_FS_END

#endif /* _AUDIO_PLAYER_H_ */ 







