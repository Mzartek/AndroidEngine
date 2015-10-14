package com.paris8.univ.androidproject.engine;

import android.content.Context;
import android.opengl.GLSurfaceView;

import com.paris8.univ.androidproject.R;
import com.paris8.univ.androidproject.engine.camera.PerspCamera;

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
        setEGLConfigChooser(8, 8, 8, 0, 24, 8);
        setEGLContextClientVersion(2);
        setRenderer(new Renderer());
    }

    private class Renderer implements GLSurfaceView.Renderer
    {
        private int mWidth = 0;
        private int mHeight = 0;

        private ShaderProgram skyboxProgram;

        private PerspCamera camera;

        @Override
        public void onSurfaceCreated(GL10 gl, EGLConfig config)
        {
            GraphicsRenderer.printGLinfo();

            skyboxProgram = new ShaderProgram(getResources().openRawResource(R.raw.skybox_vs), getResources().openRawResource(R.raw.skybox_fs));

            camera = new PerspCamera();
        }

        @Override
        public void onSurfaceChanged(GL10 gl, int width, int height)
        {
            mWidth = width;
            mHeight = height;
            GraphicsRenderer.setSize(mWidth, mHeight);

            camera.setPositionAndTarget(10, 10, 10, 0, 0, 0);
            camera.updateData();
        }

        @Override
        public void onDrawFrame(GL10 gl)
        {
            GraphicsRenderer.clear();
        }
    }
}
