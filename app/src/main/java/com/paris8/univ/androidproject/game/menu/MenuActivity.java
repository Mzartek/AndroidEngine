package com.paris8.univ.androidproject.game.menu;

import android.app.Activity;
import android.content.Intent;
import android.content.SharedPreferences;
import android.media.MediaPlayer;
import android.os.Bundle;
import android.preference.*;
import android.view.View;
import android.widget.Button;

import com.paris8.univ.androidproject.R;

public class MenuActivity extends Activity {
    public static SharedPreferences sharedPreferences;

    private Button playButton;
    private Button scoreButton;
    private Button settingsButton;

    private MediaPlayer mMediaPlayer;

    @Override
    public void onResume(){
        super.onResume();
        if(mMediaPlayer == null) { mMediaPlayer = MediaPlayer.create(getBaseContext(), R.raw.menu); mMediaPlayer.setLooping(true); }
        if(sharedPreferences.getBoolean(getResources().getString(R.string.pref_sound), true))
            if(!mMediaPlayer.isPlaying())mMediaPlayer.start();
    }

    @Override
    public void onPause()
    {
        if(mMediaPlayer.isPlaying()) mMediaPlayer.pause();
        super.onPause();
    }

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_menu);

        sharedPreferences = PreferenceManager.getDefaultSharedPreferences(this);
        ScoreActivity.init(getSharedPreferences("Score", MODE_PRIVATE));

        mMediaPlayer = MediaPlayer.create(getBaseContext(), R.raw.menu);
        mMediaPlayer.setLooping(true);
        playButton = (Button) findViewById(R.id.playButton);
        scoreButton = (Button) findViewById(R.id.scoreButton);
        settingsButton = (Button) findViewById(R.id.settingsButton);

        if (sharedPreferences.getBoolean(getResources().getString(R.string.pref_sound), true)) {
            if(!mMediaPlayer.isPlaying())mMediaPlayer.start();
        }

        playButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(MenuActivity.this, LevelActivity.class);
                MenuActivity.this.startActivity(intent);
            }
        });

        scoreButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(MenuActivity.this, ScoreActivity.class);
                MenuActivity.this.startActivity(intent);
            }
        });

        settingsButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(MenuActivity.this, PreferenceActivity.class);
                MenuActivity.this.startActivity(intent);
            }
        });
    }
}
