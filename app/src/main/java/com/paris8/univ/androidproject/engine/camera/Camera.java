package com.paris8.univ.androidproject.engine.camera;

import com.paris8.univ.androidproject.engine.EngineObject;

/**
 * Created by khavranek on 14/10/15.
 */
public abstract class Camera extends EngineObject
{
    public Camera(long objectHandler)
    {
        super(objectHandler);
    }

    public abstract void updateData();
}
