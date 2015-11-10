package com.paris8.univ.androidproject.game;

import android.content.Context;
import android.content.res.AssetManager;
import android.opengl.GLSurfaceView;
import android.util.Log;
import android.view.DragEvent;
import android.view.MotionEvent;
import android.view.View;

import com.paris8.univ.androidproject.engine.GraphicsRenderer;
import com.paris8.univ.androidproject.engine.camera.PerspCamera;
import com.paris8.univ.androidproject.game.piece.Form1;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

/**
 * Created by mzartek on 22/09/15.
 */
public class GameView extends GLSurfaceView
{
    final static private String TAG = "GameView";

    private AssetManager mAssetManager;
    private Renderer mRenderer;
    private boolean mSurfaceCreated = false;

    private PerspCamera mCamera;

    private MySkyBox mySkyBox;
    private Level mLevel;

    private boolean selectEvent = false;
    private int[] selectEventPosition = new int[] { 0,  0 };

    public GameView(Context context, AssetManager assetManager)
    {
        super(context);

        mAssetManager = assetManager;
        mRenderer = new Renderer();

        setEGLConfigChooser(8, 8, 8, 0, 24, 8);
        setEGLContextClientVersion(2);
        setRenderer(mRenderer);

        setOnTouchListener(new TouchListener());
        setOnDragListener(new DragListener());
    }

    private class Renderer implements GLSurfaceView.Renderer
    {
        private int mWidth = 0;
        private int mHeight = 0;

        @Override
        public void onSurfaceCreated(GL10 gl, EGLConfig config)
        {
            GraphicsRenderer.printGLinfo();

            mCamera = new PerspCamera();
            mCamera.setPositionAndTarget(20, 20, 0, 0, 0, 0);

            mySkyBox = new MySkyBox(mAssetManager);
            mLevel = new Level();

            mLevel.addForm(new Form1(mAssetManager, 0.10f, 0.75f, 0.25f, 0, 0, 0, 0, 0, 0, 0, 0));

            mSurfaceCreated = true;
        }

        @Override
        public void onSurfaceChanged(GL10 gl, int width, int height)
        {
            mWidth = width;
            mHeight = height;
            GraphicsRenderer.setSize(mWidth, mHeight);

            mCamera.setPerspective(90, width, height, 0.1f, 100.0f);
        }

        @Override
        public void onDrawFrame(GL10 gl)
        {
            if (selectEvent)
            {
                mLevel.selectForm(selectEventPosition[0], selectEventPosition[1]);
                selectEvent = false;
            }

            GraphicsRenderer.clear();

            mCamera.updateData();

            mySkyBox.display(mCamera);
            mLevel.display(mCamera);
        }
    }

    public class TouchListener implements OnTouchListener
    {
        @Override
        public boolean onTouch(View v, MotionEvent event)
        {
            if (mSurfaceCreated)
            {
                if (event.getAction() == MotionEvent.ACTION_DOWN)
                {
                    selectEvent = true;
                    selectEventPosition[0] = (int)event.getX();
                    selectEventPosition[1] = (int)event.getY();
                }
            }

            return true;
        }
    }

    public class DragListener implements OnDragListener
    {
        @Override
        public boolean onDrag(View v, DragEvent event)
        {
            return true;
        }
    }
}
