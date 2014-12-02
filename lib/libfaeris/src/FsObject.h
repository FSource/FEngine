#ifndef _FS_OBJECT_H_
#define _FS_OBJECT_H_ 

#include <functional>
#include "FsMacros.h"
#include "FsVariant.h"

#define FS_INVALID_HASH_CODE (-1)

NS_FS_BEGIN

class ObjectMgr;
class FsDict;
class FsObject 
{
	/* class attribute */
	private:
		static int m_objectNu;
	public:
		static int getObjectNu(){return FsObject::m_objectNu;}


	public:
		FS_CLASS_DECLARE(FsObject);

	public:
		void setAttributes(FsDict* dict);
		void setAttribute(const char* name,const FsVariant& v);
		FsVariant getAttribute(const char* name);

	/* object attribute */
	private:
		bool m_refDelete;
		int m_refNu;
		ObjectMgr* m_objectMgr;
		void* m_userData;

	public:
		int refCnt(){return m_refNu;}
		void addRef(){m_refNu++;}
		void decRef()
		{
			m_refNu--;
			if((m_refNu<=0)&&m_refDelete)
			{
				delete this;
			}
		}
		void setRefDelete(bool value)
		{
			m_refDelete=value;
		}
		bool getRefDelete(){return m_refDelete;}

		void destroy()
		{
			FS_TRACE_WARN_ON(m_refNu>1,"Object(%s) Is Owner By Other %d Object",className(),m_refNu);
			delete this;
		}
		void autoDestroy()
		{
			if(m_refNu<=0)
			{
				delete this;
			}
		}

		void setUserData(void* data)
		{
			m_userData=data;
		}

		void* getUserData()
		{
			return m_userData;
		}

	public:
		std::function<void(FsObject*)> onFinalize;


	public:
		FsObject()
			:m_refDelete(true),
			m_refNu(0),
			m_objectMgr(NULL),
#if FS_CONFIG(FS_SCRIPT_SUPPORT)
			m_scriptData(-1),
			m_userData(NULL)
#endif 
		{ 

			onFinalize=nullptr;
			FsObject::m_objectNu++;
		}

		virtual ~FsObject();
		virtual long getHashCode();
		virtual bool equal(FsObject* ob); 
		virtual void finalize();

#if FS_CONFIG(FS_SCRIPT_SUPPORT)
	public:
		int m_scriptData; /* script data */
	public:
		void dropScriptData();
#endif 

};
NS_FS_END

#endif  /*_FS_OBJECT_H_*/




