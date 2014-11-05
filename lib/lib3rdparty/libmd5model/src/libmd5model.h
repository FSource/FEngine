#ifndef  _LIB_MO5_MODEL_H_
#define  _LIB_MO5_MODEL_H_ 


#include <stdio.h>
#include <vector>
#include <string>
#include <math.h>


/* MESH */
class Md5MeshHeader
{
	public:
		int m_version;
		std::string m_commandLine;
		int m_jointsNu;
		int m_meshNu;
};

class Md5Point 
{
	public:
		Md5Point(float _x,float _y,float _z)
		{
			x=_x; y=_y; z=_z;
		}
		Md5Point()
		{
			x=0;y=0;z=0;
		}
	public:
		float x,y,z;
};


class Md5Quat
{
	public:
		Md5Quat(float _x,float _y,float _z)
		{
			x=_x;
			y=_y;
			z=_z;
			float w2= 1-_x*_x-_y*_y-_z*_z;
			if(w2< 0)
			{
				w2=-w2;
			}
			w=-sqrt(w2);

		}
		Md5Quat()
		{
			x=0;y=0;z=0;w=0;
		}


	public:
		float x,y,z,w;
};

class Md5MeshJoint 
{

	public:
		Md5MeshJoint(const std::string& name,int p_index,const Md5Point& p,const Md5Quat& q)
		{
			m_jointName=name;
			m_parentIndex=p_index;
			m_position=p;
			m_orientation=q;
		}


	public:
		std::string m_jointName;
		int m_index;
		int m_parentIndex;
		Md5Point m_position;
		Md5Quat m_orientation;
};

class Md5Weight
{
	public:
		Md5Weight(int joint_index,float weight,float x,float y,float z)
		{
			m_jointIndex=joint_index;
			m_weight=weight;
			m_offsetX=x;
			m_offsetY=y;
			m_offsetZ=z;
		}

		Md5Weight()
		{
			m_jointIndex=0;
			m_weight=0.0f;
			m_offsetX=0.0f;
			m_offsetY=0.0f;
			m_offsetZ=0.0f;
		}



	public:
		int m_jointIndex;
		float m_weight;
		float m_offsetX;
		float m_offsetY;
		float m_offsetZ;
};


class Md5Vertex
{
	public:
		Md5Vertex(float u,float v,int wi,int wn)
		{
			m_texU=u;
			m_texV=v;
			m_weightIndex=wi;
			m_weightNu=wn;
		}

		Md5Vertex()
		{
			m_texU=0.0f;
			m_texV=0.0f;
			m_weightIndex=0;
			m_weightNu=0;
		}



	public:
		float m_texU;
		float m_texV;
		int m_weightIndex;
		int m_weightNu;
};

class Md5Triangle 
{

	public:
		Md5Triangle(int a,int b,int c)
		{
			m_vertIndexA=a;
			m_vertIndexB=b;
			m_vertIndexC=c;
		}
		Md5Triangle()
		{
			m_vertIndexA=0;
			m_vertIndexB=0;
			m_vertIndexC=0;
		}


	public:
		int m_vertIndexA;
		int m_vertIndexB;
		int m_vertIndexC;
};

class Md5SubMesh 
{
	public:
		/* vertex */
		void setVertex( int index,const Md5Vertex& v)
		{
			if(index>=(int)m_verts.size())
			{
				printf("Vertex Index Out Of Rangle");
				return;
			}
			m_verts[index]=v;
		}

		void setVertexNu(int nu)
		{
			m_verts.resize(nu);
		}


		/* triangle */
		void setTriangle(int index,const Md5Triangle& t)
		{
			if(index >= (int)m_tris.size())
			{
				printf("Triangle Outof Rangle");
				return;
			}

			m_tris[index]=t;
		}

		void setTriangleNu(int nu)
		{
			m_tris.resize(nu);
		}


		/* weight */
		void setWeight(int index,const Md5Weight& w)
		{
			if(index >= (int) m_weights.size())
			{
				printf("weight index outof range ");
				return;
			}
			m_weights[index]=w;
		}

		void setWeightNu( int nu)
		{
			m_weights.resize(nu);
		}

		void setTextureUrl(const char* url)
		{
			m_textureUrl=url;
		}


	public:
		std::string m_textureUrl;
		std::vector<Md5Vertex> m_verts;
		std::vector<Md5Triangle> m_tris;
		std::vector<Md5Weight> m_weights;
};

class Md5Mesh 
{

	public:
		void commitSubMesh()
		{
			if(m_curSubMesh!=NULL)
			{
				m_subMeshs.push_back(m_curSubMesh);
				m_curSubMesh=NULL;
			}
		}

		Md5SubMesh* getCurrentSubMesh()
		{
			if(!m_curSubMesh)
			{
				m_curSubMesh=new Md5SubMesh;
			}

			return m_curSubMesh;
		}

		void setJointNu(int nu){m_joints.resize(nu);}


		void appendJoint(const std::string& name, int parent_index,const Md5Point& p,const Md5Quat& q)
		{
			m_joints.push_back(new Md5MeshJoint(name,parent_index,p,q));
		}


	public:
		Md5Mesh()
		{
			m_curSubMesh=NULL;
		}
		~Md5Mesh()
		{
			if(m_curSubMesh)
			{
				delete m_curSubMesh;
				m_curSubMesh=NULL;
			}

			int sub_nu=m_subMeshs.size();
			for(int i=0;i<sub_nu;i++)
			{
				delete m_subMeshs[i];
			}
			m_subMeshs.clear();

			int joint_nu=m_joints.size();
			for(int i=0;i<joint_nu;i++)
			{
				delete m_joints[i];
			}
			m_joints.clear();

		}





	public:

		Md5MeshHeader m_header;
		std::vector<Md5MeshJoint*> m_joints;
		std::vector<Md5SubMesh*> m_subMeshs;

	protected:
		Md5SubMesh* m_curSubMesh;
};


/* ANIM */
class Md5AnimHeader 
{
	public:
		int m_version;
		std::string m_commandLine;
		int m_numFrames;
		int m_numJoints;
		int m_frameRate;
		int m_numAnimatedComponent;
};

class Md5Bound 
{
	public:
		Md5Bound(const Md5Point& min,const Md5Point& max)
		{
			m_min=min;
			m_max=max;
		}

	public:
		Md5Point m_min;
		Md5Point m_max;
};


class Md5AnimFrame 
{
	public:
		std::vector<float> m_data;
};


class Md5Joint 
{
	public:
		Md5Joint(const char* name,int parent_index,int flags,int start_index)
		{
			m_name=name;
			m_parentIndex=parent_index;
			m_flags=flags;
			m_startIndex=start_index;
		}

	public:
		std::string m_name;
		int m_parentIndex;
		int m_flags;
		int m_startIndex;
};


class Md5Anim 
{
	public:

		Md5AnimFrame* getCurrentAnimFrame()
		{
			if(m_curAnimFrame==NULL)
			{
				m_curAnimFrame=new Md5AnimFrame;
			}
			return m_curAnimFrame;
		}

		void commitAnimFrame()
		{
			if(m_curAnimFrame!=NULL)
			{
				m_animFrames.push_back(m_curAnimFrame);
				m_curAnimFrame=NULL;
			}
		}

		void appendBound(const Md5Point& min,const Md5Point& max)
		{
			m_bounds.push_back(new Md5Bound(min,max));
		}

		void appendJoint(const char* name, int parent_index,int flag,int start_index)
		{
			m_joints.push_back(new Md5Joint(name,parent_index,flag,start_index));

		}

		void appendBaseFrame(float v1,float v2,float v3,float r1,float r2,float r3)
		{
			m_baseFrame->m_data.push_back(v1);
			m_baseFrame->m_data.push_back(v2);
			m_baseFrame->m_data.push_back(v3);
			m_baseFrame->m_data.push_back(r1);
			m_baseFrame->m_data.push_back(r2);
			m_baseFrame->m_data.push_back(r3);

		}


	public:
		Md5Anim()
		{
			m_baseFrame=new Md5AnimFrame;
			m_curAnimFrame=NULL;
		}

		~Md5Anim()
		{
			if(m_baseFrame)
			{
				delete m_baseFrame;
				m_baseFrame=NULL;
			}

			int joint_nu=m_joints.size();
			for(int i=0;i<joint_nu;i++)
			{
				delete m_joints[i];
			}
			m_joints.clear();

			int anim_frame_nu=m_animFrames.size();
			for(int i=0;i<anim_frame_nu;i++)
			{
				delete m_animFrames[i];
			}
			m_animFrames.clear();

			int bound_nu=m_bounds.size();
			for(int i=0;i<bound_nu;i++)
			{
				delete m_bounds[i];
			}
			m_bounds.clear();
		}




	public:
		Md5AnimHeader m_header;
		std::vector<Md5Joint*> m_joints;
		std::vector<Md5AnimFrame*> m_animFrames;
		Md5AnimFrame* m_baseFrame;
		std::vector<Md5Bound*> m_bounds;



	protected:
		Md5AnimFrame* m_curAnimFrame;


};












typedef int (*LibMd5_ReadIo)(void* data,void* buf,int length);
Md5Mesh* LibMd5Mesh_Parse(void* data,LibMd5_ReadIo io);
Md5Anim* LibMd5Anim_Parse(void* data,LibMd5_ReadIo io);

#endif /* _LIB_MO5_MODEL_H_ */






