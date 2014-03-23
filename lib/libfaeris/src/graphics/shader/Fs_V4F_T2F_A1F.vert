"											\n\
attribute vec4 a_position; 	    			\n\
attribute vec2  a_texCoord;					\n\
attribute float a_alpha;					\n\
uniform mat4 u_mvp;							\n\
#ifdef GL_ES								\n\
varying mediump vec2 v_texCoord;			\n\
varying mediump float v_alpha;				\n\
#else										\n\
varying vec2 v_texCoord;					\n\
varying float v_alpha;						\n\
#endif										\n\
void main() 								\n\
{ 											\n\
	gl_Position=u_mvp*a_position;			\n\
	v_texCoord=a_texCoord;					\n\
	v_alpha=a_alpha;						\n\
}											\n\
";
