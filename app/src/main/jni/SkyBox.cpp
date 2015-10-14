//
// Created by khavranek on 30/09/15.
//

#include "SkyBox.h"

Engine::SkyBox::SkyBox(std::shared_ptr<ShaderProgram> program)
        : _program(program)
{
    _cubeTexture = std::make_shared<TextureCube>();
    _vertexBuffer = std::make_shared<Buffer>();
    _indexBuffer = std::make_shared<Buffer>();

    GLfloat vertexArray[] =
            {
                    +SKYBOX_DIM, -SKYBOX_DIM, -SKYBOX_DIM,
                    -SKYBOX_DIM, -SKYBOX_DIM, -SKYBOX_DIM,
                    -SKYBOX_DIM, -SKYBOX_DIM, +SKYBOX_DIM,
                    +SKYBOX_DIM, -SKYBOX_DIM, +SKYBOX_DIM,
                    +SKYBOX_DIM, +SKYBOX_DIM, -SKYBOX_DIM,
                    -SKYBOX_DIM, +SKYBOX_DIM, -SKYBOX_DIM,
                    -SKYBOX_DIM, +SKYBOX_DIM, +SKYBOX_DIM,
                    +SKYBOX_DIM, +SKYBOX_DIM, +SKYBOX_DIM
            };
    GLuint indexArray[] =
            {
                    0, 1, 2, 0, 2, 3,
                    4, 7, 6, 4, 6, 5,
                    0, 4, 5, 0, 5, 1,
                    3, 2, 6, 3, 6, 7,
                    1, 5, 6, 1, 6, 2,
                    0, 3, 7, 0, 7, 4
            };
    _numElement = sizeof indexArray / sizeof(GLuint);
    _vertexBuffer->createStore(GL_ARRAY_BUFFER, vertexArray, sizeof vertexArray, GL_STATIC_DRAW);
    _indexBuffer->createStore(GL_ELEMENT_ARRAY_BUFFER, indexArray, sizeof indexArray, GL_STATIC_DRAW);

    _MVPUniformLocation = glGetUniformLocation(_program->getId(), "MVP");

    glUseProgram(_program->getId());
    glUniform1i(glGetUniformLocation(_program->getId(), "cubeMap"), 0);
}

Engine::SkyBox::~SkyBox(void)
{
}

void Engine::SkyBox::load(const GLchar *posx, const GLchar *negx,
                                    const GLchar *posy, const GLchar *negy,
                                    const GLchar *posz, const GLchar *negz) const
{
    _cubeTexture->loadFromFiles(posx, negx, posy, negy, posz, negz);
}

const std::shared_ptr<Engine::TextureCube> &Engine::SkyBox::getTexture(void) const
{
    return _cubeTexture;
}

void Engine::SkyBox::display(const std::shared_ptr<PerspCamera> &cam) const
{
    Engine::GraphicsRenderer::Instance().setSkyboxState();

    glm::mat4 pos = cam->getVPMatrix() * glm::translate(cam->getCameraPosition());

    glUseProgram(_program->getId());

    glUniformMatrix4fv(_MVPUniformLocation, 1, GL_FALSE, glm::value_ptr(pos));

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_CUBE_MAP, _cubeTexture->getId());

    glBindBuffer(GL_ARRAY_BUFFER, _vertexBuffer->getId());
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _indexBuffer->getId());
    {
        glEnableVertexAttribArray(0);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, GLsizei(3 * sizeof(GLfloat)), BUFFER_OFFSET(0));
        glDrawElements(GL_TRIANGLES, _numElement, GL_UNSIGNED_INT, 0);

        glDisableVertexAttribArray(0);
    }
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

extern "C"
{
    JNI_RETURN(Engine::ObjectHandler) Java_com_paris8_univ_androidproject_engine_SkyBox_newSkyBox(JNIEnv *env, jobject thiz, Engine::ObjectHandler shaderProgramHandler);
    JNI_RETURN(void) Java_com_paris8_univ_androidproject_engine_SkyBox_load(JNIEnv *env, jobject thiz, Engine::ObjectHandler objectHandler,
                                                                            jstring posx, jstring negx,
                                                                            jstring posy, jstring negy,
                                                                            jstring posz, jstring negz);
    JNI_RETURN(void) Java_com_paris8_univ_androidproject_engine_SkyBox_display(JNIEnv *env, jobject thiz, Engine::ObjectHandler objectHandler, Engine::ObjectHandler cameraObjectHandler);
}

Engine::ObjectHandler Java_com_paris8_univ_androidproject_engine_SkyBox_newSkyBox(JNIEnv *env, jobject thiz, Engine::ObjectHandler shaderProgramHandler)
{
    Engine::ShaderProgram *shaderProgram = Engine::Object::retrieveObject<Engine::ShaderProgram>(shaderProgramHandler);
    Engine::Object *object = new Engine::SkyBox(std::shared_ptr<Engine::ShaderProgram>(shaderProgram, Engine::null_deleter));

    ALOGD("New SkyBox (Handler=%lld)", object->getHandler());
    return object->getHandler();
}

void Java_com_paris8_univ_androidproject_engine_SkyBox_load(JNIEnv *env, jobject thiz, Engine::ObjectHandler objectHandler,
                                                            jstring posx, jstring negx,
                                                            jstring posy, jstring negy,
                                                            jstring posz, jstring negz)
{
    const char *posx_string = env->GetStringUTFChars(posx, 0);
    const char *negx_string = env->GetStringUTFChars(negx, 0);
    const char *posy_string = env->GetStringUTFChars(posy, 0);
    const char *negy_string = env->GetStringUTFChars(negy, 0);
    const char *posz_string = env->GetStringUTFChars(posz, 0);
    const char *negz_string = env->GetStringUTFChars(negz, 0);

    Engine::Object::retrieveObject<Engine::SkyBox>(objectHandler)->load(posx_string, negx_string,
                                                                        posy_string, negy_string,
                                                                        posz_string, negz_string);

    env->ReleaseStringUTFChars(posx, posx_string);
    env->ReleaseStringUTFChars(negx, negx_string);
    env->ReleaseStringUTFChars(posy, posy_string);
    env->ReleaseStringUTFChars(negy, negy_string);
    env->ReleaseStringUTFChars(posz, posz_string);
    env->ReleaseStringUTFChars(negz, negz_string);
}

void Java_com_paris8_univ_androidproject_engine_SkyBox_display(JNIEnv *env, jobject thiz, Engine::ObjectHandler objectHandler, Engine::ObjectHandler cameraObjectHandler)
{
    Engine::PerspCamera *perspCamera = Engine::Object::retrieveObject<Engine::PerspCamera>(cameraObjectHandler);
    Engine::Object::retrieveObject<Engine::SkyBox>(objectHandler)->display(std::shared_ptr<Engine::PerspCamera>(perspCamera, Engine::null_deleter));
}