package com.paris8.univ.androidproject.engine.texture;

import com.paris8.univ.androidproject.engine.EngineObject;

/**
 * Created by Mzartek on 27/10/15.
 */
public class Texture2D extends Texture
{
    private static native long createTexture2D();

    private static native void loadFromFile(long objectHandler, String file);

    public Texture2D(long objectHandler)
    {
        super(createTexture2D());
    }

    public void loadFromFile(String file)
    {
        loadFromFile(this.getObjectHandler(), file);
    }

}
