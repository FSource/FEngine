#ifndef _FS_GL_OSX_H_
#define _FS_GL_OSX_H_

#define CC_GL_DEPTH24_STENCIL8      -1


#define glDeleteVertexArrays            glDeleteVertexArraysAPPLE
#define glGenVertexArrays               glGenVertexArraysAPPLE
#define glBindVertexArray               glBindVertexArrayAPPLE

#define glClearDepthf                   glClearDepth
#define glDepthRangef                   glDepthRange

#define glReleaseShaderCompiler(xxx)

#endif /*_FS_GL_OSX_H_*/

