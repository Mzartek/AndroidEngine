package com.paris8.univ.androidproject.game.geometry;

import android.content.res.AssetManager;

import com.paris8.univ.androidproject.engine.camera.PerspCamera;

/**
 * C'est une barre |
 */
public class Form1 extends Form
{
    public Form1(AssetManager assetManager,
                 Vector3D color,
                 Vector2D position, float xwin, float zwin,
                 float rotation)
    {
        super(color, position, xwin, zwin);

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
        cubes[2].getModel().displayOffSet(camera, 0, 0, 4);
        cubes[3].getModel().displayOffSet(camera, 0, 0, 6);

        super.displayFloor(camera);

        cubes[0].getModel().displayOffSet(camera, 0, 0, 0);
        cubes[1].getModel().displayOffSet(camera, 0, 0, 2);
        cubes[2].getModel().displayOffSet(camera, 0, 0, 4);
        cubes[3].getModel().displayOffSet(camera, 0, 0, 6);

        super.displayCube(camera);

        cubes[0].getModel().displayOffSet(camera, 0, 0, 0);
        cubes[1].getModel().displayOffSet(camera, 0, 0, 2);
        cubes[2].getModel().displayOffSet(camera, 0, 0, 4);
        cubes[3].getModel().displayOffSet(camera, 0, 0, 6);
    }
}
