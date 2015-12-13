package com.paris8.univ.androidproject.game.level;

import android.content.res.AssetManager;

import com.paris8.univ.androidproject.game.geometry.Form1;
import com.paris8.univ.androidproject.game.geometry.Form2;
import com.paris8.univ.androidproject.game.geometry.Form3;
import com.paris8.univ.androidproject.game.geometry.Form4;
import com.paris8.univ.androidproject.game.geometry.Form5;
import com.paris8.univ.androidproject.game.geometry.Vector2D;
import com.paris8.univ.androidproject.game.geometry.Vector3D;

import java.util.ArrayList;

public class Levels
{
    public static Level getLevel0(AssetManager assetManager)
    {
        Level level = new Level();

        // Form1 section
        ArrayList<Vector2D> form1Solutions = new ArrayList();
        form1Solutions.add(new Vector2D(-10, -4));

        level.addForm(new Form1(assetManager,
                new Vector3D(1, 1, 0),
                new Vector2D(8, -14),
                form1Solutions,
                0));

        // Form2 section
        ArrayList<Vector2D> form2Solutions = new ArrayList();
        form2Solutions.add(new Vector2D(-4, 6));
        form2Solutions.add(new Vector2D(0, 2));

        level.addForm(new Form2(assetManager,
                new Vector3D(1, 1, 0.5f),
                new Vector2D(4, 10),
                form2Solutions,
                (float)Math.toRadians(180)));

        level.addForm(new Form2(assetManager,
                new Vector3D(0.5f, 1, 0.5f),
                new Vector2D(-4, 10),
                form2Solutions,
                (float)Math.toRadians(180)));

        // Form4 section
        ArrayList<Vector2D> form4Solutions = new ArrayList();
        form4Solutions.add(new Vector2D(-8, -4));
        form4Solutions.add(new Vector2D(-10, 4));
        form4Solutions.add(new Vector2D(-2, 4));

        level.addForm(new Form4(assetManager,
                new Vector3D(1, 0, 0),
                new Vector2D(4, -14),
                form4Solutions,
                0));

        level.addForm(new Form4(assetManager,
                new Vector3D(0, 1, 0),
                new Vector2D(0, -14),
                form4Solutions,
                0));

        level.addForm(new Form4(assetManager,
                new Vector3D(0, 1, 0.75f),
                new Vector2D(0, 0),
                form4Solutions,
                0));

        // Form3 section
        ArrayList<Vector2D> form3Solutions = new ArrayList<>();
        form3Solutions.add(new Vector2D(-8, 0));
        form3Solutions.add(new Vector2D(-4, -4));

        level.addForm(new Form3(assetManager,
                new Vector3D(1, 0, 1),
                new Vector2D(-4, -14),
                form3Solutions,
                0));

        level.addForm(new Form3(assetManager,
                new Vector3D(0.40f, 0.21f, 1),
                new Vector2D(-1, -4),
                form3Solutions,
                0));


        return level;
    }

    public static Level getLevel1(AssetManager assetManager)
    {
        Level level = new Level();

        /*level.addForm(new Form3(assetManager,
                new Vector3D(0, 1, 0),
                new Vector2D(1.75f, 0),
                0, 3.75f,
                66));
        level.addForm(new Form2(assetManager,
                new Vector3D(1, 0, 0),
                new Vector2D(3, 1),
                1, 2,
                33));*/

        return level;
    }

    public static Level getLevel2(AssetManager assetManager)
    {
        Level level = new Level();

        /*level.addForm(new Form4(assetManager,
                new Vector3D(0, 1, 0),
                new Vector2D(1.75f, 0),
                0, 3.75f,
                66));
        level.addForm(new Form5(assetManager,
                new Vector3D(1, 0, 0),
                new Vector2D(3, 1),
                1, 2,
                33));*/

        return level;
    }
}
