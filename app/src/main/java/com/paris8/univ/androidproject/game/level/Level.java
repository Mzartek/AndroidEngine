package com.paris8.univ.androidproject.game.level;

import com.paris8.univ.androidproject.engine.camera.PerspCamera;
import com.paris8.univ.androidproject.game.geometry.Form;

import java.util.ArrayList;

public class Level
{
    private static final String TAG = "Level";

    private ArrayList<Form> forms;
    private Form selectedForm = null;

    public Level()
    {
        forms = new ArrayList<>();
    }

    public void addForm(Form form)
    {
        forms.add(form);
    }

    public void unselectForm()
    {
        if (selectedForm != null)
        {
            selectedForm.unselectIt();
            selectedForm = null;
        }
    }

    public boolean selectForm(int x, int y)
    {
        unselectForm();

        for (Form form : forms)
        {
            if (form.isPointed(x, y))
            {
                selectedForm = form;
                selectedForm.selectIt();

                return true;
            }
        }

        return false;
    }

    public boolean isFormSelected()
    {
        if (selectedForm != null)
            return true;
        return false;
    }

    public Form getSelectedForm()
    {
        return selectedForm;
    }

    public void display(PerspCamera camera)
    {
        for (Form form : forms)
        {
            form.display(camera);
        }
    }

    public boolean isWin()
    {
        for (Form form : forms)
        {
            if (!form.winPosition())
            {
                return false;
            }
        }
        return true;
    }
}
