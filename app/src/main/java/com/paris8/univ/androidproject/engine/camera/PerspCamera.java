package com.paris8.univ.androidproject.engine.camera;

public class PerspCamera extends Camera
{
    private static native long newPerspCamera();

    private static native void setCameraPosition(long objectHandler,
                                                 float posx, float posy, float posz);

    private static native void setAngle(long objectHandler,
                                        float atheta, float aphi);

    private static native void setPositionAndTarget(long objectHandler,
                                                    float posx, float posy, float posz,
                                                    float tarx, float tary, float tarz);

    private static native void setPerspective(long objectHandler,
                                              float fov, int width, int height, float near, float far);

    private static native void updateData(long objectHandler);

    public PerspCamera()
    {
        super(newPerspCamera());
    }

    public void setCameraPosition(float posx, float posy, float posz)
    {
        setCameraPosition(this.getObjectHandler(), posx, posy, posz);
    }

    public void setAngle(float atheta, float aphi)
    {
        setAngle(this.getObjectHandler(), atheta, aphi);
    }

    public void setPositionAndTarget(float posx, float posy, float posz,
                                     float tarx, float tary, float tarz)
    {
        setPositionAndTarget(this.getObjectHandler(), posx, posy, posz, tarx, tary, tarz);
    }

    public void setPerspective(float fov, int width, int height, float near, float far)
    {
        setPerspective(this.getObjectHandler(), fov, width, height, near, far);
    }

    @Override
    public void updateData()
    {
        updateData(this.getObjectHandler());
    }
}
