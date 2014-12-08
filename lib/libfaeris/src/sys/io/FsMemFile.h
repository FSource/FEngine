#ifndef _FAERY_MEM_FILE_H_
#define _FAERY_MEM_FILE_H_

#include "sys/io/FsFile.h"

NS_FS_BEGIN
class MemFile:public FsFile
{
	public:
		static MemFile* create();
		static MemFile* create(ulong len);
		static MemFile* create(const void* mem,ulong len);
	public:
		/* inherit FsFile */
		virtual long read(void* buf,long len);
		virtual long write(const void* buf,long len);
		virtual long seek(long offset,E_FileSeek where);
		virtual long tell();
		virtual int close();

		/* inherit FsObject */
		virtual const char* className();
	public:
		void* getInternalBuffer();

	protected:
		MemFile();
		virtual ~MemFile();

		virtual bool init();
		virtual bool init(ulong len);
		virtual bool init(const void* mem,ulong len);

		void ensureMore(ulong len);
	private:
		uint8_t* m_mem;
		ulong m_length;
		ulong m_cap;
		ulong m_pos;
};
NS_FS_END

#endif /*_FAERY_MEM_FILE_H_*/





