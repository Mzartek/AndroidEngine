package com.paris8.univ.androidproject.engine;

import android.content.Context;
import android.opengl.GLSurfaceView;
import android.util.Log;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

/**
 * Created by mzartek on 22/09/15.
 */
public class EngineView extends GLSurfaceView
{
    final static private String TAG = "EngineView";

    public EngineView(Context context)
    {
        super(context);
        setEGLConfigChooser(8, 8, 8, 0, 16, 0);
        setEGLContextClientVersion(2);
        setRenderer(new Renderer());
    }

    private class Renderer implements GLSurfaceView.Renderer
    {
        @Override
        public void onSurfaceCreated(GL10 gl, EGLConfig config)
        {
            Log.d(TAG, "Surface Created");
            GraphicsRenderer.printGLinfo();
        }

        @Override
        public void onSurfaceChanged(GL10 gl, int width, int height)
        {
        }

        @Override
        public void onDrawFrame(GL10 gl)
        {
        }
    }
}
