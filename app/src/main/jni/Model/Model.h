//
// Created by Mzartek on 13/10/15.
//

#ifndef ANDROIDPROJECT_MODEL_H
#define ANDROIDPROJECT_MODEL_H

#include "../Buffer.h"
#include "../Object.h"

#include "../Camera/PerspCamera.h"

#include "../ShaderProgram.h"

#include "Mesh.h"

namespace Engine
{
     class Model : public Object
     {
	  glm::vec3 _position;
	  glm::vec3 _scale;
	  glm::quat _rotation;

	  GLboolean _needMatrix;

     protected:
	  struct
	  {
	       glm::mat4 model;
	       glm::mat4 normal;
	  } _matrix;

	  GLboolean _isMirror;

	  std::shared_ptr<std::vector<std::shared_ptr<Mesh>>> _tMesh;

	  std::shared_ptr<TextureCube> _cubeTexture;

	  std::shared_ptr<ShaderProgram> _program;

	  GLint _MVPMatrixUniformLocation;
	  GLint _projectionMatrixUniformLocation;
	  GLint _viewMatrixUniformLocation;
	  GLint _modelMatrixUniformLocation;
	  GLint _normalMatrixUniformLocation;

	  void checkMatrix(void);

     public:
	  Model(const std::shared_ptr<ShaderProgram> &program);
	  Model(const std::shared_ptr<Model> &model, const std::shared_ptr<ShaderProgram> &program);
	  ~Model(void);

	  void addMesh(const std::shared_ptr<Mesh> &mesh);

	  void setPosition(const glm::vec3 &position);
	  void setScale(const glm::vec3 &scale);
	  void setRotation(const glm::vec3 &rotation);
	  void setRotation(const glm::vec3 &axis, GLfloat angle);

	  void addPosition(const glm::vec3 &position);
	  void addScale(const glm::vec3 &scale);
	  void addRotation(const glm::vec3 &rotation);
	  void addRotation(const glm::vec3 &axis, GLfloat angle);

	  void setCubeTexture(const std::shared_ptr<TextureCube> &cubeTexture);

	  const glm::vec3 &getPosition(void) const;
	  const glm::vec3 &getScale(void) const;
	  std::pair<const glm::vec3 &, GLfloat> getAxisAngleRotation(void) const;

	  const std::shared_ptr<Mesh> &getMesh(GLuint num) const;

	  virtual void display(const std::shared_ptr<PerspCamera> &cam) = 0;
	  virtual void displayTransparent(const std::shared_ptr<PerspCamera> &cam) = 0;
	  virtual void displayOffSet(const std::shared_ptr<PerspCamera> &cam, const glm::vec3 &offset) = 0;
     };
}

#endif //ANDROIDPROJECT_MODEL_H
