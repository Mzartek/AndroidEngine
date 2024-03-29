uniform mat4 MVPMatrix;

attribute vec3 vertexPosition;

varying vec3 out_texCoord;

void main(void)
{
    gl_Position = MVPMatrix * vec4(vertexPosition, 1.0);
    out_texCoord = vertexPosition;
}