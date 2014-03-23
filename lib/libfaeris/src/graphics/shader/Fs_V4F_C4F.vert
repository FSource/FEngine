"										\n\
uniform mat4 u_mvp;						\n\
uniform float u_pointSize;				\n\
uniform vec4 u_color;					\n\
uniform float u_opacity; 				\n\
attribute vec4 a_position;				\n\
attribute vec4 a_color;					\n\
#ifdef GL_ES							\n\
varying lowp vec4 v_fragmentColor;		\n\
#else									\n\
varying vec4 v_fragmentColor;			\n\
#endif									\n\
void main()   							\n\
{										\n\
	gl_Position=u_mvp*a_position;		\n\
	gl_PointSize=u_pointSize;			\n\
	vec4 tmpc=a_color*u_color;			\n\
	v_fragmentColor=vec4(tmpc.rgb,tmpc.a*u_opacity); \n\
}  										\n\
";
