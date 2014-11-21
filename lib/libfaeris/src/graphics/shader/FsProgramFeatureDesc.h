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


