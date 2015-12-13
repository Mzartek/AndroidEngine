package com.paris8.univ.androidproject.game.geometry;

public class Vector3D
{
    public float x, y, z;

    public Vector3D(float x, float y, float z)
    {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    public Vector3D(Vector3D obj)
    {
        this.x = obj.x;
        this.y = obj.y;
        this.z = obj.z;
    }

    public boolean isEqualTo(Vector3D obj)
    {
        if (this.x == obj.x && this.y == obj.y && this.z == obj.z)
        {
            return true;
        }
        return false;
    }
}
