"VertexShader{   \n\
	attribute vec4 a_position=$(VERTICES); 	    		   \n\
	attribute vec2 a_texCoord=$(UVS);					   \n\
	uniform mat4 u_mvp=$(R.WORLD_VIEW_PROJECTION_MAT);	   \n\
#ifdef GL_ES										   \n\
	varying mediump vec2 v_texCoord;					   \n\
#else												   \n\
	varying vec2 v_texCoord;							   \n\
#endif												   \n\
	void main() 										   \n\
	{ 													   \n\
		gl_Position=u_mvp*a_position;					   \n\
		v_texCoord=a_texCoord;							   \n\
	}													   \n\
}   \n\
   \n\
   \n\
FragmentShader{   \n\
#ifdef GL_ES                       					   \n\
	precision lowp float;               				   \n\
#endif												   \n\
	varying vec2 v_texCoord; 							   \n\
	uniform sampler2D u_texture0=$(M.COLOR_MAP);       	   \n\
	uniform vec3 	 u_color=$(M.COLOR);				   \n\
	void main()											   \n\
	{													   \n\
		gl_FragColor=vec4(texture2D(u_texture0,v_texCoord).rgb*u_color,1.0);     \n\
	}														   \n\
}"   ;
