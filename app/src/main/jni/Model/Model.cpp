#include "Model.h"

void Engine::Model::checkMatrix(void)
{
     if (_needMatrix == GL_TRUE)
     {
	  _matrix.model = glm::translate(_position) * glm::toMat4(_rotation) * glm::scale(_scale);
	  _matrix.normal = glm::inverseTranspose(_matrix.model);
	  _needMatrix = GL_FALSE;
     }
}

Engine::Model::Model(const std::shared_ptr<ShaderProgram> &program)
     : _needMatrix(GL_TRUE), _isMirror(GL_FALSE), _cubeTexture(nullptr), _program(program)
{
     _position = glm::vec3(0, 0, 0);
     _scale = glm::vec3(1, 1, 1);
     _rotation = glm::quat();

     _tMesh = std::make_shared<std::vector<std::shared_ptr<Mesh>>>();

     glUseProgram(_program->getId());
     glUniform1i(glGetUniformLocation(_program->getId(), "diffuseTex"), 0);
     glUniform1i(glGetUniformLocation(_program->getId(), "specularTex"), 1);
     glUniform1i(glGetUniformLocation(_program->getId(), "ambiantTex"), 2);
     glUniform1i(glGetUniformLocation(_program->getId(), "emissiveTex"), 3);
     glUniform1i(glGetUniformLocation(_program->getId(), "shininessTex"), 4);
     glUniform1i(glGetUniformLocation(_program->getId(), "opacityTex"), 5);
     glUniform1i(glGetUniformLocation(_program->getId(), "bumpMap"), 6);
     glUniform1i(glGetUniformLocation(_program->getId(), "normalMap"), 7);
     glUniform1i(glGetUniformLocation(_program->getId(), "displacementMap"), 8);
     glUniform1i(glGetUniformLocation(_program->getId(), "lightMap"), 9);
     glUniform1i(glGetUniformLocation(_program->getId(), "reflectionTex"), 10);

     _MVPMatrixUniformLocation = glGetUniformLocation(_program->getId(), "MVPMatrix");
     _projectionMatrixUniformLocation = glGetUniformLocation(_program->getId(), "projectionMatrix");
     _viewMatrixUniformLocation = glGetUniformLocation(_program->getId(), "viewMatrix");
     _modelMatrixUniformLocation = glGetUniformLocation(_program->getId(), "modelMatrix");
     _normalMatrixUniformLocation = glGetUniformLocation(_program->getId(), "normalMatrix");
}

Engine::Model::Model(const std::shared_ptr<Model> &model, const std::shared_ptr<ShaderProgram> &program)
     : _needMatrix(GL_TRUE), _isMirror(GL_TRUE), _cubeTexture(nullptr), _program(program)
{
     _position = glm::vec3(0, 0, 0);
     _scale = glm::vec3(1, 1, 1);
     _rotation = glm::quat();

     _tMesh = model->_tMesh;

     glUseProgram(_program->getId());
     glUniform1i(glGetUniformLocation(_program->getId(), "diffuseTex"), 0);
     glUniform1i(glGetUniformLocation(_program->getId(), "specularTex"), 1);
     glUniform1i(glGetUniformLocation(_program->getId(), "ambiantTex"), 2);
     glUniform1i(glGetUniformLocation(_program->getId(), "emissiveTex"), 3);
     glUniform1i(glGetUniformLocation(_program->getId(), "shininessTex"), 4);
     glUniform1i(glGetUniformLocation(_program->getId(), "opacityTex"), 5);
     glUniform1i(glGetUniformLocation(_program->getId(), "bumpMap"), 6);
     glUniform1i(glGetUniformLocation(_program->getId(), "normalMap"), 7);
     glUniform1i(glGetUniformLocation(_program->getId(), "displacementMap"), 8);
     glUniform1i(glGetUniformLocation(_program->getId(), "lightMap"), 9);

     _MVPMatrixUniformLocation = glGetUniformLocation(_program->getId(), "MVPMatrix");
     _projectionMatrixUniformLocation = glGetUniformLocation(_program->getId(), "projectionMatrix");
     _viewMatrixUniformLocation = glGetUniformLocation(_program->getId(), "viewMatrix");
     _modelMatrixUniformLocation = glGetUniformLocation(_program->getId(), "modelMatrix");
     _normalMatrixUniformLocation = glGetUniformLocation(_program->getId(), "normalMatrix");
}

Engine::Model::~Model(void)
{
}

void Engine::Model::addMesh(const std::shared_ptr<Mesh> &mesh)
{
     if (_isMirror == GL_TRUE)
     {
	  ALOGE("Error Model configuration");
	  throw std::exception();
     }

     _tMesh->push_back(mesh);
}

void Engine::Model::setPosition(const glm::vec3 &position)
{
     _position = position;
     _needMatrix = GL_TRUE;
}

void Engine::Model::setScale(const glm::vec3 &scale)
{
     _scale = scale;
     _needMatrix = GL_TRUE;
}

void Engine::Model::setRotation(const glm::vec3 &rotation)
{
     _rotation = glm::quat(rotation);
     _needMatrix = GL_TRUE;
}

void Engine::Model::setRotation(const glm::vec3 &axis, GLfloat angle)
{
     _rotation = glm::angleAxis(fmodf(angle, glm::pi<GLfloat>() * 2), axis);
     _needMatrix = GL_TRUE;
}

void Engine::Model::addPosition(const glm::vec3 &position)
{
     _position += position;
     _needMatrix = GL_TRUE;
}

void Engine::Model::addScale(const glm::vec3 &scale)
{
     _scale += scale;
     _needMatrix = GL_TRUE;
}

void Engine::Model::addRotation(const glm::vec3 &rotation)
{
     _rotation = glm::quat(rotation) * _rotation;
     _needMatrix = GL_TRUE;
}

void Engine::Model::addRotation(const glm::vec3 &axis, GLfloat angle)
{
     _rotation = glm::angleAxis(fmodf(angle, glm::pi<GLfloat>() * 2), axis) * _rotation;
     _needMatrix = GL_TRUE;
}

void Engine::Model::setCubeTexture(const std::shared_ptr<TextureCube> &cubeTexture)
{
     _cubeTexture = cubeTexture;
}

const glm::vec3 &Engine::Model::getPosition(void) const
{
     return _position;
}

const glm::vec3 &Engine::Model::getScale(void) const
{
     return _scale;
}

std::pair<const glm::vec3 &, GLfloat> Engine::Model::getAxisAngleRotation(void) const
{
     return std::pair<const glm::vec3 &, GLfloat>(glm::vec3(glm::axis(_rotation)), glm::angle(_rotation));
}

const std::shared_ptr<Engine::Mesh> &Engine::Model::getMesh(GLuint num) const
{
     if (num >= _tMesh->size())
     {
	  throw std::invalid_argument("Bad num Mesh");
     }
     return (*_tMesh)[num];
}

extern "C"
{
     JNI_RETURN(void)
     Java_com_paris8_univ_androidproject_engine_model_Model_addMesh(JNIEnv *env, jobject thiz,
								    Engine::ObjectHandler objectHandler, 
								    Engine::ObjectHandler meshHandler)
     {
	  Engine::Mesh *mesh = Engine::Object::retrieveObject<Engine::Mesh>(meshHandler);
	  Engine::Object::retrieveObject<Engine::Model>(objectHandler)
	       ->addMesh(std::shared_ptr<Engine::Mesh>(mesh, Engine::null_deleter));
     }

     JNI_RETURN(void)
     Java_com_paris8_univ_androidproject_engine_model_Model_setPosition(JNIEnv *env, jobject thiz,
									Engine::ObjectHandler objectHandler,
									float x, float y, float z)
     {
	  Engine::Object::retrieveObject<Engine::Model>(objectHandler)->setPosition(glm::vec3(x, y, z));
     }

     JNI_RETURN(void)
     Java_com_paris8_univ_androidproject_engine_model_Model_setScale(JNIEnv *env, jobject thiz,
								     Engine::ObjectHandler objectHandler,
								     float x, float y, float z)
     {
	  Engine::Object::retrieveObject<Engine::Model>(objectHandler)->setScale(glm::vec3(x, y, z));
     }

     JNI_RETURN(void)
     Java_com_paris8_univ_androidproject_engine_model_Model_setRotation1(JNIEnv *env, jobject thiz,
									 Engine::ObjectHandler objectHandler,
									 float x, float y, float z)
     {
	  Engine::Object::retrieveObject<Engine::Model>(objectHandler)->setRotation(glm::vec3(x, y, z));
     }

     JNI_RETURN(void)
     Java_com_paris8_univ_androidproject_engine_model_Model_setRotation2(JNIEnv *env, jobject thiz,
									 Engine::ObjectHandler objectHandler,
									 float x, float y, float z, float angle)
     {
	  Engine::Object::retrieveObject<Engine::Model>(objectHandler)->setRotation(glm::vec3(x, y, z), angle);
     }

     JNI_RETURN(void)
     Java_com_paris8_univ_androidproject_engine_model_Model_addPosition(JNIEnv *env, jobject thiz,
									Engine::ObjectHandler objectHandler,
									float x, float y, float z)
     {
	  Engine::Object::retrieveObject<Engine::Model>(objectHandler)->addPosition(glm::vec3(x, y, z));
     }

     JNI_RETURN(void)
     Java_com_paris8_univ_androidproject_engine_model_Model_addScale(JNIEnv *env, jobject thiz,
								     Engine::ObjectHandler objectHandler,
								     float x, float y, float z)
     {
	  Engine::Object::retrieveObject<Engine::Model>(objectHandler)->addScale(glm::vec3(x, y, z));
     }

     JNI_RETURN(void)
     Java_com_paris8_univ_androidproject_engine_model_Model_addRotation1(JNIEnv *env, jobject thiz,
									 Engine::ObjectHandler objectHandler,
									 float x, float y, float z)
     {
	  Engine::Object::retrieveObject<Engine::Model>(objectHandler)->addRotation(glm::vec3(x, y, z));
     }

     JNI_RETURN(void)
     Java_com_paris8_univ_androidproject_engine_model_Model_addRotation2(JNIEnv *env, jobject thiz,
									 Engine::ObjectHandler objectHandler,
									 float x, float y, float z, float angle)
     {
	  Engine::Object::retrieveObject<Engine::Model>(objectHandler)->addRotation(glm::vec3(x, y, z), angle);
     }
}
