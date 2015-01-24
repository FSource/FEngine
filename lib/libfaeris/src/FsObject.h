/*************************************************************************/
/*  FsObject.h                                                           */
/*************************************************************************/
/* Copyright (C) 2012-2014 nosiclin@foxmail.com                          */
/* Copyright (C) 2014-2015 www.fsource.cn                                */
/*                                                                       */
/* http://www.fsource.cn                                                 */
/*                                                                       */
/* Permission is hereby granted, free of charge, to any person obtaining */
/* a copy of this software and associated documentation files (the       */
/* "Software"), to deal in the Software without restriction, including   */
/* without limitation the rights to use, copy, modify, merge, publish,   */
/* distribute, sublicense, and/or sell copies of the Software, and to    */
/* permit persons to whom the Software is furnished to do so, subject to */
/* the following conditions:                                             */
/*                                                                       */
/* The above copyright notice and this permission notice shall be        */
/* included in all copies or substantial portions of the Software.       */
/*                                                                       */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,       */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF    */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.*/
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY  */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,  */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE     */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                */
/*************************************************************************/


#ifndef _FS_OBJECT_H_
#define _FS_OBJECT_H_ 

#include <functional>
#include "FsMacros.h"
#include "FsVariant.h"

#define FS_INVALID_HASH_CODE (-1)

NS_FS_BEGIN

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
#if FS_CONFIG(FS_SCRIPT_SUPPORT)
			m_userData(NULL),
			m_scriptData(-1)
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




