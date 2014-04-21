
package com.faeris.libext;
import com.faeris.lib.Fs_Application;

import android.content.Context;
import android.location.Criteria;
import android.location.Location;
import android.location.LocationListener;
import android.location.LocationManager;
import android.location.LocationProvider;
import android.os.Bundle;
import android.util.Log;



public class Fs_GpsProvider 
{

	private static final String TAG="Fs_GpsProvider";

	private LocationManager m_locationManager;
	private double m_latitude=0;
	private double m_longitude=0;

	public static Fs_GpsProvider create()
	{
		Fs_GpsProvider ret=new Fs_GpsProvider(Fs_Application.getContext());
		return ret;
	}

	public Fs_GpsProvider(final Context context)
	{
		m_locationManager=null;
		
		Fs_Application.runUiThread(new Runnable(){
			public void run(){

				Log.i(TAG,"set location manager ");
				m_locationManager=(LocationManager)context.getSystemService(Context.LOCATION_SERVICE);
				m_locationManager.requestLocationUpdates(LocationManager.GPS_PROVIDER, 1000, 1, m_locationListener);
			}
		});
	}

	void updateLocation()
	{
		if(m_locationManager==null)
		{
			return;
		}
		
		Location  ret= m_locationManager.getLastKnownLocation(LocationManager.GPS_PROVIDER);
		if(ret == null) 
		{
			Log.i("Fs_GpsProvider","GetLastKnownLoation Failed");
			ret=new Location(LocationManager.GPS_PROVIDER);
		}
		m_latitude=ret.getLatitude();
		m_longitude=ret.getLongitude();
	}

	double getLatitude()
	{
		return m_latitude;
	}
	double getLongitude()
	{
		return m_longitude;
	}

	void setLocation(Location l)
	{
		m_latitude=l.getLatitude();
		m_longitude=l.getLongitude();
	}

	private LocationListener m_locationListener=new LocationListener() {


		public void onLocationChanged(Location location) {
			setLocation(location);

			Log.i(TAG, "time:"+location.getTime()); 
			Log.i(TAG, "longitude:"+location.getLongitude()); 
			Log.i(TAG, "latitude:"+location.getLatitude()); 
			Log.i(TAG, "altitude:"+location.getAltitude()); 
		}


		public void onStatusChanged(String provider, int status, Bundle extras) {
			switch (status) {

				case LocationProvider.AVAILABLE:
					Log.i(TAG, "gps available");
					break;

				case LocationProvider.OUT_OF_SERVICE:
					Log.i(TAG, "gps out of service");
					break;

				case LocationProvider.TEMPORARILY_UNAVAILABLE:
					Log.i(TAG, "gps temporarily unavaliable");
					break;
			}
		}


		public void onProviderEnabled(String provider) {
			Location location=m_locationManager.getLastKnownLocation(provider);
			setLocation(location);
		}


		public void onProviderDisabled(String provider) {
	
		}



	};

}
















