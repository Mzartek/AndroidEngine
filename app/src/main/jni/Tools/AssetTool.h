//
// Created by mzartek on 22/10/15.
//

#ifndef ANDROIDPROJECT_ASSETTOOL_H
#define ANDROIDPROJECT_ASSETTOOL_H

#include "../Object.h"

#include <android/asset_manager_jni.h>

namespace Engine
{
    namespace Tools
    {	
	extern JNIEnv *jniEnv;
    	extern jobject jniAssetManager;

        struct AssetRessource
        {
            AAsset *asset;
            long size;
            char *buffer;
        };

        AssetRessource openAsset(const char *asset);
        void closeAsset(AssetRessource assetRessource);
    }
}

#endif //ANDROIDPROJECT_ASSETTOOL_H
