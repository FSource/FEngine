/*************************************************************************/
/*  FsProgram.h                                                          */
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






