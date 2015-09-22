//
// Created by mzartek on 22/09/15.
//

#ifndef ANDROIDPROJECT_OBJECT_H
#define ANDROIDPROJECT_OBJECT_H

#include <map>
#include <string>

#include <jni.h>

#include <android/log.h>

#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>

#define ALOGD(LOG_TAG, ...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#define ALOGE(LOG_TAG, ...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)
#define ALOGI(LOG_TAG, ...) __android_log_print(ANDROID_LOG_INFO , LOG_TAG, __VA_ARGS__)

namespace Engine
{
    typedef unsigned int ObjectHandler;

    class Object
    {
    public:
        static std::map<ObjectHandler, const Object *> objectsHandler;

    private:
        static ObjectHandler GenerateHandler(void);
        ObjectHandler _handler;

    public:
        Object(void);
        virtual ~Object(void);

        ObjectHandler getHandler(void);
    };
}

#endif //ANDROIDPROJECT_OBJECT_H
