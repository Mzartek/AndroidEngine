#version 330

uniform samplerCube cubeMap;

in VertexData
{
	vec3 texCoord;
} FragIn;

layout(location = 0) out vec4 fragColor;

void main(void)
{
	fragColor = texture(cubeMap, vec3(FragIn.texCoord.x, FragIn.texCoord.y, FragIn.texCoord.z));
}