package com.faeris.payment;

public class Fs_PaymentJni {

	public native static void billingFinish(int tradeid, int ret_code, String msg) ;

}
