LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := engine-jni
LOCAL_SRC_FILES := Object.cpp GraphicsRenderer.cpp
LOCAL_CFLAGS    := -std=c++11 -Wall
LOCAL_LDLIBS    := -llog -lGLESv2

include $(BUILD_SHARED_LIBRARY)
