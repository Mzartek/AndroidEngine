package com.paris8.univ.androidproject.game.menu;

import android.app.Activity;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.widget.TextView;

import com.paris8.univ.androidproject.R;

public class ScoreActivity extends Activity {

    private static SharedPreferences settings;
    private static SharedPreferences.Editor settingsEditor;

    private static String prefScore1 = "PrefScore1";
    private static String prefScore2 = "PrefScore2";
    private static String prefScore3 = "PrefScore3";

    private TextView mTextViewScoreLevel1;
    private TextView mTextViewScoreLevel2;
    private TextView mTextViewScoreLevel3;

    private static void setScore(long ms, String prefScore) {
        settingsEditor.putLong(prefScore, ms);
        settingsEditor.apply();
    }

    private static void displayScore(long ms, TextView textView) {
        long m = (long)(ms / 60000.0);
        long s = (long)(ms / 1000.0);
        textView.setText(new String(m + "m " + s % 60 + "s " + ms % 1000 + "ms"));
    }

    public static void init(SharedPreferences sharedPreferences) {
        settings = sharedPreferences;
        settingsEditor = settings.edit();
    }

    public static void setScoreLevel1(long ms) {
        long currentScore = settings.getLong(prefScore1, 0);
        if (currentScore !=0)
        {
            if (ms < currentScore)
            {
                setScore(ms, prefScore1);
            }
        }
        else
        {
            setScore(ms, prefScore1);
        }
    }

    public static void setScoreLevel2(long ms) {
        long currentScore = settings.getLong(prefScore2, 0);
        if (currentScore !=0)
        {
            if (ms < currentScore)
            {
                setScore(ms, prefScore2);
            }
        }
        else
        {
            setScore(ms, prefScore2);
        }
    }

    public static void setScoreLevel3(long ms) {
        long currentScore = settings.getLong(prefScore3, 0);
        if (currentScore !=0)
        {
            if (ms < currentScore)
            {
                setScore(ms, prefScore3);
            }
        }
        else
        {
            setScore(ms, prefScore3);
        }
    }

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_score);

        mTextViewScoreLevel1 = (TextView)findViewById(R.id.scoreLevel1);
        mTextViewScoreLevel2 = (TextView)findViewById(R.id.scoreLevel2);
        mTextViewScoreLevel3 = (TextView)findViewById(R.id.scoreLevel3);

        displayScore(settings.getLong(prefScore1, 0), mTextViewScoreLevel1);
        displayScore(settings.getLong(prefScore2, 0), mTextViewScoreLevel2);
        displayScore(settings.getLong(prefScore3, 0), mTextViewScoreLevel3);
    }
}
