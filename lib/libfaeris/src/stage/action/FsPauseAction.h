#ifndef _FS_PAUSE_ACTION_H_
#define _FS_PAUSE_ACTION_H_

#include "FsAction.h"

NS_FS_BEGIN
class PauseAction:public Action 
{
	public:
		static PauseAction* create(float time);

	public:
		/* inherit Action */
		virtual bool run(ActionTarget* target,float dt,float* out);
		virtual bool restart();

		/* inherit FsObject */
		virtual const char* className();

	public:
		void setPauseTime(float time){m_lifeTime=time;}
		float getPauseTime(){return m_lifeTime;}


	protected:
		PauseAction();
		void initTotalTime(float time){ m_lifeTime=time; }


	private:
		float m_elapse;
		float m_lifeTime;
};

NS_FS_END



#endif /*_FS_PAUSE_ACTION_H_*/

