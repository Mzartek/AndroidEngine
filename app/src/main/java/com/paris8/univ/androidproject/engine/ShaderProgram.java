package com.paris8.univ.androidproject.engine;

import android.util.Log;

import com.paris8.univ.androidproject.engine.tools.StringHandler;

import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;

/**
 * Created by mzartek on 24/09/15.
 */
public class ShaderProgram extends EngineObject
{
    private static final String TAG = "ShaderProgram";

    private static native long newShaderProgram(String vs, String fs);

    public ShaderProgram(InputStream vs, InputStream fs)
    {
        super(newShaderProgram(
                StringHandler.readFromInputStream(vs),
                StringHandler.readFromInputStream(fs)));
    }
}
