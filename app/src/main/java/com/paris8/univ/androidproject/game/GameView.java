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
import com.paris8.univ.androidproject.game.piece.Form2;
import com.paris8.univ.androidproject.game.piece.Form3;
import com.paris8.univ.androidproject.game.piece.Form4;
import com.paris8.univ.androidproject.game.piece.Form5;

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

    private GameButton upButton;
    private GameButton downButton;
    private GameButton rightButton;
    private GameButton leftButton;
    private GameButton rotateButton;

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

        public int getWidth()
        {
            return mWidth;
        }

        public int getHeight()
        {
            return mHeight;
        }

        @Override
        public void onSurfaceCreated(GL10 gl, EGLConfig config)
        {
            GraphicsRenderer.printGLinfo();

            mCamera = new PerspCamera();
            mCamera.setPositionAndTarget(20, 20, 0, 0, 0, 0);

            mySkyBox = new MySkyBox(mAssetManager);
            mLevel = new Level();

            mLevel.addForm(new Form5(mAssetManager, 0.10f, 0.75f, 0.25f,
                    1.75555555555555555555f, 0,
                    0, 3.75f,
                    66, 137));

            upButton = new GameButton(mAssetManager, "Textures/Control/arrow.jpg",
                    0.2f * 2.0f - 1.0f, 0.22f * 2.0f - 1.0f, 1.0f, 0.0f,
                    0.4f * 2.0f - 1.0f, 0.22f * 2.0f - 1.0f, 1.0f, 1.0f,
                    0.2f * 2.0f - 1.0f, 0.33f * 2.0f - 1.0f, 0.0f, 0.0f,
                    0.4f * 2.0f - 1.0f, 0.33f * 2.0f - 1.0f, 0.0f, 1.0f);

            downButton = new GameButton(mAssetManager, "Textures/Control/arrow.jpg",
                    0.2f * 2.0f - 1.0f, 0.0f * 2.0f - 1.0f, 0.0f, 1.0f,
                    0.4f * 2.0f - 1.0f, 0.0f * 2.0f - 1.0f, 0.0f, 0.0f,
                    0.2f * 2.0f - 1.0f, 0.11f * 2.0f - 1.0f, 1.0f, 1.0f,
                    0.4f * 2.0f - 1.0f, 0.11f * 2.0f - 1.0f, 1.0f, 0.0f);

            leftButton = new GameButton(mAssetManager, "Textures/Control/arrow.jpg",
                    0.0f * 2.0f - 1.0f, 0.11f * 2.0f - 1.0f, 0.0f, 0.0f,
                    0.2f * 2.0f - 1.0f, 0.11f * 2.0f - 1.0f, 1.0f, 0.0f,
                    0.0f * 2.0f - 1.0f, 0.22f * 2.0f - 1.0f, 0.0f, 1.0f,
                    0.2f * 2.0f - 1.0f, 0.22f * 2.0f - 1.0f, 1.0f, 1.0f);

            rightButton = new GameButton(mAssetManager, "Textures/Control/arrow.jpg",
                    0.4f * 2.0f - 1.0f, 0.11f * 2.0f - 1.0f, 1.0f, 1.0f,
                    0.6f * 2.0f - 1.0f, 0.11f * 2.0f - 1.0f, 0.0f, 1.0f,
                    0.4f * 2.0f - 1.0f, 0.22f * 2.0f - 1.0f, 1.0f, 0.0f,
                    0.6f * 2.0f - 1.0f, 0.22f * 2.0f - 1.0f, 0.0f, 0.0f);

            rotateButton = new GameButton(mAssetManager, "Textures/Control/rotate.jpg",
                    0.2f * 2.0f - 1.0f, 0.11f * 2.0f - 1.0f, 0.0f, 0.0f,
                    0.4f * 2.0f - 1.0f, 0.11f * 2.0f - 1.0f, 1.0f, 0.0f,
                    0.2f * 2.0f - 1.0f, 0.22f * 2.0f - 1.0f, 0.0f, 1.0f,
                    0.4f * 2.0f - 1.0f, 0.22f * 2.0f - 1.0f, 1.0f, 1.0f);

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

            if (mLevel.isFormSelected())
            {
                upButton.display(mCamera);
                downButton.display(mCamera);
                leftButton.display(mCamera);
                rightButton.display(mCamera);
                rotateButton.display(mCamera);
            }
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
                    if(mLevel.isFormSelected() &&
                            upButton.isClicked((int)event.getX(), (int)event.getY(), mRenderer.getWidth(), mRenderer.getHeight()))
                    {
                        mLevel.getSelectedForm().remX();
                    }
                    else if(mLevel.isFormSelected() &&
                            downButton.isClicked((int)event.getX(), (int)event.getY(), mRenderer.getWidth(), mRenderer.getHeight()))
                    {
                        mLevel.getSelectedForm().addX();
                    }
                    else if(mLevel.isFormSelected() &&
                            leftButton.isClicked((int)event.getX(), (int)event.getY(), mRenderer.getWidth(), mRenderer.getHeight()))
                    {
                        mLevel.getSelectedForm().addZ();
                    }
                    else if(mLevel.isFormSelected() &&
                            rightButton.isClicked((int)event.getX(), (int)event.getY(), mRenderer.getWidth(), mRenderer.getHeight()))
                    {
                        mLevel.getSelectedForm().remZ();
                    }
                    else if(mLevel.isFormSelected() &&
                            rotateButton.isClicked((int)event.getX(), (int)event.getY(), mRenderer.getWidth(), mRenderer.getHeight()))
                    {
                        mLevel.getSelectedForm().addRot();
                    }
                    else
                    {
                        selectEvent = true;
                        selectEventPosition[0] = (int)event.getX();
                        selectEventPosition[1] = Math.abs((int)event.getY() - mRenderer.getHeight());
                    }
                }
            }

            return true;
        }
    }

    public class DragListener implements OnDragListener
    {
        private float x, y;

        @Override
        public boolean onDrag(View v, DragEvent event)
        {
            switch (event.getAction())
            {
                case DragEvent.ACTION_DRAG_STARTED:
                    Log.d(TAG, "START DRAG");
                    x = event.getX();
                    y = event.getY();
                    break;
                case DragEvent.ACTION_DRAG_ENTERED:
                    Log.d(TAG, "DRAGING");
                    break;
            }

            return true;
        }
    }
}
