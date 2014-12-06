#include "stdio.h"
#include "stdlib.h"
#include <GL/glew.h>
#include <GL/glu.h>

#include "loader/FsMeshLoader.h"
#include "fsys/FsFile.h"
#include "fsys/FsVFS.h"
#include "fsys/FsSysFile.h"
#include "core/FsWindow.h"
#include "graphics/FsRender.h"
#include "core/FsFrame.h"



using namespace Faeris;

class MyFrameListener:public FrameListener 
{
	public:
		MyFrameListener(Mesh* mesh)
		{
			m_time=0;
			m_mesh=mesh;
		}

	public:
		virtual void frameUpdate(FsLong now,FsLong diff)
		{
			m_time++;
			printf("draw begin=%d,%d\n",m_time,Frame::instance()->getAvgFPS());

			Render* render=Render::instance();
			render->clear(true);


			render->rotate(Vector3(1,0.5,0.25),0.5);
			glPushMatrix();
			render->translate(Vector3(-2.5,-0.5,0.5));
			m_mesh->draw(Render::instance());
			glPopMatrix();

			glPushMatrix();
			render->translate(Vector3(-0.5,-0.5,0.5));
			m_mesh->draw(Render::instance());
			glPopMatrix();

			glPushMatrix();
			render->translate(Vector3(1.5,-0.5,0.5));
			m_mesh->draw(Render::instance());
			glPopMatrix();

			printf("draw end\n");
			Render::instance()->swapBuffers();
		}
	private:
		FsInt m_time;
		Mesh* m_mesh;
};

int main(int argc,char** argv)
{
	glewInit();
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	if(argc!=2)
	{
		printf("usage:%s <filename>\n",argv[0]);
		exit(-1);
	}

	FsFile* file=VFS::open(argv[1]);
	if(file==NULL)
	{
		printf("Can't Open File(%s)\n",argv[1]);
		exit(-1);
	}

	Mesh* mesh =MeshLoader::loadMesh(file);
	file->decRef();

	if(mesh==NULL)
	{
		printf("Load Mesh Failed\n");
		return 0;
	}

	Window* win=Window::create(0);
	Render* render=Render::instance();
	win->setSize(1024,800);
	win->setCaption("Faeris.V1.0.1");
	win->show();
	win->setPosition(100,200);




	render->setRenderTarget(win);

	render->init();

	render->setViewport(0,0,1024,800);

	//render->scale(Vector3(0.5,0.5,1));
	//render->rotate(Vector3(0,1,0),45);
	glHint(GL_POLYGON_SMOOTH_HINT,GL_NICEST);
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(90,(float)1024.0/800.0,0,1000);
	//glOrtho(-1,1,-1,1,-100,100);
	glMatrixMode(GL_MODELVIEW);

	render->translate(Vector3(0,0,-4.5));

	MyFrameListener* framelistener=new MyFrameListener(mesh);
	Frame::instance()->addListener(framelistener);
	Frame::instance()->setFPS(50);
	Frame::instance()->start();

	if(mesh) mesh->decRef();
}


