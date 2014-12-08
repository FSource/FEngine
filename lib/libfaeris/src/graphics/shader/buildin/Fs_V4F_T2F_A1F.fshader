"   \n\
UniformMap    \n\
{   \n\
	u_mvp = $(R.WORLD_VIEW_PROJECTION_MAT)   \n\
	u_texture0 = $(M.COLOR_MAP)   \n\
	u_color = $(M.COLOR)   \n\
	u_opacity = $(M.OPACITY)   \n\
	   \n\
}   \n\
   \n\
AttributeMap     \n\
{   \n\
	a_position = $(VERTICES)   \n\
	a_texCoord  = $(UVS)   \n\
	a_alpha = $(USER_DEFINE1)   \n\
}   \n\
   \n\
   \n\
   \n\
VertexShader    \n\
{     \n\
	attribute vec4 a_position;   \n\
	attribute vec2  a_texCoord;   \n\
	attribute float a_alpha;   \n\
	uniform mat4 u_mvp;   \n\
#ifdef GL_ES											     \n\
	varying mediump vec2 v_texCoord;						     \n\
	varying mediump float v_alpha;							     \n\
#else													     \n\
	varying vec2 v_texCoord;								     \n\
	varying float v_alpha;									     \n\
#endif													     \n\
	void main() 											     \n\
	{ 														     \n\
		gl_Position=u_mvp*a_position;						     \n\
		v_texCoord=a_texCoord;								     \n\
		v_alpha=a_alpha;									     \n\
	}														     \n\
}     \n\
     \n\
     \n\
     \n\
     \n\
FragmentShader    \n\
{     \n\
     \n\
#ifdef GL_ES 											     \n\
	precision lowp float;									     \n\
#endif 													     \n\
	varying vec2  v_texCoord;           					     \n\
	varying float v_alpha;									     \n\
	uniform sampler2D u_texture0;   \n\
	uniform vec4      u_color;   \n\
	uniform float     u_opacity;   \n\
	void main()                         					     \n\
	{														     \n\
		gl_FragColor=texture2D(u_texture0,v_texCoord)*u_color;       \n\
		gl_FragColor.a*=u_opacity*v_alpha;    			         \n\
	}														     \n\
}"   ;   
