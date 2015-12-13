package com.paris8.univ.androidproject.game.geometry;

import com.paris8.univ.androidproject.engine.GraphicsRenderer;
import com.paris8.univ.androidproject.engine.camera.PerspCamera;

import java.lang.reflect.Array;
import java.util.ArrayList;

public abstract class Form
{
    private static final String TAG = "Form";

    protected Cube[] cubes;
    protected Vector3D[] offsets;

    protected Vector3D color;
    protected Vector3D position;
    protected ArrayList<Vector2D> winPositions;

    public Form(Vector3D color,
                Vector2D position,
                ArrayList winPositions)
    {
        this.color = color;
        this.position = new Vector3D(position.x, 1, position.y);
        this.winPositions = winPositions;

        if ((this.position.x % 2) != 0) this.position.x += 2 -(this.position.x % 2);
        if ((this.position.z % 2) != 0) this.position.z += 2 -(this.position.z % 2);

        for (Vector2D p : this.winPositions)
        {
            if ((p.x % 2) != 0) p.x += 2 -(p.x % 2);
            if ((p.y % 2) != 0) p.y += 2 -(p.y % 2);
        }
    }

    public boolean winPosition()
    {
        for (Vector2D p : this.winPositions)
        {
            if (position.x == p.x && position.y == 1 && position.z == p.y)
            {
                return true;
            }
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
        int i = 0;
        for (Cube cube : cubes)
        {
            cube.setColor(color);
            cube.getModel().setScale(1, 1, 1);
            cube.getModel().setPosition(position.x, position.y, position.z);
            cube.getModel().displayOffSet(camera,
                    offsets[i].x,
                    offsets[i].y,
                    offsets[i].z);
            i++;
        }
    }

    protected void displayFloor(PerspCamera camera)
    {
        int i = 0;
        for (Cube cube : cubes)
        {
            cube.setColor(new Vector3D(0.5f, 0, 0));
            cube.getModel().setScale(1, 0, 1);
            for (Vector2D p : this.winPositions)
            {
                cube.getModel().setPosition(p.x, 0, p.y);
                cube.getModel().displayOffSet(camera,
                        offsets[i].x,
                        offsets[i].y,
                        offsets[i].z);
            }
            i++;
        }
    }

    protected void displayShadow(PerspCamera camera)
    {
        int i = 0;
        for (Cube cube : cubes) {
            cube.setColor(new Vector3D(0, 0, 0));
            cube.getModel().setScale(1, 0, 1);
            cube.getModel().setPosition(position.x, 0.1f, position.z);
            cube.getModel().displayOffSet(camera,
                    offsets[i].x,
                    offsets[i].y,
                    offsets[i].z);
            i++;
        }
    }

    public abstract void display(PerspCamera camera);
}
