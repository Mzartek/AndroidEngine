package com.paris8.univ.androidproject.engine;

import android.content.Context;
import android.content.res.AssetManager;
import android.opengl.GLES20;
import android.opengl.GLSurfaceView;
import android.util.Log;

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

    public EngineView(Context context, AssetManager assetManager)
    {
        super(context);
        setEGLConfigChooser(8, 8, 8, 0, 24, 8);
        setEGLContextClientVersion(2);
        setRenderer(new Renderer(assetManager));
    }

    private class Renderer implements GLSurfaceView.Renderer
    {
        private static final String TAG = "Renderer";

        private AssetManager assetManager;

        private int mWidth = 0;
        private int mHeight = 0;

        private PerspCamera camera;

        private ShaderProgram skyboxProgram;

        private SkyBox skyBox;

        public Renderer(AssetManager assetManager)
        {
            this.assetManager = assetManager;
        }

        @Override
        public void onSurfaceCreated(GL10 gl, EGLConfig config)
        {
            GraphicsRenderer.printGLinfo();

            camera = new PerspCamera();
            camera.setPositionAndTarget(10, 10, 10, 0, 0, 0);

            try
            {
                skyboxProgram = new ShaderProgram(
                        assetManager.open("Shaders/SkyBox/skybox_vs.glsl"),
                        assetManager.open("Shaders/SkyBox/skybox_fs.glsl"));
            }
            catch (Exception ex)
            {
                Log.e(TAG, ex.toString());
            }

            skyBox = new SkyBox(skyboxProgram);
            /*skyBox.load(
                    "Textures/BlueSky/bluesky_back.jpg", "Textures/BlueSky/bluesky_back.jpg",
                    "Textures/BlueSky/bluesky_back.jpg", "Textures/BlueSky/bluesky_back.jpg",
                    "Textures/BlueSky/bluesky_back.jpg", "Textures/BlueSky/bluesky_back.jpg");*/
        }

        @Override
        public void onSurfaceChanged(GL10 gl, int width, int height)
        {
            mWidth = width;
            mHeight = height;
            GraphicsRenderer.setSize(mWidth, mHeight);
        }

        @Override
        public void onDrawFrame(GL10 gl)
        {
            GraphicsRenderer.clear();

            camera.updateData();
        }
    }
}
