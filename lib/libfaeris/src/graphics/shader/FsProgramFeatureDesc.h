/*************************************************************************/
/*  FsProgramFeatureDesc.h                                               */
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


#ifndef _FS_PROGRAM_FEATURE_DESC_H_
#define _FS_PROGRAM_FEATURE_DESC_H_

#include <string>
#include "FsMacros.h"
#include "FsObject.h"
#include "FsEnums.h"

NS_FS_BEGIN

class ProgramFeatureDesc:public FsObject
{

	public:
		static ProgramFeatureDesc* create();
		static bool equal(ProgramFeatureDesc* l,ProgramFeatureDesc* r,uint32_t flags);

	public:
		/* inherit */
		const char* className() FS_OVERRIDE;
		bool equal(FsObject* v) FS_OVERRIDE
		{
			ProgramFeatureDesc* desc = dynamic_cast<ProgramFeatureDesc*>(v);
			if(desc)
			{
				uint32_t flag=0;
				return ProgramFeatureDesc::equal(this,desc,~flag);
			}
			return false;
		}


	public:
		ProgramFeatureDesc* clone() ;
		void copy(ProgramFeatureDesc* desc) ;

	public:
		void setSupportFlags(uint32_t flag){m_supportFlags=flag;}
		uint32_t getSupportFlags(){return m_supportFlags;}

		void addSupportFlag(uint32_t flag){m_supportFlags|=flag;}

		void removeSupportFlag(uint32_t flag){m_supportFlags&=~flag;}

		void clearSupportFlags(ulong flag){m_supportFlags=0;}


	protected:
		ProgramFeatureDesc();


	public:

		/* feature support flags */
		uint32_t m_supportFlags;


		/* light info */
		int m_ambientLightNu;
		int m_directionalLightNu;
		int m_pointLightNu;
		int m_spotLightNu;
		int m_hemiSphereLightNu;

		/* shadow info */
		int m_shadowMapNu;
		E_ShadowType m_shadowType;

		/* fog */
		E_FogType m_fogType;

		/* bone */
		int m_boneNu;

};


NS_FS_END

#endif /*_FS_PROGRAM_FEATURE_DESC_H_*/


