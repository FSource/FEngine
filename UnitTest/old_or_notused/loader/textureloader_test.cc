#include<GL/glew.h>
#include<GL/glut.h>
#include "graphics/FsTexture2D.h"
#include "loader/FsTextureLoader.h"
#include "fsys/FsVFS.h"
#include "fsys/FsFile.h"
NS_FS_USE
Texture2D* ttr=NULL;
void init(const char* filename)
{
	glewInit();
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_DEPTH_TEST);
	glShadeModel(GL_SMOOTH);
	glTranslatef(0.0,0.0,-3.6);
	glEnable(GL_TEXTURE_2D);
	FsFile* file=VFS::open(filename);
	if(file==NULL)
	{
		printf("open file failed(%s)\n",filename);
		exit(-1);
	}
	ttr=TextureLoader::loadFromFile(file);
	file->decRef();

	if(ttr==NULL)
	{
		printf("load texture failed\n");
		exit(-1);
	}
}

void display(void)
{
	glClearColor(1.0f,1.0f,0.0f,1.0f);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	ttr->bind();
	/*
	glBegin(GL_QUADS);
	glTexCoord2f(0.0,0.0);glVertex3f(-2.0,-1.0,0.0);
	glTexCoord2f(0.0,1.0);glVertex3f(-2.0,1.0,0.0);
	glTexCoord2f(1.0,1.0);glVertex3f(2.0,1.0,-30.0);
	glTexCoord2f(1.0,0.0);glVertex3f(2.0,-1.0,-30.0);
	glEnd();
	*/

	glPushMatrix();
	glTranslatef(0,0,-5);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0,0.0);glVertex3f(-2.0,-2.0,-0.0);
	glTexCoord2f(0.0,7.0);glVertex3f(-2.0,2.0,-0.0);
	glTexCoord2f(7.0,7.0);glVertex3f(2,2.0,0.0);
	glTexCoord2f(7.0,0.0);glVertex3f(2,-2.0,0.0);
	glEnd();
	glPopMatrix();

	glFlush();
}
void reshape(int w,int h)
{
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60,1,0.1,10000);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	//glTranslatef(0.0,0.0,-3.4);
}

int main(int argc,char** argv)
{
	if(argc!=2)
	{
		printf("usage: %s <filename>" ,argv[0]);
		exit(-1);
	}
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(1024,800);
	glutCreateWindow(argv[0]);
	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	init(argv[1]);
	glutMainLoop();
	return 0;
}


