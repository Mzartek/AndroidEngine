LOCAL_PATH              := $(call my-dir)
LOCAL_LIB_PATH          := $(LOCAL_PATH)/externals/lib
LOCAL_INCLUDE_PATH      := $(LOCAL_PATH)/externals/include

#include $(CLEAR_VARS)
#LOCAL_MODULE            := assimpStaticLib
#LOCAL_SRC_FILES         := /home/mzartek/Programmation/AndroidProject/app/src/main/jni/externals/lib/libassimp.a
#include $(PREBUILT_STATIC_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE            := engine-jni
LOCAL_SRC_FILES         := Object.cpp GraphicsRenderer.cpp ShaderProgram.cpp Tools/StringHandler.cpp
#LOCAL_C_INCLUDES        := $(LOCAL_INCLUDE_PATH)
LOCAL_CFLAGS            := -std=c++11 -Wall
LOCAL_LDLIBS            := -llog -lGLESv2
#LOCAL_STATIC_LIBRARIES  := assimpStaticLib
include $(BUILD_SHARED_LIBRARY)
