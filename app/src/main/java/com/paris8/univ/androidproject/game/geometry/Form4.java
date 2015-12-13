package com.paris8.univ.androidproject.game.geometry;

import android.content.res.AssetManager;

import com.paris8.univ.androidproject.engine.camera.PerspCamera;

/**
 * C'est un carre
 */
public class Form4 extends Form
{
    public Form4(AssetManager assetManager,
                 Vector3D<Float> color,
                 float x, float z, float xwin, float zwin,
                 float rotation)
    {
        super(color, x, z, xwin, zwin);

        cubes = new Cube[]
                {
                        new Cube(assetManager),
                        new Cube(assetManager),
                        new Cube(assetManager),
                        new Cube(assetManager),
                };

        for (Cube cube : cubes)
        {
            cube.getModel().setRotation(0, rotation, 0);
        }
    }

    @Override
    public void display(PerspCamera camera)
    {
        super.displayShadow(camera);

        cubes[0].getModel().displayOffSet(camera, 0, 0, 0);
        cubes[1].getModel().displayOffSet(camera, 0, 0, 2);
        cubes[2].getModel().displayOffSet(camera, 2, 0, 0);
        cubes[3].getModel().displayOffSet(camera, 2, 0, 2);

        super.displayFloor(camera);

        cubes[0].getModel().displayOffSet(camera, 0, 0, 0);
        cubes[1].getModel().displayOffSet(camera, 0, 0, 2);
        cubes[2].getModel().displayOffSet(camera, 2, 0, 0);
        cubes[3].getModel().displayOffSet(camera, 2, 0, 2);

        super.displayCube(camera);

        cubes[0].getModel().displayOffSet(camera, 0, 0, 0);
        cubes[1].getModel().displayOffSet(camera, 0, 0, 2);
        cubes[2].getModel().displayOffSet(camera, 2, 0, 0);
        cubes[3].getModel().displayOffSet(camera, 2, 0, 2);
    }
}
