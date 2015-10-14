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

#define JNI_FUNCTION(X) Java_com_paris8_univ_androidproject_engine_SkyBox_X
extern "C"
{
    JNI_RETURN(Engine::ObjectHandler) JNI_FUNCTION(newSkyBox)(JNIEnv *env, jobject thiz, Engine::ObjectHandler shaderProgramHandler);
    //JNI_RETURN(Engine::ObjectHandler) JNI_FUNCTION(getTexture)(JNIEnv *env)
}

Engine::ObjectHandler JNI_FUNCTION(newSkyBox)(JNIEnv *env, jobject thiz, Engine::ObjectHandler shaderProgramHandler)
{
    Engine::ShaderProgram *shaderProgram = Engine::Object::retrieveObject<Engine::ShaderProgram>(shaderProgramHandler);
    Engine::Object *object = new Engine::SkyBox(std::shared_ptr<Engine::ShaderProgram>(shaderProgram, Engine::null_deleter));

    ALOGD("New SkyBox (Handler=%lld)", object->getHandler());
    return object->getHandler();
}