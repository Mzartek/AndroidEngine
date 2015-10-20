#version 130

uniform mat4 MVPMatrix;

in vec3 vertexPosition;

out vec3 out_texCoord;

void main(void)
{
    gl_Position = MVPMatrix * vec4(vertexPosition, 1.0);
    out_texCoord = vertexPosition;
}