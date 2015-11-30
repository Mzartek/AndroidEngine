#ifndef ANDROIDPROJECT_PERSPCAMERA_H
#define ANDROIDPROJECT_PERSPCAMERA_H

#include "Camera.h"

namespace Engine
{
     class PerspCamera : public Camera
     {
     protected:
	  struct
	  {
	       glm::vec3 position;
	       glm::vec3 forward;
	       glm::vec3 left;
	       glm::vec3 up;
	  } _cameraInfo;

	  GLfloat _near;
	  GLfloat _far;
	  GLfloat _fov;
	  GLfloat _frusSphereDistance;
	  GLfloat _frusSphereRadius;
	  glm::vec3 _frusSpherePosition;

     public:
	  PerspCamera(void);
	  ~PerspCamera(void);

	  void setCameraPosition(const glm::vec3 &pos);
	  void setAngle(GLfloat atheta, GLfloat aphi);
	  void setPositionAndTarget(const glm::vec3 &pos, const glm::vec3 &tar);
	  void setPerspective(GLfloat fov, GLuint width, GLuint height, GLfloat n, GLfloat f);

	  const glm::vec3 &getCameraPosition(void) const;
	  const glm::vec3 &getForwardVector(void) const;
	  const glm::vec3 &getLeftVector(void) const;
	  const glm::vec3 &getUpVector(void) const;

	  GLfloat getNear(void) const;
	  GLfloat getFar(void) const;
	  GLfloat getFOV(void) const;
	  GLfloat getFrusSphereDistance(void) const;
	  GLfloat getFrusSphereRadius(void) const;
	  const glm::vec3 &getFrusSpherePosition(void) const;

	  void updateData(void) override;
     };
}

#endif //ANDROIDPROJECT_PERSPCAMERA_H
