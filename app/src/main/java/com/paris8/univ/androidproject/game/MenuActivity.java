package com.paris8.univ.androidproject.game;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

import com.paris8.univ.androidproject.R;

/**
 * Created by Mzartek on 23/11/15.
 */
public class MenuActivity extends Activity {

    private Button playButton;
    private Button soundButton;

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_menu);

        playButton = (Button) findViewById(R.id.playButton);
        soundButton = (Button) findViewById(R.id.soundButton);

        playButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(MenuActivity.this, GameActivity.class);
                MenuActivity.this.startActivity(intent);
            }
        });

        soundButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                //faire un truc avec le son
            }
        });

    }
}
