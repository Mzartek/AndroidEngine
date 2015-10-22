//
// Created by mzartek on 22/10/15.
//

#include "AssetTool.h"

Engine::Tools::AssetRessource Engine::Tools::openAsset(JNIEnv *env,
                                                       jobject assetManager,
                                                       const char *assetPath)
{
    AssetRessource assetRessource;
    AAssetManager* mgr = AAssetManager_fromJava(env, assetManager);
    assetRessource.asset = AAssetManager_open(mgr, assetPath, AASSET_MODE_UNKNOWN);
    if (assetRessource.asset == nullptr)
    {
        ALOGE("Asset not found: %s", assetPath);
        throw std::exception();
    }
    assetRessource.size = AAsset_getLength(assetRessource.asset);
    assetRessource.buffer = (char *)malloc(assetRessource.size);
    AAsset_read (assetRessource.asset,
            assetRessource.buffer,
            assetRessource.size);

    return assetRessource;
}

void Engine::Tools::closeAsset(AssetRessource assetRessource)
{
    AAsset_close(assetRessource.asset);
}