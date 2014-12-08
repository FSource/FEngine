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
#include "support/util/FsArray.h"
#include "FsUniformMap.h"
#include "FsStreamMap.h"



#if FS_CONFIG(FS_GLES2_0_RENDER_DEVICE) 
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
		static Program* create(ProgramSource* source,ProgramFeatureDesc* desc);
		static Program* create(ProgramSource* source);

	public:

		bool canMatch(ProgramFeatureDesc* desc);

		/* return the location of the  Attribute/Uniform 
		 * if not exist in program,-1 will returned 
		 */

		int getUniformLocation(const char* name);
		int getCacheUniformLocation(int index,const char* name);

		int getAttrLocation(const char* name);
		int getCacheAttrLocation(int index,const char* name);


		PlatformProgram getPlatformProgram()const{return m_program;}
		virtual const char* className();


		ProgramFeatureDesc*  getFeatureDesc()
		{
			return m_featureDesc;
		}

		void setFeatureDesc(ProgramFeatureDesc* desc)
		{
			m_featureDesc=desc;
		}

		/* uniform map */
		UniformMap* getUniformMap(int index)
		{
			return (UniformMap*)m_uniformMaps->get(index);
		}

		int getUniformMapNu()
		{
			return m_uniformMaps->size();
		}

		void addUniformMap(UniformMap* map)
		{
			m_uniformMaps->push(map);
		}

		/* stream map */
		StreamMap* getStreamMapFromSeq(int index)
		{
			return (StreamMap*)m_streamMaps->get(index);
		}

		int getStreamMapNu()
		{
			return m_streamMaps->size();
		}

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
		bool init(ProgramSource* source,ProgramFeatureDesc* desc);

	private:
		FS_FEATURE_WEAK_REF(ProgramSource*) m_programSource;
		ProgramFeatureDesc* m_featureDesc;

		int m_cacheUniformLoc[FS_PROGRAM_CACHE_UNIFORM_SUPPORT];
		int m_cacheAttrLoc[FS_PROGRAM_CACHE_ATTR_SUPPORT];

		FsArray* m_uniformMaps;
		FsArray* m_streamMaps;

		StreamMap* m_seqStreamMaps[static_cast<int>(E_StreamType::MAX_NU)];

		/* platform type */
		PlatformProgram m_program;
};

NS_FS_END 

#endif  /*_FS_PROGRAM_H_*/






