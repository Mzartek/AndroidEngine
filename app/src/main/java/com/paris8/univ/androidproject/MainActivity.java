package com.paris8.univ.androidproject;

import android.opengl.GLSurfaceView;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;

import com.paris8.univ.androidproject.engine.EngineView;

public class MainActivity extends AppCompatActivity
{
    final static private String TAG = "MainActivity";

    GLSurfaceView mView;

    @Override
    protected void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);

        mView = new EngineView(getApplication());
        setContentView(mView);
        //setContentView(R.layout.activity_main);
    }

    @Override
    protected void onPause()
    {
        super.onPause();
        mView.onPause();
    }

    @Override
    protected void onResume()
    {
        super.onResume();
        mView.onResume();
    }

    /*@Override
    public boolean onCreateOptionsMenu(Menu menu)
    {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.menu_main, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item)
    {
        // Handle action bar item clicks here. The action bar will
        // automatically handle clicks on the Home/Up button, so long
        // as you specify a parent activity in AndroidManifest.xml.
        int id = item.getItemId();

        //noinspection SimplifiableIfStatement
        if (id == R.id.action_settings) {
            return true;
        }

        return super.onOptionsItemSelected(item);
    }*/

    static
    {
        System.loadLibrary("engine-jni");
    }
}
