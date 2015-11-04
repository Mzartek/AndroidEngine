uniform sampler2D diffuseTex;

uniform vec3 diffuseMaterial;

varying vec2 out_TexCoord;

void main(void)
{
	gl_FragColor = vec4(diffuseMaterial, 1.0);
}