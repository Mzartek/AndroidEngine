package com.paris8.univ.androidproject.game;

import android.content.res.AssetManager;
import android.util.Log;

import com.paris8.univ.androidproject.engine.ShaderProgram;
import com.paris8.univ.androidproject.engine.camera.PerspCamera;
import com.paris8.univ.androidproject.engine.model.Material;
import com.paris8.univ.androidproject.engine.model.staticmodel.StaticMesh;
import com.paris8.univ.androidproject.engine.model.staticmodel.StaticModel;

/**
 * Created by Mzartek on 04/11/2015.
 */
public class Cube
{
    private static final String TAG = "Cube";

    static float dimension = 1;
    static float[] vertex =
            {
                    +dimension, -dimension, -dimension,
                    0, 0, 0, 0, 0, 0, 0, 0,

                    -dimension, -dimension, -dimension,
                    0, 0, 0, 0, 0, 0, 0, 0,

                    -dimension, -dimension, +dimension,
                    0, 0, 0, 0, 0, 0, 0, 0,

                    +dimension, -dimension, +dimension,
                    0, 0, 0, 0, 0, 0, 0, 0,

                    +dimension, +dimension, -dimension,
                    0, 0, 0, 0, 0, 0, 0, 0,

                    -dimension, +dimension, -dimension,
                    0, 0, 0, 0, 0, 0, 0, 0,

                    -dimension, +dimension, +dimension,
                    0, 0, 0, 0, 0, 0, 0, 0,

                    +dimension, +dimension, +dimension,
                    0, 0, 0, 0, 0, 0, 0, 0,
            };

    static int[] index =
            {
                    0, 1, 2, 0, 2, 3,
                    4, 7, 6, 4, 6, 5,
                    0, 4, 5, 0, 5, 1,
                    3, 2, 6, 3, 6, 7,
                    1, 5, 6, 1, 6, 2,
                    0, 3, 7, 0, 7, 4,
            };

    private ShaderProgram mShaderProgram;
    private Material mMaterial;
    private StaticMesh mStaticMesh;
    private StaticModel mStaticModel;

    public Cube(AssetManager assetManager, float r, float g, float b)
    {
        try
        {
            mShaderProgram = new ShaderProgram(assetManager,
                    "Shaders/Cube/object_vs.glsl",
                    "Shaders/Cube/object_fs.glsl");
        }
        catch (Exception ex)
        {
            Log.e(TAG, ex.toString());
        }

        mMaterial = new Material();
        mMaterial.setAmbient(r, g, b);

        mStaticMesh = new StaticMesh(mShaderProgram);
        mStaticMesh.setMaterial(mMaterial);
        mStaticMesh.load(vertex, index);

        mStaticModel = new StaticModel(mShaderProgram);
        mStaticModel.addMesh(mStaticMesh);
    }

    public void display(PerspCamera camera)
    {
        mStaticModel.display(camera);
    }
}
