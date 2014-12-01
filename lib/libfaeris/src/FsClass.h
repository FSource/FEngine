#ifndef _FS_CLASS_H_
#define _FS_CLASS_H_

#include "FsMacros.h"
#include "FsObject.h"
#include "FsEnums.h"

NS_FS_BEGIN

class FsString;
class FsDict;
class FsArray;

class FsClass :public FsObject 
{
	public:
		typedef  FsObject* (*NewInstanceFunc)(FsClass* cls);
		typedef void (*AttrSetFunc)(FsObject* ob,void*);
		typedef void* (*AttrGetFunc)(FsObject* ob);

	public:
		class FsAttributeDeclare
		{
			public:
				const char* name;
				FsType attrType;
				FsAttributeDeclare* subAttributeDeclare;
				AttrSetFunc setFunc;
				AttrGetFunc getFunc;
		};


		class FsAttribute:public FsObject
		{
			public:
				static FsAttribute* create(FsAttributeDeclare* desc)
				{
					FsAttribute* ret=new FsAttribute(desc);
					return ret;
				}

			public:
				bool callSet(FsObject* bo,const FsVariant& v);
				FsVariant callGet(FsObject* ob);
				FsString* getName(){return m_name;}


			protected:
				FsAttribute(FsAttributeDeclare* desc);
				~FsAttribute();

			protected:
				FsString* m_name;
				FsType m_attrType;
				FsDict* m_subAttributes;
				AttrSetFunc m_setFunc;
				AttrGetFunc m_getFunc;
		};

	public:
		static FsClass* create(const char* name,NewInstanceFunc new_func,FsAttributeDeclare* mb);
		static FsClass* create(FsClass* base,const char* name,NewInstanceFunc new_func,FsAttributeDeclare* mb);

	public:

		FsObject* newInstance();
		bool callSet(FsObject* ob,const char* name,const FsVariant& v);
		FsVariant callGet(FsObject* ob,const char* name);

		FsAttribute* getAttribute(const char* name);

	protected:
		FsClass();
		~FsClass();

		void init(FsClass* base,const char* name,NewInstanceFunc new_func,FsAttributeDeclare* mb);

	private:

		FsString* m_name;
		NewInstanceFunc m_newFunc;
		FsClass* m_baseClass;
		FsDict* m_attribute;
};






#define FS_CLASS_IMPLEMENT(cls,new_instnce,attrs) \
	FsClass* cls::m_fsclass=NULL; \
	FsClass* cls::getClass() \
	{ \
		if( cls::m_fsclass==NULL) \
		{ \
			cls::m_fsclass=FsClass::create(#cls,(FsClass::NewInstanceFunc)new_instnce,attrs); \
		} \
		return cls::m_fsclass; \
	} \
	FsClass* cls::getObjectClass()  \
	{ \
		return getClass(); \
	} \
	const char* getClassName()  \
	{ \
		static char* class_name=#cls; \
		return  class_name; \
	} \
	const char* className() \
	{ \
		return getClassName(); \
   	} \




NS_FS_END

#endif /*_FS_CLASS_H_*/
