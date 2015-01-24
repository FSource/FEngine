/*************************************************************************/
/*  FsAudioPlayer.cc                                                     */
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


#include "FsMacros.h"
#include "FsAudioPlayer.h"



#if FS_PLATFORM_OS(FS_OS_LINUX) || FS_PLATFORM_OS(FS_OS_WIN32)  || FS_PLATFORM_OS(FS_OS_OSX)
	#include "platform/FsFmodPlayer.h"
#elif FS_PLATFORM_OS(FS_OS_ANDROID)
	#include "platform/FsAndroidAudioPlayer.h"
	//#include "platform/FsFmodPlayer.h"
#else 
	#error "UNKOWN AUDIO TYPE"
#endif


NS_FS_BEGIN
AudioPlayer* AudioPlayer::create(int channel_nu)
{
#if FS_PLATFORM_OS(FS_OS_LINUX) || FS_PLATFORM_OS(FS_OS_WIN32)  || FS_PLATFORM_OS(FS_OS_OSX) 
	return FmodPlayer::create(channel_nu);
#elif FS_PLATFORM_OS(FS_OS_ANDROID)
	return AndroidAudioPlayer::create(channel_nu);
//	return FmodPlayer::create(channel_nu);
#else 
	#error "Unkown Audio Player"
#endif 
}

AudioPlayer::~AudioPlayer()
{
}

NS_FS_END

#if FS_PLATFORM_OS(FS_OS_LINUX) || FS_PLATFORM_OS(FS_OS_WIN32)  || FS_PLATFORM_OS(FS_OS_OSX) 
	#include "platform/FsFmodPlayer.cc"
#elif FS_PLATFORM_OS(FS_OS_ANDROID)
	#include "platform/FsAndroidAudioPlayer.cc"
	//#include "platform/FsFmodPlayer.cc"
#else 
	#error "UNKOWN AUDIO TYPE"
#endif

