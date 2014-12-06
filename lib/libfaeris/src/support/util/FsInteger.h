#ifndef _FS_REFCONT_INTEGER_H_
#define _FS_REFCONT_INTEGER_H_
#include "FsMacros.h"
#include "FsObject.h"

NS_FS_BEGIN
class FsInteger:public FsObject 
{
	public:
		static FsInteger* create(int value);
		static bool checkType(FsObject* ob);

	public:
		FsInteger();
		FsInteger(int value);
		

		int getValue(){return m_value;}

	public:
		virtual long getHashCode();
		virtual const char* className();
		virtual bool equal(FsObject* ob);

	private:
		int m_value;
};

NS_FS_END 

#endif /*_FS_REFCONT_INTEGER_H_*/
