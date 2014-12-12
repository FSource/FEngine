#ifndef _FS_REFCONT_STRING_H_
#define _FS_REFCONT_STRING_H_
#include <string>

#include "FsMacros.h"
#include "FsObject.h"

NS_FS_BEGIN
class FsString:public FsObject
{
	private:
		std::string m_string;
		long m_hash_code;
	public:
		static FsString* create();
		static FsString* create(const char* str);
		static bool checkType(FsObject* ob);

	public: 
		FsString();
		FsString(const char* str);
		FsString(int value);

	public:
		int toIntValue();
		float toFloatValue();

	public:
		virtual long getHashCode();
		virtual const char* className();
		virtual bool equal(FsObject* ob);
		virtual bool equal(const char* str);
	public:
		FsString& append(const char* str);
		FsString& append(const char* str,long n);
		FsString& append(const FsString& str);
		FsString& append(const FsString& str,long n);

		FsString& assign(const FsString& str);
		FsString& assign(const FsString& str,long n);
		FsString& assign(const char* str);
		FsString& assign(const char* str,long n);

		void clear();
		int compare(const FsString& str) const;
		int compare(const char* str)const;
		const char* cstr()const;
		bool empty()const; 
		ulong length()const;
		FsString& erase(long pos,long num=1);
		char operator[](ulong n)const ;
	private:
		inline void mCalHashCode();
};
NS_FS_END 

#include "FsString.inl"

#endif  /*_FS_REFCONT_STRING_H_*/
	





	
