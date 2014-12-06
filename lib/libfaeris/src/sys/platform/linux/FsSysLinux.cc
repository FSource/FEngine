#include <sys/stat.h>

#include <unistd.h>
#include <errno.h>
#include <time.h>

#include "sys/FsSys.h"

NS_FS_BEGIN
/*
FsLong Sys::getTime()
{
	return 0;

}
*/
void Sys::usleep(long time)
{
	struct timespec req= { time/1000, (time%1000)*1000000 };
	struct timespec rem;
	int ret=0;
	while(1)
	{
		ret=nanosleep(&req,&rem);
		if(ret==-1)
		{
			if(errno==EINTR)
			{
				req=rem;
				nanosleep(&req,&rem);
				continue;
			}
		}
		break;
	}
}

const char* Sys::currentDir()
{
	char* ret=getcwd(m_tempBuf,FS_SYS_TEMP_BUF_SIZE);
	return ret;
}



int Sys::mkdir(const char* dir_name)
{
	int ret=::mkdir(dir_name,0775);
	return ret;
}


bool Sys::isDir(const char* dir_name)
{
	struct stat st;
	if (stat(dir_name, &st) != 0)
    {
		return false;
    }
    else if (!S_ISDIR(st.st_mode))
    {
		return false;
    }
	return true;

}

void Sys::openInputTextDialog(const char* title,const char* msg,
							int input_mode,int input_flag,
							int return_type,int max_length)
{

}

void Sys::openNetSettingInterface()
{

}


NS_FS_END

