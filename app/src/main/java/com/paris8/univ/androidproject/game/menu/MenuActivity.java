package com.paris8.univ.androidproject.game.menu;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.preference.PreferenceManager;
import android.view.View;
import android.widget.Button;

import com.paris8.univ.androidproject.R;
import com.paris8.univ.androidproject.game.MyMusicManager;

public class MenuActivity extends Activity
{
    private Button playButton;
    private Button scoreButton;
    private Button settingsButton;

    @Override
    public void onResume()
    {
        super.onResume();
        MyMusicManager.GetInstance().resumeMusic();
    }

    @Override
    public void onPause()
    {
        MyMusicManager.GetInstance().stopMusic();
        super.onPause();
    }

    @Override
    public void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_menu);

        ScoreActivity.init(getSharedPreferences("Score", MODE_PRIVATE));

        MyMusicManager.GetInstance().init(getBaseContext(), getResources(), PreferenceManager.getDefaultSharedPreferences(this));
        MyMusicManager.GetInstance().startMusic(R.raw.menu);

        playButton = (Button) findViewById(R.id.playButton);
        scoreButton = (Button) findViewById(R.id.scoreButton);
        settingsButton = (Button) findViewById(R.id.settingsButton);

        playButton.setOnClickListener(new View.OnClickListener()
        {
            @Override
            public void onClick(View v)
            {
                Intent intent = new Intent(MenuActivity.this, LevelActivity.class);
                MenuActivity.this.startActivity(intent);
            }
        });

        scoreButton.setOnClickListener(new View.OnClickListener()
        {
            @Override
            public void onClick(View v)
            {
                Intent intent = new Intent(MenuActivity.this, ScoreActivity.class);
                MenuActivity.this.startActivity(intent);
            }
        });

        settingsButton.setOnClickListener(new View.OnClickListener()
        {
            @Override
            public void onClick(View v)
            {
                Intent intent = new Intent(MenuActivity.this, PreferenceActivity.class);
                MenuActivity.this.startActivity(intent);
            }
        });
    }
}
