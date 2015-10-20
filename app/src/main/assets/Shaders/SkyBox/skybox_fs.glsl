#version 130

uniform samplerCube cubeMap;

in vec3 out_texCoord;

out vec4 fragColor;

void main(void)
{
	fragColor = texture(cubeMap, out_texCoord);
}