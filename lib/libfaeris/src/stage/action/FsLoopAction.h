#ifndef _FS_LOOP_ACTION_H_
#define _FS_LOOP_ACTION_H_

#include "FsMacros.h"
#include "FsAction.h"

NS_FS_BEGIN

class LoopAction:public Action 
{
	public:
		/* if count is -1, mean loop forever 
		 * else loop for count value
		 */
		static LoopAction* create(Action* action,int count);

		/* LoopAction will forever */
		static LoopAction* create(Action* action);

	public:
		/* inherit Action */
		virtual bool update(ActionTarget* target,float dt,float* out);
		virtual bool run(ActionTarget* target,float dt,float* out)=0;
		virtual bool restart();

		/* inherit FsObject */
		virtual const char* className();

	public:
		void getTotalLoopNu(){return m_totalLoopNu;}
		void setTotalLoopNu(int count){m_totalLoopNu=count;}

		void getCurLoopNu(){return m_curLoopNu;}
		void setCurLoopNu(int count){m_curLoopNu=count;}


	protected:
		LoopAction(Action* action,int count);
		virtual ~LoopAction();

	private:
		int m_totalLoopNu;
		int m_curLoopNu;
		Action* m_action;
};


NS_FS_END

#endif /*_FS_LOOP_ACTION_H_*/
