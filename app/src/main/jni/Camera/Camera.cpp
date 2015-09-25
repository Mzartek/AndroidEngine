//
// Created by mzartek on 25/09/15.
//

#include "Camera.h"

Engine::Camera::Camera(void)
{
}

Engine::Camera::~Camera(void)
{
}

const glm::mat4 &Engine::Camera::getProjectionMatrix(void) const
{
    return _projectionMatrix;
}

const glm::mat4 &Engine::Camera::getViewMatrix(void) const
{
    return _viewMatrix;
}

const glm::mat4 &Engine::Camera::getVPMatrix(void) const
{
    return _VPMatrix;
}

const glm::mat4 &Engine::Camera::getIVPMatrix(void) const
{
    return _IVPMatrix;
}