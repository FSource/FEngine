#ifndef _FS_STRAM_MAP_H_
#define _FS_STRAM_MAP_H_

#include "FsMacros.h"
#include "FsEnums.h"

#include "FsObject.h"



NS_FS_BEGIN

class StreamMap :public FsObject
{
	public:
		static StreamMap* create(const char* name,E_StreamType ref_type)
		{
			return new StreamMap(name,ref_type);
		}

	public:
		StreamMap* clone()
		{
			StreamMap* ret=new StreamMap(m_name.c_str(),m_refType);
			return ret;
		}

	protected:
		StreamMap(const char* name,E_StreamType ref_type)
			:m_name(name),
			m_refType(ref_type),
			m_location(-2)
		{ }

	public:
		std::string m_name;
		E_StreamType m_refType;
		int m_location;
};

NS_FS_END

#endif /*_FS_STRAM_MAP_H_ */

