/*************************************************************************/
/*  FsProgramSource.h                                                    */
/*************************************************************************/
/* Copyright (C) 2012-2014 nosiclin@foxmail.com                          */
/* Copyright (C) 2014-2015 www.fsource.cn                                */
/*                                                                       */
/* http://www.fsource.cn                                                 */
/*                                                                       */
/* Permission is hereby granted, free of charge, to any person obtaining */
/* a copy of this software and associated documentation files (the       */
/* "Software"), to deal in the Software without restriction, including   */
/* without limitation the rights to use, copy, modify, merge, publish,   */
/* distribute, sublicense, and/or sell copies of the Software, and to    */
/* permit persons to whom the Software is furnished to do so, subject to */
/* the following conditions:                                             */
/*                                                                       */
/* The above copyright notice and this permission notice shall be        */
/* included in all copies or substantial portions of the Software.       */
/*                                                                       */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,       */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF    */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.*/
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY  */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,  */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE     */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                */
/*************************************************************************/


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

