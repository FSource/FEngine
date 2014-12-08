package com.faeris.lib;

import java.io.FileDescriptor;

import android.content.res.AssetFileDescriptor;
import android.media.MediaPlayer;
import android.util.Log;

public class Fs_Music {


	/* static const */
	private static final String TAG="Fs_Music";
	
	/* attribute */
	private MediaPlayer m_mediaPlayer;
	private boolean m_isPrepared = true;
	private float m_volume=1.0f;

	
	
	/* static  method */
	public static Fs_Music createFromPath(final String path)
	{
		
		MediaPlayer media_player;
		media_player=new MediaPlayer();
		try
		{
			media_player.setDataSource(path);
			media_player.prepare();
		}
		catch(Exception e)
		{
			media_player.release();
			return null;
		}
		
		Fs_Music ret= new Fs_Music();
		ret.m_mediaPlayer=media_player;
		return ret;

		
	}
	public static Fs_Music createFromAssets(final AssetFileDescriptor af )
	{
		MediaPlayer media_player;
		media_player=new MediaPlayer();
		try
		{
			media_player.setDataSource(af.getFileDescriptor(),af.getStartOffset(),af.getLength());
			media_player.prepare();
		}
		catch(Exception e)
		{
			media_player.release();
			return null;
		}
		
		Fs_Music ret= new Fs_Music();
		ret.m_mediaPlayer=media_player;
		return ret;

		
	}
	
	
	
	/*  nostaic method */
	public Fs_Music() {
		// TODO Auto-generated constructor stub
	}
	
	
	public void setLooping(boolean loop)
	{
		m_mediaPlayer.setLooping(loop);
	}

	public boolean isLoop()
	{
		return m_mediaPlayer.isLooping();
	}
	
	public boolean isPlaying()
	{
		return m_mediaPlayer.isPlaying();
	}

	public void play()
	{
		if(m_mediaPlayer.isPlaying())
		{
			return;
		}
		try{
			if(!m_isPrepared)
			{
				m_mediaPlayer.prepare();
				m_isPrepared=true;
				m_mediaPlayer.seekTo(0);
			}
			m_mediaPlayer.start();
		}
		catch(Exception e)
		{
			Log.v(Fs_Music.TAG,"Play Music Failed:"+e.getMessage());
		}
	}
	
	public void pause()
	{
		if(m_mediaPlayer.isPlaying())
		{
			m_mediaPlayer.pause();
		}
	}
	
	public void resume()
	{
		play();
	}


	public float getVolume()
	{
		return m_volume;
	}

	public void setVolume(float volume)
	{
		m_mediaPlayer.setVolume(volume,volume);
		this.m_volume=volume;
	}


	public void stop()
	{
		m_mediaPlayer.stop();

		m_isPrepared=false;
	}

	public void release()
	{
		if(m_mediaPlayer!=null)
		{
			if(m_mediaPlayer.isPlaying())
			{
				try
				{
					m_mediaPlayer.stop();
					m_mediaPlayer.release();
				}
				catch(Throwable t)
				{
					Log.v(Fs_Music.TAG,"release Fs_Music Failed");
				}
				finally 
				{
					m_mediaPlayer=null;
				}
				
			}
			else 
			{
				m_mediaPlayer.release();
				m_mediaPlayer=null;
			}
		}
	}


}














