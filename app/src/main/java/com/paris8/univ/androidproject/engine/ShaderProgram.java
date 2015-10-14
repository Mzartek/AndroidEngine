package com.paris8.univ.androidproject.engine;

import android.util.Log;

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

    private static String readFromInputStream(InputStream inputStream)
    {
        BufferedReader reader = new BufferedReader(new InputStreamReader(inputStream));
        StringBuilder result = new StringBuilder();
        String line;
        try
        {
            while ((line = reader.readLine()) != null)
            {
                result.append(line);
            }
        }
        catch (Exception ex)
        {
            Log.e(TAG, ex.toString());
        }

        return result.toString();
    }

    public ShaderProgram(InputStream vs, InputStream fs)
    {
        super(newShaderProgram(readFromInputStream(vs), readFromInputStream(fs)));
    }
}
