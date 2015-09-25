//
// Created by mzartek on 24/09/15.
//

#include "ShaderProgram.h"

#include "Tools/StringHandler.h"

inline GLuint loadShader(const GLchar *filename, const GLenum &type)
{
    GLuint id;
    GLchar *content, *log;
    GLsizei logsize;
    GLint status;

    id = glCreateShader(type);
    if (id == 0)
    {
        throw std::runtime_error("Error while creating shader");
    }

    content = Engine::Tools::readText(filename);

    glShaderSource(id, 1, const_cast<const GLchar **>(&content), nullptr);
    glCompileShader(id);
    glGetShaderiv(id, GL_COMPILE_STATUS, &status);
    if (status != GL_TRUE)
    {
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &logsize);

        log = new GLchar[logsize + 1];
        log[logsize] = '\0';

        glGetShaderInfoLog(id, logsize, &logsize, log);
        std::string error("Error while compiling shader: " + std::string(filename) + '\n' + std::string(log));

        glDeleteShader(id);
        delete[] log;
        delete[] content;

        throw std::runtime_error(error);
    }

    delete[] content;
    return id;
}

Engine::ShaderProgram::ShaderProgram(const GLchar *vs, const GLchar *fs)
        : _idProgram(0), _idVertexShader(0), _idFragmentShader(0)
{
    GLchar *log;
    GLsizei logsize;
    GLint status;

    _idProgram = glCreateProgram();
    if (_idProgram == 0)
    {
        throw std::runtime_error("Error while creating program");
    }

    if (vs != nullptr)
    {
        _idVertexShader = loadShader(vs, GL_VERTEX_SHADER);
        glAttachShader(_idProgram, _idVertexShader);
    }

    if (fs != nullptr)
    {
        _idFragmentShader = loadShader(fs, GL_FRAGMENT_SHADER);
        glAttachShader(_idProgram, _idFragmentShader);
    }

    glLinkProgram(_idProgram);

    glGetProgramiv(_idProgram, GL_LINK_STATUS, &status);
    if (status != GL_TRUE)
    {
        glGetProgramiv(_idProgram, GL_INFO_LOG_LENGTH, &logsize);

        log = new GLchar[logsize + 1];
        log[logsize] = '\0';

        glGetProgramInfoLog(_idProgram, logsize, &logsize, log);
        std::string error("Error while linking program: " + std::string(log));

        delete[] log;

        throw std::runtime_error(error);
    }
}

Engine::ShaderProgram::~ShaderProgram(void)
{
    if (glIsProgram(_idProgram)) glDeleteProgram(_idProgram);
    if (glIsShader(_idVertexShader)) glDeleteShader(_idVertexShader);
    if (glIsShader(_idFragmentShader)) glDeleteShader(_idFragmentShader);
}

GLuint Engine::ShaderProgram::getId(void) const
{
    return _idProgram;
}

extern "C"
{
    JNIEXPORT jlong JNICALL Java_com_paris8_univ_androidproject_engine_ShaderProgram_newShaderProgram(JNIEnv *env, jobject thiz, jstring vs, jstring fs);
}

jlong Java_com_paris8_univ_androidproject_engine_ShaderProgram_newShaderProgram(JNIEnv *env, jobject thiz, jstring vs, jstring fs)
{
    const char *VSString = env->GetStringUTFChars(vs, 0);
    const char *FSString = env->GetStringUTFChars(fs, 0);

    Engine::Object *object = new Engine::ShaderProgram(VSString, FSString);

    env->ReleaseStringUTFChars(vs, VSString);
    env->ReleaseStringUTFChars(fs, FSString);

    ALOGD("New ShaderProgram (Handler=%lld)", object->getHandler());
    return object->getHandler();
}