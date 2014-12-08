package com.faeris.lib;

import android.os.Handler;
import android.os.HandlerThread;
import android.os.Looper;
import android.os.Message;

public class Fs_LooperThread extends HandlerThread{
	
	public Fs_LooperThread(String name) {
		super(name);
	}

	private Handler m_handler;
	
	public void runTask(Runnable runable)
	{
		if ( m_handler==null)
		{
			m_handler=new Handler(this.getLooper());
		}
		m_handler.post(runable);
	}
}

