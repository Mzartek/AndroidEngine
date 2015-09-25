//
// Created by mzartek on 25/09/15.
//

#include "Buffer.h"

Engine::Buffer::Buffer(void)
        : _target(GL_ARRAY_BUFFER), _idBuffer(0), _size(0)
{
}

Engine::Buffer::~Buffer(void)
{
    if (glIsBuffer(_idBuffer)) glDeleteBuffers(1, &_idBuffer);
}

GLenum Engine::Buffer::getTarget(void) const
{
    return _target;
}

GLuint Engine::Buffer::getId(void) const
{
    return _idBuffer;
}

void Engine::Buffer::createStore(GLenum target, const GLvoid *data, GLsizeiptr size, GLenum usage)
{
    _target = target;
    _size = size;

    if (glIsBuffer(_idBuffer)) glDeleteBuffers(1, &_idBuffer);
    glGenBuffers(1, &_idBuffer);
    glBindBuffer(_target, _idBuffer);
    glBufferData(_target, _size, data, usage);
    glBindBuffer(_target, 0);
}

void Engine::Buffer::updateStoreSub(const GLvoid *data) const
{
    glBindBuffer(_target, _idBuffer);
    glBufferSubData(_target, 0, _size, data);
    glBindBuffer(_target, 0);
}