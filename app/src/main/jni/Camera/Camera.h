#ifndef ANDROIDPROJECT_CAMERA_H
#define ANDROIDPROJECT_CAMERA_H

#include "../Buffer.h"

namespace Engine
{
     class Camera : public Object
     {
     protected:
	  glm::mat4 _projectionMatrix;
	  glm::mat4 _viewMatrix;
	  glm::mat4 _VPMatrix;
	  glm::mat4 _IVPMatrix;

     public:
	  Camera(void);
	  ~Camera(void);

	  const glm::mat4 &getProjectionMatrix(void) const;
	  const glm::mat4 &getViewMatrix(void) const;
	  const glm::mat4 &getVPMatrix(void) const;
	  const glm::mat4 &getIVPMatrix(void) const;

	  virtual void updateData(void) = 0;
     };
}

#endif //ANDROIDPROJECT_CAMERA_H
