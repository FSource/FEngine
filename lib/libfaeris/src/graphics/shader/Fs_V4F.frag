" 									\n\
#ifdef GL_ES 						\n\
precision lowp float;				\n\
#endif 								\n\
varying vec4 v_fragmentColor;		\n\
uniform float u_opacity;			\n\
void main()							\n\
{									\n\
	gl_FragColor=v_fragmentColor*u_opacity;	\n\
}									\n\
"
