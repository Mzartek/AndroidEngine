package com.paris8.univ.androidproject.engine.model;

import com.paris8.univ.androidproject.engine.EngineObject;

/**
 * Created by Mzartek on 27/10/15.
 */
public abstract class Mesh extends EngineObject
{
    public Mesh(long objectHandler)
    {
        super(objectHandler);
    }

    public abstract void display();
}
