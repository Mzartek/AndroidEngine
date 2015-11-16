package com.paris8.univ.androidproject.game.piece;

import com.paris8.univ.androidproject.engine.GraphicsRenderer;
import com.paris8.univ.androidproject.engine.camera.PerspCamera;
import com.paris8.univ.androidproject.game.Cube;

/**
 * Created by Mzartek on 09/11/15.
 */
public abstract class Form
{
    protected Cube[] cubes;

    protected float r, g, b;

    protected float x, y, z;
    protected float xwin, ywin, zwin;

    protected float rotation;
    protected float rotationWin;

    public Form(float r, float g, float b,
                float x, float y, float z, float xwin, float ywin, float zwin,
                float rotation, float rotationWin)
    {
        this.r = r;
        this.g = g;
        this.b = b;

        this.x = x;
        this.y = y;
        this.z = z;

        this.xwin = xwin;
        this.ywin = ywin;
        this.zwin = zwin;

        this.rotation = rotation;

        this.rotationWin = rotationWin;
    }

    public boolean winPosition()
    {
        if (x == xwin && y == ywin && z == zwin && rotation == rotationWin)
        {
            return true;
        }

        return false;
    }

    public void addX()
    {
        x += 2;
    }

    public void remX()
    {
        x -= 2;
    }

    public void addZ()
    {
        z += 2;
    }

    public void remZ()
    {
        z -= 2;
    }

    public void addRot()
    {
        rotation += Math.toRadians(90);
    }

    public boolean isPointed(int x, int y)
    {
        return GraphicsRenderer.compareColor(x, y, r, g, b);
    }

    public void unselectIt()
    {
        y = 0;
    }

    public void selectIt()
    {
        y = 10;
    }

    protected void displayCube(PerspCamera camera)
    {
        for (Cube cube : cubes)
        {
            cube.setColor(r, g, b);
            cube.getModel().setScale(1, 1, 1);
            cube.getModel().setPosition(x, y, z);
            cube.getModel().setRotation(0, rotation, 0);
        }
    }

    protected void displayFloor(PerspCamera camera)
    {
        for (Cube cube : cubes)
        {
            cube.setColor(0.5f, 0, 0);
            cube.getModel().setScale(1, 0, 1);
            cube.getModel().setPosition(xwin, ywin, zwin);
            cube.getModel().setRotation(0, rotationWin, 0);
        }
    }

    public abstract void display(PerspCamera camera);
}
