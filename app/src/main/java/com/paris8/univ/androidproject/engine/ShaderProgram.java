package com.paris8.univ.androidproject.engine;

import android.content.res.AssetManager;
import android.util.Log;

import com.paris8.univ.androidproject.engine.tools.StringHandler;

import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;

public class ShaderProgram extends EngineObject
{
    private static final String TAG = "ShaderProgram";

    private static native long newShaderProgram(AssetManager assetManager, String vs, String fs);

    public ShaderProgram(AssetManager assetManager, String vs, String fs)
    {
        super(newShaderProgram(assetManager, vs, fs));
    }
}
