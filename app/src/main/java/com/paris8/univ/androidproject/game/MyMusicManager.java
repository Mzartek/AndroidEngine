package com.paris8.univ.androidproject.game;

import android.content.SharedPreferences;
import android.media.MediaPlayer;

public class MyMusicManager extends Thread
{
    private static MyMusicManager Instance = new MyMusicManager();

    private SharedPreferences mSharedPreference;
    private MediaPlayer mMediaPlayer;

    public static MyMusicManager GetInstance()
    {
        return Instance;
    }

    private MyMusicManager()
    {
    }

    public void setSharedPreference(SharedPreferences sharedPreference)
    {
        mSharedPreference = sharedPreference;
    }

    public void run()
    {
    }
}
