#ifndef _LIB_MD5_MODEL_EXT_H_
#define _LIB_MD5_MODEL_EXT_H_


#define fileno(x) 0
#define isatty(x) 0

	

char* libmd5_strdup(const char* s);
int libmd5_input(void* buf,int size);


#define YY_INPUT(buf,result,max_size) \
	result=libmd5_input(buf,max_size)
	



#endif /*_LIB_MD5_MODEL_EXT_H_*/

