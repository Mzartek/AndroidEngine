uniform sampler2D diffuseTex;

varying vec2 out_TexCoord;

void main(void)
{
	gl_FragColor = texture2D(diffuseTex, out_TexCoord);
}