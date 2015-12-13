package com.paris8.univ.androidproject.game.geometry;

public class Vector2D<T>
{
    public T x, y;

    public Vector2D(T x, T y)
    {
        this.x = x;
        this.y = y;
    }

    public Vector2D(Vector2D<T> obj)
    {
        this.x = obj.x;
        this.y = obj.y;
    }

    public boolean isEqualTo(Vector2D<T> obj)
    {
        if (this.x == obj.x && this.y == obj.y)
        {
            return true;
        }
        return false;
    }
}
