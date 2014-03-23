#ifndef _FS_PROGRAM_H_
#define _FS_PROGRAM_H_

#include <string>
#include "FsMacros.h"
#include "sys/io/FsFile.h"
#include "FsConfig.h"
#include "FsObject.h"
#include "mgr/FsResource.h"
#include "support/util/FsDict.h"
#include "support/util/FsString.h"

#if FS_CONFIG(FS_GL_RENDER) ||FS_CONFIG(FS_GLES_RENDER)
	typedef uint PlatformProgram;
#else 
	#error "Unsupport PlatformProgram"
#endif 


#define FS_PROGRAM_CACHE_UNIFORM_SUPPORT  128
#define FS_PROGRAM_CACHE_LOC_SUPPORT 32

NS_FS_BEGIN 





class Program:public Resource
{
	public:
		static Program* create(const char* vertex_src,const char* fragment_src);

	public:
		/* return the location of the  Attribute/Uniform 
		 * if not exist in program,-1 will returned 
		 */
		int getAttrLocation(const char* name);
		int getUniformLocation(const char* name);

		int getCacheAttLocation(int index,const char* name);
		int getCacheUniformLocation(int index,const char* name);


		PlatformProgram getPlatformProgram()const{return m_program;}
		virtual const char* className();

		void reload();
		void markInvalid();


	protected:
		Program();
		~Program();

		bool init(const char* vertex_src,const char* fragment_src);


	private:
		PlatformProgram m_program;
		int m_cacheAttrLoc[FS_PROGRAM_CACHE_ATTR_SUPPORT];
		int m_cacheUniformLoc[FS_PROGRAM_CACHE_UNIFORM_SUPPORT];
		std::string m_vertSrc;
		std::string m_fragSrc;
		
};

NS_FS_END 

#endif  /*_FS_PROGRAM_H_*/






