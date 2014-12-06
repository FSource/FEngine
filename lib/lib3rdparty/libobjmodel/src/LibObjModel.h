#ifndef __LIB_OBJ_MODEL_H_
#define __LIB_OBJ_MODEL_H_

#include <string>
#include <vector>


class LibObjTexCoord 
{
	public:
		LibObjTexCoord(float _u,float _v)
		{
			u=_u; v=_v;
		}

		LibObjTexCoord()
		{
			u=0; v=0;
		}

	public:
		float u;
		float v;
} ;


class LibObjVector3
{
	public:
		static float docProduct(const LibObjVector3& l,const LibObjVector3& r);
		LibObjVector3 crossProduct(const LibObjVector3& l,const LibObjVector3& r);

	public:
		LibObjVector3(float _x,float _y,float _z)
		{ 
			x=_x; y=_y; z=_z; 
		}

		LibObjVector3()
		{
			x=0; y=0; z=0; 
		}

	public:
		void normalize();
		void set(float _x,float _y,float _z)
		{
			x=_x; y=_y; z=_z; 
		}



	public:
		float x;
		float y;
		float z;
};









class LibObjVertexIndex 
{
	public:
		LibObjVertexIndex(int v,int u,int n)
		{
			m_vertex=v;
			m_uv=u;
			m_normal=n;
		}
		LibObjVertexIndex()
		{
			m_vertex=0;
			m_uv=0;
			m_normal=0;
		}
		
	public:
		int m_vertex;
		int m_uv;
		int m_normal;
};


class LibObjFace
{
	public:
		std::vector<LibObjVertexIndex>  m_data;
};


class LibObjSubMesh 
{
	public:
		LibObjSubMesh() {}
		~LibObjSubMesh()
		{
			int face_nu=m_faces.size();
			for(int i=0;i<face_nu;i++)
			{
				delete m_faces[i];
			}
			m_faces.clear();
		}

	public:

		void newFace() { m_faces.push_back(new LibObjFace()); }

		void addVertexIndex(int v,int u,int n)
		{
			m_faces.back()->m_data.push_back(LibObjVertexIndex(v,u,n));
		}


		/* material */
		void setMaterialName(const char* name) { m_materialName=std::string(name); }
		const char* getMaterialName() { return m_materialName.c_str(); }

		/* face */
		int getFaceNu() { return m_faces.size(); }
		LibObjFace* getFace(int index) { return m_faces[index]; }


	private:
		std::string m_materialName;
		std::vector<LibObjFace*>  m_faces;
};


class LibObjMesh 
{

	public:
		LibObjMesh()
		{
			m_curSubMesh=NULL;
		}


		~LibObjMesh()
		{
			int submesh_nu=m_submeshes.size();
			for(int i=0;i<submesh_nu;i++)
			{
				delete m_submeshes[i];
			}
			m_submeshes.clear();
		}


		int getSubMeshNu()
		{
			return m_submeshes.size();
		}

		LibObjSubMesh* getCurSubMesh() 
		{
			if(m_curSubMesh==NULL)
			{
				m_curSubMesh=new LibObjSubMesh;
				m_submeshes.push_back(m_curSubMesh);
			}
			return m_curSubMesh;
		}

		LibObjSubMesh* getSubMesh(int index)
		{
			return m_submeshes[index];
		}


		void commitSubMesh()
		{
			m_curSubMesh=NULL;
		}


		/* vertex info */
		int getVertex(){return m_vertices.size();}
		void addVertex(float x,float y,float z){m_vertices.push_back(LibObjVector3(x,y,z));}
		LibObjVector3& getVertex(int index){return m_vertices[index-1];}


		int getUvNu(){return m_uvs.size();}
		void addUv(float x,float y){m_uvs.push_back(LibObjTexCoord(x,y));}
		LibObjTexCoord& getUv(int index){return m_uvs[index-1];}


		int getNormalNu(){return m_normals.size();}
		void addNormal(float x,float y,float z){m_normals.push_back(LibObjVector3(x,y,z));}
		LibObjVector3& getNormal(int index){return m_normals[index-1];}


		/* material */
		void setMaterialLibName(const char* name) { m_materialLibName=std::string(name);}
		const char* getMaterialLibName(){return m_materialLibName.c_str();}


	private:
		std::string m_materialLibName;

		std::vector<LibObjTexCoord>  m_uvs;
		std::vector<LibObjVector3>   m_vertices;
		std::vector<LibObjVector3>   m_normals;

		std::vector<LibObjSubMesh*> m_submeshes;

		LibObjSubMesh* m_curSubMesh;


};



/* material */

class LibObjMaterial 
{
	public:
		std::string m_name;
		LibObjVector3 m_ambient;
		LibObjVector3 m_diffuse;
		LibObjVector3 m_specular;

		float m_opacity;
		float m_shiness;
		int m_illuminationMode;
		float m_ni;

		std::string m_ambientMap;
		std::string m_diffuseMap;
		std::string m_specularMap;
		std::string m_boumpMap;
		std::string m_alphaMap;

};

class LibObjMaterialLib 
{

	public:

		LibObjMaterial* getCurMaterial()
		{
			if(m_curMaterial==NULL)
			{
				m_curMaterial=new LibObjMaterial();
				m_materials.push_back(m_curMaterial);
			}

			return m_curMaterial;
		}

		void commitMaterial() { m_curMaterial=NULL; }

		int getMaterialNu(){return m_materials.size();}
		LibObjMaterial* getMaterial(int index){return m_materials[index];}




	public:
		LibObjMaterialLib() 
		{
			m_curMaterial=NULL;
		}
		~LibObjMaterialLib() 
		{
			int material_nu=m_materials.size();
			for(int i=0;i<material_nu;i++)
			{
				delete m_materials[i];
			}
			m_materials.clear();
	   	}




	private:
		std::vector<LibObjMaterial*> m_materials;
		LibObjMaterial* m_curMaterial;

};




typedef int (*LibObj_ReadIoFunc)(void* file,void* buf,int length);

class LibObjParserContext 
{
	public:
		LibObjParserContext(void* scanner,void* data,void* file,LibObj_ReadIoFunc io)
		{
			m_scanner=scanner;
			m_data=data;
			m_file=file;
			m_readIo=io;
		}

	public:
		void* m_scanner;
		void* m_data;
		void* m_file;
		LibObj_ReadIoFunc m_readIo;
};


LibObjMesh* LibObj_ParseMesh(void* file,LibObj_ReadIoFunc io_func);

LibObjMaterialLib* LibObj_ParseMtl(void* file,LibObj_ReadIoFunc io_func);



#endif /* __LIB_OBJ_MODEL_H_*/




