package com.paris8.univ.androidproject.game.menu;

import android.os.Bundle;

import com.paris8.univ.androidproject.R;

/**
 * Created by Jérémie on 30/11/2015.
 */
public class PreferenceActivity extends android.preference.PreferenceActivity {

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        addPreferencesFromResource(R.xml.settings);

    }








}
