//
// Created by Mzartek on 05/10/15.
//

#include "Material.h"

Engine::Material::Material(void)
        : _diffuseTexture(nullptr), _specularTexture(nullptr), _ambientTexture(nullptr), _emissiveTexture(nullptr), _shininessTexture(nullptr),
          _opacityTexture(nullptr), _bumpMap(nullptr), _normalMap(nullptr), _displacementMap(nullptr), _lightMap(nullptr)
{
	_mat.diffuse = glm::vec3(0.0f, 0.0f, 0.0f);
	_mat.specular = glm::vec3(0.0f, 0.0f, 0.0f);
	_mat.ambient = glm::vec3(0.0f, 0.0f, 0.0f);
	_mat.emissive = glm::vec3(0.0f, 0.0f, 0.0f);
	_mat.shininess = 1.0f;
	_mat.opacity = 1.0f;

	_state.hasDiffuseTexture = GL_FALSE;
	_state.hasSpecularTexture = GL_FALSE;
	_state.hasAmbientTexture = GL_FALSE;
	_state.hasEmissiveTexture = GL_FALSE;
	_state.hasShininessTexture = GL_FALSE;
	_state.hasOpacityTexture = GL_FALSE;
	_state.hasBumpMap = GL_FALSE;
	_state.hasNormalMap = GL_FALSE;
	_state.hasDisplacementMap = GL_FALSE;
	_state.hasLightMap = GL_FALSE;
}

Engine::Material::~Material(void)
{
}

void Engine::Material::setDiffuse(const glm::vec3 &color)
{
	_mat.diffuse = color;
}

void Engine::Material::setSpecular(const glm::vec3 &color)
{
	_mat.specular = color;
}

void Engine::Material::setAmbient(const glm::vec3 &color)
{
	_mat.ambient = color;
}

void Engine::Material::setEmissive(const glm::vec3 &color)
{
	_mat.emissive = color;
}

void Engine::Material::setShininess(GLfloat shininess)
{
	_mat.shininess = shininess;
}

void Engine::Material::setOpacity(GLfloat opacity)
{
	_mat.opacity = opacity;
}

void Engine::Material::setDiffuseTexture(const std::shared_ptr<Texture2D> &tex)
{
	_diffuseTexture = tex;

	if (_diffuseTexture)
		_state.hasDiffuseTexture = GL_TRUE;
	else
		_state.hasDiffuseTexture = GL_FALSE;
}

void Engine::Material::setSpecularTexture(const std::shared_ptr<Texture2D> &tex)
{
	_specularTexture = tex;

	if (_diffuseTexture)
		_state.hasSpecularTexture = GL_TRUE;
	else
		_state.hasSpecularTexture = GL_FALSE;
}

void Engine::Material::setAmbientTexture(const std::shared_ptr<Texture2D> &tex)
{
	_ambientTexture = tex;

	if (_diffuseTexture)
		_state.hasAmbientTexture = GL_TRUE;
	else
		_state.hasAmbientTexture = GL_FALSE;
}

void Engine::Material::setEmissiveTexture(const std::shared_ptr<Texture2D> &tex)
{
	_emissiveTexture = tex;

	if (_diffuseTexture)
		_state.hasEmissiveTexture = GL_TRUE;
	else
		_state.hasEmissiveTexture = GL_FALSE;
}

void Engine::Material::setShininessTexture(const std::shared_ptr<Texture2D> &tex)
{
	_shininessTexture = tex;

	if (_diffuseTexture)
		_state.hasShininessTexture = GL_TRUE;
	else
		_state.hasShininessTexture = GL_FALSE;
}

void Engine::Material::setOpacityTexture(const std::shared_ptr<Texture2D> &tex)
{
	_opacityTexture = tex;

	if (_diffuseTexture)
		_state.hasOpacityTexture = GL_TRUE;
	else
		_state.hasOpacityTexture = GL_FALSE;
}

void Engine::Material::setBumpMap(const std::shared_ptr<Texture2D> &tex)
{
	_bumpMap = tex;

	if (_diffuseTexture)
		_state.hasBumpMap = GL_TRUE;
	else
		_state.hasBumpMap = GL_FALSE;
}

void Engine::Material::setNormalMap(const std::shared_ptr<Texture2D> &tex)
{
	_normalMap = tex;

	if (_diffuseTexture)
		_state.hasNormalMap = GL_TRUE;
	else
		_state.hasNormalMap = GL_FALSE;
}

void Engine::Material::setDisplacementMap(const std::shared_ptr<Texture2D> &tex)
{
	_displacementMap = tex;

	if (_diffuseTexture)
		_state.hasDisplacementMap = GL_TRUE;
	else
		_state.hasDisplacementMap = GL_FALSE;
}

void Engine::Material::setLightMap(const std::shared_ptr<Texture2D> &tex)
{
	_lightMap = tex;

	if (_diffuseTexture)
		_state.hasLightMap = GL_TRUE;
	else
		_state.hasLightMap = GL_FALSE;
}

const glm::vec3 &Engine::Material::getDiffuse(void) const
{
	return _mat.diffuse;
}

const glm::vec3 &Engine::Material::getSpecular(void) const
{
	return _mat.specular;
}

const glm::vec3 &Engine::Material::getAmbient(void) const
{
	return _mat.ambient;
}

const glm::vec3 &Engine::Material::getEmissive(void) const
{
	return _mat.emissive;
}

GLfloat Engine::Material::getShininess(void) const
{
	return _mat.shininess;
}

GLfloat Engine::Material::getOpacity(void) const
{
	return _mat.opacity;
}

const std::shared_ptr<Engine::Texture2D> &Engine::Material::getDiffuseTexture(void) const
{
	return _diffuseTexture;
}

const std::shared_ptr<Engine::Texture2D> &Engine::Material::getSpecularTexture(void) const
{
	return _specularTexture;
}

const std::shared_ptr<Engine::Texture2D> &Engine::Material::getAmbientTexture(void) const
{
	return _ambientTexture;
}

const std::shared_ptr<Engine::Texture2D> &Engine::Material::getEmissiveTexture(void) const
{
	return _emissiveTexture;
}

const std::shared_ptr<Engine::Texture2D> &Engine::Material::getShininessTexture(void) const
{
	return _shininessTexture;
}

const std::shared_ptr<Engine::Texture2D> &Engine::Material::getOpacityTexture(void) const
{
	return _opacityTexture;
}

const std::shared_ptr<Engine::Texture2D> &Engine::Material::getBumpMap(void) const
{
	return _bumpMap;
}

const std::shared_ptr<Engine::Texture2D> &Engine::Material::getNormalMap(void) const
{
	return _normalMap;
}

const std::shared_ptr<Engine::Texture2D> &Engine::Material::getDisplacementMap(void) const
{
	return _displacementMap;
}

const std::shared_ptr<Engine::Texture2D> &Engine::Material::getLightMap(void) const
{
	return _lightMap;
}

GLboolean Engine::Material::hasDiffuseTexture(void) const
{
	return static_cast<GLboolean>(_state.hasDiffuseTexture);
}

GLboolean Engine::Material::hasSpecularTexture(void) const
{
	return static_cast<GLboolean>(_state.hasSpecularTexture);
}

GLboolean Engine::Material::hasAmbientTexture(void) const
{
	return static_cast<GLboolean>(_state.hasAmbientTexture);
}

GLboolean Engine::Material::hasEmissiveTexture(void) const
{
	return static_cast<GLboolean>(_state.hasEmissiveTexture);
}

GLboolean Engine::Material::hasShininessTexture(void) const
{
	return static_cast<GLboolean>(_state.hasShininessTexture);
}

GLboolean Engine::Material::hasOpacityTexture(void) const
{
	return static_cast<GLboolean>(_state.hasOpacityTexture);
}

GLboolean Engine::Material::hasBumpMap(void) const
{
	return static_cast<GLboolean>(_state.hasBumpMap);
}

GLboolean Engine::Material::hasNormalMap(void) const
{
	return static_cast<GLboolean>(_state.hasNormalMap);
}

GLboolean Engine::Material::hasDisplacementMap(void) const
{
	return static_cast<GLboolean>(_state.hasDisplacementMap);
}

GLboolean Engine::Material::hasLightMap(void) const
{
	return static_cast<GLboolean>(_state.hasLightMap);
}

extern "C"
{
	JNI_RETURN(Engine::ObjectHandler)
	Java_com_paris8_univ_androidproject_engine_model_Material_createMaterial(JNIEnv *env, jobject thiz)
	{
		Engine::Object *object = new Engine::Material();

		ALOGD("New Material (Handler=%lld)", object->getHandler());
		return object->getHandler();
	}

	JNI_RETURN(void)
	Java_com_paris8_univ_androidproject_engine_model_Material_setDiffuse(JNIEnv *env, jobject thiz,
									     Engine::ObjectHandler objectHandler,
									     jfloat r, jfloat g, jfloat b)
	{
		Engine::Object::retrieveObject<Engine::Material>(objectHandler)->setDiffuse(glm::vec3(r, g, b));
	}

	JNI_RETURN(void)
	Java_com_paris8_univ_androidproject_engine_model_Material_setSpecular(JNIEnv *env, jobject thiz,
									     Engine::ObjectHandler objectHandler,
									     jfloat r, jfloat g, jfloat b)
	{
		Engine::Object::retrieveObject<Engine::Material>(objectHandler)->setSpecular(glm::vec3(r, g, b));
	}

	JNI_RETURN(void)
	Java_com_paris8_univ_androidproject_engine_model_Material_setAmbient(JNIEnv *env, jobject thiz,
									     Engine::ObjectHandler objectHandler,
									     jfloat r, jfloat g, jfloat b)
	{
		Engine::Object::retrieveObject<Engine::Material>(objectHandler)->setAmbient(glm::vec3(r, g, b));
	}

	JNI_RETURN(void)
	Java_com_paris8_univ_androidproject_engine_model_Material_setEmissive(JNIEnv *env, jobject thiz,
									     Engine::ObjectHandler objectHandler,
									     jfloat r, jfloat g, jfloat b)
	{
		Engine::Object::retrieveObject<Engine::Material>(objectHandler)->setEmissive(glm::vec3(r, g, b));
	}

	JNI_RETURN(void)
	Java_com_paris8_univ_androidproject_engine_model_Material_setShininess(JNIEnv *env, jobject thiz,
									     Engine::ObjectHandler objectHandler,
									     jfloat shininess)
	{
		Engine::Object::retrieveObject<Engine::Material>(objectHandler)->setShininess(shininess);
	}

	JNI_RETURN(void)
	Java_com_paris8_univ_androidproject_engine_model_Material_setOpacity(JNIEnv *env, jobject thiz,
									     Engine::ObjectHandler objectHandler,
									     jfloat opacity)
	{
		Engine::Object::retrieveObject<Engine::Material>(objectHandler)->setOpacity(opacity);
	}

	JNI_RETURN(void)
	Java_com_paris8_univ_androidproject_engine_model_Material_setDiffuseTexture(JNIEnv *env, jobject thiz,
									     Engine::ObjectHandler objectHandler,
									     Engine::ObjectHandler textureHandler)
	{
		Engine::Texture2D *texture = Engine::Object::retrieveObject<Engine::Texture2D>(textureHandler);
		Engine::Object::retrieveObject<Engine::Material>(objectHandler)
			->setDiffuseTexture(std::shared_ptr<Engine::Texture2D>(texture, Engine::null_deleter));
	}

	JNI_RETURN(void)
	Java_com_paris8_univ_androidproject_engine_model_Material_setSpecularTexture(JNIEnv *env, jobject thiz,
									     Engine::ObjectHandler objectHandler,
									     Engine::ObjectHandler textureHandler)
	{
		Engine::Texture2D *texture = Engine::Object::retrieveObject<Engine::Texture2D>(textureHandler);
		Engine::Object::retrieveObject<Engine::Material>(objectHandler)
			->setSpecularTexture(std::shared_ptr<Engine::Texture2D>(texture, Engine::null_deleter));
	}

	JNI_RETURN(void)
	Java_com_paris8_univ_androidproject_engine_model_Material_setAmbientTexture(JNIEnv *env, jobject thiz,
									     Engine::ObjectHandler objectHandler,
									     Engine::ObjectHandler textureHandler)
	{
		Engine::Texture2D *texture = Engine::Object::retrieveObject<Engine::Texture2D>(textureHandler);
		Engine::Object::retrieveObject<Engine::Material>(objectHandler)
			->setAmbientTexture(std::shared_ptr<Engine::Texture2D>(texture, Engine::null_deleter));
	}

	JNI_RETURN(void)
	Java_com_paris8_univ_androidproject_engine_model_Material_setEmissiveTexture(JNIEnv *env, jobject thiz,
									     Engine::ObjectHandler objectHandler,
									     Engine::ObjectHandler textureHandler)
	{
		Engine::Texture2D *texture = Engine::Object::retrieveObject<Engine::Texture2D>(textureHandler);
		Engine::Object::retrieveObject<Engine::Material>(objectHandler)
			->setEmissiveTexture(std::shared_ptr<Engine::Texture2D>(texture, Engine::null_deleter));
	}

	JNI_RETURN(void)
	Java_com_paris8_univ_androidproject_engine_model_Material_setShininessTexture(JNIEnv *env, jobject thiz,
									     Engine::ObjectHandler objectHandler,
									     Engine::ObjectHandler textureHandler)
	{
		Engine::Texture2D *texture = Engine::Object::retrieveObject<Engine::Texture2D>(textureHandler);
		Engine::Object::retrieveObject<Engine::Material>(objectHandler)
			->setShininessTexture(std::shared_ptr<Engine::Texture2D>(texture, Engine::null_deleter));
	}

	JNI_RETURN(void)
	Java_com_paris8_univ_androidproject_engine_model_Material_setOpacityTexture(JNIEnv *env, jobject thiz,
									     Engine::ObjectHandler objectHandler,
									     Engine::ObjectHandler textureHandler)
	{
		Engine::Texture2D *texture = Engine::Object::retrieveObject<Engine::Texture2D>(textureHandler);
		Engine::Object::retrieveObject<Engine::Material>(objectHandler)
			->setOpacityTexture(std::shared_ptr<Engine::Texture2D>(texture, Engine::null_deleter));
	}

	JNI_RETURN(void)
	Java_com_paris8_univ_androidproject_engine_model_Material_setBumpMap(JNIEnv *env, jobject thiz,
									     Engine::ObjectHandler objectHandler,
									     Engine::ObjectHandler textureHandler)
	{
		Engine::Texture2D *texture = Engine::Object::retrieveObject<Engine::Texture2D>(textureHandler);
		Engine::Object::retrieveObject<Engine::Material>(objectHandler)
			->setBumpMap(std::shared_ptr<Engine::Texture2D>(texture, Engine::null_deleter));
	}

	JNI_RETURN(void)
	Java_com_paris8_univ_androidproject_engine_model_Material_setNormalMap(JNIEnv *env, jobject thiz,
									     Engine::ObjectHandler objectHandler,
									     Engine::ObjectHandler textureHandler)
	{
		Engine::Texture2D *texture = Engine::Object::retrieveObject<Engine::Texture2D>(textureHandler);
		Engine::Object::retrieveObject<Engine::Material>(objectHandler)
			->setNormalMap(std::shared_ptr<Engine::Texture2D>(texture, Engine::null_deleter));
	}

	JNI_RETURN(void)
	Java_com_paris8_univ_androidproject_engine_model_Material_setDisplacementMap(JNIEnv *env, jobject thiz,
									     Engine::ObjectHandler objectHandler,
									     Engine::ObjectHandler textureHandler)
	{
		Engine::Texture2D *texture = Engine::Object::retrieveObject<Engine::Texture2D>(textureHandler);
		Engine::Object::retrieveObject<Engine::Material>(objectHandler)
			->setDisplacementMap(std::shared_ptr<Engine::Texture2D>(texture, Engine::null_deleter));
	}

	JNI_RETURN(void)
	Java_com_paris8_univ_androidproject_engine_model_Material_setLightMap(JNIEnv *env, jobject thiz,
									     Engine::ObjectHandler objectHandler,
									     Engine::ObjectHandler textureHandler)
	{
		Engine::Texture2D *texture = Engine::Object::retrieveObject<Engine::Texture2D>(textureHandler);
		Engine::Object::retrieveObject<Engine::Material>(objectHandler)
			->setLightMap(std::shared_ptr<Engine::Texture2D>(texture, Engine::null_deleter));
	}
}
