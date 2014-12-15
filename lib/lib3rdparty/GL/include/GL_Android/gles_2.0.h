#ifndef _FS_GL_ES_H_
#define _FS_GL_ES_H_

#define glClearDepth                glClearDepthf
#define glDeleteVertexArrays        glDeleteVertexArraysOES
#define glGenVertexArrays           glGenVertexArraysOES
#define glBindVertexArray           glBindVertexArrayOES
#define glDepthRange 				glDepthRangef

#include <GLES2/gl2platform.h>
#ifndef GL_GLEXT_PROTOTYPES
#define GL_GLEXT_PROTOTYPES 1
#endif

#include <GLES2/gl2.h>

#endif 
