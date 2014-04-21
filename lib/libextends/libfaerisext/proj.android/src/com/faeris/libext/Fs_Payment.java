package com.faeris.libext;

import com.faeris.lib.Fs_Application;

public class Fs_Payment {
	
	public static final int SUCCESS=0;
	public static final int CANCEL=1;
	public static final int FAILED=2;
	public static final int ERROR=3;
	
	private static Fs_PaymentImp m_paymentImp;
	private static int m_tradeId=0;
	
	public static void setPaymentImp(Fs_PaymentImp imp)
	{
		m_paymentImp=imp;
	}
	
	public static Fs_PaymentImp getPaymentImp()
	{
		return m_paymentImp;
	}

	

	
	public static void setConfig(final String msg)
	{
		Fs_Application.runUiThread(new Runnable(){
			@Override
			public void run() {
				m_paymentImp.setConfig(Fs_Application.getContext(),msg);
				
			}
		});
	}
	
	
	public static int billing(final String name, final String msg)
	{
		m_tradeId=m_tradeId+1;
		final int tradeid=m_tradeId;
		
		Fs_Application.runUiThread(new Runnable(){
			@Override
			public void run()
			{
				m_paymentImp.billing(Fs_Application.getContext(),name,msg,new Fs_PaymentListener(){
					@Override
					public void payResult(final int ret_code, final String msg) {
						Fs_Application.runOnEngineThread(new Runnable(){
							@Override
							public void run() {
								Fs_PaymentJni.billingFinish(tradeid,ret_code,msg);
								
							}
						});
					}
					
				});
			}
			
		});
		return m_tradeId;
	}

	
	
	

}
