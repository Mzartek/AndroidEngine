package com.paris8.univ.androidproject.engine.texture;

import android.content.res.AssetManager;

import com.paris8.univ.androidproject.engine.EngineObject;

public class Texture2D extends Texture
{
    private static native long createTexture2D();

    private static native void loadFromAsset(long objectHandler, AssetManager assetManager, String asset);

    public Texture2D()
    {
        super(createTexture2D());
    }

    public void loadFromAsset(AssetManager assetManager, String asset)
    {
        loadFromAsset(this.getObjectHandler(), assetManager, asset);
    }

}
