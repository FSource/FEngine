#ifndef _FS_T_EVENT_DISPATCHER_H_
#define _FS_T_EVENT_DISPATCHER_H_ 


#include <vector>
#include "FsMacros.h"
#include "scheduler/FsSchedulerTarget.h"
#include "FsObject.h"
#include "support/util/FsSlowArray.h"

NS_FS_BEGIN

template<typename T_Event,typename T_Listener>
class TEventDispatcher:public SchedulerTarget 
{
	public:
		typedef  std::vector<T_Event*> EventQueue;

	public:
		/* override SchedulerTarget */
        virtual void update(int /*priority*/,float /*dt*/)
		{
			flush();
		}

	public:
		void dispatchEvent(T_Event* event)
		{
			m_eventPending->push_back(event);
		}

		void flush()
		{
			swapEventQueue();
			int event_nu=m_eventHandling->size();

			m_listenerArray->lock();
			for(int i=0;i<event_nu;i++)
			{
				T_Event* event=m_eventHandling->at(i);
				int listen_nu=m_listenerArray->size();

				for(int j=0;j<listen_nu;j++)
				{
					T_Listener* listen=(T_Listener*)m_listenerArray->get(j);
					listen->handleEvent(event);
				}
			}
			m_listenerArray->unlock();
			m_listenerArray->flush();
			clearEventQueue(m_eventHandling);
		}
		void clearPending()
		{
			clearEventQueue(m_eventPending);
		}

	public:
		void addListener(T_Listener* l)
		{
			m_listenerArray->push(l);
		}
		void removeListener(T_Listener* l)
		{
			m_listenerArray->remove(l);
		}

	protected:
		TEventDispatcher()
		{
			init();
		}
		virtual ~TEventDispatcher()
		{
			destruct();
		}
		void init()
		{
			m_eventPending=new EventQueue;
			m_eventHandling=new EventQueue;

			m_listenerArray=FsSlowArray::create();
			FS_NO_REF_DESTROY(m_listenerArray);

		}

		void destruct()
		{
			clearEventQueue(m_eventPending);
			clearEventQueue(m_eventHandling);
			delete m_eventPending;
			delete m_eventHandling;

			FS_DESTROY(m_listenerArray);

			m_eventPending=NULL;
			m_eventHandling=NULL;
			m_listenerArray=NULL;
		}

		void swapEventQueue()
		{
			EventQueue* tmp=m_eventHandling;
			m_eventHandling=m_eventPending;
			m_eventPending=tmp;
		}

		void clearEventQueue(EventQueue* queue)
		{
			typename EventQueue::iterator iter=queue->begin();
			for(;iter!=queue->end();++iter)
			{
				delete *iter;
			}
			queue->clear();
		}

	protected:
		EventQueue* m_eventPending;
		EventQueue* m_eventHandling;
		FsSlowArray* m_listenerArray;
};

NS_FS_END

#endif /*_FS_T_EVENT_DISPATCHER_H_*/



