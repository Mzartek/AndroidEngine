package com.paris8.univ.androidproject.game.geometry;

import com.paris8.univ.androidproject.engine.GraphicsRenderer;
import com.paris8.univ.androidproject.engine.camera.PerspCamera;

import java.util.ArrayList;

public abstract class Form
{
    private static final String TAG = "Form";

    protected Cube[] cubes;
    protected Vector3D color;
    protected Vector3D position;
    protected ArrayList winPositions = new ArrayList();
    protected float xwin, zwin;

    public Form(Vector3D color,
                Vector2D position, float xwin, float zwin)
    {
        this.color = color;
        this.position = new Vector3D(position.x, 1, position.y);

        this.xwin = xwin;
        this.zwin = zwin;

        if ((this.position.x % 2) != 0) this.position.x += 2 -(this.position.x % 2);
        if ((this.position.z % 2) != 0) this.position.z += 2 -(this.position.z % 2);

        if ((this.xwin % 2) != 0) this.xwin += 2 -(this.xwin % 2);
        if ((this.zwin % 2) != 0) this.zwin += 2 -(this.zwin % 2);
    }

    public boolean winPosition()
    {
        if (position.x == xwin && position.y == 1 && position.z == zwin)
        {
            return true;
        }

        return false;
    }

    public void addX()
    {
        position.x += 2;
    }

    public void remX()
    {
        position.x -= 2;
    }

    public void addZ()
    {
        position.z += 2;
    }

    public void remZ()
    {
        position.z -= 2;
    }

    public boolean isPointed(int x, int y)
    {
        return GraphicsRenderer.compareColor(x, y, color.x, color.y, color.z);
    }

    public void unselectIt()
    {
        position.y = 1;
    }

    public void selectIt()
    {
        position.y = 10;
    }

    protected void displayCube(PerspCamera camera)
    {
        for (Cube cube : cubes)
        {
            cube.setColor(color);
            cube.getModel().setScale(1, 1, 1);
            cube.getModel().setPosition(position.x, position.y, position.z);
        }
    }

    protected void displayFloor(PerspCamera camera)
    {
        for (Cube cube : cubes)
        {
            cube.setColor(new Vector3D(0.5f, 0, 0));
            cube.getModel().setScale(1, 0, 1);
            cube.getModel().setPosition(xwin, 0, zwin);
        }
    }

    protected void displayShadow(PerspCamera camera)
    {
        for (Cube cube : cubes)
        {
            cube.setColor(new Vector3D(0, 0, 0));
            cube.getModel().setScale(1, 0, 1);
            cube.getModel().setPosition(position.x, 0.1f, position.z);
        }
    }

    public abstract void display(PerspCamera camera);
}
