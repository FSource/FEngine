#include "FsMacros.h"
#include "sys/platform/android/FsJniUtil.h"
#include "FsAndroidAudioPlayer.h"

static const char* JNI_AUDIO_PLAYER_CLASS_NAME="com/faeris/lib/Fs_AudioPlayer";
static const char* JNI_MUSIC_CLASS_NAME = "com/faeris/lib/Fs_Music";

NS_FS_BEGIN

AndroidAudioPlayer* AndroidAudioPlayer::create(int channel_nu)
{

	AndroidAudioPlayer* ret=new AndroidAudioPlayer();
	if(!ret->init(channel_nu))
	{
		delete ret;
		return NULL;
	}
	return ret;
}


Sound* AndroidAudioPlayer::createSound(const char* filename)
{
	JNIEnv* env=JniUtil::getEnv();
	jstring jfile_name=env->NewStringUTF(filename);

	jint ret;
	FS_JNI_CALL_METHOD(m_audioPlayer,JNI_AUDIO_PLAYER_CLASS_NAME,"createSound","(Ljava/lang/String;)I",Int,ret,jfile_name);
	env->DeleteLocalRef(jfile_name);

	if(ret==-1)
	{
		FS_TRACE_WARN("Create Sound %s Failed",filename);
		return NULL;
	}
	return (Sound*) ((int)ret);
}

void AndroidAudioPlayer::releaseSound(Sound* s)
{
	int sound_id=(int) s;
	JniUtil::attachCurrentThread();
	FS_JNI_CALL_VOID_METHOD(m_audioPlayer,JNI_AUDIO_PLAYER_CLASS_NAME,"releaseSound","(I)V",sound_id);
}

Channel* AndroidAudioPlayer::playSound(Sound* s,int loop,int priority)
{
	int sound_id=(int) s;
	JniUtil::attachCurrentThread();

	int pri_nu=1;
	switch (priority)
	{
		case AudioPlayer::PRIORITY_HIGH:
			pri_nu=2;
			break;
		case AudioPlayer::PRIORITY_MIDDLE:
			pri_nu=1;
			break;
		case AudioPlayer::PRIORITY_LOW:
			pri_nu=0;
			break;
	}
	
	jint ret;
	FS_JNI_CALL_METHOD(m_audioPlayer,JNI_AUDIO_PLAYER_CLASS_NAME,"playSound","(III)I",Int,ret,sound_id,loop,priority);
	if(ret==-1)
	{
		return NULL;
	}
	return (Channel*) ((int)ret);
}


void AndroidAudioPlayer::pauseChannel(Channel* c)
{
	int channel=(int) c;
	JniUtil::attachCurrentThread();
	FS_JNI_CALL_VOID_METHOD(m_audioPlayer,JNI_AUDIO_PLAYER_CLASS_NAME,"pauseChannel","(I)V",channel);
}
void AndroidAudioPlayer::resumeChannel(Channel* c)
{
	int channel=(int) c;
	JniUtil::attachCurrentThread();
	FS_JNI_CALL_VOID_METHOD(m_audioPlayer,JNI_AUDIO_PLAYER_CLASS_NAME,"resumeChannel","(I)V",channel);
}

void AndroidAudioPlayer::stopChannel(Channel* c)
{
	int channel=(int) c;
	JniUtil::attachCurrentThread();
	FS_JNI_CALL_VOID_METHOD(m_audioPlayer,JNI_AUDIO_PLAYER_CLASS_NAME,"stopChannel","(I)V",channel);
}

void AndroidAudioPlayer::setChannelVolume(Channel* c,float value)
{
	int channel=(int) c;
	JniUtil::attachCurrentThread();
	FS_JNI_CALL_VOID_METHOD(m_audioPlayer,JNI_AUDIO_PLAYER_CLASS_NAME,"stopChannel","(IF)V",channel,value);
}


float AndroidAudioPlayer::getChannelVolume(Channel* c)
{
	int channel=(int) c;
	JniUtil::attachCurrentThread();
	jfloat ret;
	FS_JNI_CALL_METHOD(m_audioPlayer,JNI_AUDIO_PLAYER_CLASS_NAME,"stopChannel","(I)F",Float,ret,channel);
}

void AndroidAudioPlayer::pauseChannels()
{
	JniUtil::attachCurrentThread();
	FS_JNI_CALL_VOID_METHOD(m_audioPlayer,JNI_AUDIO_PLAYER_CLASS_NAME,"pauseChannels","()V");
}

void AndroidAudioPlayer::resumeChannels()
{
	JniUtil::attachCurrentThread();
	FS_JNI_CALL_VOID_METHOD(m_audioPlayer,JNI_AUDIO_PLAYER_CLASS_NAME,"resumeChannels","()V");
}
void AndroidAudioPlayer::stopChannnels()
{
	JniUtil::attachCurrentThread();
	FS_JNI_CALL_VOID_METHOD(m_audioPlayer,JNI_AUDIO_PLAYER_CLASS_NAME,"stopChannels","()V");
}

void AndroidAudioPlayer::setVolume(float value)
{
	JniUtil::attachCurrentThread();
	FS_JNI_CALL_VOID_METHOD(m_audioPlayer,JNI_AUDIO_PLAYER_CLASS_NAME,"setVolume","(F)V",value);
}

bool AndroidAudioPlayer::init(int channel_nu)
{
	JNIEnv* env=JniUtil::getEnv();
	FS_JNI_NEW_OBJECT(JNI_AUDIO_PLAYER_CLASS_NAME,"(I)V",m_audioPlayer,channel_nu);
	if(m_audioPlayer)
	{
		env->NewGlobalRef(m_audioPlayer);
		return true;
	}
	return false;
}

void AndroidAudioPlayer::destory()
{
	JNIEnv* env=JniUtil::getEnv();
	if(m_audioPlayer)
	{
		env->DeleteGlobalRef(m_audioPlayer);
		m_audioPlayer=0;
	}

}

AndroidAudioPlayer::AndroidAudioPlayer()
{
	m_audioPlayer=0;
}
AndroidAudioPlayer::~AndroidAudioPlayer ()
{
	destory();
}



class Music 
{
	public:
		Music(jobject ob)
		{
			m_object=ob;
		}
		~Music()
		{
			JNIEnv* env=JniUtil::getEnv();
			if(m_object)
			{
				env->DeleteGlobalRef(m_object);
				m_object=NULL;
			}
		}
	public:
		jobject m_object;
};



Music* AndroidAudioPlayer::createMusic(const char* filename)
{
	JNIEnv* env=JniUtil::getEnv();
	jstring jfile_name=env->NewStringUTF(filename);

	jobject ret;
	FS_JNI_CALL_METHOD(m_audioPlayer,JNI_AUDIO_PLAYER_CLASS_NAME,"createMusic","(Ljava/lang/String;)Lcom/faeris/lib/Fs_Music;",Object,ret,jfile_name);
	env->DeleteLocalRef(jfile_name);

	if(ret!=NULL)
	{
		env->NewGlobalRef(ret);
		return new Music(ret);
	}
	return NULL;
}

void AndroidAudioPlayer::releaseMusic(Music* m)
{
	JniUtil::attachCurrentThread();
	FS_JNI_CALL_VOID_METHOD(m->m_object,JNI_MUSIC_CLASS_NAME,"release","()V");
};

void AndroidAudioPlayer::playMusic(Music* m,bool loop)
{
	JniUtil::attachCurrentThread();
	FS_JNI_CALL_VOID_METHOD(m->m_object,JNI_MUSIC_CLASS_NAME,"play","()V");
	FS_JNI_CALL_VOID_METHOD(m->m_object,JNI_MUSIC_CLASS_NAME,"setLooping","(Z)V",loop);
}


void AndroidAudioPlayer::stopMusic(Music* m)
{
	JniUtil::attachCurrentThread();
	FS_JNI_CALL_VOID_METHOD(m->m_object,JNI_MUSIC_CLASS_NAME,"stop","()V");
}

bool AndroidAudioPlayer::isMusicPlaying(Music* m)
{
	JniUtil::attachCurrentThread();
	bool ret;
	FS_JNI_CALL_METHOD(m->m_object,JNI_MUSIC_CLASS_NAME,"isPlaying","()Z",Boolean,ret);
	return ret;
}

void AndroidAudioPlayer::pauseMusic(Music* m)
{
	JniUtil::attachCurrentThread();
	FS_JNI_CALL_VOID_METHOD(m->m_object,JNI_MUSIC_CLASS_NAME,"pause","()V");
}


void AndroidAudioPlayer::resumeMusic(Music* m)
{
	JniUtil::attachCurrentThread();
	FS_JNI_CALL_VOID_METHOD(m->m_object,JNI_MUSIC_CLASS_NAME,"resume","()V");
}


bool AndroidAudioPlayer::isMusicPaused(Music* m)
{
	return isMusicPlaying(m);
}


void AndroidAudioPlayer::setMusicLooping(Music* m,bool loop)
{
	JniUtil::attachCurrentThread();
	jboolean j_loop=loop;
	FS_JNI_CALL_VOID_METHOD(m->m_object,JNI_MUSIC_CLASS_NAME,"isLooping","(Z)V",j_loop);
}

bool AndroidAudioPlayer::isMusicLooping(Music* m)
{
	JniUtil::attachCurrentThread();
	jboolean ret;
	FS_JNI_CALL_METHOD(m->m_object,JNI_MUSIC_CLASS_NAME,"setLooping","()Z",Boolean,ret);
	return ret;
}


void AndroidAudioPlayer::setMusicVolume(Music* m,float value)
{
	JniUtil::attachCurrentThread();
	jfloat j_value=value;
	FS_JNI_CALL_VOID_METHOD(m->m_object,JNI_MUSIC_CLASS_NAME,"setVolume","(F)V",j_value);
}

float AndroidAudioPlayer::getMusicVolume(Music* m)
{
	JniUtil::attachCurrentThread();
	jfloat ret;
	FS_JNI_CALL_METHOD(m->m_object,JNI_MUSIC_CLASS_NAME,"getVolume","()F",Float,ret);
	return ret;
}


NS_FS_END
