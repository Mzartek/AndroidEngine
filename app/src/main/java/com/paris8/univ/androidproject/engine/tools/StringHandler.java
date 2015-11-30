package com.paris8.univ.androidproject.engine.tools;

import android.util.Log;

import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;

public class StringHandler
{
    private static final String TAG = "StringHandler";

    public static String readFromInputStream(InputStream inputStream)
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
}
