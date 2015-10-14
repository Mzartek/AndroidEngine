package com.paris8.univ.androidproject.engine;

/**
 * Created by mzartek on 24/09/15.
 */
public class EngineObject extends Object
{
    private static native void deleteObject(long objectHandler);

    private long objectHandler;

    public EngineObject(long objectHandler)
    {
        this.objectHandler = objectHandler;
    }

    @Override
    protected void finalize() throws Throwable
    {
        try
        {
            deleteObject(objectHandler);
        }
        catch(Throwable t)
        {
            throw t;
        }
        finally
        {
            super.finalize();
        }
    }

    public long getObjectHandler()
    {
        return objectHandler;
    }
}
