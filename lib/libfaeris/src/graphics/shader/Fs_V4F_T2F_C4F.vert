"									\n\
uniform mat4 u_mvp; 				\n\
attribute vec4 a_position;          \n\
attribute vec4 a_color;             \n\
attribute vec2 a_texCoord; 			\n\
#ifdef GL_ES 				        \n\
varying lowp vec4 v_fragmentColor;  \n\
varying lowp vec2 v_texCoord;       \n\
#else 								\n\
varying vec4 v_fragmentColor;       \n\
varying vec2 v_texCoord;            \n\
#endif                              \n\
void main()							\n\
{									\n\
	gl_Position=u_mvp*a_position;   \n\
	v_fragmentColor=a_color;        \n\
	v_texCoord=a_texCoord;          \n\
}";
