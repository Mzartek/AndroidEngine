package com.paris8.univ.androidproject.engine;

import android.content.res.AssetManager;

public class EngineObject extends Object
{
    private static native void deleteObject(long objectHandler);

    private long objectHandler;

    public EngineObject(long objectHandler)
    {
        this.objectHandler = objectHandler;
    }

    public void deleteObject()
    {
        this.deleteObject(objectHandler);
    }

    public long getObjectHandler()
    {
        return objectHandler;
    }
}
