package com.faeris.lib;




import android.content.Context;
import android.content.res.AssetFileDescriptor;
import android.media.AudioManager;
import android.media.SoundPool;
import android.util.Log;
import java.io.File;

public class Fs_AudioPlayer 
{
	/* class scope attribute */
	private static final int ERR_SOUND_ID=-1;
	private static final int ERR_CHANNEL_ID=-1;
	private static final String TAG="FsAudioPlayer";


	/* instance scope attribute */
	private final Context m_context;
	private SoundPool m_soundPool;
	private float  m_volume;

	/* public method */
	public Fs_AudioPlayer(int channel_nu)
	{
		this.m_context=Fs_Application.getContext();
		this.init(channel_nu);
	}
	
	protected void init(int channel_nu)
	{
		this.m_soundPool=new SoundPool(channel_nu,AudioManager.STREAM_MUSIC,0);
		this.m_volume=1.0f;
	}
	
	/* music */
	
	public Fs_Music createMusic(final String path)
	{
		File file=null;
		if(path.startsWith("/"))
		{
			Log.v(Fs_AudioPlayer.TAG,"load music from absoult path:"+path);
			try
			{
				file=new File(path);
				if(file.exists())
				{
					return Fs_Music.createFromPath(path);
				}
			}
			catch(Exception e)
			{
				return null;
			}
		}
		
		/* load from external path */
		do{
			Log.v(Fs_AudioPlayer.TAG,"load music from absoult external path:"+path);
			String external_dir=Fs_Application.getExternalDir();
			String external_path=external_dir+path;
			try
			{
				file=new File(external_path);
				if(file.exists())
				{
					return Fs_Music.createFromPath(external_path);
				}
				
			}
			catch(Exception e)
			{
				/*do nothing here */
			}
		}while(false);
		
		/* load from asserts */
		do{
			Log.v(Fs_AudioPlayer.TAG,"load music from assets path:"+path);
			try{
				AssetFileDescriptor af=this.m_context.getAssets().openFd(path);
				return Fs_Music.createFromAssets(af);
			}
			catch(Exception e)
			{
				/* do nothing here */
			}
			
		}while(false);
		
		/* load file */
		Log.v(Fs_AudioPlayer.TAG,"Load Music Failed From Path:"+path);
		return null;
	}


	/* create and release sound */
	public int createSound(final String path)
	{
		int id=Fs_AudioPlayer.ERR_SOUND_ID;
	
		/* load from absolute path */
		if(path.startsWith("/"))
		{
			Log.v(Fs_AudioPlayer.TAG,"Loading: load sound from Absoulte Path: "+path);
			try
			{
				File file=new File(path);
				if(file.exists())
				{
					id=this.m_soundPool.load(path,1);
					return id;
				}
			}
			catch(Exception e)
			{
				Log.v(Fs_AudioPlayer.TAG,"Exception:can't load sound from Absoulte Path: "+path);
				/* do nothing */
			}
		}
		/* load from external path */
		do
		{
			Log.v(Fs_AudioPlayer.TAG,"Loading: load sound from External Path: "+path);
			try
			{
				File file=new File(Fs_Application.getExternalDir()+path);
				if(file.exists())
				{
					id=this.m_soundPool.load(Fs_Application.getExternalDir()+path,1);
					return id;
				}
			}
			catch(Exception e)
			{
				Log.v(Fs_AudioPlayer.TAG,"Exception:can't load sound from External Path: "+path);
				/* do nothing */
			}
			
		}while(false);
		
		do 
		{
			Log.v(Fs_AudioPlayer.TAG,"Loading: load sound from Assets Path: "+path);
			try
			{
				AssetFileDescriptor fd=this.m_context.getAssets().openFd(path);
				id=this.m_soundPool.load(fd,1);
				return id;
			}
			catch(Exception e)
			{
				Log.v(Fs_AudioPlayer.TAG,"Exception:can't load sound from Assets Path: "+path);
				/* do nothing */
			}
		}while(false);
		
		Log.v(Fs_AudioPlayer.TAG,"Can't Load Sound From Path:"+path);
		
		return Fs_AudioPlayer.ERR_SOUND_ID;

	}
	public void releaseSound(int sound)
	{
		this.m_soundPool.unload(sound);
	}

	/* play sound */
	public int playSound(int sound,int loop,int priority)
	{
		int channel=Fs_AudioPlayer.ERR_CHANNEL_ID;
		channel=m_soundPool.play(sound,this.m_volume,this.m_volume,priority,loop==-1?-1:0, 1.0f);
		return channel;

	}

	/* single channel */
	public void pauseChannel(int channel)
	{
		this.m_soundPool.pause(channel);
	}
	
	public void resumeChannel(int channel)
	{
		this.m_soundPool.resume(channel);
	}
	
	public void stopChannel(int channel)
	{
		this.m_soundPool.stop(channel);
	}
	
	public void setChannelVolume(int channel,float value)
	{
		this.m_soundPool.setVolume(channel,value*this.m_volume,value*this.m_volume);
	}
	
	public float getChannelVolume(int channel)
	{
		Log.v(Fs_AudioPlayer.TAG,"StopChannels Not Impliment");
		return this.m_volume;
	}


	/* all channel */
	public void pauseChannels() 
	{
		this.m_soundPool.autoPause();
	}
	public void resumeChannels()
	{
		this.m_soundPool.autoResume();
	}
	public void stopChannels()
	{
		Log.v(Fs_AudioPlayer.TAG,"StopChannels Not Impliment");
	}	
	public void setVolume(float value) 
	{
		Log.v(Fs_AudioPlayer.TAG,"SetVolume Not Impliment");
		this.m_volume=value;
	}


}
