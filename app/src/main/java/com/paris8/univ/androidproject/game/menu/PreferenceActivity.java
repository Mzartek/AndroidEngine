package com.paris8.univ.androidproject.game.menu;

import android.os.Bundle;
import android.preference.CheckBoxPreference;

import com.paris8.univ.androidproject.R;

public class PreferenceActivity extends android.preference.PreferenceActivity {
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        addPreferencesFromResource(R.xml.settings);
    }
}
