package com.faeris.libext;
import com.faeris.lib.Fs_Application;

import android.content.Context;
import android.telephony.TelephonyManager;

public class Fs_SIMCardInfo {
	
	public final int UNKOWN=0;   /* 未知运营商 */
	public final int MOBILE=1;   /* 中移动 */
	public final int UNICOM=2;	 /* 联通 */
	public final int TELECOM=3;  /* 电信 */
	
	
	
	static public  String getNativePhoneNumber()
	{
		Context context=Fs_Application.getContext();
		TelephonyManager telephony_manager=(TelephonyManager) context.getSystemService(context.TELEPHONY_SERVICE); 
		return telephony_manager.getLine1Number();
	}
	
	public int getProvidersName()
	{
			Context context=Fs_Application.getContext();
			TelephonyManager telephony_manager=(TelephonyManager) context.getSystemService(context.TELEPHONY_SERVICE); 
			
			// 返回唯一的用户ID;就是这张卡的编号神马的  
			String IMSI = telephony_manager.getSubscriberId();  
			
			// IMSI号前面3位460是国家，
			// 紧接着后面2位00 02是中国移动
			// 01是中国联通
			// 03是中国电信。  
		
			if (IMSI.startsWith("46000") || IMSI.startsWith("46002")) {  
				return MOBILE;
			} else if (IMSI.startsWith("46001")) {  
			    return UNICOM;
			} else if (IMSI.startsWith("46003")) {  
			    return TELECOM;
			}  
			return UNKOWN;
	}
	
	public static  String getIMSI()
	{
		Context context=Fs_Application.getContext();
		TelephonyManager telephony_manager=(TelephonyManager) context.getSystemService(context.TELEPHONY_SERVICE); 
		
		// 返回唯一的用户ID;就是这张卡的编号神马的  
		String IMSI = telephony_manager.getSubscriberId();  
		
		return IMSI;
	}
	
		
}
