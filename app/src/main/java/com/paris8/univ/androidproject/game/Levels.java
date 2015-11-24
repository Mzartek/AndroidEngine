package com.paris8.univ.androidproject.game;

import android.content.res.AssetManager;

import com.paris8.univ.androidproject.game.piece.Form1;
import com.paris8.univ.androidproject.game.piece.Form2;
import com.paris8.univ.androidproject.game.piece.Form3;
import com.paris8.univ.androidproject.game.piece.Form4;
import com.paris8.univ.androidproject.game.piece.Form5;

/**
 * Created by Mzartek on 24/11/15.
 */
public class Levels
{
    public static Level getLevel0(AssetManager assetManager)
    {
        Level level = new Level();

        level.addForm(new Form5(assetManager, 0.10f, 0.75f, 0.25f,
                1.75f, 0,
                0, 3.75f,
                66));
        level.addForm(new Form1(assetManager, 1, 0, 0,
                3, 1,
                1, 2,
                33));

        return level;
    }

    public static Level getLevel1(AssetManager assetManager)
    {
        Level level = new Level();

        level.addForm(new Form3(assetManager, 0.10f, 0.75f, 0.25f,
                1.75f, 0,
                0, 3.75f,
                66));
        level.addForm(new Form2(assetManager, 1, 0, 0,
                3, 1,
                1, 2,
                33));

        return level;
    }

    public static Level getLevel2(AssetManager assetManager)
    {
        Level level = new Level();

        level.addForm(new Form4(assetManager, 0.10f, 0.75f, 0.25f,
                1.75f, 0,
                0, 3.75f,
                66));
        level.addForm(new Form5(assetManager, 1, 0, 0,
                3, 1,
                1, 2,
                33));

        return level;
    }
}
