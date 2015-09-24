//
// Created by mzartek on 22/09/15.
//

#ifndef ANDROIDPROJECT_OBJECT_H
#define ANDROIDPROJECT_OBJECT_H

#include <map>
#include <string>
#include <fstream>

#include <jni.h>

#include <android/log.h>

#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>

#define ALOGD(...) __android_log_print(ANDROID_LOG_DEBUG, __FILE__, __VA_ARGS__)
#define ALOGE(...) __android_log_print(ANDROID_LOG_ERROR, __FILE__, __VA_ARGS__)
#define ALOGI(...) __android_log_print(ANDROID_LOG_INFO , __FILE__, __VA_ARGS__)

namespace Engine
{
    typedef long long ObjectHandler;

    class Object
    {
    public:
        template<typename T>
        static T* retrieveObject(ObjectHandler objectHandler)
        {
            return reinterpret_cast<T*>(objectHandler);
        }

    public:
        Object(void);
        virtual ~Object(void);

        ObjectHandler getHandler(void);
    };
}

#endif //ANDROIDPROJECT_OBJECT_H
