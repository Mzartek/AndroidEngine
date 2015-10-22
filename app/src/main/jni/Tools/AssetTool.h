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
        struct AssetRessource
        {
            AAsset *asset;
            long size;
            char *buffer;
        };

        AssetRessource openAsset(JNIEnv *env, jobject assetManager, const char *asset);
        void closeAsset(AssetRessource assetRessource);
    }
}

#endif //ANDROIDPROJECT_ASSETTOOL_H
