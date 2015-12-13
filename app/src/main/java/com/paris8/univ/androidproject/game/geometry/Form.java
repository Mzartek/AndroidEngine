package com.paris8.univ.androidproject.game.geometry;

import com.paris8.univ.androidproject.engine.GraphicsRenderer;
import com.paris8.univ.androidproject.engine.camera.PerspCamera;

public abstract class Form
{
    private static final String TAG = "Form";

    protected Cube[] cubes;

    protected Vector3D<Float> color;

    protected float x, y, z;
    protected float xwin, zwin;

    public Form(Vector3D<Float> color,
                float x, float z, float xwin, float zwin)
    {
        this.color = color;

        this.x = x;
        this.y = 1;
        this.z = z;

        this.xwin = xwin;
        this.zwin = zwin;

        if ((this.x % 2) != 0) this.x += 2 -(this.x % 2);
        if ((this.z % 2) != 0) this.z += 2 -(this.z % 2);

        if ((this.xwin % 2) != 0) this.xwin += 2 -(this.xwin % 2);
        if ((this.zwin % 2) != 0) this.zwin += 2 -(this.zwin % 2);
    }

    public boolean winPosition()
    {
        if (x == xwin && y == 1 && z == zwin)
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

    public boolean isPointed(int x, int y)
    {
        return GraphicsRenderer.compareColor(x, y, color.x, color.y, color.z);
    }

    public void unselectIt()
    {
        y = 1;
    }

    public void selectIt()
    {
        y = 10;
    }

    protected void displayCube(PerspCamera camera)
    {
        for (Cube cube : cubes)
        {
            cube.setColor(color);
            cube.getModel().setScale(1, 1, 1);
            cube.getModel().setPosition(x, y, z);
        }
    }

    protected void displayFloor(PerspCamera camera)
    {
        for (Cube cube : cubes)
        {
            cube.setColor(new Vector3D(0.5f, 0.0f, 0.0f));
            cube.getModel().setScale(1, 0, 1);
            cube.getModel().setPosition(xwin, 0, zwin);
        }
    }

    protected void displayShadow(PerspCamera camera)
    {
        for (Cube cube : cubes)
        {
            cube.setColor(new Vector3D(0.0f, 0.0f, 0.0f));
            cube.getModel().setScale(1, 0, 1);
            cube.getModel().setPosition(x, 0.1f, z);
        }
    }

    public abstract void display(PerspCamera camera);
}
