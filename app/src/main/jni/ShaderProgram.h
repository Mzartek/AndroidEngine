#ifndef ANDROIDPROJECT_SHADERPROGRAM_H
#define ANDROIDPROJECT_SHADERPROGRAM_H

#include "Object.h"

namespace Engine
{
     class ShaderProgram : public Object
     {
     private:
	  GLuint _idProgram;
	  GLuint _idVertexShader;
	  GLuint _idFragmentShader;

     public:
	  ShaderProgram(const GLchar *vs, const GLchar *fs);
	  ~ShaderProgram(void);

	  GLuint getId(void) const;
     };
}

#endif //ANDROIDPROJECT_SHADERPROGRAM_H
