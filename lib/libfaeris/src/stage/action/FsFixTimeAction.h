#ifndef _FS_FIX_TIME_ACTION_H_
#define _FS_FIX_TIME_ACTION_H_

#include <functional>

#include "FsMacros.h"
#include "FsAction.h"
#include "math/easing/FsEaseExpr.h"

NS_FS_BEGIN

class FixTimeAction:public Action 
{

	public:
		static FixTimeAction* create(float total_time);


	public:
		/* inherit  Action */
		virtual bool run(ActionTarget* target,float dt,float* out);
		virtual bool restart();


		/* subclass interface */
		virtual void  step(ActionTarget* target,float percent); 

		/* inherit FsObject */
		virtual const char* className();

	public:
		std::function<void(FixTimeAction*,ActionTarget* ,float)> onStep;

	public:
		void setTotalTime(float time){m_totalTime=time;}
		float getTotalTime(){return m_totalTime;}

		void setCurTime(float time){m_curTime=time;}
		float getCurTime(){return m_curTime;}

		void setEasing(EaseExpr* easing){FS_SAFE_ASSIGN(m_easing,easing);}
		EaseExpr* getEasing(){return m_easing;}

		void setReverse(bool value){m_reverse=value;}
		bool getReverse(){return m_reverse;}

	protected:
		FixTimeAction(float time);
		FixTimeAction();
		virtual ~FixTimeAction();

	private:
		float m_totalTime;
		float m_curTime;
		EaseExpr* m_easing;
		bool m_reverse;
};



NS_FS_END




#endif /*_FS_FIX_TIME_ACTION_H_*/

