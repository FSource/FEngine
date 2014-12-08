"   \n\
UniformMap    \n\
{   \n\
	u_mvp =$(R.WORLD_VIEW_PROJECTION_MAT)   \n\
	u_texture0 = $(M.COLOR_MAP)   \n\
	u_color=$(M.COLOR)   \n\
}   \n\
   \n\
AttributeMap    \n\
{   \n\
	a_position=$(VERTICES)   \n\
	a_texCoord=$(UVS)   \n\
   \n\
}   \n\
   \n\
VertexShader   \n\
{     \n\
	attribute vec4 a_position;   \n\
	attribute vec2 a_texCoord;   \n\
	uniform mat4 u_mvp;   \n\
#ifdef GL_ES										     \n\
	varying mediump vec2 v_texCoord;					     \n\
#else												     \n\
	varying vec2 v_texCoord;							     \n\
#endif												     \n\
	void main() 										     \n\
	{ 													     \n\
		gl_Position=u_mvp*a_position;					     \n\
		v_texCoord=a_texCoord;							     \n\
	}													     \n\
}     \n\
     \n\
     \n\
FragmentShader    \n\
{     \n\
#ifdef GL_ES                       					     \n\
	precision lowp float;               				     \n\
#endif												     \n\
	varying vec2 v_texCoord; 							     \n\
	uniform sampler2D u_texture0;   \n\
	uniform vec3 	 u_color;   \n\
	void main()											     \n\
	{													     \n\
		gl_FragColor=vec4(texture2D(u_texture0,v_texCoord).rgb*u_color,1.0);       \n\
	}														     \n\
}"   ; 
