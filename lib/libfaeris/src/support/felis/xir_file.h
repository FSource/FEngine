#ifndef _FAERY_XIR_SCRIPT_FILE_H_
#define _FAERY_XIR_SCRIPT_FILE_H_ 

#define FS_EOF (-1)
#include "sys/io/FsFile.h"

class XirFile
{
	public:
		XirFile(Faeris::FsFile* file);
		~XirFile();

	public:
		int nextChar();
		void mark()
		{
			m_mark=m_buf_pos;
		}
		void backToMark()
		{
			m_buf_pos=m_mark;
		}
		void forwardToMark()
		{
			m_begin=m_mark;
			m_buf_pos=m_mark;
		}

	protected:
		int loadData();

	private:
		Faeris::FsFile* m_file;
		char* m_buf;
		int m_buf_cap;
		int m_buf_size;
		int m_begin;
		int m_mark;
		int m_buf_pos;
};
#endif  /* _FAERY_XIR_SCRIPT_FILE_H_ */


