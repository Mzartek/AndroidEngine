//
// Created by mzartek on 22/09/15.
//

#include "Object.h"

Engine::Object::Object(void)
{
}

Engine::Object::~Object(void)
{
}

Engine::ObjectHandler Engine::Object::getHandler(void)
{
    return reinterpret_cast<long long>(this);
}

void Engine::null_deleter(Object *obj) { }

extern "C"
{
    JNI_RETURN(void) Java_com_paris8_univ_androidproject_engine_EngineObject_DeleteObject(JNIEnv *env, jobject thiz, jlong objectHandler);
}

void Java_com_paris8_univ_androidproject_engine_EngineObject_DeleteObject(JNIEnv *env, jobject thiz, jlong objectHandler)
{
    ALOGD("Delete Object (Handler=%lld)", objectHandler);
    delete Engine::Object::retrieveObject<Engine::Object>(objectHandler);
}

/*#include <assimp/Importer.hpp>
#include <assimp/postprocess.h>
void testtest(void)
{
    Assimp::Importer importer;
    const aiScene *pScene = importer.ReadFile("test", aiProcess_Triangulate);
}*/