package com.paris8.univ.androidproject.game;

import android.app.Activity;
import android.opengl.GLSurfaceView;
import android.os.Bundle;
import android.view.MotionEvent;

public class GameActivity extends Activity
{
    final static private String TAG = "GameActivity";

    GameView mView;

    @Override
    protected void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);

        mView = new GameView(getApplication(), getAssets());
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

    @Override
    public boolean onTouchEvent (MotionEvent event)
    {
        super.onTouchEvent(event);

        mView.touchEvent = true;
        mView.touchPosition[0] = event.getX();
        mView.touchPosition[1] = event.getY();

        return true;
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
