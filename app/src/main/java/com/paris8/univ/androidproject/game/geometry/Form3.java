package com.paris8.univ.androidproject.game.geometry;

import android.content.res.AssetManager;

import com.paris8.univ.androidproject.engine.camera.PerspCamera;

import java.util.ArrayList;

/**
 * C'est la cicatrice d'harry potter
 */
public class Form3 extends Form
{
    public Form3(AssetManager assetManager,
                 Vector3D color,
                 Vector2D position,
                 ArrayList<Vector2D> winPositions,
                 Vector3D rotation)
    {
        super(color, position, winPositions);

        cubes = new Cube[]
                {
                        new Cube(assetManager),
                        new Cube(assetManager),
                        new Cube(assetManager),
                        new Cube(assetManager),
                        new Cube(assetManager),
                };

        offsets = new Vector3D[]
                {
                        new Vector3D(0, 0, 0),
                        new Vector3D(0, 0, 2),
                        new Vector3D(2, 0, 2),
                        new Vector3D(2, 0, 4),
                        new Vector3D(2, 0, 6),
                };

        for (Cube cube : cubes)
        {
            cube.getModel().setRotation(rotation.x, rotation.y, rotation.z);
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