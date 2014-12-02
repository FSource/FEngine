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
				FsAttributeDeclare(const char* _name,FsType _type,FsAttributeDeclare* _sub,
									AttrSetFunc _setFunc,AttrGetFunc _getFunc)
				{
					name=_name;
					attrType=_type;
					subAttributeDeclare=_sub;
					setFunc=_setFunc;
					getFunc=_getFunc;
				}

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
		bool callSet(FsObject* ob,FsString* name,const FsVariant& v);

		FsVariant callGet(FsObject* ob,const char* name);
		FsVariant callGet(FsObject* ob,FsString* name);

		bool callSets(FsObject* ob,FsDict* dict);


		FsAttribute* getAttribute(const char* name);
		FsAttribute* getAttribute(FsString* name);

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
	FsClass* cls::objectClass()  \
	{ \
		return cls::getClass(); \
	} \
	const char* cls::getClassName()  \
	{ \
		static char* class_name=#cls; \
		return  class_name; \
	} \
	const char* cls::className() \
	{ \
		return cls::getClassName(); \
   	} \


#define FS_CLASS_ATTR_GET_SET_FUNCTION(cls,set,get,t)  \
	static  void cls##_##set(cls* ob,t* v) \
	{ \
		ob->set(*v); \
	} \
	static const t* cls##_##get(cls* ob)  \
	{ \
		return &ob->get(); \
	} \
	
#define FS_CLASS_ATTR_DECLARE(name,type,sub_attr,set_func,get_func) \
	FsClass::FsAttributeDeclare(name,type, \
			sub_attr, \
			(FsClass::AttrSetFunc)set_func, \
			(FsClass::AttrGetFunc)get_func)
 



 
 


NS_FS_END

#endif /*_FS_CLASS_H_*/
