package com.paris8.univ.androidproject.game;

import android.content.res.AssetManager;
import android.util.Log;

import com.paris8.univ.androidproject.engine.ShaderProgram;
import com.paris8.univ.androidproject.engine.camera.PerspCamera;
import com.paris8.univ.androidproject.engine.model.Material;
import com.paris8.univ.androidproject.engine.model.staticmodel.StaticMesh;
import com.paris8.univ.androidproject.engine.model.staticmodel.StaticModel;
import com.paris8.univ.androidproject.engine.texture.Texture2D;

/**
 * Created by Mzartek on 16/11/15.
 */
public class GameButton
{
    private static final String TAG = "GameButton";

    static int[] index = { 0, 1, 2, 2, 1, 3 };

    private float[] vertex;

    private float x0, y0, x1, y1, x2, y2, x3, y3;

    private ShaderProgram mShaderProgram;
    private Texture2D mTexture2D;
    private Material mMaterial;
    private StaticMesh mStaticMesh;
    private StaticModel mStaticModel;

    public GameButton(AssetManager assetManager, String texturePath,
                      float x0, float y0, float tx0, float ty0,
                      float x1, float y1, float tx1, float ty1,
                      float x2, float y2, float tx2, float ty2,
                      float x3, float y3, float tx3, float ty3)
    {
        this.x0 = x0;
        this.y0 = y0;

        this.x1 = x1;
        this.y1 = y1;

        this.x2 = x2;
        this.y2 = y2;

        this.x3 = x3;
        this.y3 = y3;

        vertex = new float[]
                {
                        x0, y0, 0,
                        tx0, ty0,
                        0, 0, 0, 0, 0, 0,

                        x1, y1, 0,
                        tx1, ty1,
                        0, 0, 0, 0, 0, 0,

                        x2, y2, 0,
                        tx2, ty2,
                        0, 0, 0, 0, 0, 0,

                        x3, y3, 0,
                        tx3, ty3,
                        0, 0, 0, 0, 0, 0,
                };

        try
        {
            mShaderProgram = new ShaderProgram(assetManager,
                    "Shaders/Control/control_vs.glsl",
                    "Shaders/Control/control_fs.glsl");
        }
        catch (Exception ex)
        {
            Log.e(TAG, ex.toString());
        }

        mTexture2D = new Texture2D();
        mTexture2D.loadFromAsset(assetManager, texturePath);

        mMaterial = new Material();
        mMaterial.setDiffuseTexture(mTexture2D);

        mStaticMesh = new StaticMesh(mShaderProgram);
        mStaticMesh.setMaterial(mMaterial);
        mStaticMesh.load(vertex, index);

        mStaticModel = new StaticModel(mShaderProgram);
        mStaticModel.addMesh(mStaticMesh);
    }

    public boolean isClicked(int x, int y, int width, int height)
    {
        float coordX = ((float)x / width) * 2.0f - 1.0f;
        float coordY = (((float)y / height) * 2.0f - 1.0f) * (-1.0f);

        if (
                coordX > this.x0 && coordY > this.y0 &&
                coordX < this.x1 && coordY > this.y1 &&
                coordX > this.x2 && coordY < this.y2 &&
                coordX < this.x3 && coordY < this.y3)
        {
            return true;
        }

        return false;
    }

    public void display(PerspCamera camera)
    {
        mStaticModel.display(camera);
    }
}
