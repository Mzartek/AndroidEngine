uniform mat4 MVPMatrix;

attribute vec3 vertexPosition;
attribute vec2 textureCoord;
attribute vec3 normalVector;
attribute vec3 tangentVector;

varying vec2 out_TexCoord;

void main(void)
{
    gl_Position = MVPMatrix * vec4(vertexPosition, 1.0);
    out_TexCoord = textureCoord;
}