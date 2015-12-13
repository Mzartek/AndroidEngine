package com.paris8.univ.androidproject.game.geometry;

public class Vector2D
{
    public float x, y;

    public Vector2D(float x, float y)
    {
        this.x = x;
        this.y = y;
    }

    public Vector2D(Vector2D obj)
    {
        this.x = obj.x;
        this.y = obj.y;
    }

    public boolean isEqualTo(Vector2D obj)
    {
        if (this.x == obj.x && this.y == obj.y)
        {
            return true;
        }
        return false;
    }
}
