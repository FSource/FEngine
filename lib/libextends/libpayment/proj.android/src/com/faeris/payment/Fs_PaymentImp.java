package com.faeris.payment;

import android.content.Context;

public interface Fs_PaymentImp {
	public void init(Context context,String msg,Fs_PaymentListener listener);
	public void billing(Context context,String name,String msg,Fs_PaymentListener listener);
	public void config(Context context,String config,Fs_PaymentListener listener);
}
