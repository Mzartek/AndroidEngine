package com.paris8.univ.androidproject.engine;

/**
 * Created by khavranek on 30/09/15.
 */
public class SkyBox extends EngineObject
{
    private static native long newSkyBox(long shaderProgram);

    public SkyBox(ShaderProgram shaderProgram)
    {
        super(newSkyBox(shaderProgram.getObjectHandler()));
    }
}
