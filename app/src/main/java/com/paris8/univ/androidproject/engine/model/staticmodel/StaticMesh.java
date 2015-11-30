package com.paris8.univ.androidproject.engine.model.staticmodel;

import com.paris8.univ.androidproject.engine.ShaderProgram;
import com.paris8.univ.androidproject.engine.model.Mesh;

public class StaticMesh extends Mesh
{
    private static native long createStaticMesh(long shaderProgramHandler);

    private static native void load(long objectHandler,
            int numVertex, float[] vertices, int numIndex, int[] indices);

    public StaticMesh(ShaderProgram shaderProgram)
    {
        super(createStaticMesh(shaderProgram.getObjectHandler()));
    }

    public void load(float[] vertices, int[] indices)
    {
        load(this.getObjectHandler(), vertices.length, vertices, indices.length, indices);
    }
}
