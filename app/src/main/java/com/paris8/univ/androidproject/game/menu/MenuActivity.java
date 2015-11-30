package com.paris8.univ.androidproject.game.menu;

import android.app.Activity;
import android.content.Intent;
import android.media.MediaPlayer;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.CheckBox;

import com.paris8.univ.androidproject.R;


public class MenuActivity extends Activity {

    public static boolean sound = true;

    private Button playButton;
    private CheckBox soundButton;
    private Button scoreButton;

    private MediaPlayer mMediaPlayer;

    @Override
    public void onResume(){
        super.onResume();
        if(sound)
            mMediaPlayer.start();
    }

    @Override
    public void onPause()
    {
        mMediaPlayer.pause();
        super.onPause();
    }

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_menu);

        mMediaPlayer = MediaPlayer.create(getBaseContext(), R.raw.menu);

        playButton = (Button) findViewById(R.id.playButton);
        soundButton = (CheckBox) findViewById(R.id.soundButton);
        scoreButton = (Button) findViewById(R.id.scoreButton);

        if (soundButton.isChecked()) {
            soundButton.setChecked(true);
            mMediaPlayer.start();
            sound = true;
        } else {
            sound = false;
        }


        playButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(MenuActivity.this, LevelChooser.class);
                mMediaPlayer.pause();
                MenuActivity.this.startActivity(intent);
            }
        });

        soundButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if (soundButton.isChecked())
                    sound = true;
                else
                    sound = false;
                if (!sound)
                    mMediaPlayer.pause();
                else
                    mMediaPlayer.start();
            }
        });

        scoreButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                //afficher les scores !
            }
        });
    }
}
