package com.faeris.lib;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

import android.util.Log;


public class Fs_GLRender implements GLSurfaceView.Renderer
{
	private boolean m_init=false;
	private long m_now;
	private long m_last;
	@Override 
	public void onDrawFrame(final GL10 gl)
	{
		m_now=System.currentTimeMillis() ;
		float diff=m_now-m_last;
		float sleep_time=Fs_Jni.onUpdate(diff/1000.0f);
		/*
		if(sleep_time>0)
		{
			try
			{
				Thread.sleep((long) sleep_time);
			}
			catch(final Exception e)
			{
			}
		}
		*/
		m_last=m_now;
	}
	public void setIsDraw(boolean draw)
	{
		
	}
	public boolean getIsDraw()
	{
		return true;
	}

	@Override
	public void onSurfaceChanged(GL10 gl, int width, int height)
	{
		Log.v("size change","width:"+width+"height"+height);
		Fs_Jni.onResize(width, height);
		
	} 

	@Override
	public void onSurfaceCreated(GL10 gl, EGLConfig config) 
	{
		if(!this.m_init)
		{
			Fs_Jni.moduleInit();
			this.m_init=true;
		}
		else 
		{
			Log.v("Fs_GLRender","Opengl context lost,Kill Process");
			Fs_Application.getContext().finish();
		}
		m_now=System.currentTimeMillis();
		m_last=m_now;
	}

}


