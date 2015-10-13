LOCAL_PATH              := $(call my-dir)
EXTERNALS_INCLUDE       := externals/include
EXTERNALS_LIB           := externals/lib

include $(CLEAR_VARS)
LOCAL_MODULE            := libSDL2
LOCAL_SRC_FILES         := $(EXTERNALS_LIB)/$(TARGET_ARCH_ABI)/libSDL2.so
include $(PREBUILT_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE            := libSDL2_image
LOCAL_SRC_FILES         := $(EXTERNALS_LIB)/$(TARGET_ARCH_ABI)/libSDL2_image.so
include $(PREBUILT_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE            := libassimp
LOCAL_SRC_FILES         := $(EXTERNALS_LIB)/$(TARGET_ARCH_ABI)/libassimp.so
include $(PREBUILT_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE            := engine-jni
LOCAL_SRC_FILES         := Object.cpp GraphicsRenderer.cpp Buffer.cpp ShaderProgram.cpp SkyBox.cpp Camera/Camera.cpp Camera/OrthoCamera.cpp Camera/PerspCamera.cpp Model/Model.cpp Model/Material.cpp Model/Mesh.cpp Model/Static/StaticMesh.cpp Texture/Texture.cpp Texture/Texture2D.cpp Texture/TextureCube.cpp Tools/StringHandler.cpp
LOCAL_C_INCLUDES        := $(LOCAL_PATH)/$(EXTERNALS_INCLUDE)
LOCAL_CFLAGS            := -std=c++11 -Wall -Wno-attributes -fexceptions
LOCAL_LDLIBS            := -llog -lGLESv2
LOCAL_SHARED_LIBRARIES  := libSDL2 libSDL2_image libassimp
include $(BUILD_SHARED_LIBRARY)
