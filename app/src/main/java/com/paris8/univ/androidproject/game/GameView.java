package com.paris8.univ.androidproject.game;

import android.content.Context;
import android.content.res.AssetManager;
import android.opengl.GLSurfaceView;
import android.util.Log;

import com.paris8.univ.androidproject.engine.GraphicsRenderer;
import com.paris8.univ.androidproject.engine.ShaderProgram;
import com.paris8.univ.androidproject.engine.SkyBox;
import com.paris8.univ.androidproject.engine.camera.PerspCamera;
import com.paris8.univ.androidproject.game.piece.Form1;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

/**
 * Created by mzartek on 22/09/15.
 */
public class GameView extends GLSurfaceView
{
    final static private String TAG = "EngineView";

    public GameView(Context context, AssetManager assetManager)
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

        private float tmp = 0.0f;

        private PerspCamera camera;

        private MySkyBox mySkyBox;
        private Form1 form1;

        public Renderer(AssetManager assetManager)
        {
            this.assetManager = assetManager;
        }

        @Override
        public void onSurfaceCreated(GL10 gl, EGLConfig config)
        {
            GraphicsRenderer.printGLinfo();

            camera = new PerspCamera();
            camera.setPositionAndTarget(20, 20, 0, 0, 0, 0);

            mySkyBox = new MySkyBox(this.assetManager);

            form1 = new Form1(this.assetManager,
                    0, 255, 0,
                    0, 0, 0, 0, 0, 0,
                    0, 0);
        }

        @Override
        public void onSurfaceChanged(GL10 gl, int width, int height)
        {
            mWidth = width;
            mHeight = height;
            GraphicsRenderer.setSize(mWidth, mHeight);

            camera.setPerspective(90, width, height, 0.1f, 100.0f);
        }

        @Override
        public void onDrawFrame(GL10 gl)
        {
            GraphicsRenderer.clear();

            camera.updateData();

            mySkyBox.display(camera);

            form1.display(camera);
            form1.addRot();
        }
    }
}
