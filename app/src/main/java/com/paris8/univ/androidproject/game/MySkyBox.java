package com.paris8.univ.androidproject.game;

import android.content.res.AssetManager;
import android.util.Log;

import com.paris8.univ.androidproject.engine.ShaderProgram;
import com.paris8.univ.androidproject.engine.SkyBox;
import com.paris8.univ.androidproject.engine.camera.PerspCamera;

/**
 * Created by Mzartek on 04/11/2015.
 */
public class MySkyBox
{
    private static final String TAG = "MySkyBox";

    private SkyBox skyBox;
    private ShaderProgram skyboxProgram;

    public MySkyBox(AssetManager assetManager)
    {
        try
        {
            skyboxProgram = new ShaderProgram(assetManager,
                    "Shaders/SkyBox/skybox_vs.glsl",
                    "Shaders/SkyBox/skybox_fs.glsl");
        }
        catch (Exception ex)
        {
            Log.e(TAG, ex.toString());
        }

        skyBox = new SkyBox(skyboxProgram);
        skyBox.load(assetManager,
                "Textures/BlueSky/bluesky_right.jpg", "Textures/BlueSky/bluesky_left.jpg",
                "Textures/BlueSky/bluesky_top.jpg", "Textures/BlueSky/floor.jpg",
                "Textures/BlueSky/bluesky_front.jpg", "Textures/BlueSky/bluesky_back.jpg");
    }

    public void display(PerspCamera camera)
    {
        skyBox.display(camera);
    }
}
