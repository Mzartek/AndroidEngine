//
// Created by mzartek on 22/09/15.
//

#ifndef ANDROIDPROJECT_OBJECT_H
#define ANDROIDPROJECT_OBJECT_H

#include <map>
#include <vector>
#include <string>
#include <fstream>
#include <memory>

#include <jni.h>

#include <android/log.h>

#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>

#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/matrix.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/matrix_access.hpp>
#include <glm/gtc/matrix_inverse.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/gtc/type_ptr.hpp>

#define BUFFER_OFFSET(i) ((GLbyte *)NULL + (i))

#define JNI_RETURN(TYPE) JNIEXPORT TYPE JNICALL

#define ALOGD(...) __android_log_print(ANDROID_LOG_DEBUG, __FILE__, __VA_ARGS__)
#define ALOGE(...) __android_log_print(ANDROID_LOG_ERROR, __FILE__, __VA_ARGS__)
#define ALOGI(...) __android_log_print(ANDROID_LOG_INFO , __FILE__, __VA_ARGS__)

namespace Engine
{
    typedef long long int ObjectHandler;

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

    void null_deleter(Object *obj);
}

#endif //ANDROIDPROJECT_OBJECT_H
