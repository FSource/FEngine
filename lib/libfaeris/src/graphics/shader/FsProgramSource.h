#ifndef _FS_PROGRAM_SOURCE_H_
#define _FS_PROGRAM_SOURCE_H_ 


#include <vector>
#include <string>

#include "mgr/FsResource.h"

NS_FS_BEGIN

class FsFile;
class UniformMap;
class StreamMap;
class ProgramFeatureDesc;
class Program;
class FsDict;

class ProgramSource:public Resource
{
	public:
		static ProgramSource* create(const char* filename);
		static ProgramSource* create();
		static ProgramSource* create(FsFile* file);

	public:
		virtual const char* className();

	public:
		void setVertexStr(const char* str)
		{
			m_vertexSrc=str;
		}

		const char* getVertexStr()
		{
			return m_vertexSrc.c_str();
		}

		void setFragmentStr(const char* str)
		{
			m_fragmentSrc=str;
		}

		const char* getFragmentStr()
		{
			return m_fragmentSrc.c_str();
		}

		/* uniform map */
		UniformMap* getUniformMap(int index)
		{
			return m_uniformMaps[index];
		}

		int getUniformMapNu()
		{
			return m_uniformMaps.size();
		}

		/* stream map */
		StreamMap* getStreamMap(int index)
		{
			return m_streamMaps[index];
		}

		int getStreamMapNu()
		{
			return m_streamMaps.size();
		}


		/* support flags */
		uint32_t getSupportFlags()
		{
			return m_supportFlags;
		}

	public:
		Program* getProgram(ProgramFeatureDesc* desc);

	protected:
		ProgramSource();
		virtual ~ProgramSource();
		bool init(FsFile* file);
		bool init(const char* filename);

		void addStreamMap(StreamMap* map){m_streamMaps.push_back(map);}
		void addUniformMap(UniformMap* map){m_uniformMaps.push_back(map);}


	protected:
		std::string m_vertexSrc;
		std::string m_fragmentSrc;
		std::vector<UniformMap*> m_uniformMaps;
		std::vector<StreamMap*> m_streamMaps;


		Program* m_defaultProgramCache;
		FsDict* m_programCache;

		uint32_t m_supportFlags;

};

NS_FS_END


#endif /*_FS_PROGRAM_SOURCE_H_*/

