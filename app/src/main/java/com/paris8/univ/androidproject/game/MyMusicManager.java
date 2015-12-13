package com.paris8.univ.androidproject.game;

import android.content.Context;
import android.content.SharedPreferences;
import android.content.res.Resources;
import android.media.MediaPlayer;

import com.paris8.univ.androidproject.R;

public class MyMusicManager
{
    private static MyMusicManager Instance = new MyMusicManager();

    private Context mContext;
    private Resources mResources;
    private SharedPreferences mSharedPreference;
    private MediaPlayer mMediaPlayer;

    public static MyMusicManager GetInstance()
    {
        return Instance;
    }

    private MyMusicManager()
    {
    }

    public void init(Context context, Resources resources, SharedPreferences sharedPreference)
    {
        mContext = context;
        mResources = resources;
        mSharedPreference = sharedPreference;
    }

    public void stopMusic()
    {
        if (mMediaPlayer != null)
        {
            if (mMediaPlayer.isPlaying()) mMediaPlayer.stop();
        }
    }

    public void resumeMusic()
    {
        if (mMediaPlayer != null)
        {
            if (!mMediaPlayer.isPlaying()) mMediaPlayer.start();
        }
    }

    public void startMusic(int selectedMusic)
    {
        stopMusic();
        if(mSharedPreference.getBoolean(mResources.getString(R.string.pref_sound), true))
        {
            mMediaPlayer = MediaPlayer.create(mContext, selectedMusic);
            mMediaPlayer.setLooping(true);
            mMediaPlayer.start();
        }
    }
}
