package com.paris8.univ.androidproject.engine;

import android.util.Log;

import com.paris8.univ.androidproject.engine.camera.PerspCamera;

/**
 * Created by khavranek on 30/09/15.
 */
public class SkyBox extends EngineObject
{
    private static native long newSkyBox(long shaderProgram);
    private static native void load(long objectHandler,
                                    String posx, String negx,
                                    String posy, String negy,
                                    String posz, String negz);
    private static native void display(long objectHandler, long cameraObjectHandler);

    public SkyBox(ShaderProgram shaderProgram)
    {
        super(newSkyBox(shaderProgram.getObjectHandler()));
    }

    public void load(String posx, String negx,
                     String posy, String negy,
                     String posz, String negz)
    {
        this.load(this.getObjectHandler(),
                posx, negx,
                posy, negy,
                posz, negz);
    }

    public void display(PerspCamera camera)
    {
        display(this.getObjectHandler(), camera.getObjectHandler());
    }
}
