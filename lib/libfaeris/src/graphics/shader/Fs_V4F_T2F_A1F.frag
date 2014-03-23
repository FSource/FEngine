"									\n\
#ifdef GL_ES                       	\n\
precision lowp float;               \n\
#endif                              \n\
varying vec2 v_texCoord; 			\n\
varying  float v_alpha;				\n\
uniform sampler2D u_texture0;       \n\
uniform vec4 	 u_color;			\n\
uniform float 	 u_opacity;			\n\
void main()							\n\
{									\n\
	vec4 tmp=texture2D(u_texture0,v_texCoord)*u_color;  \n\
	gl_FragColor=vec4(tmp.rgb,tmp.a*u_opacity*v_alpha);	\n\
}														\n\
";
