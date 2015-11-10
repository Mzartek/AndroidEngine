package com.paris8.univ.androidproject.game;

import com.paris8.univ.androidproject.game.piece.Form;

import java.util.ArrayList;

/**
 * Created by Mzartek on 10/11/15.
 */
public class Level
{
    private ArrayList<Form> forms;
    private Form selectedForm;

    public Level()
    {
        forms = new ArrayList<>();
    }

    public void addForm(Form form)
    {
        forms.add(form);
    }
}
