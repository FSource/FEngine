#ifndef _FS_PROGRAM_H_
#define _FS_PROGRAM_H_

#include <vector>
#include <string>
#include "FsMacros.h"
#include "FsEnums.h"
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

class UniformMap;
class StreamMap;
class ProgramFeatureDesc;
class ProgramSource;

class Program:public Resource
{
	public:
		static Program* create(const char* vertex_src,const char* fragment_src);
		static Program* create(ProgramFeatureDesc* desc,ProgramSource* source);
		static Program* create(ProgramSource* source);

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


		const ProgramFeatureDesc*  getFeatureDesc(){return m_featureDesc;}
		void setFeatureDesc(ProgramFeatureDesc* desc){m_featureDesc=desc;}

		/* uniform map */
		UniformMap* getUniformMap(int index){return m_uniformMaps[index];}
		int getUniformMapNu(){return m_uniformMaps.size();}
		void addUniformMap(UniformMap* map){m_uniformMaps.push_back(map);}

		/* stream map */
		StreamMap* getStreamMap(int index){return m_streamMaps[index];}
		int getStreamMapNu(){return m_streamMaps.size();}
		void addStreamMap(StreamMap* map);

		StreamMap* getStreamMap(E_StreamType t)
		{
			return m_seqStreamMaps[static_cast<int>(t)];
		}


	protected:
		Program();
		~Program();

		bool init(const char* vertex_src,const char* fragment_src);
		bool init(ProgramSource* source);

	private:

		ProgramFeatureDesc* m_featureDesc;

		int m_cacheUniformLoc[FS_PROGRAM_CACHE_UNIFORM_SUPPORT];
		int m_cacheAttrLoc[FS_PROGRAM_CACHE_ATTR_SUPPORT];

		std::vector<UniformMap*> m_uniformMaps;
		std::vector<StreamMap*> m_streamMaps;

		StreamMap* m_seqStreamMaps[E_StreamType::MAX_NU];

		/* platform type */
		PlatformProgram m_program;
};

NS_FS_END 

#endif  /*_FS_PROGRAM_H_*/






