package com.paris8.univ.androidproject.game.piece;

import android.util.Log;

import com.paris8.univ.androidproject.engine.GraphicsRenderer;
import com.paris8.univ.androidproject.engine.camera.PerspCamera;
import com.paris8.univ.androidproject.game.Cube;

/**
 * Created by Mzartek on 09/11/15.
 */
public abstract class Form
{
    private static final String TAG = "Form";

    protected Cube[] cubes;

    protected float r, g, b;

    protected float x, y, z;
    protected float xwin, zwin;

    protected float rotation;
    protected float rotationWin;

    public Form(float r, float g, float b,
                float x, float z, float xwin, float zwin,
                float rotation, float rotationWin)
    {
        this.r = r;
        this.g = g;
        this.b = b;

        this.x = x;
        this.y = 1;
        this.z = z;

        this.xwin = xwin;
        this.zwin = zwin;

        this.rotation = rotation % (float)Math.toRadians(360);

        this.rotationWin = rotationWin % (float)Math.toRadians(360);

        if ((this.x % 2) != 0) this.x += 2 -(this.x % 2);
        if ((this.z % 2) != 0) this.z += 2 -(this.z % 2);

        if ((this.xwin % 2) != 0) this.xwin += 2 -(this.xwin % 2);
        if ((this.zwin % 2) != 0) this.zwin += 2 -(this.zwin % 2);

        if ((this.rotation % Math.toRadians(90)) != 0) this.rotation += Math.toRadians(90) - (this.rotation % Math.toRadians(90));

        if ((this.rotationWin % Math.toRadians(90)) != 0) this.rotationWin += Math.toRadians(90) - (this.rotationWin % Math.toRadians(90));
    }

    public boolean winPosition()
    {
        Log.d(TAG, x + " " + y + " " + z);
        Log.d(TAG, xwin + " " + 1 + " " + zwin);
        Log.d(TAG, rotation + " " + rotationWin);
        Log.d(TAG, "END");

        if (x == xwin && y == 1 && z == zwin && rotation == rotationWin)
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
        this.rotation %= (float)Math.toRadians(360);
    }

    public boolean isPointed(int x, int y)
    {
        return GraphicsRenderer.compareColor(x, y, r, g, b);
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
            cube.getModel().setPosition(xwin, 0, zwin);
            cube.getModel().setRotation(0, rotationWin, 0);
        }
    }

    protected void displayShadow(PerspCamera camera)
    {
        for (Cube cube : cubes)
        {
            cube.setColor(0, 0, 0);
            cube.getModel().setScale(1, 0, 1);
            cube.getModel().setPosition(x, 0.1f, z);
            cube.getModel().setRotation(0, rotation, 0);
        }
    }

    public abstract void display(PerspCamera camera);
}
