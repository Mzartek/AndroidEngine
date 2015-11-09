//
// Created by Mzartek on 13/10/15.
//

#include "StaticModel.h"

#include "../../Tools/StringHandler.h"
#include "../../Tools/AssimpTool.h"
#include "../../Tools/AssetTool.h"

Engine::StaticModel::StaticModel(const std::shared_ptr<ShaderProgram> &program)
     : Model(program)
{
}

Engine::StaticModel::StaticModel(const std::shared_ptr<StaticModel> &model, const std::shared_ptr<ShaderProgram> &program)
     : Model(model, program)
{
}

Engine::StaticModel::~StaticModel(void)
{
}

void Engine::StaticModel::loadFromAsset(const GLchar *asset)
{
     if (_isMirror == GL_TRUE)
     {
	  ALOGE("Error Model configuration");
	  throw std::exception();
     }

     _tMesh->clear();

     Assimp::Importer importer;
     const aiScene *pScene = ToolsPrivate::openAsset(importer, asset);
     if (pScene->HasAnimations())
     {
	  ALOGE("Error Model configuration");
	  throw std::exception();
     }

     std::vector<StaticMesh::Vertex> vertices;
     std::vector<GLuint> indices;
     for (GLuint i = 0; i < pScene->mNumMeshes; i++)
     {
	  std::shared_ptr<StaticMesh> mesh = std::make_shared<StaticMesh>(_program);

	  vertices = ToolsPrivate::loadStaticVertices(pScene->mMeshes[i]);
	  indices = ToolsPrivate::loadIndices(pScene->mMeshes[i]);
	  mesh->setMaterial(ToolsPrivate::loadMaterial(pScene->mMaterials[pScene->mMeshes[i]->mMaterialIndex], Tools::getDir(asset)));

	  mesh->load(vertices, indices);

	  vertices.clear();
	  indices.clear();

	  addMesh(mesh);
     }
}

void Engine::StaticModel::display(const std::shared_ptr<PerspCamera> &cam)
{
     checkMatrix();

     Engine::GraphicsRenderer::Instance().setGeometryState();

     glUseProgram(_program->getId());

     glUniformMatrix4fv(_MVPMatrixUniformLocation       , 1, GL_FALSE, glm::value_ptr(cam->getVPMatrix() * _matrix.model));
     glUniformMatrix4fv(_projectionMatrixUniformLocation, 1, GL_FALSE, glm::value_ptr(cam->getProjectionMatrix()));
     glUniformMatrix4fv(_viewMatrixUniformLocation      , 1, GL_FALSE, glm::value_ptr(cam->getViewMatrix()));
     glUniformMatrix4fv(_modelMatrixUniformLocation     , 1, GL_FALSE, glm::value_ptr(_matrix.model));
     glUniformMatrix4fv(_normalMatrixUniformLocation    , 1, GL_FALSE, glm::value_ptr(_matrix.normal));

     for (GLuint i = 0; i < _tMesh->size(); i++)
	  if ((*_tMesh)[i]->getMaterial()->getOpacity() == 1.0f)
	  {
	       if (_cubeTexture)
		    (*_tMesh)[i]->display(_cubeTexture);
	       else
		    (*_tMesh)[i]->display();
	  }
}

void Engine::StaticModel::displayTransparent(const std::shared_ptr<PerspCamera> &cam)
{
     checkMatrix();

     Engine::GraphicsRenderer::Instance().setGeometryState();

     glUseProgram(_program->getId());

     glUniformMatrix4fv(_MVPMatrixUniformLocation       , 1, GL_FALSE, glm::value_ptr(cam->getVPMatrix() * _matrix.model));
     glUniformMatrix4fv(_projectionMatrixUniformLocation, 1, GL_FALSE, glm::value_ptr(cam->getProjectionMatrix()));
     glUniformMatrix4fv(_viewMatrixUniformLocation      , 1, GL_FALSE, glm::value_ptr(cam->getViewMatrix()));
     glUniformMatrix4fv(_modelMatrixUniformLocation     , 1, GL_FALSE, glm::value_ptr(_matrix.model));
     glUniformMatrix4fv(_normalMatrixUniformLocation    , 1, GL_FALSE, glm::value_ptr(_matrix.normal));

     for (GLuint i = 0; i < _tMesh->size(); i++)
	  if ((*_tMesh)[i]->getMaterial()->getOpacity() < 1.0f)
	  {
	       if (_cubeTexture)
		    (*_tMesh)[i]->display(_cubeTexture);
	       else
		    (*_tMesh)[i]->display();
	  }
}

void Engine::StaticModel::displayOffSet(const std::shared_ptr<PerspCamera> &cam, const glm::vec3 &offset)
{
     checkMatrix();

     Engine::GraphicsRenderer::Instance().setGeometryState();

     glUseProgram(_program->getId());

     glUniformMatrix4fv(_MVPMatrixUniformLocation       , 1, GL_FALSE, glm::value_ptr(cam->getVPMatrix() * _matrix.model * glm::translate(offset)));
     glUniformMatrix4fv(_projectionMatrixUniformLocation, 1, GL_FALSE, glm::value_ptr(cam->getProjectionMatrix()));
     glUniformMatrix4fv(_viewMatrixUniformLocation      , 1, GL_FALSE, glm::value_ptr(cam->getViewMatrix()));
     glUniformMatrix4fv(_modelMatrixUniformLocation     , 1, GL_FALSE, glm::value_ptr(_matrix.model * glm::translate(offset)));
     glUniformMatrix4fv(_normalMatrixUniformLocation    , 1, GL_FALSE, glm::value_ptr(_matrix.normal));

     for (GLuint i = 0; i < _tMesh->size(); i++)
	  if ((*_tMesh)[i]->getMaterial()->getOpacity() == 1.0f)
	  {
	       if (_cubeTexture)
		    (*_tMesh)[i]->display(_cubeTexture);
	       else
		    (*_tMesh)[i]->display();
	  }
}

extern "C"
{
     JNI_RETURN(Engine::ObjectHandler)
     Java_com_paris8_univ_androidproject_engine_model_staticmodel_StaticModel_createStaticModel1(JNIEnv *env, jobject thiz,
												 Engine::ObjectHandler shaderProgramHandler)
     {
	  Engine::ShaderProgram *shaderProgram = Engine::Object::retrieveObject<Engine::ShaderProgram>(shaderProgramHandler);
	  Engine::Object *object = new Engine::StaticModel(std::shared_ptr<Engine::ShaderProgram>(shaderProgram, Engine::null_deleter));

	  ALOGD("New StaticModel (Handler=%lld)", object->getHandler());
	  return object->getHandler();
     }
	
     JNI_RETURN(Engine::ObjectHandler)
     Java_com_paris8_univ_androidproject_engine_model_staticmodel_StaticModel_createStaticModel2(JNIEnv *env, jobject thiz,
												 Engine::ObjectHandler staticModelHandler,
												 Engine::ObjectHandler shaderProgramHandler)
     {
	  Engine::StaticModel *staticModel = Engine::Object::retrieveObject<Engine::StaticModel>(staticModelHandler);
	  Engine::ShaderProgram *shaderProgram = Engine::Object::retrieveObject<Engine::ShaderProgram>(shaderProgramHandler);
	  Engine::Object *object = new Engine::StaticModel(
	       std::shared_ptr<Engine::StaticModel>(staticModel, Engine::null_deleter),
	       std::shared_ptr<Engine::ShaderProgram>(shaderProgram, Engine::null_deleter));

	  ALOGD("New StaticModel (Handler=%lld)", object->getHandler());
	  return object->getHandler();
     }

     JNI_RETURN(void)
     Java_com_paris8_univ_androidproject_engine_model_staticmodel_StaticModel_loadFromAsset(JNIEnv *env, jobject thiz,
											    Engine::ObjectHandler objectHandler,
											    jobject assetManager, jstring asset)
     {		
	  const char *assetString = env->GetStringUTFChars(asset, 0);

	  Engine::Tools::jniEnv = env;
	  Engine::Tools::jniAssetManager = assetManager;
	  Engine::Object::retrieveObject<Engine::StaticModel>(objectHandler)->loadFromAsset(assetString);

	  env->ReleaseStringUTFChars(asset, assetString);
     }

     JNI_RETURN(void)
     Java_com_paris8_univ_androidproject_engine_model_staticmodel_StaticModel_display(JNIEnv *env, jobject thiz,
										      Engine::ObjectHandler objectHandler,
										      Engine::ObjectHandler cameraHandler)
     {
	  Engine::PerspCamera *camera = Engine::Object::retrieveObject<Engine::PerspCamera>(cameraHandler);
	  Engine::Object::retrieveObject<Engine::StaticModel>(objectHandler)
	       ->display(std::shared_ptr<Engine::PerspCamera>(camera, Engine::null_deleter));
     }

     JNI_RETURN(void)
     Java_com_paris8_univ_androidproject_engine_model_staticmodel_StaticModel_displayTransparent(JNIEnv *env, jobject thiz,
												 Engine::ObjectHandler objectHandler,
												 Engine::ObjectHandler cameraHandler)
     {
	  Engine::PerspCamera *camera = Engine::Object::retrieveObject<Engine::PerspCamera>(cameraHandler);
	  Engine::Object::retrieveObject<Engine::StaticModel>(objectHandler)
	       ->displayTransparent(std::shared_ptr<Engine::PerspCamera>(camera, Engine::null_deleter));
     }

     JNI_RETURN(void)
     Java_com_paris8_univ_androidproject_engine_model_staticmodel_StaticModel_displayOffSet(JNIEnv *env, jobject thiz,
											    Engine::ObjectHandler objectHandler,
											    Engine::ObjectHandler cameraHandler,
											    jfloat x, jfloat y, jfloat z)
     {
	  Engine::PerspCamera *camera = Engine::Object::retrieveObject<Engine::PerspCamera>(cameraHandler);
	  Engine::Object::retrieveObject<Engine::StaticModel>(objectHandler)
	       ->displayOffSet(std::shared_ptr<Engine::PerspCamera>(camera, Engine::null_deleter), glm::vec3(x, y, z));
     }
}
