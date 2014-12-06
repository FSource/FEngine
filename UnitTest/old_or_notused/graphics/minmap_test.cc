#include<GL/glut.h>
#include "graphics/FsTexture2D.h"
#include "loader/FsTextureLoader.h"
#include "fsys/FsVFS.h"
#include "fsys/FsFile.h"
NS_FS_USE
Texture2D* ttr=NULL;
void init(const char* filename)
{
	glEnable(GL_DEPTH_TEST);
	glShadeModel(GL_FLAT);
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
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	ttr->bind();
	glBegin(GL_QUADS);
	glTexCoord2f(0.0,0.0);glVertex3f(-2.0,-1.0,0.0);
	glTexCoord2f(0.0,8.0);glVertex3f(-2.0,1.0,0.0);
	glTexCoord2f(8.0,8.0);glVertex3f(2000.0,1.0,-6000.0);
	glTexCoord2f(8.0,0.0);glVertex3f(2000.0,-1.0,-6000.0);
	glEnd();
	glFlush();
}
void reshape(int w,int h)
{
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60,(float)w/h,0.1,10000);

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
	glutInitWindowSize(500,500);
	glutCreateWindow(argv[0]);
	init(argv[1]);
	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}


