//
// Created by mzartek on 22/09/15.
//

#include "GraphicsRenderer.h"

#include <cstdlib>

Engine::GraphicsRenderer& Engine::GraphicsRenderer::Instance(void)
{
    static GraphicsRenderer instance;
    return instance;
}

Engine::GraphicsRenderer::GraphicsRenderer(void)
{
}

Engine::GraphicsRenderer::~GraphicsRenderer(void)
{
}

void Engine::GraphicsRenderer::printGLinfo(void)
{
    ALOGD("Version:    \"%s\"", glGetString(GL_VERSION)   );
    ALOGD("Vendor:     \"%s\"", glGetString(GL_VENDOR)    );
    ALOGD("Renderer:   \"%s\"", glGetString(GL_RENDERER)  );
    ALOGD("Extensions: \"%s\"", glGetString(GL_EXTENSIONS));
}

void Engine::GraphicsRenderer::setState(GLuint width, GLuint height) const
{
	glBindFramebuffer(GL_FRAMEBUFFER, 0);

	glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	glDepthMask(GL_FALSE);

	glDisable(GL_STENCIL_TEST);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glBlendEquation(GL_FUNC_ADD);

	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glFrontFace(GL_CCW);

	glViewport(0, 0, width, height);
	glDepthRangef(0.0f, 1.0f);
}

void Engine::GraphicsRenderer::clear(void) const
{
	glBindFramebuffer(GL_FRAMEBUFFER, 0);

	glClearColor(0.0, 0.0, 1.0, 0.0);
	glClearDepthf(1.0f);
	glClearStencil(0);

	glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);
	glDepthMask(GL_TRUE);
	glStencilMask(0xFF);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
}

extern "C"
{
    JNIEXPORT void JNICALL Java_com_paris8_univ_androidproject_engine_GraphicsRenderer_printGLinfo(JNIEnv *env, jobject thiz);
    JNIEXPORT void JNICALL Java_com_paris8_univ_androidproject_engine_GraphicsRenderer_setState(JNIEnv *env, jobject thiz, jint width, jint height);
    JNIEXPORT void JNICALL Java_com_paris8_univ_androidproject_engine_GraphicsRenderer_clear(JNIEnv *env, jobject thiz);
};

void Java_com_paris8_univ_androidproject_engine_GraphicsRenderer_printGLinfo(JNIEnv *env, jobject thiz)
{
	Engine::GraphicsRenderer::Instance().printGLinfo();
}

void Java_com_paris8_univ_androidproject_engine_GraphicsRenderer_setState(JNIEnv *env, jobject thiz, jint width, jint height)
{
    Engine::GraphicsRenderer::Instance().setState(width, height);
}

void Java_com_paris8_univ_androidproject_engine_GraphicsRenderer_clear(JNIEnv *env, jobject thiz)
{
    Engine::GraphicsRenderer::Instance().clear();
}