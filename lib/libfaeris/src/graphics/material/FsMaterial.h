#ifndef _FS_BASE_MATERIAL_H_
#define _FS_BASE_MATERIAL_H_


#include <vector>

#include "FsMacros.h"
#include "FsEnums.h"
#include "mgr/FsResource.h"
#include "FsObject.h"
#include "graphics/FsRenderDevice.h"



NS_FS_BEGIN

class Program;
class ProgramFeatureDesc;


class Material:public Resource
{
	public:
		Material();
		virtual ~Material();
		virtual const char* className();

	public:
		/* blend */
		void setBlend(E_BlendEquation equation,E_BlendFactor src,E_BlendFactor dst)
		{
			m_blendEquation=equation;
			m_blendSrc=src;
			m_blendDst=dst;
		}

		void setBlend(E_BlendFactor src,E_BlendFactor dst)
		{
			m_blendEquation=E_BlendEquation::ADD;
			m_blendSrc=src;
			m_blendDst=dst;
		}


		E_BlendEquation getBlendEquation() { return m_blendEquation; }
		E_BlendFactor getBlendSrc() { return m_blendSrc; }
		E_BlendFactor getBlendDst() { return m_blendDst; }


		void setDoubleSideEnabled(bool value) {m_doubleSideEnabled=value;}
		bool getDoubleSideEnabled(){return m_doubleSideEnabled;}

		void setFrontSide(E_FrontFace front){m_frontSide=front;}
		E_FrontFace getFrontSide(){return m_frontSide;}

		/* depth test */
		void setDepthTestEnabled(bool enable) { m_depthTestEnabled=enable; }
		bool getDepthTestEnabled() { return m_depthTestEnabled; }

		void setDepthWriteEnabled(bool enable) {m_depthWriteEnabled=enable;}
		bool getDepthWriteEnabled(){return m_depthWriteEnabled;}



	public:
		virtual Program* getProgram(ProgramFeatureDesc* desc)=0;
		virtual void configRenderDevice(RenderDevice* rd);

	protected:
		/* render state */
		bool m_wireframe;

		E_BlendEquation m_blendEquation;
		E_BlendFactor m_blendSrc;
		E_BlendFactor m_blendDst;

		E_FrontFace m_frontSide;

		bool m_depthTestEnabled;
		bool m_depthWriteEnabled;
		bool m_doubleSideEnabled;

};

NS_FS_END 

#endif /*_FS_MATTERIAL_H_*/


