package com.paris8.univ.androidproject;

import android.app.Activity;
import android.opengl.GLSurfaceView;
import android.os.Bundle;

import com.paris8.univ.androidproject.engine.EngineView;

import java.io.File;

public class GameActivity extends Activity
{
    final static private String TAG = "GameActivity";

    GLSurfaceView mView;

    @Override
    protected void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);

        mView = new EngineView(getApplication(), getAssets());
        setContentView(mView);
    }

    @Override
    protected void onPause()
    {
        super.onPause();
        mView.onPause();
    }

    @Override
    protected void onResume() {
        super.onResume();
        mView.onResume();
    }

    static
    {
        // Warning! The order of the load is important
        System.loadLibrary("SDL2");
        System.loadLibrary("SDL2_image");
        System.loadLibrary("assimp");
        System.loadLibrary("engine-jni");
    }
}
