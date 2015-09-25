//
// Created by mzartek on 25/09/15.
//

#include "PerspCamera.h"

Engine::PerspCamera::PerspCamera(void)
        : _near(0.0f), _far(0.0f), _fov(0.0f), _frusSphereDistance(0.0f), _frusSphereRadius(0.0f)
{
    _cameraInfo.position = glm::vec3(0, 0, 0);
    _cameraInfo.forward = glm::vec3(0, 0, 1);
    _cameraInfo.left = glm::normalize(glm::vec3(_cameraInfo.forward.z, 0.0f, -_cameraInfo.forward.x));
    _cameraInfo.up = glm::cross(_cameraInfo.forward, _cameraInfo.left);
}

Engine::PerspCamera::~PerspCamera(void)
{
}

void Engine::PerspCamera::setCameraPosition(const glm::vec3 &pos)
{
    _cameraInfo.position = pos;
}

void Engine::PerspCamera::setAngle(GLfloat atheta, GLfloat aphi)
{
    GLfloat tmp = cosf(aphi);
    _cameraInfo.forward = glm::vec3(tmp * sinf(atheta), sinf(aphi), tmp * cosf(atheta));
    _cameraInfo.left = glm::normalize(glm::vec3(_cameraInfo.forward.z, 0.0f, -_cameraInfo.forward.x));
    _cameraInfo.up = glm::cross(_cameraInfo.forward, _cameraInfo.left);
}

void Engine::PerspCamera::setPositionAndTarget(const glm::vec3 &pos, const glm::vec3 &tar)
{
    _cameraInfo.position = pos;
    _cameraInfo.forward = glm::normalize(tar - pos);
    _cameraInfo.left = glm::normalize(glm::vec3(_cameraInfo.forward.z, 0.0f, -_cameraInfo.forward.x));
    _cameraInfo.up = glm::cross(_cameraInfo.forward, _cameraInfo.left);
}

void Engine::PerspCamera::setPerspective(GLfloat fov, GLuint width, GLuint height, GLfloat n, GLfloat f)
{
    GLfloat ratio = static_cast<GLfloat>(width) / height;
    GLfloat yfar = tanf(fov * 0.5f) * f;
    GLfloat xfar = yfar * ratio;

    _projectionMatrix = glm::perspective(fov, ratio, n, f);

    _near = n;
    _far = f;
    _fov = fov * ratio;
    _frusSphereDistance = n + (f - n) * 0.5f;
    _frusSphereRadius = glm::length(glm::vec3(xfar, yfar, f) - glm::vec3(0.0f, 0.0f, _frusSphereDistance));
}

const glm::vec3 &Engine::PerspCamera::getCameraPosition(void) const
{
    return _cameraInfo.position;
}

const glm::vec3 &Engine::PerspCamera::getForwardVector(void) const
{
    return _cameraInfo.forward;
}

const glm::vec3 &Engine::PerspCamera::getLeftVector(void) const
{
    return _cameraInfo.left;
}

const glm::vec3 &Engine::PerspCamera::getUpVector(void) const
{
    return _cameraInfo.up;
}

GLfloat Engine::PerspCamera::getNear(void) const
{
    return _near;
}

GLfloat Engine::PerspCamera::getFar(void) const
{
    return _far;
}

GLfloat Engine::PerspCamera::getFOV(void) const
{
    return _fov;
}

GLfloat Engine::PerspCamera::getFrusSphereDistance(void) const
{
    return _frusSphereDistance;
}

GLfloat Engine::PerspCamera::getFrusSphereRadius(void) const
{
    return _frusSphereRadius;
}

const glm::vec3 &Engine::PerspCamera::getFrusSpherePosition(void) const
{
    return _frusSpherePosition;
}

void Engine::PerspCamera::updateData(void)
{
    _frusSpherePosition = _cameraInfo.forward * _frusSphereDistance;

    _viewMatrix = glm::lookAt(_cameraInfo.position, _cameraInfo.position + _cameraInfo.forward, _cameraInfo.up);
    _VPMatrix = _projectionMatrix * _viewMatrix;
    _IVPMatrix = glm::inverse(_VPMatrix);
}