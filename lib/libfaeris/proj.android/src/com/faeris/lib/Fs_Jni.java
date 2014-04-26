package com.faeris.lib;

public class Fs_Jni {
	
	/* Init add Exit FsEngine Module */
	public static native void moduleInit();
	public static native void moduleExit();
	
	
	
	/* sys event */
	public static native void onForeground();
	public static native void onBackground();
	public static native void onQuit();
	public static native void onExit();
	
	/* touches event */
	public static native void onTouchesBegin(int id,float x,float y);
	public static native void onTouchesPointerDown(int id,float x,float y);
	public static native void onTouchesMove(int pointer_nu,final int[] ids,final float[] xs,final float[] ys);
	public static native void onTouchesPointerUp(int id,float x,float y);
	public static native void onTouchesEnd(int id,float x,float y);
	
	/* menu event */
	public static native void onKeyEventBack();
	public static native void onKeyEventMenu();
	
	/* input method */
	public static native void onInputText(String text);
	
	
	/* surface event */
	public static native void onResize(int width,int height);

	/* update event */
	public static native float onUpdate(float dt);
	

	
	
	/* env */
	public static native void setEnv(String name,String value);
	
	public static native boolean schedulerStop();

}
