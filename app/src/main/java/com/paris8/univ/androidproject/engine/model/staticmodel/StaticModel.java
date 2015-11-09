package com.paris8.univ.androidproject.engine.model.staticmodel;

import android.content.res.AssetManager;

import com.paris8.univ.androidproject.engine.ShaderProgram;
import com.paris8.univ.androidproject.engine.camera.PerspCamera;
import com.paris8.univ.androidproject.engine.model.Model;

/**
 * Created by Mzartek on 02/11/15.
 */
public class StaticModel extends Model
{
    private static native long createStaticModel1(long shaderProgramHandler);
    private static native long createStaticModel2(long staticModelHandler, long shaderProgramHandler);

    private static native void loadFromAsset(long objectHandler, AssetManager assetManager, String asset);

    private static native void display(long objectHandler, long cameraHandler);
    private static native void displayTransparent(long objectHandler, long cameraHandler);
    private static native void displayOffSet(long objectHandler, long cameraHandler, float x, float y, float z);

    public StaticModel(ShaderProgram shaderProgram)
    {
        super(createStaticModel1(shaderProgram.getObjectHandler()));
    }

    public StaticModel(StaticModel staticModel, ShaderProgram shaderProgram)
    {
        super(createStaticModel2(staticModel.getObjectHandler(), shaderProgram.getObjectHandler()));
    }

    public void loadFromAsset(AssetManager assetManager, String asset)
    {
        loadFromAsset(this.getObjectHandler(), assetManager, asset);
    }

    @Override
    public void display(PerspCamera perspCamera)
    {
        display(this.getObjectHandler(), perspCamera.getObjectHandler());
    }

    @Override
    public void displayTransparent(PerspCamera perspCamera)
    {
        displayTransparent(this.getObjectHandler(), perspCamera.getObjectHandler());
    }

    @Override
    public void displayOffSet(PerspCamera perspCamera, float x, float y, float z)
    {
        displayOffSet(this.getObjectHandler(), perspCamera.getObjectHandler(), x, y, z);
    }
}
