#include <Windows.h>
#include  <direct.h>  
#include  <stdio.h>  
#include <string>


NS_FS_BEGIN

void Sys::usleep(long time)
{
	Sleep(time);
}

const char* Sys::currentDir()
{
    _getcwd(m_tempBuf, FS_SYS_TEMP_BUF_SIZE); 
	return m_tempBuf;
}


int Sys::mkdir(const char* dir_name)
{
	int ret=CreateDirectory(dir_name,NULL);
	if(ret)
	{
		return 0;
	}
	else 
	{
		return -1;
	}
}

bool Sys::isDir(const char* dir_name)
{
	int ret=GetFileAttributes(dir_name);
	if(ret==FILE_ATTRIBUTE_DIRECTORY)
	{
		return true;
	}
	else 
	{
		return false;
	}
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




