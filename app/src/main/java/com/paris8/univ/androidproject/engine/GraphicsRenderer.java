package com.paris8.univ.androidproject.engine;

public class GraphicsRenderer
{
    public static native void printGLinfo();
    public static native void setSize(int width, int height);
    public static native void setState();
    public static native boolean compareColor(int x, int y, float r, float g, float b);
    public static native void clear();
}
