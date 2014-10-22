#ifndef _FS_PROGRAM_FEATURE_DESC_H_
#define _FS_PROGRAM_FEATURE_DESC_H_

#include "FsMacros.h"
#include "FsObject.h"

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


NS_FS_END

#endif /*_FS_PROGRAM_FEATURE_DESC_H_*/


