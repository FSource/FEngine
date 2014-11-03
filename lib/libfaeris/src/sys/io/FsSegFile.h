#ifndef _FS_SEG_FILE_H_
#define _FS_SEG_FILE_H_ 

#include "FsMacros.h"
#include "sys/io/FsFile.h"

NS_FS_BEGIN
class SegFile:public FsFile 
{
	public:
		static SegFile* create(FsFile* file,uint32_t offset,uint32_t length);

	public:
		/* override FsFile */
		virtual long read(void* buf,long length);
		virtual long write(const void* buf,long length);
		virtual long seek(long offset,E_FileSeek where);
		virtual int  close();
		virtual long tell();
		virtual long getLength();

	public: 
		/* override FsObject */
		virtual const char* className();

	protected:
		virtual ~SegFile();
		SegFile();
		void destruct();
		bool init(FsFile* file,uint32_t offset,uint32_t length);

	private:
		FsFile* m_stream;
		uint32_t m_offset;
		uint32_t m_length;
		uint32_t m_curpos;
};



NS_FS_END 



#endif /*_FS_SEG_FILE_H_*/

