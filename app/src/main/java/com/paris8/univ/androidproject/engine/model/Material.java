package com.paris8.univ.androidproject.engine.model;

import com.paris8.univ.androidproject.engine.EngineObject;
import com.paris8.univ.androidproject.engine.texture.Texture2D;

public class Material extends EngineObject
{
    private static native long createMaterial();

    private static native void setDiffuse(long objectHandler, float r, float g, float b);
    private static native void setSpecular(long objectHandler, float r, float g, float b);
    private static native void setAmbient(long objectHandler, float r, float g, float b);
    private static native void setEmissive(long objectHandler, float r, float g, float b);
    private static native void setShininess(long objectHandler, float shininess);
    private static native void setOpacity(long objectHandler, float opacity);

    private static native void setDiffuseTexture(long objectHandler, long textureHandler);
    private static native void setSpecularTexture(long objectHandler, long textureHandler);
    private static native void setAmbientTexture(long objectHandler, long textureHandler);
    private static native void setEmissiveTexture(long objectHandler, long textureHandler);
    private static native void setShininessTexture(long objectHandler, long textureHandler);
    private static native void setOpacityTexture(long objectHandler, long textureHandler);
    private static native void setBumpMap(long objectHandler, long textureHandler);
    private static native void setNormalMap(long objectHandler, long textureHandler);
    private static native void setDisplacementMap(long objectHandler, long textureHandler);
    private static native void setLightMap(long objectHandler, long textureHandler);

    public Material()
    {
        super(createMaterial());
    }

    public void setDiffuse(float r, float g, float b)
    {
        setDiffuse(this.getObjectHandler(), r, g, b);
    }

    public void setSpecular(float r, float g, float b)
    {
        setSpecular(this.getObjectHandler(), r, g, b);
    }

    public void setAmbient(float r, float g, float b)
    {
        setAmbient(this.getObjectHandler(), r, g, b);
    }

    public void setEmissive(float r, float g, float b)
    {
        setEmissive(this.getObjectHandler(), r, g, b);
    }

    public void setShininess(float shininess)
    {
        setShininess(this.getObjectHandler(), shininess);
    }

    public void setOpacity(float opacity)
    {
        setShininess(this.getObjectHandler(), opacity);
    }

    public void setDiffuseTexture(Texture2D texture)
    {
        setDiffuseTexture(this.getObjectHandler(), texture.getObjectHandler());
    }

    public void setSpecularTexture(Texture2D texture)
    {
        setSpecularTexture(this.getObjectHandler(), texture.getObjectHandler());
    }

    public void setAmbientTexture(Texture2D texture)
    {
        setAmbientTexture(this.getObjectHandler(), texture.getObjectHandler());
    }

    public void setEmissiveTexture(Texture2D texture)
    {
        setEmissiveTexture(this.getObjectHandler(), texture.getObjectHandler());
    }

    public void setShininessTexture(Texture2D texture)
    {
        setShininessTexture(this.getObjectHandler(), texture.getObjectHandler());
    }

    public void setOpacityTexture(Texture2D texture)
    {
        setOpacityTexture(this.getObjectHandler(), texture.getObjectHandler());
    }

    public void setBumpMap(Texture2D texture)
    {
        setBumpMap(this.getObjectHandler(), texture.getObjectHandler());
    }

    public void setNormalMap(Texture2D texture)
    {
        setNormalMap(this.getObjectHandler(), texture.getObjectHandler());
    }

    public void setDisplacementMap(Texture2D texture)
    {
        setDisplacementMap(this.getObjectHandler(), texture.getObjectHandler());
    }

    public void setLightMap(Texture2D texture)
    {
        setLightMap(this.getObjectHandler(), texture.getObjectHandler());
    }
}
