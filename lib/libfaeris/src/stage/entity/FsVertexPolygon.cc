#include "stage/entity/FsVertexPolygon.h"
#include "FsGlobal.h"
#include "mgr/FsProgramSourceMgr.h"
#include "graphics/shader/FsStreamMap.h"
#include "graphics/shader/FsProgram.h"
#include "FsClass.h"



NS_FS_BEGIN



VertexPolygon* VertexPolygon::create()
{
	VertexPolygon* ret=new VertexPolygon();
	if(!ret->init())
	{
		delete ret;
		return NULL;
	}

	return ret;
}





void VertexPolygon::setVertex(uint index,Vector3 v)
{
	if(index>=m_vertics.size())
	{
		FS_TRACE_WARN("Index Out Of Range");
		return;
	}

	m_vertics[index]=v;

}
void VertexPolygon::setVertex(uint index,Vector2 v)
{
	setVertex(index,Vector3(v.x,v.y,0));
}

void VertexPolygon::setVertex(uint index,float x,float y,float z)
{
	setVertex(index,Vector3(x,y,z));
}



Vector3 VertexPolygon::getVertex(uint index)
{
	if (index>=m_vertics.size())
	{
		FS_TRACE_WARN("Index Out Of Range");
		return Vector3(0,0,0);
	}
	return m_vertics[index];
}

void VertexPolygon::append(Vector3 v)
{
	m_vertics.push_back(v);
}

void VertexPolygon::append(Vector2 v)
{
	m_vertics.push_back(Vector3(v.x,v.y,0));
}

void VertexPolygon::append(float x,float y,float z)
{
	m_vertics.push_back(Vector3(x,y,z));
}


void VertexPolygon::removeVertex(uint index)
{
	if(index>=m_vertics.size())
	{
		FS_TRACE_WARN("Index Out Of Range");
		return;
	}

	m_vertics.erase(m_vertics.begin()+index);
}

void VertexPolygon::insertVertex(uint index,Vector3 v)
{
	if(index>m_vertics.size())
	{
		FS_TRACE_WARN("Index Out Of Range");
		return;
	}
	m_vertics.insert(m_vertics.begin()+index,v);
}

void VertexPolygon::insertVertex(uint index,Vector2 v)
{
	insertVertex(index,Vector3(v.x,v.y,0));
}

void VertexPolygon::insertVertex(uint index,float x,float y,float z)
{
	insertVertex(index,Vector3(x,y,z));
}







void VertexPolygon::resize(int nu)
{
	m_vertics.resize(nu);
}

int VertexPolygon::getVertexNu()
{
	return m_vertics.size();
}
void VertexPolygon::setMode(E_DrawMode mode)
{
	m_mode=mode;
}


E_DrawMode VertexPolygon::getMode()
{
	return m_mode;
}




VertexPolygon::VertexPolygon()
{
	m_mode=E_DrawMode::POINTS;

	static ProgramSource* S_programSource=NULL;

	if(S_programSource==NULL)
	{
		S_programSource=(ProgramSource*)Global::programSourceMgr()->load(FS_PRE_PROGRAM_SOURCE_V4F);
	}

	setProgramSource(S_programSource);

}

VertexPolygon::~VertexPolygon()
{
	destruct();
}

bool VertexPolygon::init()
{
	return true;

}

void VertexPolygon::destruct()
{
	m_vertics.clear();
}


void VertexPolygon::draw(RenderDevice* rd,bool update_matrix)
{
	Program* prog=getProgram(NULL);

	if(!prog)
	{
		return;
	}

	if(m_vertics.size()==0)
	{
		return;
	}

	if(update_matrix)
	{
		updateWorldMatrix();
	}

	rd->setWorldMatrix(&m_worldMatrix);
	rd->setProgram(prog);

	m_material->configRenderDevice(rd);


	rd->disableAllAttrArray();


	StreamMap* map_v=prog->getStreamMap(E_StreamType::VERTICES);

	if(map_v)
	{
		rd->setAndEnableVertexAttrPointer(map_v->m_location,3,FS_FLOAT,m_vertics.size(),0,&m_vertics[0]);
	}

	rd->drawArray(m_mode,0,m_vertics.size());

}





/**** Used For  Vertex   Attribute  */
static VertexPolygon* VertexPolygon_NewInstance(FsDict* attr)
{
	VertexPolygon* ret=VertexPolygon::create();
	if(attr)
	{
		ret->setAttributes(attr);
	}
	return ret;
}

static void VertexPolygon_setVertices(VertexPolygon* vp,FsArray* array)
{
	vp->resize(0);

	int vertices_nu=array->size();
	for(int i=0;i<vertices_nu;i++)
	{
		FsArray* vs=array->getArray(i);
		if(!vs)
		{
			FS_TRACE_WARN("Ingore:Need Array In Vertices Entry");
			continue;
		}
		Vector3f v(0,0,0);
		int v_nu=vs->size();
		for(int i=0;i<3&&i<v_nu;i++)
		{
			v.v[i]=vs->getString(i)->toFloatValue();
		}
		vp->append(v);
	}
}



FS_CLASS_ATTR_SET_GET_FUNCTION(VertexPolygon,setColor,getColor,Color4f);
FS_CLASS_ATTR_SET_GET_FUNCTION(VertexPolygon,setOpacity,getOpacity,float);
FS_CLASS_ATTR_SET_CHARS_FUNCTION(VertexPolygon,setProgramSource);
FS_CLASS_ATTR_SET_GET_ENUM_CHAR_FUNCTION(VertexPolygon,setBlendEquation,getBlendEquation,BlendEquation);
FS_CLASS_ATTR_SET_GET_ENUM_CHAR_FUNCTION(VertexPolygon,setBlendSrc,getBlendSrc,BlendFactor);
FS_CLASS_ATTR_SET_GET_ENUM_CHAR_FUNCTION(VertexPolygon,setBlendDst,getBlendDst,BlendFactor);

FS_CLASS_ATTR_SET_GET_ENUM_CHAR_FUNCTION(VertexPolygon,setMode,getMode,DrawMode);


static FsClass::FsAttributeDeclare  S_VertexPolygon_Main_Attr[]=
{
	FS_CLASS_ATTR_DECLARE("color",FsType::FT_COLOR_4,NULL,VertexPolygon_setColor,VertexPolygon_getColor),
	FS_CLASS_ATTR_DECLARE("opacity",FsType::FT_F_1,NULL,VertexPolygon_setOpacity,VertexPolygon_getOpacity),
	FS_CLASS_ATTR_DECLARE("shader",FsType::FT_CHARS,NULL,VertexPolygon_setProgramSource,0),
	FS_CLASS_ATTR_DECLARE("blendEquation",FsType::FT_CHARS,NULL,VertexPolygon_setBlendEquation,VertexPolygon_getBlendEquation),
	FS_CLASS_ATTR_DECLARE("blendSrc",FsType::FT_CHARS,NULL,VertexPolygon_setBlendSrc,VertexPolygon_getBlendSrc),
	FS_CLASS_ATTR_DECLARE("blendDst",FsType::FT_CHARS,NULL,VertexPolygon_setBlendDst,VertexPolygon_getBlendDst),
	FS_CLASS_ATTR_DECLARE("vertices",FsType::FT_ARRAY,NULL,VertexPolygon_setVertices,0),
	FS_CLASS_ATTR_DECLARE("mode",FsType::FT_CHARS,NULL,VertexPolygon_setMode,VertexPolygon_getMode),

	FS_CLASS_ATTR_DECLARE(NULL,FsType::FT_IN_VALID,NULL,0,0)
};

FS_CLASS_IMPLEMENT_WITH_BASE(VertexPolygon,Entity,VertexPolygon_NewInstance,S_VertexPolygon_Main_Attr);




NS_FS_END







