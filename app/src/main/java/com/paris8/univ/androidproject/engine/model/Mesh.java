package com.paris8.univ.androidproject.engine.model;

import com.paris8.univ.androidproject.engine.EngineObject;

/**
 * Created by Mzartek on 27/10/15.
 */
public abstract class Mesh extends EngineObject
{
    private static native void setMaterial(long objectHandler, long materialHandler);

    private static native void display(long objectHandler);

    public Mesh(long objectHandler)
    {
        super(objectHandler);
    }

    public void setMaterial(Material material)
    {
        setMaterial(this.getObjectHandler(), material.getObjectHandler());
    }

    public void display()
    {
        display(this.getObjectHandler());
    }
}
