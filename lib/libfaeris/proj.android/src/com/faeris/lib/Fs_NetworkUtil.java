package com.faeris.lib;


import java.lang.reflect.Method;

import android.content.Context;
import android.net.ConnectivityManager;
import android.net.NetworkInfo;
import android.net.wifi.WifiInfo;
import android.net.wifi.WifiManager;
import android.telephony.TelephonyManager;
import android.text.TextUtils;
import android.util.DisplayMetrics;
import android.view.WindowManager;


public class Fs_NetworkUtil {

	/***
	 * 检测当前的网络连接
	 * @param context
	 * @return
	 */

	public static boolean checkNet(){
		Context  context =Fs_Application.getContext();
		if(null ==context) return false;
		boolean wifiConnected = isWIFIConnected(context);
		boolean mobileConnected = isMOBILEConnected(context);
		if(wifiConnected==false&&mobileConnected==false){//如果都没有连接返回false，提示用户当前没有网络
			return false;
		}
		if(mobileConnected==true){
			return true;
		}
		return true;
	}
	
	/**
	 * 判断手机是否采用wifi连接
	 */
	public static boolean isWIFIConnected(Context context){
		if(null == context) return false;
		ConnectivityManager manager=(ConnectivityManager) context.getSystemService(Context.CONNECTIVITY_SERVICE);
		NetworkInfo networkInfo = manager.getNetworkInfo(ConnectivityManager.TYPE_WIFI);
		if(networkInfo!=null&&networkInfo.isConnected()){
			return true;
		}
		return false;
	}
		
	public static boolean isMOBILEConnected(Context context){
		ConnectivityManager manager=(ConnectivityManager) context.getSystemService(Context.CONNECTIVITY_SERVICE);
		NetworkInfo networkInfo = manager.getNetworkInfo(ConnectivityManager.TYPE_MOBILE);
		if(networkInfo!=null&&networkInfo.isConnected()){
			return true;
		}
		return false;
	}

}

