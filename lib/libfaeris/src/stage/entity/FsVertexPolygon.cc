#include "stage/entity/FsVertexPolygon.h"
#include "FsGlobal.h"
#include "mgr/FsProgramSourceMgr.h"
#include "graphics/shader/FsStreamMap.h"
#include "graphics/shader/FsProgram.h"



NS_FS_BEGIN


const char* VertexPolygon::className()
{
	return FS_VERTEX_POLYGON_CLASS_NAME;
}


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

























NS_FS_END







