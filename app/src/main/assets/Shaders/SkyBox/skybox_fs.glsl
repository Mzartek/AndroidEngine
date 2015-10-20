#version 100

uniform samplerCube cubeMap;

varying vec3 out_texCoord;

void main(void)
{
	gl_FragColor = textureCube(cubeMap, out_texCoord);
}