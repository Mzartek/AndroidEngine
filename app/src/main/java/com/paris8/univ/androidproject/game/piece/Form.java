package com.paris8.univ.androidproject.game.piece;

import com.paris8.univ.androidproject.engine.GraphicsRenderer;

/**
 * Created by Mzartek on 09/11/15.
 */
public abstract class Form
{
    protected float r, g, b;

    protected float x, y, z;
    protected float xwin, ywin, zwin;

    protected float rotation;
    protected float rotationWin;

    public boolean isSelected(int x, int y)
    {
        return GraphicsRenderer.compareColor(x, y, r, g, b);
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
}
