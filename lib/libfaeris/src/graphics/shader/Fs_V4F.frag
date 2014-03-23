" 									\n\
#ifdef GL_ES 						\n\
precision lowp float;				\n\
#endif 								\n\
varying vec4 v_fragmentColor;		\n\
uniform float u_opacity;			\n\
void main()							\n\
{									\n\
	gl_FragColor=vec4(v_fragmentColor.rgb,v_fragmentColor.a*u_opacity);		\n\
}									\n\
";
