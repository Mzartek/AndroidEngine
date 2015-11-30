#ifndef ANDROIDPROJECT_GRAPHICSRENDERER_H
#define ANDROIDPROJECT_GRAPHICSRENDERER_H

#include "Object.h"

namespace Engine
{
     class GraphicsRenderer
     {
     public:
	  static GraphicsRenderer& Instance(void);

     private:
	  GraphicsRenderer(void);
	  ~GraphicsRenderer(void);

	  GLuint _width;
	  GLuint _height;

     public:
	  void printGLinfo(void);

	  void setSize(GLuint width, GLuint height);

	  void setSkyboxState(void) const;
	  void setGeometryState(void) const;

	  bool compareColor(const int x, const int y, const glm::vec3 &color);

	  void clear(void) const;
     };
}

#endif //ANDROIDPROJECT_GRAPHICSRENDERER_H
