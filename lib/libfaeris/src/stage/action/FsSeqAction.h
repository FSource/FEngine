#ifndef _FS_SEQ_ACTION_H_
#define _FS_SEQ_ACTION_H_

#include "stage/action/FsAction.h" 

NS_FS_BEGIN

class FsArray;
class Scene;
class SeqAction:public Action 
{
	public:
		static SeqAction* create();

	public:
		/* inherit Action */
		virtual bool run(ActionTarget* target,float dt,float* out);
		virtual bool restart();

		/* inherit FsObject  */
		virtual const char* className();

	public:

		void addAction(Action* action);
		void removeAction(Action* action);
		void clearAction();

	protected:

		SeqAction();
		virtual ~SeqAction();

		bool init();
		void destruct();

	private:
		FsArray* m_actions;
		int m_curIndex;
};




NS_FS_END


#endif /*_FS_SEQ_ACTION_H_*/

