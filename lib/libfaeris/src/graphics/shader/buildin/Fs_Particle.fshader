"VERTEX_BEGIN												\n\
uniform mat4 u_mvp=$(R.WORLD_VIEW_PROJECTION_MAT); 			\n\
attribute vec4 a_position=$(VERTICES);          				\n\
attribute vec4 a_color=$(COLORS);             				\n\
attribute vec2 a_texCoord=$(UVS); 							\n\
#ifdef GL_ES 				        						\n\
varying lowp vec4 v_fragmentColor;  						\n\
varying lowp vec2 v_texCoord;       						\n\
#else 														\n\
varying vec4 v_fragmentColor;       						\n\
varying vec2 v_texCoord;            						\n\
#endif                              						\n\
void main()													\n\
{															\n\
	gl_Position=u_mvp*a_position;   						\n\
	v_fragmentColor=a_color;        						\n\
	v_texCoord=a_texCoord;          						\n\
}															\n\
VERTEX_END 													\n\
															\n\
FRAGMENT_BEGIN 												\n\
															\n\
#ifdef GL_ES 												\n\
precision lowp float;										\n\
#endif 														\n\
varying vec2  v_texCoord;           						\n\
varying vec4  v_fragmentColor;								\n\
uniform sampler2D u_texture0=$(M.COLOR_MAP);				\n\
void main()                         						\n\
{															\n\
	gl_FragColor=texture2D(u_texture0,v_texCoord)*v_fragmentColor; 	\n\
}															\n\
FRAGMENT_END" ;
