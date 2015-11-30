package com.paris8.univ.androidproject.game;

import android.app.Activity;
import android.content.Context;
import android.content.res.AssetManager;
import android.media.MediaPlayer;
import android.opengl.GLSurfaceView;
import android.provider.Settings;
import android.util.Log;
import android.view.DragEvent;
import android.view.MotionEvent;
import android.view.View;

import com.paris8.univ.androidproject.R;
import com.paris8.univ.androidproject.engine.GraphicsRenderer;
import com.paris8.univ.androidproject.engine.camera.PerspCamera;
import com.paris8.univ.androidproject.game.geometry.MySkyBox;
import com.paris8.univ.androidproject.game.level.Level;
import com.paris8.univ.androidproject.game.level.Levels;
import com.paris8.univ.androidproject.game.menu.MenuActivity;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

/**
 * Created by mzartek on 22/09/15.
 */
public class GameView extends GLSurfaceView
{
    final static private String TAG = "GameView";

    //Pour la musique [
    private MediaPlayer mMediaPlayer;
    private MenuActivity menu;
    // ]

    private GameActivity mGameActivity;

    private int mSelectedLevel;

    private AssetManager mAssetManager;
    private Renderer mRenderer;
    private boolean mSurfaceCreated = false;

    private PerspCamera mCamera;

    private MySkyBox mySkyBox;
    private Level mLevel;

    private GameButton mUpButton;
    private GameButton mDownButton;
    private GameButton mRightButton;
    private GameButton mLeftButton;

    private boolean selectEvent = false;
    private int[] selectEventPosition = new int[] { 0,  0 };

    public GameView(GameActivity gameActivity, Context context, AssetManager assetManager, int selectedLevel)
    {
        super(context);

        mGameActivity = gameActivity;

        mSelectedLevel = selectedLevel;

        mAssetManager = assetManager;
        mRenderer = new Renderer();

        setEGLConfigChooser(8, 8, 8, 0, 24, 8);
        setEGLContextClientVersion(2);
        setRenderer(mRenderer);

        setOnTouchListener(new TouchListener());
        setOnDragListener(new DragListener());
    }

    @Override
    public void onPause(){
        mMediaPlayer.stop();
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

            mUpButton = new GameButton(mAssetManager, "Textures/Control/arrow.jpg",
                    0.2f * 2.0f - 1.0f, 0.22f * 2.0f - 1.0f, 1.0f, 0.0f,
                    0.4f * 2.0f - 1.0f, 0.22f * 2.0f - 1.0f, 1.0f, 1.0f,
                    0.2f * 2.0f - 1.0f, 0.33f * 2.0f - 1.0f, 0.0f, 0.0f,
                    0.4f * 2.0f - 1.0f, 0.33f * 2.0f - 1.0f, 0.0f, 1.0f);

            mDownButton = new GameButton(mAssetManager, "Textures/Control/arrow.jpg",
                    0.2f * 2.0f - 1.0f, 0.0f * 2.0f - 1.0f, 0.0f, 1.0f,
                    0.4f * 2.0f - 1.0f, 0.0f * 2.0f - 1.0f, 0.0f, 0.0f,
                    0.2f * 2.0f - 1.0f, 0.11f * 2.0f - 1.0f, 1.0f, 1.0f,
                    0.4f * 2.0f - 1.0f, 0.11f * 2.0f - 1.0f, 1.0f, 0.0f);

            mLeftButton = new GameButton(mAssetManager, "Textures/Control/arrow.jpg",
                    0.0f * 2.0f - 1.0f, 0.11f * 2.0f - 1.0f, 0.0f, 0.0f,
                    0.2f * 2.0f - 1.0f, 0.11f * 2.0f - 1.0f, 1.0f, 0.0f,
                    0.0f * 2.0f - 1.0f, 0.22f * 2.0f - 1.0f, 0.0f, 1.0f,
                    0.2f * 2.0f - 1.0f, 0.22f * 2.0f - 1.0f, 1.0f, 1.0f);

            mRightButton = new GameButton(mAssetManager, "Textures/Control/arrow.jpg",
                    0.4f * 2.0f - 1.0f, 0.11f * 2.0f - 1.0f, 1.0f, 1.0f,
                    0.6f * 2.0f - 1.0f, 0.11f * 2.0f - 1.0f, 0.0f, 1.0f,
                    0.4f * 2.0f - 1.0f, 0.22f * 2.0f - 1.0f, 1.0f, 0.0f,
                    0.6f * 2.0f - 1.0f, 0.22f * 2.0f - 1.0f, 0.0f, 0.0f);

            switch (mSelectedLevel)
            {
                case 0:
                    mMediaPlayer = MediaPlayer.create(getContext(), R.raw.level1_music);
                    runMusic();
                    mLevel = Levels.getLevel0(mAssetManager);
                    break;
                case 1:
                    mMediaPlayer = MediaPlayer.create(getContext(), R.raw.level2_music);
                    runMusic();
                    mLevel = Levels.getLevel1(mAssetManager);
                    break;
                case 2:
                    mMediaPlayer = MediaPlayer.create(getContext(), R.raw.level3_music);
                    runMusic();
                    mLevel = Levels.getLevel2(mAssetManager);
                    break;
                default:
                    Log.e(TAG, "Invalid level number");
                    mGameActivity.finish();
            }

            mSurfaceCreated = true;

            Chronometer.start();
        }

        public void runMusic()
        {
            if(menu.sound)
                mMediaPlayer.start();
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

                if (mLevel.isWin())
                {
                    mMediaPlayer.stop();
                    mGameActivity.finish();
                }
            }

            GraphicsRenderer.clear();

            mCamera.updateData();

            mySkyBox.display(mCamera);
            mLevel.display(mCamera);

            if (mLevel.isFormSelected())
            {
                mUpButton.display(mCamera);
                mDownButton.display(mCamera);
                mLeftButton.display(mCamera);
                mRightButton.display(mCamera);
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
                            mUpButton.isClicked((int)event.getX(), (int)event.getY(), mRenderer.getWidth(), mRenderer.getHeight()))
                    {
                        mLevel.getSelectedForm().remX();
                    }
                    else if(mLevel.isFormSelected() &&
                            mDownButton.isClicked((int)event.getX(), (int)event.getY(), mRenderer.getWidth(), mRenderer.getHeight()))
                    {
                        mLevel.getSelectedForm().addX();
                    }
                    else if(mLevel.isFormSelected() &&
                            mLeftButton.isClicked((int)event.getX(), (int)event.getY(), mRenderer.getWidth(), mRenderer.getHeight()))
                    {
                        mLevel.getSelectedForm().addZ();
                    }
                    else if(mLevel.isFormSelected() &&
                            mRightButton.isClicked((int)event.getX(), (int)event.getY(), mRenderer.getWidth(), mRenderer.getHeight()))
                    {
                        mLevel.getSelectedForm().remZ();
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
