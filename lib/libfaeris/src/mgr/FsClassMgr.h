#ifndef _FS_CLASS_MGR_H_
#define _FS_CLASS_MGR_H_

#include "FsMacros.h"
#include "FsObject.h"

NS_FS_BEGIN

class FsClass;
class FsString;
class FsDict;

class ClassMgr:public FsObject 
{
	public:
		static ClassMgr* create();

	public:
		FsObject* newInstance(FsDict* dict);

	public:
		FsClass* getClass(FsString* name);
		FsClass* getClass(const char* name);

		void registerClass(FsString* name,FsClass* cls);
		void registerClass(const char* name,FsClass* cls);

		void unRegisterClass(const char* name);
		void unRegisterClass(FsString* name);

		void unRegisterAll();


		void preRegisterClass();

	protected:
		ClassMgr();
		~ClassMgr();


	private:
		FsDict* m_cls;

};

NS_FS_END

#endif /*_FS_CLASS_MGR_H_*/



