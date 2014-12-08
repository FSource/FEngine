package com.faeris.lib;



import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

import android.content.Context;
import android.view.KeyEvent;
import android.view.MotionEvent;
import android.util.Log;



public class Fs_GLSurfaceView  extends GLSurfaceView
{
	private Fs_GLRender m_render;
	private float m_width;
	private float m_height;
	
	public  Fs_GLSurfaceView(final Context context)
	{
		super(context);
		setEGLContextClientVersion(2);
	}
	
	public void setFsGLRender(Fs_GLRender r) 
	{

		this.m_render=r;
		this.setRenderer(this.m_render);
		setRenderMode(GLSurfaceView.RENDERMODE_CONTINUOUSLY);

	}


	@Override 
	public void onResume()
	{
		super.onResume();
		this.queueEvent(new Runnable() {
			@Override 
			public void run(){
				Fs_Jni.onForeground();
			}
		});
	}

	@Override
	public void onPause() 
	{
		//super.onPause();
		this.queueEvent(new Runnable(){
			@Override
			public void run(){
				Fs_Jni.onBackground();
			}
		});
	}
	


	@Override 
	public boolean onTouchEvent(final MotionEvent event)
	{

		final int pointer_nu=event.getPointerCount();
	//	Log.v("key","onKeyBack,pointer_nu"+pointer_nu);
	
		final int[] ids=new int[pointer_nu];
		final float[] sx=new float[pointer_nu];
		final float[] sy=new float[pointer_nu];

		for( int i=0;i<pointer_nu;i++)
		{
			ids[i]=event.getPointerId(i);
			sx[i]=event.getX(i);
			sy[i]=event.getY(i);

		}
		for(int i=0;i<pointer_nu;i++)
		{
			sx[i]=sx[i]/m_width;
			sy[i]=1-sy[i]/m_height;

		}
		switch(event.getAction()&MotionEvent.ACTION_MASK)
		{
			case MotionEvent.ACTION_DOWN:
				final int id_down=event.getPointerId(0);
				final float x_down=sx[0];
				final float y_down=sy[0];
				this.queueEvent(new Runnable(){
					@Override
					public void run()
				{
					Fs_Jni.onTouchesBegin(id_down,x_down,y_down);
				}
				});

				break;

			case MotionEvent.ACTION_POINTER_DOWN:
				final int index_pointer_down=event.getAction()>>MotionEvent.ACTION_POINTER_ID_SHIFT;
				final int id_pointer_down=event.getPointerId(index_pointer_down);
				final float  x_pointer_down=event.getX(index_pointer_down)/m_width;
				final float  y_pointer_down=1-event.getY(index_pointer_down)/m_height;
				this.queueEvent(new Runnable(){
					@Override
					public void run()
					{
						Fs_Jni.onTouchesPointerDown(id_pointer_down,x_pointer_down,y_pointer_down);
					}
				});
				break;

			case MotionEvent.ACTION_MOVE:
				this.queueEvent(new Runnable(){
					@Override
					public void run()
				{
					Fs_Jni.onTouchesMove(pointer_nu,ids,sx,sy);
				}
				});
				break;

			case MotionEvent.ACTION_POINTER_UP:
				final int index_pointer_up=event.getAction()>>MotionEvent.ACTION_POINTER_ID_SHIFT;
				final int id_pointer_up=event.getPointerId(index_pointer_up);
				final float x_pointer_up=event.getX(index_pointer_up)/m_width;
				final float y_pointer_up=1-event.getY(index_pointer_up)/m_height;

				this.queueEvent(new Runnable(){
					@Override
					public void run()
					{
						Fs_Jni.onTouchesPointerUp(id_pointer_up,x_pointer_up,y_pointer_up);
					}
				});
				break;

			case MotionEvent.ACTION_UP:
				final int id_up=event.getPointerId(0);
				final float x_up=sx[0];
				final float y_up=sy[0];
				this.queueEvent(new Runnable(){
					@Override
					public void run()
				{
					Fs_Jni.onTouchesEnd(id_up,x_up,y_up);
				}
				});
				break;

		}
		return true;
	}
	
	@Override
		protected void onSizeChanged(final int new_width,final int new_height, final int old_width,final int old_height)
		{
			m_width=new_width;
			m_height=new_height;
			this.queueEvent(new Runnable(){
				@Override
				public void run(){
					//Fs_Jni.onResize(new_width,new_height);
					Log.v("size11 change","width:"+new_width+"height"+new_height);
				}
			});
		}

	@Override
		public boolean onKeyDown(int keyCode, KeyEvent event) {
			// exit program when key back is entered
			Log.v("key","onKeyEvent");
			if (keyCode == KeyEvent.KEYCODE_BACK) {
				android.os.Process.killProcess(android.os.Process.myPid());
			}
			return super.onKeyDown(keyCode, event);
		}




}

















