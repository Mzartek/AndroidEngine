package com.paris8.univ.androidproject.game.geometry;

public class Vector3D<T>
{
    public T x, y, z;

    public Vector3D(T x, T y, T z)
    {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    public Vector3D(Vector3D<T> obj)
    {
        this.x = obj.x;
        this.y = obj.y;
        this.z = obj.z;
    }

    public boolean isEqualTo(Vector3D<T> obj)
    {
        if (this.x == obj.x && this.y == obj.y && this.z == obj.z)
        {
            return true;
        }
        return false;
    }
}
