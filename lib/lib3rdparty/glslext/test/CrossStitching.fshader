
Feature 
{
}

UniformMap 
{
	u_mvp=$(R.WORLD_VIEW_PROJECTION_MAT)	
	u_texture0=$(M.COLOR_MAP)
	u_time=$(R.TIME)
	u_color=$(M.COLOR)
}

AttributeMap 
{
	a_position=$(VERTICES) 	   
	a_texCoord=$(UVS)	
}


VertexShader 
{
	attribute vec4 a_position;
	attribute vec2 a_texCoord;
	uniform mat4 u_mvp;
#ifdef GL_ES						
	varying mediump vec2 v_texCoord;
#else						
	varying vec2 v_texCoord;
#endif				
	void main() 	
	{ 			
		gl_Position=u_mvp*a_position;
		v_texCoord=a_texCoord;		
	}							

}



FragmentShader 
{

#ifdef GL_ES                            
	precision highp float;                  
#endif                                

	uniform float u_time;
	varying vec2 v_texCoord; 
	uniform sampler2D u_texture0;
	uniform vec3 u_color;


	void main()
	{
		float size = u_color.g;
		float rt_w=1.0;
		float rt_h=1.0;

		if (u_color.r > v_texCoord.x )
		{
			vec4 c = vec4(0.0);
			vec2 cPos = v_texCoord* vec2(rt_w, rt_h);
			vec2 tlPos = floor(cPos / vec2(size, size));
			tlPos *= size;
			int remX = int(mod(cPos.x, size));
			int remY = int(mod(cPos.y, size));
			if (remX == 0 && remY == 0)
				tlPos = cPos;
			vec2 blPos = tlPos;
			blPos.y += (size - 1.0);
			if ((remX == remY) || 
					(((int(cPos.x) - int(blPos.x)) == (int(blPos.y) - int(cPos.y)))))
			{
				if (invert == 1)
					c = vec4(0.2, 0.15, 0.05, 1.0);
				else
					c = texture2D(u_texture0, tlPos * vec2(1.0/rt_w, 1.0/rt_h)) * 1.4;
			}
			else
			{
				if (invert == 1)
					c = texture2D(u_texture0, tlPos * vec2(1.0/rt_w, 1.0/rt_h)) * 1.4;
				else
					c = vec4(0.0, 0.0, 0.0, 1.0);
			}
			gl_FragColor=c;

		}
		else 
		{
			gl_FragColor=texture2D(u_texture0,v_texCoord);
		}
	}
}
