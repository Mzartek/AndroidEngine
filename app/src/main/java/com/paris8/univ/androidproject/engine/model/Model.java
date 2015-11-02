package com.paris8.univ.androidproject.engine.model;

import com.paris8.univ.androidproject.engine.EngineObject;
import com.paris8.univ.androidproject.engine.camera.PerspCamera;

/**
 * Created by Mzartek on 02/11/15.
 */
public abstract class Model extends EngineObject
{
    private static native void addMesh(long objectHandler, long meshHandler);

    private static native void setPosition(long objectHandler, float x, float y, float z);
    private static native void setScale(long objectHandler, float x, float y, float z);
    private static native void setRotation1(long objectHandler, float x, float y, float z);
    private static native void setRotation2(long objectHandler, float x, float y, float z, float angle);

    private static native void addPosition(long objectHandler, float x, float y, float z);
    private static native void addScale(long objectHandler, float x, float y, float z);
    private static native void addRotation1(long objectHandler, float x, float y, float z);
    private static native void addRotation2(long objectHandler, float x, float y, float z, float angle);

    public Model(long objectHandler)
    {
        super(objectHandler);
    }

    public void addMesh(Mesh mesh)
    {
        addMesh(this.getObjectHandler(), mesh.getObjectHandler());
    }

    public void setPosition(float x, float y, float z)
    {
        setPosition(this.getObjectHandler(), x, y, z);
    }

    public void setScale(float x, float y, float z)
    {
        setScale(this.getObjectHandler(), x, y, z);
    }

    public void setRotation(float x, float y, float z)
    {
        setRotation1(this.getObjectHandler(), x, y, z);
    }

    public void setRotation(float x, float y, float z, float angle)
    {
        setRotation2(this.getObjectHandler(), x, y, z, angle);
    }

    public void addPosition(float x, float y, float z)
    {
        addPosition(this.getObjectHandler(), x, y, z);
    }

    public void addScale(float x, float y, float z)
    {
        addScale(this.getObjectHandler(), x, y, z);
    }

    public void addRotation(float x, float y, float z)
    {
        addRotation1(this.getObjectHandler(), x, y, z);
    }

    public void addRotation(float x, float y, float z, float angle)
    {
        addRotation2(this.getObjectHandler(), x, y, z, angle);
    }

    public abstract void display(PerspCamera perspCamera);
    public abstract void displayTransparent(PerspCamera perspCamera);
}
