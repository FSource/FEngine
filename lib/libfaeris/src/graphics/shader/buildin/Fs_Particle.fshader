"   \n\
UniformMap    \n\
{   \n\
	u_mvp = $(R.WORLD_VIEW_INVERSE_TRANSPOSE_MAT)    \n\
	u_texture0 = $(M.COLOR_MAP)   \n\
}   \n\
   \n\
AttributeMap    \n\
{   \n\
	a_position = $(VERTICES)   \n\
	a_color  = $(COLORS)   \n\
	a_texCoord = $(UVS)   \n\
}   \n\
   \n\
   \n\
VertexShader{     \n\
	uniform mat4 u_mvp;   \n\
	attribute vec4 a_position;   \n\
	attribute vec4 a_color;   \n\
	attribute vec2 a_texCoord;   \n\
   \n\
#ifdef GL_ES 				        						     \n\
	varying lowp vec4 v_fragmentColor;  						     \n\
	varying lowp vec2 v_texCoord;       						     \n\
#else 														     \n\
	varying vec4 v_fragmentColor;       						     \n\
	varying vec2 v_texCoord;            						     \n\
#endif                              						     \n\
   \n\
	void main()													     \n\
	{															     \n\
		gl_Position=u_mvp*a_position;   						     \n\
		v_fragmentColor=a_color;        						     \n\
		v_texCoord=a_texCoord;          						     \n\
	}															     \n\
}     \n\
     \n\
     \n\
FragmentShader{     \n\
     \n\
#ifdef GL_ES 												     \n\
	precision lowp float;										     \n\
#endif 														     \n\
	varying vec2  v_texCoord;           						     \n\
	varying vec4  v_fragmentColor;								     \n\
	uniform sampler2D u_texture0;   \n\
	void main()                         						     \n\
	{															     \n\
		gl_FragColor=texture2D(u_texture0,v_texCoord)*v_fragmentColor; 	     \n\
	}															     \n\
}" ;  
