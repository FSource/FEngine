package com.faeris.payment;

import android.content.Context;

public interface Fs_PaymentImp {
	public void init(Context context,String msg);
	public void config(Context context,String value);
	public void billing(Context context,String msg,Fs_PaymentListener listener);

}


