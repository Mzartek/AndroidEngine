package com.paris8.univ.androidproject.game.geometry;

import android.content.res.AssetManager;

import com.paris8.univ.androidproject.engine.camera.PerspCamera;

import java.util.ArrayList;

/**
 * C'est un carre
 */
public class Form4 extends Form
{
    public Form4(AssetManager assetManager,
                 Vector3D color,
                 Vector2D position,
                 ArrayList<Vector2D> winPositions,
                 float rotation)
    {
        super(color, position, winPositions);

        cubes = new Cube[]
                {
                        new Cube(assetManager),
                        new Cube(assetManager),
                        new Cube(assetManager),
                        new Cube(assetManager),
                };

        offsets = new Vector3D[]
                {
                        new Vector3D(0, 0, 0),
                        new Vector3D(0, 0, 2),
                        new Vector3D(2, 0, 0),
                        new Vector3D(2, 0, 2),
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
        super.displayFloor(camera);
        super.displayCube(camera);
    }
}
