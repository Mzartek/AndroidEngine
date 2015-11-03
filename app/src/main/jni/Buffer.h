//
// Created by mzartek on 25/09/15.
//

#ifndef ANDROIDPROJECT_BUFFER_H
#define ANDROIDPROJECT_BUFFER_H

#include "Object.h"

namespace Engine
{
     class Buffer : public Object
     {
	  GLenum _target;
	  GLuint _idBuffer;
	  GLsizeiptr _size;

     public:
	  Buffer(void);
	  ~Buffer(void);
	  GLenum getTarget(void) const;
	  GLuint getId(void) const;
	  void createStore(GLenum target, const GLvoid *data, GLsizeiptr size, GLenum usage);
	  void updateStoreSub(const GLvoid *data) const;
     };
}

#endif //ANDROIDPROJECT_BUFFER_H
