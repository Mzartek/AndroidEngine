package com.paris8.univ.androidproject.game;

import android.app.Activity;
import android.os.Bundle;

public class GameActivity extends Activity
{
    final static private String TAG = "GameActivity";

    static public int mSelectedLevel = 0;

    GameView mView;

    @Override
    protected void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);

        mView = new GameView(getApplication(), getAssets(), mSelectedLevel);
        setContentView(mView);
    }

    @Override
    protected void onPause()
    {
        super.onPause();
        mView.onPause();
    }

    @Override
    protected void onResume()
    {
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
