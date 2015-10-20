#version 130 uniform mat4 MVPMatrix;

layout(location = 0) in vec3 vertex;

out VertexData
{
    vec3 texCoord;
} VertOut;

void main(void)
{
    gl_Position = MVPMatrix * vec4(vertex, 1.0);
    VertOut.texCoord = vertex;
}