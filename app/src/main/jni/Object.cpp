//
// Created by mzartek on 22/09/15.
//

#include "Object.h"

std::map<Engine::ObjectHandler, Engine::Object *> Engine::Object::objectsHandler;

Engine::ObjectHandler Engine::Object::GenerateHandler(void)
{
    static ObjectHandler objectHandler = 1;

    while (objectsHandler.find(objectHandler) != objectsHandler.end())
    {
        objectHandler++;
    }

    return objectHandler++;
}

Engine::Object::Object(void)
        : _handler(GenerateHandler())
{
    objectsHandler[_handler] = this;
}

Engine::Object::~Object(void)
{
    objectsHandler.erase(_handler);
}

Engine::ObjectHandler Engine::Object::getHandler(void)
{
    return _handler;
}

extern "C"
{
    JNIEXPORT void JNICALL Java_com_paris8_univ_androidproject_engine_EngineObject_DeleteObject(JNIEnv *env, jobject thiz, jint objectHandler);
}

void Java_com_paris8_univ_androidproject_engine_EngineObject_DeleteObject(JNIEnv *env, jobject thiz, jint objectHandler)
{
    ALOGD("Delete Object (Handler=%d)", objectHandler);
    delete Engine::Object::retrieveObject<Engine::Object>(objectHandler);
}