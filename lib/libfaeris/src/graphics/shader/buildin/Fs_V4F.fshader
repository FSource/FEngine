"   \n\
UniformMap    \n\
{   \n\
	u_mvp = $(R.WORLD_VIEW_PROJECTION_MAT)   \n\
	u_pointSize = $(M.POINT_SIZE)   \n\
	u_color= $(M.COLOR)   \n\
	u_opacity =$(M.OPACITY)   \n\
}   \n\
   \n\
AttributeMap    \n\
{   \n\
	a_position = $(VERTICES)   \n\
}   \n\
   \n\
VertexShader{     \n\
	uniform mat4 u_mvp;   \n\
	uniform float u_pointSize;   \n\
	attribute vec4 a_position;   \n\
	void main() 														     \n\
	{																	     \n\
		gl_Position=u_mvp*a_position;									     \n\
		gl_PointSize=u_pointSize;										     \n\
	}																	     \n\
}     \n\
     \n\
     \n\
     \n\
     \n\
FragmentShader{     \n\
     \n\
#ifdef GL_ES 														     \n\
	precision lowp float;												     \n\
#endif 																     \n\
	uniform vec4  u_color;   \n\
	uniform float u_opacity;   \n\
	void main()															     \n\
	{																	     \n\
		gl_FragColor=u_color;											     \n\
		gl_FragColor.a*=u_opacity;										     \n\
	}																	     \n\
}"  ;
