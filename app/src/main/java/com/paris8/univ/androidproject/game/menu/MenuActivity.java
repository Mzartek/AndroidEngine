package com.paris8.univ.androidproject.game.menu;

import android.app.Activity;
import android.content.Intent;
import android.media.MediaPlayer;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

import com.paris8.univ.androidproject.R;

/**
 * Created by Mzartek on 23/11/15.
 */
public class MenuActivity extends Activity {

    public static boolean sound = true;

    private Button playButton;
    private Button soundButton;
    private Button scoreButton;

    private MediaPlayer mMediaPlayer;

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_menu);

        mMediaPlayer = MediaPlayer.create(getBaseContext(), R.raw.menu);
        mMediaPlayer.start();

        playButton = (Button) findViewById(R.id.playButton);
        soundButton = (Button) findViewById(R.id.soundButton);
        scoreButton = (Button) findViewById(R.id.scoreButton);

        playButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(MenuActivity.this, LevelChooser.class);
                MenuActivity.this.startActivity(intent);
            }
        });

        soundButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                sound = !sound;
                if(!sound)
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
