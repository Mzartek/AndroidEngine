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
     : _width(0), _height(0)
{
}

Engine::GraphicsRenderer::~GraphicsRenderer(void)
{
}

void Engine::GraphicsRenderer::printGLinfo(void)
{
     ALOGD("Version:    \"%s\"", glGetString(GL_VERSION)                 );
     ALOGD("Shader:     \"%s\"", glGetString(GL_SHADING_LANGUAGE_VERSION));
     ALOGD("Vendor:     \"%s\"", glGetString(GL_VENDOR)                  );
     ALOGD("Renderer:   \"%s\"", glGetString(GL_RENDERER)                );
     ALOGD("Extensions: \"%s\"", glGetString(GL_EXTENSIONS)              );
}

void Engine::GraphicsRenderer::setSize(GLuint width, GLuint height)
{
     _width = width;
     _height = height;
}

void Engine::GraphicsRenderer::setSkyboxState() const
{
     glBindFramebuffer(GL_FRAMEBUFFER, 0);

     glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);

     glEnable(GL_DEPTH_TEST);
     glDepthFunc(GL_LESS);
     glDepthMask(GL_FALSE);

     glDisable(GL_STENCIL_TEST);

     glDisable(GL_BLEND);

     glDisable(GL_CULL_FACE);

     glViewport(0, 0, _width, _height);
     glDepthRangef(0.0f, 1.0f);
}

void Engine::GraphicsRenderer::setGeometryState(void) const
{
     glBindFramebuffer(GL_FRAMEBUFFER, 0);

     glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);

     glEnable(GL_DEPTH_TEST);
     glDepthFunc(GL_LESS);
     glDepthMask(GL_TRUE);

     glEnable(GL_STENCIL_TEST);
     glStencilMask(0xFF);
     glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);
     glStencilFunc(GL_ALWAYS, 1, 0xFF);

     glEnable(GL_BLEND);
     glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
     glBlendEquation(GL_FUNC_ADD);

     glDisable(GL_CULL_FACE);

     glViewport(0, 0, _width, _height);
     glDepthRangef(0.0f, 1.0f);
}

bool Engine::GraphicsRenderer::compareColor(const int x, const int y, const glm::vec3 &color)
{
     glBindFramebuffer(GL_FRAMEBUFFER, 0);
     
     GLubyte pixel[3];
     glReadPixels(x, y, 1, 1, GL_RGB, GL_UNSIGNED_BYTE, pixel);
     
     if (pixel[0] == static_cast<GLubyte>(color.x * 255 + 0.5f) &&
	 pixel[1] == static_cast<GLubyte>(color.y * 255 + 0.5f) &&
	 pixel[2] == static_cast<GLubyte>(color.z * 255 + 0.5f))
     {
	  return true;
     }
     
     return false;
}

/*
void gl4dutStream2texSave(void) {
  int i, j, i1 , i2;
  if(!_s2tWriter) return;
  if(_s2tGrabbedFrame <= _s2tSavedFrame) return;
  glPixelStorei(GL_PACK_ALIGNMENT, 1);
  glReadPixels(0, 0, _s2tWimg->width, _s2tWimg->height, GL_BGR, GL_UNSIGNED_BYTE
, _s2tWimg->imageData);
  for(i = 0; i < _s2tWimg->height; i++) {
    i1 = 3 * (_s2tWimg->height - i - 1) * _s2tWimg->width;
    i2 = 3 * i * _s2tWimg->width;
    for(j = 0; j < 3 * _s2tWimg->width; j++)
      _s2tFimg->imageData[i1 + j] = _s2tWimg->imageData[i2 + j];
  }
*/

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
     JNI_RETURN(void)
     Java_com_paris8_univ_androidproject_engine_GraphicsRenderer_printGLinfo(JNIEnv *env, jobject thiz)
     {
	  Engine::GraphicsRenderer::Instance().printGLinfo();
     }
  
     JNI_RETURN(void)
     Java_com_paris8_univ_androidproject_engine_GraphicsRenderer_setSize(JNIEnv *env, jobject thiz, jint width, jint height)
     {
	  Engine::GraphicsRenderer::Instance().setSize(width, height);
     }

     JNI_RETURN(jboolean)
     Java_com_paris8_univ_androidproject_engine_GraphicsRenderer_compareColor(JNIEnv *env, jobject thiz,
									      jint x, jint y,
									      jfloat r, jfloat g, jfloat b)
     {
	  return Engine::GraphicsRenderer::Instance().compareColor(x, y, glm::vec3(r, g, b));
     }
  
     JNI_RETURN(void)
     Java_com_paris8_univ_androidproject_engine_GraphicsRenderer_clear(JNIEnv *env, jobject thiz)
     {
	  Engine::GraphicsRenderer::Instance().clear();
     }
};
