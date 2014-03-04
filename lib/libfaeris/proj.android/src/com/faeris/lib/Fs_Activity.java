package com.faeris.lib;


import android.app.Activity;
import android.app.AlertDialog;
import android.app.AlertDialog.Builder;
import android.content.Context;
import android.content.DialogInterface;
import android.content.DialogInterface.OnClickListener;
import android.content.pm.ActivityInfo;
import android.os.Bundle;
import android.util.Log;
import android.view.KeyEvent;
import android.view.ViewGroup;
import android.view.WindowManager;
import android.widget.FrameLayout;


public  class Fs_Activity extends Activity
{
	/* attibute */
	
	private Fs_GLSurfaceView m_view;

	/* method */
	@Override 
	protected void onCreate(final Bundle save_state)
	{
		super.onCreate(save_state);
		
		Fs_Application.setContext(this);
		this.initEnv(); 
		
		this.initView();
		
		getWindow().setFlags(WindowManager.LayoutParams.FLAG_KEEP_SCREEN_ON, WindowManager.LayoutParams.FLAG_KEEP_SCREEN_ON);
		setScreenOrientation();
	}
	
	
	@Override 
	protected void onResume()
	{
		super.onResume();
		this.m_view.onResume();
		//Fs_Jni.onForeground();
	}

	@Override
	protected void onPause()
	{
		super.onPause();
		this.m_view.onPause();
		
		//Fs_Jni.onBackground();
	}
	
	
	
	@Override
	protected void onDestroy()
	{
		Log.v("Fs_Activity","onDestroy");
		
		super.onDestroy();
		Fs_Jni.onDestroy();
		android.os.Process.killProcess(android.os.Process.myPid());
	}
	
	protected void initView()
	{
		m_view=new Fs_GLSurfaceView(this);
		Fs_GLRender r=new Fs_GLRender();
		
		m_view.setFsGLRender(r);
		this.setContentView(m_view);
	}
	protected void initEnv()
	{
		String os_type=Fs_Application.getOsType();
		String os_version=Fs_Application.getOsVersion();
		String package_name=Fs_Application.getPackageName();
		String device_name=Fs_Application.getDeviceName();
		String imei=Fs_Application.getIMEI();
		String imsi=Fs_Application.getIMSI();

		Fs_Jni.setEnv("os_type",os_type);
		Fs_Jni.setEnv("os_version",os_version);
		Fs_Jni.setEnv("package_name",package_name);
		Fs_Jni.setEnv("device_name",device_name);
		Fs_Jni.setEnv("imei",imei);
		Fs_Jni.setEnv("imsi",imsi);
	}
	

	
	@Override
	public boolean onKeyDown(int keyCode, KeyEvent event) {
		if (keyCode == KeyEvent.KEYCODE_BACK) {
			AlertDialog.Builder builder = new Builder(Fs_Activity.this);
			builder.setMessage("ȷ���˳���Ϸ��?");
			builder.setTitle("��ʾ");
			builder.setPositiveButton("ȷ��", new OnClickListener() {
					public void onClick(DialogInterface dialog, int which) {
						dialog.dismiss();
						Fs_Activity.this.finish();
					}
			});

			builder.setNegativeButton("ȡ��", new OnClickListener() {
					public void onClick(DialogInterface dialog, int which) {
							dialog.dismiss();
					}
				});

				builder.create().show();
		}

		return super.onKeyDown(keyCode, event);
	}

	public Fs_GLSurfaceView getFsGLSurfaceView()
	{
		return m_view;
	}
	
	
	private void setScreenOrientation()
	{
		if (android.os.Build.VERSION.SDK_INT >= 9)
		{
			int SCREEN_ORIENTATION_SENSOR_LANDSCAPE = 6;
			int SCREEN_ORIENTATION_SENSOR_PORTRAIT = 7;
			int orientation = getRequestedOrientation();
			switch(orientation)
			{
				case ActivityInfo.SCREEN_ORIENTATION_LANDSCAPE:
					setRequestedOrientation(SCREEN_ORIENTATION_SENSOR_LANDSCAPE);
					break;
				case ActivityInfo.SCREEN_ORIENTATION_PORTRAIT:
					setRequestedOrientation(SCREEN_ORIENTATION_SENSOR_PORTRAIT);
					break; 
			}

		}
	}
 
}





