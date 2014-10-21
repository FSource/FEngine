/* sfdaf */

VERTEX_BEGIN

#ifdef MAX_LIGHT > 0 

attribute vec4 a_vertex  = $(VERTICES);
attribute vec2 a_texCoord0 = $(UVS);

#endif 

uniform mat4 u_worldViewProjectionMatrix=$(WORLD_VIEW_PROJECTION_MATRIX);
varying vec2 v_texCoord0;

/* may name is chen lin */
// my name s dsfasdf faa 

void main(void)
{
	v_texCoord0=a_texCoord0;
	gl_Position = u_worldViewProjectionMatrix * a_vertex;
}


VERTEX_END 


/*=====================================*/

FRAGMENT_BEGIN

#ifdef GL_FRAGMENT_PRECISION_HIGH
// Default precision
precision highp float;
#else
precision mediump float;
#endif

uniform sampler2D u_texture0=$(UNDEF);
uniform vec3 u_color=$(1.0,1.0,1.0);

varying vec2 v_texCoord0;

void main(void)
{
	gl_FragColor = texture2D(u_texture0,v_texCoord0);
	gl_FragColor.xyz*=u_color;
}


FRAGMENT_END 


/*fsf da*/



