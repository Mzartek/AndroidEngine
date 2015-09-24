package com.paris8.univ.androidproject.engine;

/**
 * Created by mzartek on 24/09/15.
 */
public class ShaderProgram extends EngineObject
{
    private static native long newShaderProgram(String vs, String fs);

    public ShaderProgram(String vs, String fs)
    {
        super(newShaderProgram(vs, fs));
    }
}
