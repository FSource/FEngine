"  \n\
UniformMap   \n\
{  \n\
	u_mvp = $(R.WORLD_VIEW_PROJECTION_MAT)  \n\
	u_color= $(M.COLOR)  \n\
}  \n\
  \n\
AttributeMap   \n\
{  \n\
	a_position=$(VERTICES)  \n\
}  \n\
  \n\
VertexShader  \n\
{		  \n\
	uniform mat4 u_mvp;  \n\
	attribute vec4 a_position;  \n\
	void main() 														  \n\
	{																	  \n\
		gl_Position=u_mvp*a_position;									  \n\
	}																	  \n\
}  \n\
  \n\
  \n\
  \n\
  \n\
FragmentShader{  \n\
  \n\
#ifdef GL_ES 														  \n\
	precision lowp float;												  \n\
#endif 																  \n\
	uniform vec3  u_color;  \n\
	void main()															  \n\
	{																	  \n\
		gl_FragColor=vec4(u_color,1.0);											  \n\
	}																	  \n\
}"  ;  
