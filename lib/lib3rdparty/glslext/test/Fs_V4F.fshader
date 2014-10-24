VERTEX_BEGIN    													
uniform mat4 u_mvp=$(R.WORLD_VIEW_PROJECTION_MAT);				
uniform vec4  u_color=$(M.COLOR);							
uniform float u_pointSize=$(M.POINT_SIZE) ;				
attribute vec4 a_position=$(VERTICES);				
#ifdef GL_ES									
varying lowp vec4 v_fragmentColor;									
#else 																
varying vec4 v_fragmentColor;										
#endif 																
void main() 														
{																	
	gl_Position=u_mvp*a_position;									
	gl_PointSize=u_pointSize;										
	v_fragmentColor=u_color;										
}																	
 																	
																	
VERTEX_END 															
																	
																	
FRAGMENT_BEGIN 														
																	
#ifdef GL_ES 														
precision lowp float;												
#endif 																
varying vec4 v_fragmentColor;										
uniform float u_opacity=$(M.OPACITY);								
void main()															
{																	
	gl_FragColor=vec4(v_fragmentColor.rgb,v_fragmentColor.a*u_opacity);		
}																			
FRAGMENT_END
