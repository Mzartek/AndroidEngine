//
// Created by mzartek on 25/09/15.
//

#ifndef ANDROIDPROJECT_ORTHOCAMERA_H
#define ANDROIDPROJECT_ORTHOCAMERA_H

#include "Camera.h"

namespace Engine
{
    class OrthoCamera : public Camera
    {
    protected:
        struct
        {
            glm::vec3 position;
            glm::vec3 direction;
        } _cameraInfo;

        GLfloat _left;
        GLfloat _right;
        GLfloat _bottom;
        GLfloat _top;
        GLfloat _zNear;
        GLfloat _zFar;

    public:
        OrthoCamera(void);
        ~OrthoCamera(void);

        void setPosition(const glm::vec3 &pos);
        void setDirection(const glm::vec3 &dir);
        void setOrthogonal(GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat zNear, GLfloat zFar);

        void updateData(void) override;
    };
}

#endif //ANDROIDPROJECT_ORTHOCAMERA_H
