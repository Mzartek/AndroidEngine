//
// Created by mzartek on 22/09/15.
//

#include "GraphicsRenderer.h"

#define LOG_TAG "GraphicsRenderer"

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
    ALOGD(LOG_TAG, "Version:    \"%s\"", glGetString(GL_VERSION)   );
    ALOGD(LOG_TAG, "Vendor:     \"%s\"", glGetString(GL_VENDOR)    );
    ALOGD(LOG_TAG, "Renderer:   \"%s\"", glGetString(GL_RENDERER)  );
    ALOGD(LOG_TAG, "Extensions: \"%s\"", glGetString(GL_EXTENSIONS));
}

extern "C"
{
    JNIEXPORT void JNICALL Java_com_paris8_univ_androidproject_engine_GraphicsRenderer_printGLinfo(JNIEnv *env, jobject thiz);
};

void Java_com_paris8_univ_androidproject_engine_GraphicsRenderer_printGLinfo(JNIEnv *env, jobject thiz)
{
	Engine::GraphicsRenderer::Instance().printGLinfo();
}
