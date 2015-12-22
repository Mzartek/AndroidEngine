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
        form1Solutions.add(new Vector2D(-6, 4));

        level.addForm(new Form1(assetManager,
                new Vector3D(1, 1, 0),
                new Vector2D(8, -14),
                form1Solutions,
                new Vector3D(0,0,0)));

        // Form2 section
        ArrayList<Vector2D> form2Solutions = new ArrayList();
        form2Solutions.add(new Vector2D(0, 14));
        form2Solutions.add(new Vector2D(4, 10));

        level.addForm(new Form2(assetManager,
                new Vector3D(1, 1, 0.5f),
                new Vector2D(4, 10),
                form2Solutions,
                new Vector3D(0.0f,(float)Math.toRadians(180),0.0f)));

        level.addForm(new Form2(assetManager,
                new Vector3D(0.5f, 1, 0.5f),
                new Vector2D(-4, 10),
                form2Solutions,
                new Vector3D(0.0f,(float)Math.toRadians(180),0.0f)));

        // Form4 section
        ArrayList<Vector2D> form4Solutions = new ArrayList();
        form4Solutions.add(new Vector2D(-4, 4));
        form4Solutions.add(new Vector2D(-6, 12));
        form4Solutions.add(new Vector2D(2, 12));

        level.addForm(new Form4(assetManager,
                new Vector3D(1, 0, 0),
                new Vector2D(4, -14),
                form4Solutions,
                new Vector3D(0,0,0)));

        level.addForm(new Form4(assetManager,
                new Vector3D(0, 1, 0),
                new Vector2D(0, -14),
                form4Solutions,
                new Vector3D(0,0,0)));

        level.addForm(new Form4(assetManager,
                new Vector3D(0, 1, 0.75f),
                new Vector2D(0, 0),
                form4Solutions,
                new Vector3D(0,0,0)));

        // Form3 section
        ArrayList<Vector2D> form3Solutions = new ArrayList<>();
        form3Solutions.add(new Vector2D(-4, 8));
        form3Solutions.add(new Vector2D(0, 4));

        level.addForm(new Form3(assetManager,
                new Vector3D(1, 0, 1),
                new Vector2D(-4, -14),
                form3Solutions,
                new Vector3D(0,0,0)));

        level.addForm(new Form3(assetManager,
                new Vector3D(0.40f, 0.21f, 1),
                new Vector2D(-1, -4),
                form3Solutions,
                new Vector3D(0,0,0)));


        return level;
    }

    public static Level getLevel1(AssetManager assetManager)
    {
        Level level = new Level();

        // Form 2 section

        ArrayList<Vector2D> form2_1_solution = new ArrayList();
        form2_1_solution.add(new Vector2D(-6, 6));

        ArrayList<Vector2D> form2_2_solution = new ArrayList();
        form2_2_solution.add(new Vector2D(-6, 8));

        ArrayList<Vector2D> form2_3_solution = new ArrayList();
        form2_3_solution.add(new Vector2D(-2, 14));

        ArrayList<Vector2D> form2_4_solution = new ArrayList();
        form2_4_solution.add(new Vector2D(0, 8));

        level.addForm(new Form2(assetManager,
                new Vector3D(0.0f, 1.0f, 0.0f),
                new Vector2D(4.0f, 0),
                form2_1_solution,
                new Vector3D(0.0f, (float) Math.toRadians(180), (float) Math.toRadians(180))));

        level.addForm(new Form2(assetManager,
                new Vector3D(1.0f, 1.0f, 0.0f),
                new Vector2D(3.0f, 0),
                form2_2_solution,
                new Vector3D(0,0,0)));

        level.addForm(new Form2(assetManager,
                new Vector3D(1.0f, 1.0f, 1.0f),
                new Vector2D(-8.0f, 8),
                form2_3_solution,
                new Vector3D(0,(float) Math.toRadians(90),0)));

        level.addForm(new Form2(assetManager,
                new Vector3D(1.0f, 0.0f, 1.0f),
                new Vector2D(-8.0f, 8),
                form2_4_solution,
                new Vector3D(0, (float) Math.toRadians(180), 0)));

        // Form 3 section

        ArrayList<Vector2D> form3_1_solution = new ArrayList();
        form3_1_solution.add(new Vector2D(-4, 2));

        ArrayList<Vector2D> form3_2_solution = new ArrayList();
        form3_2_solution.add(new Vector2D(4, 2));

        ArrayList<Vector2D> form3_3_solution = new ArrayList();
        form3_3_solution.add(new Vector2D(2, 12));

        level.addForm(new Form3(assetManager,
                new Vector3D(1.0f, 0.0f, 0.50f),
                new Vector2D(3.0f, 0),
                form3_1_solution,
                new Vector3D(0, 0, 0)));

        level.addForm(new Form3(assetManager,
                new Vector3D(0.0f, 0.50f, 0.50f),
                new Vector2D(3.0f, 0),
                form3_2_solution,
                new Vector3D(0, 0, (float) Math.toRadians(180))));

        level.addForm(new Form3(assetManager,
                new Vector3D(0.50f, 1.0f, 0.50f),
                new Vector2D(3.0f, 0),
                form3_3_solution,
                new Vector3D(0, (float) Math.toRadians(180), (float) Math.toRadians(180))));

        // Form 1 section

        ArrayList<Vector2D> form1_1_solution = new ArrayList();
        form1_1_solution.add(new Vector2D(-4, 6));

        level.addForm(new Form1(assetManager,
                new Vector3D(0.25f, 0.50f, 0.75f),
                new Vector2D(-8, 6),
                form1_1_solution,
                new Vector3D(0, 0, 0)));

        // Form 4 section

        ArrayList<Vector2D> form4_1_solution = new ArrayList();
        form4_1_solution.add(new Vector2D(-2, 10));

        level.addForm(new Form4(assetManager,
                new Vector3D(0.0f, 1.0f, 1.0f),
                new Vector2D(8, 6),
                form4_1_solution,
                new Vector3D(0, 0, 0)));

        // Form 5 section

        ArrayList<Vector2D> form5_1_solution = new ArrayList();
        form5_1_solution.add(new Vector2D(4, 0));

        level.addForm(new Form5(assetManager,
                new Vector3D(0.75f, 0.0f, 0.25f),
                new Vector2D(8, 10),
                form5_1_solution,
                new Vector3D(0, (float) Math.toRadians(-90), 0)));


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
