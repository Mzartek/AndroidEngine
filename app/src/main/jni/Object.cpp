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

#define JNI_FUNCTION(X) Java_com_paris8_univ_androidproject_engine_EngineObject_X
extern "C"
{
    JNI_RETURN(void) JNI_FUNCTION(deleteObject)(JNIEnv *env, jobject thiz, Engine::ObjectHandler objectHandler);
}

void JNI_FUNCTION(deleteObject)(JNIEnv *env, jobject thiz, Engine::ObjectHandler objectHandler)
{
    ALOGD("Delete Object (Handler=%lld)", objectHandler);
    delete Engine::Object::retrieveObject<Engine::Object>(objectHandler);
}