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
     JNI_RETURN(void)
     Java_com_paris8_univ_androidproject_engine_EngineObject_deleteObject(JNIEnv *env, jobject thiz, Engine::ObjectHandler objectHandler)
     {
	  ALOGD("Delete Object (Handler=%lld)", objectHandler);
	  delete Engine::Object::retrieveObject<Engine::Object>(objectHandler);
     }
}
