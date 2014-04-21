package com.faeris.libext;

import android.content.Context;

public interface Fs_PaymentImp {
	public void setConfig(Context context,String value);

	public void billing(Context context,String name,String msg,Fs_PaymentListener listener);
	public boolean hasPaycode(String name);

}


