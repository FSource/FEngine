package com.faeris.lib;

import android.os.Handler;
import android.os.Message;
import java.lang.ref.WeakReference;

import com.faeris.lib.Fs_Application.InputBoxMessage;


public class Fs_UiEvent extends Handler {
	public final static int UIEVENT_EXIT=1;
	public final static int UIEVENT_SHOW_INPUT_BOX_DIALOG=2;
	
	private WeakReference<Fs_Activity> m_activity;

	public Fs_UiEvent()
	{
		
	} 

	public void handleMessage(Message msg)
	{
		switch(msg.what)
		{
			case Fs_UiEvent.UIEVENT_EXIT:
				exit(msg);
				break;
			case Fs_UiEvent.UIEVENT_SHOW_INPUT_BOX_DIALOG:
				showInputBoxDialog(msg);
				break;

		}
	}
	
	public void exit(Message msg)
	{
		Fs_Application.exit();
	}

	public void showInputBoxDialog(Message msg)
	{
		InputBoxMessage e_msg=(InputBoxMessage) msg.obj;
		Fs_InputBoxDialog dialog=new Fs_InputBoxDialog(this.m_activity.get(),
				e_msg.title,e_msg.content,
				e_msg.inputMode,e_msg.inputFlag,
				e_msg.returnType,e_msg.maxLength);

		dialog.show();
	}

}
