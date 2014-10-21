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
#define FS_PROGRAM_CACHE_ATTR_SUPPORT 32

NS_FS_BEGIN 




class ProgramFeatureDesc:public FsObject
{
	public:
		static ProgramFeatureDesc* create();

	public:
		/* inherit */
		virtual const char* className();
		virtual ProgramFeatureDesc* clone();
		virtual void copy(ProgramFeatureDesc* desc);

	public:
		void setSupportFlags(ulong flag);
		void clearSupportFlags(ulong flag);

	protected:
		ProgramFeatureDesc();

	public:

		/* feature support flags */
		ulong m_supportFlags;

		/* light info */
		int m_directionalLightNu;
		int m_pointLightNu;
		int m_SpotLightNu;
		int m_HemiSphereLightNu;

		/* shadow info */
		int m_shadowMapNu;
		E_ShadowType m_shadowType;

		/* fog */
		E_FogType m_fogType;

		/* bone */
		int m_boneNu;

		/* name */
		std::string m_name;
};


class Program:public Resource
{
	public:
		static Program* create(const char* vertex_src,const char* fragment_src);
		static Program* create(ProgramFeatureDesc* desc,const char* vertex_src,const char* fragment_src);

	public:
		/* return the location of the  Attribute/Uniform 
		 * if not exist in program,-1 will returned 
		 */

		int getUniformLocation(const char* name);
		int getCacheUniformLocation(int index,const char* name);

		int getAttrLocation(const char* name);
		int getCacheAttrLocation(int index,const char* name);


		PlatformProgram getPlatformProgram()const{return m_program;}
		virtual const char* className();


		const ProgramFeatureDesc&  getFeatureDesc(){return m_featureDesc;}
		void setFeatureDesc(const ProgramFeatureDesc& desc){m_featureDesc=desc;}


	protected:
		Program();
		~Program();

		bool init(const char* vertex_src,const char* fragment_src);

	private:

		ProgramFeatureDesc m_featureDesc;

		int m_cacheUniformLoc[FS_PROGRAM_CACHE_UNIFORM_SUPPORT];
		int m_cacheAttrLoc[FS_PROGRAM_CACHE_ATTR_SUPPORT];

		/* platform type */
		PlatformProgram m_program;
};

NS_FS_END 

#endif  /*_FS_PROGRAM_H_*/






