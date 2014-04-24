#ifndef _FS_CATMULL_ROM_CURVE_H_
#define _FS_CATMULL_ROM_CURVE_H_

#include <vector>

#include "FsMacros.h"
#include "FsTCurve.h"

/* CatmullRomCurve: 
 *
 *  			   		| 0  , 1   , 0   , 0  |   |C0|
 * P(t)=[1,t,t^2,t^3] * | -f , 0   , f   , 0  | * |P0|
 *  			   		| 2f , f-3 , 3-2f, -f |   |P1|
 *  			   		| -f , 2-f , f-2 , f  |   |C1|
 *
 */


NS_FS_BEGIN 
template <typename T_Vector>

class TCatmullRomCurve:public TCurve<T_Vector> 
{
	public:
		void addPoint(const T_Vector& v)
		{
			m_points.push_back(v);
			m_dirty=true;
		}

		int getPointNu()
		{
			return m_points.size();
		}

		void clear()
		{
			m_points.clear();
			m_dirty=true;
		}

		void insertPoint(int index,const T_Vector& v)
		{
			assert(index>=0&&index<=(int)m_points.size());

			m_points.insert(m_points.begin()+index,v);
			m_dirty=true;
		}

		void removePoint(int index)
		{
			assert(index>=0&&index<(int)m_points.size());
			m_dirty=true;
		}

		void setAdditionalControlPoint(const T_Vector& start,const T_Vector& end)
		{
			m_additionStartPoint=start;
			m_additionEndPoint=end;
		}

		void setEnableAutoTangent(bool enable)
		{
			m_autoTangent=enable;
		}

		bool getEnabledAutoTangle()
		{
			return m_autoTangent;
		}


		void setTension(float tension)
		{
			m_tension=tension;
		}

		float getTension()
		{
			return m_tension;
		}


	public:
		virtual T_Vector getValue(float t)
		{
			int point_nu=m_points.size();

			if(point_nu==0) { FS_TRACE_WARN("No Point In CatmullRomCurve"); return T_Vector(); }
			if(point_nu==1) { return m_points[0]; }
			if(t<=0) { return m_points[0]; } 
			if(t>=1) { return m_points[point_nu-1]; }

			if(m_dirty)
			{
				calSegmentTime();
				m_dirty=false;
			}

			int index=getPreNearPointIndex(t);

			T_Vector c0,p0,p1,c1;

			if(index==0) 
			{ 
				if(m_autoTangent)
				{
					c0=m_points[0]*2-m_points[1]; 
				}
				else 
				{
					c0=m_additionStartPoint;
				}

			}
			else 
			{ 
				c0=m_points[index-1]; 
			}

			if (index==point_nu-2)
			{
				if(m_autoTangent)
				{
					c1=m_points[point_nu-1]*2-m_points[point_nu-2]; 
				}
				else 
				{
					c1=m_additionEndPoint;
				}
			}
			else 
			{
			   	c1=m_points[index+2]; 
			}

			float  rt=(t-m_times[index])/(t-m_times[index+1]);

			return catmulRomLerp(c0,m_points[index],m_points[index+1],c1,rt);

		}



	protected:
		void calSegmentTime()
		{
			int point_nu=m_points.size();

			assert(point_nu>=2);

			std::vector<float> seg_length;

			T_Vector p0=m_points[0];
			float total_length=0.0f;

			for(int i=1;i<point_nu;i++)
			{
				T_Vector p1=m_points[i];
				T_Vector dp=p1-p0;

				float l=dp.length();
				seg_length.push_back(l);
				total_length+=l;

				p0=p1;
			}

			m_times.clear();
			m_times.push_back(0.0f);

			float total_time=0.0f;

			for(int i=1;i<point_nu;i++)
			{
				if(total_length==0.0f)
				{
					m_times.push_back(float(i)/float(point_nu-1));
				}
				else 
				{
					total_time+=seg_length[i]/total_length;
					m_times.push_back(total_time);
				}
			}
		}


		int getPreNearPointIndex(float t)
		{
			float rt=0;
			int rb=0;
			int re=m_times.size()-1;
			while(re-rb>1)
			{
				int middle=(re+rb)/2;
				rt=m_times[middle];
				if (rt==t) { return middle; }
				if(t>rt)
				{
					rb=middle;
				}
				else 
				{
					re=middle;
				}
			}
			return rb;
		}

		T_Vector catmulRomLerp(const T_Vector& c0,const T_Vector& p0,const T_Vector& p1,const T_Vector& c1,float t)
		{
			float f=m_tension;

			float t2=t*t;
			float t3=t2*t;

			float a =      (-f)*t + (2*f)  *t2  +   (-f) *t3;
			float b =  1 +          (f-3)  *t2  +   (2-f)*t3;
			float c=        (f)*t + (3-2*f)*t2  +  (3-2*f)*t3;
			float d=                (-f)   *t2  +     (f)*t3;

			return c0*a+p0*b+p1*c+c1*d;
		}

	protected:
		TCatmullRomCurve()
		{
			m_dirty=false;
			m_autoTangent=true;
			m_tension=0.5f;
		}

	protected:

		bool m_dirty;
		bool m_autoTangent;

		float m_tension;

		T_Vector m_additionStartPoint;
		T_Vector m_additionEndPoint;

		std::vector<T_Vector> m_points;
		std::vector<float> m_times;

};


class CatmullRomCurve2:public TCatmullRomCurve<Vector2>
{
	public:
		static CatmullRomCurve2* create();

	public:
		virtual const char* className();

};

class CatmullRomCurve3:public TCatmullRomCurve<Vector3>
{
	public:
		static CatmullRomCurve3* create();

	public:
		virtual const char* className();

};

class CatmullRomCurve4:public TCatmullRomCurve<Vector4>
{
	public:
		static CatmullRomCurve4* create();

	public:
		virtual const char* className();
};


NS_FS_END 

#endif /*_FS_CATMULL_ROM_CURVE_H_*/

















