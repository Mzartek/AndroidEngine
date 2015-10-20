#version 130 uniform samplerCube cubeMap;

in VertexData
{
	vec3 texCoord;
} FragIn;

out vec4 fragColor;

void main(void)
{
	fragColor = texture(cubeMap, vec3(FragIn.texCoord.x, FragIn.texCoord.y, FragIn.texCoord.z));
}